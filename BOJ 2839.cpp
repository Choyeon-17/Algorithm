#include <iostream>

using namespace std;

int main()
{
    int n, count;
    cin >> n;

    if (n == 4 || n == 7)
    {
        cout << "-1" << endl;
        return 0;
    }

    count = n / 5;

    switch (n % 5)
    {
    case 0:
        cout << count << endl;
        break;
    case 1:
    case 3:
        cout << count + 1 << endl;
        break;
    case 2:
    case 4:
        cout << count + 2 << endl;
        break;
    }

    return 0;
}