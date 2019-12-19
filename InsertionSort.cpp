#include <iostream>

using namespace std;

int *array;

class InsertionSort
{
private:
    int tmp, index;

public:
    void sort()
    {
        for (int i = 1; i < n; i++)
        {
            index = i;

            for (int j = i - 1; j >= 0; j--)
            {
                if (array[index] >= array[j])
                    break;

                tmp = array[j];
                array[j] = array[index];
                array[index] = tmp;
                index = j;
            }

            cout << i << " pass: ";
            for (int k = 0; k < n; k++)
                cout << array[k] << " ";
            cout << endl;
        }
    }
};

int main()
{
    InsertionSort IS;
    int n;

    cout << "Please enter a size for the array." << endl;
    cin >> n;

    array = new int[n];

    cout << "Please enter a value for the array." << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    IS.sort();

    delete[] array;
}
