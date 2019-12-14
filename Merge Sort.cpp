#include <iostream>
#include <vector>

using namespace std;

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
    }
}

int main()
{
    vector<int> array;
    int n;
    cout << "배열의 크기를 입력하세요." << endl;
    cin >> n;
    cout << "배열의 요소를 입력하세요." << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    cout << "합병 정렬 결과: " << endl;
    merge(array, 0, n-1, n/2);
}