#include <iostream>

using namespace std;

int *array;

class SelectionSort
{
private:
    int min, index = 0, tmp, flag;

public:
    void sort()
    {
        for (int i = 0; i < n - 1; i++)
        {
            min = array[i];
            flag = 0;

            for (int j = i + 1; j < n; j++)
            {
                if (min > array[j])
                {
                    min = array[j];
                    index = j;
                    flag = 1;
                }
            }

            if (flag)
            {
                tmp = array[i];
                array[i] = min;
                array[index] = tmp;
            }

            cout << i + 1 << " pass: ";
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    SelectionSort SS;
    int n;

    cout << "Please enter a size for the array." << endl;
    cin >> n;

    array = new int[n];

    cout << "Please enter a value for the array." << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    SS.sort();

    delete[] array;
}
