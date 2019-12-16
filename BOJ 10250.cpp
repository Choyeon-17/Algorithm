#include <iostream>

using namespace std;

int main()
{
    int t, h, w, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;

        if (n % h)
        {
            if (n / h + 1 >= 10)
                cout << n % h << n / h + 1 << endl;
            else
                cout << n % h << "0" << n / h + 1 << endl;
        }

        else
        {
            if (n / h >= 10)
                cout << h << n/h << endl;
            else
                cout << h << "0" << n / h << endl;
        }
    }
}