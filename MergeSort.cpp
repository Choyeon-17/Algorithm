#include <iostream>
#include <vector>

using namespace std;

vector<int> array;
int n, i = 1;

void merge(vector<int> &v, int s, int e, int m)
{
    vector<int> ret;
    int i = s, j = m + 1, copy = 0;

    while (j <= m && j <= e)
    {
        if (v[i] < v[j])
            ret.push_back(v[i++]);

        else if (v[i] > v[j])
            ret.push_back(v[j++]);
    }

    while (i <= m)
        ret.push_back(v[i++]);

    while (j <= e)
        ret.push_back(v[j++]);

    for (int k = s; k <= e; k++)
        v[k] = ret[copy++];
}

void mergeSort(vector<int> &v, int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;

        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, e, m);

        cout << i << " pass: ";
        for (int i = 0; i < n; i++)
            cout << array[i] << " ";
        cout << endl;
    }
}

int main()
{
    cout << "Please enter a size for the array." << endl;
    cin >> n;

    cout << "Please enter a value for the array." << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    mergeSort(array, 0, n - 1);
}
