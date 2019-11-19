#include <iostream>

using namespace std;

int main()
{
    int u, v, tmp;
    cin >> u >> v;
    while (v != 0)
    {
        u %= v;
        tmp = u;
        u = v;
        v = tmp;
    }
    cout << "GCD: " << u << endl;
}