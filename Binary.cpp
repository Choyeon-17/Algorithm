#include <stdio.h>

int From, To, decimal = 0, index_max = 0, To_num_inmax = 0;
char From_num[50] = { 0 }, To_num[50] = { 0 };

int ctoi(char ch)
{
    if(ch>='0' && ch<='9')
        return (ch - '0');
    else if(ch>='A' && ch<='F')
        return (ch - 'A' + 10);
    else
        return -1;
}

char itoc(int value)
{
    if(value <= 9)
        return (value + '0');
    else
        return (value - 10 + 'A');
}

int repeat(int square)
{
    int tmp = 1, i;
    if(square == 0)
        return tmp;
    for(i=0; i<square; i++)
        tmp *= From;
    return tmp;
}

int To_decimal()
{
    int i;
    for(i=0; From_num[i]; i++)
        index_max++;
    for(i=0; From_num[i]; i++)
    {
        if(ctoi(From_num[i]) != -1)
            decimal += ctoi(From_num[i]) * repeat((index_max-1) - i);
        else
        {
            printf("Error!\n");
            return 0;
        }
        if(decimal>65535)
        {
            printf("범위 초과\n");
            return 0;
        }
    }
    return decimal;
}

void Convert_to()
{
    int i;
    for(i=0; i<50; i++)
    {
        if(decimal <= 0)
            break;
        To_num[i] = itoc(decimal % To);
        decimal /= To;
    }
}

void print()
{
    int i;
    for(i=0; To_num[i]; i++)
        To_num_inmax++;
    for(i=To_num_inmax-1; i>=0; i--)
        printf("%c", To_num[i]);
    printf("\n");
}

int main()
{
    int i;
    printf("원래 진수와 변환하고자 하는 진수를 공백을 두고 순서대로 입력하세요.\n");
    scanf("%d %d", &From, &To);
    printf("원래 진수의 값을 입력하세요.\n");
    scanf("%s", From_num);
    for(i=0; From_num[i]; i++)
    {
        if(From == 2)
        {
            if(From_num[i]!='0' && From_num[i]!='1')
            {
                printf("Error!\n");
                return 0;
            }
        }
        else if(From == 8)
        {
            if(From_num[i]<'0' || From_num[i]>'7')
            {
                printf("Error!\n");
                return 0;
            }
        }
    }
    if(To_decimal() == 0)
        return 0;
    Convert_to();
    print();
}
