#include <iostream>

using namespace std;

int *array;
int i = 0;

class QuickSort
{
private:
    int pivot, tmp;
    int low, high;

public:
    int partition(int list[], int left, int right)
    {
        pivot = list[left];
        low = left;
        high = right + 1;

        do
        {
            do
            {
                low++;
            } while (low <= right && list[low] < pivot);

            do
            {
                high--;
            } while (high >= left && list[high] > pivot);

            if (low < high)
                swap(list[low], list[high]);

        } while (low < high);

        swap(list[left], list[high]);

        return high;
    }

    void quick_sort(int list[], int left, int right)
    {
        if (left < right)
        {
            int q = partition(list, left, right);

            cout << i << " pass: ";
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            cout << endl;
            i++;

            quick_sort(list, left, q - 1);
            quick_sort(list, q + 1, right);
        }
    }
};

int main()
{
    QuickSort QS;
    int n;

    cout << "Please enter a size for the array." << endl;
    cin >> n;

    array = new int[n];

    cout << "Please enter a value for the array." << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    QS.quick_sort(array, 0, n - 1);

    delete[] array;
}
