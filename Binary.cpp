#include <stdio.h>

void transBinary(long n)
{
    if (n == 0)
    {
        printf("0");
    }
    else if (n == 1)
    {
        printf("1");
    }
    else
    {
        transBinary(n / 2);
        printf("%ld", n % 2);
    }
}

int main()
{

    long n;

    scanf("%ld", &n);

    transBinary(n);

    return 0;
}