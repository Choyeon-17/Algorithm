#include <iostream>

using namespace std;

class CircleQueue
{
private:
    char Queue[8];
    int rear = 0, front = 0;

    char Interface[10] = {'0'};
    int InterfaceIndex[8] = {0, 1, 2, 5, 8, 7, 6, 3};
    int index = 0;

public:
    void push(char data)
    {
        if ((rear + 1) % 8 == front % 8)
        {
            cout << "\nCircle Queue is full.";
            return;
        }

        Queue[rear % 8] = data;
        Interface[InterfaceIndex[index % 8]] = data;

        rear++;
        index++;
    }

    void pop()
    {
        if (rear % 8 == front % 8)
            ;
        {
            cout << "\nCircle Queue is empty.";
            return;
        }

        cout << "POP " << Queue[front % 8];

        Interface[InterfaceIndex[front % 8]] = '0';

        front++;
    }

    void Interface()
    {
        int index = 0;

        cout << "Enter the data to insert." << endl;
        cout << "However, enter 0 to enter POP, enter 9 to exit." << endl
             << endl;
        cout << "rear = " << rear % 8 << " / front = " << front % 8 << endl
             << endl;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Interface[index] == '0')
                    printf("  ");
                else
                    printf("%c ", Interface[index]);

                index++;
            }

            cout << endl;
        }

        cout << "\nPlease enter a value: ";
    }
};

int main()
{
    CircleQueue CQ;
    char data;

    while (true)
    {
        Interface();

        cin >> data;

        if (data == '9')
            break;

        else if (data == '0')
        {
            cout << "\nStatus: ";
            pop();
        }

        else
        {
            if ((rear + 1) % 8 != front % 8)
                ;
            cout << "\nStatus: PUSH " << data;
            push(data);
        }

        cout << "\n\n----------------------------------------------\n\n";
    }

    cout << "\nQuit." << endl;

    return 0;
}
