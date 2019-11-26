#include <iostream>

using namespace std;

void hanoi(int n, int s, int m, int e)
{
    if (n == 1)
        cout << "1: " << s << "->" << e << endl;
    else
    {
        hanoi(n - 1, s, e, m);
        cout << n << ": " << s << "->" << e << endl;
        hanoi(n - 1, m, s, e);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);

    return 0;
}