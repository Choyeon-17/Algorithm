#include <iostream>

using namespace std;

int *array;

class BubbleSort
{
private:
    tmp, index = 1;
public:
    void sort()
    {
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }

            cout << index << " pass: ";
            for (int k = 0; k < n; k++)
                cout << array[k] << " ";
            cout << endl;
            
            index++;
        }
    }
};

int main()
{
    BubbleSort BS;
    int n;

    cout << "Please enter a size for the array." << endl;
    cin >> n;

    array = new int[n];

    cout << "Please enter a value for the array." << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    BS.sort();

    delete[] array;
}
