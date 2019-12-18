#include <iostream>

using namespace std;

int main()
{
    int a, b, i = 0, sum = 0;

    cin >> a >> b;

    while (a > 0)
    {
        if (a % 2 != 0)
            sum += b;

        a /= 2;
        b *= 2;

        i++;
    }

    cout << sum << endl;
}
