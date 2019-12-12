#include <iostream>

using namespace std;

long long int memo[100];

long long int factorial(int n)
{
    if (n == memo[n])
        return memo[n];
    if (n == 2)
        return 2;
    return memo[n] = n * factorial(n - 1);
}

long long int C(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    int n, r;
    cout << "n개의 요소, 그룹지을 r개의 요소를 입력하세요." << endl;
    cin >> n >> r;
    cout << "조합은 " << C(n, r) << "개입니다." << endl;

    return 0;
}