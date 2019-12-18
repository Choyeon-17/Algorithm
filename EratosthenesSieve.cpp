#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cin >> n;
    
    bool *PrimeArray = new bool[n];
    
    memset(PrimeArray, 0, n);

    for (int i = 2; i < n; i++)
        if (!PrimeArray[i])
            for (int j = i * 2; j < n; j += i)
                PrimeArray[j] = 1;

    for (int i = 2; i < n; i++)
        if (!PrimeArray[i])
            cout << i << " ";
    cout << endl;

    delete[] PrimeArray;
}
