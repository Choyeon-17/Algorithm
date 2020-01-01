#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

vector<int> v, h;
int n, k, m1, m2;

int Random(int i)   { return rand() % i; }

void RandGenerator(vector<int>& v, int n, int k)
{
    srand(time(NULL));

    for (int i = 1; i <= 2*n; i++)
        v.push_back(i);

    random_shuffle(v.begin(), v.end(), Random);
}

int HashFunc1(int k)    { return k % m1; }

int HashFunc2(int k)    { return 1 + k % m2; }

int DoubleFunc(int k, int i)    { return (HashFunc1(k) + i * HashFunc2(k)) % m1; }

void Hashing(vector<int>& v, vector<int>& h, int (*HashFunc)(int, int))
{
    int coll, first = 1, count = 0;
    double rate;
    
    for (int i = 0; i < k; i++)
    {
        int c = 0;

        while (true)
        {
            int key = HashFunc(v[i], c);
            
            if (h[key] == 1)
            {
                h[key] = v[i];
                break;
            }

            else
            {
                {
                    if (first == 1)
                    {
                        first = v[i];
                        rate = (double)i / n * 100;
                    }

                    count++;
                    c++;
                }
            }
        }
    }

    cout << "첫 충돌 값: " << first << endl;
    cout << "총 충돌 수: " << count << endl;
    cout << "첫 충돌 시 적재율: " << rate << endl;
}

int main()
{
    cout << "키 값 범위의 크기: ";
    cin >> k;
    cout << "해시 테이블의 크기(1 ~ n): ";
    cin >> n;
    cout << "m1, m2 입력: ";
    cin >> m1 >> m2;
    cout << endl;

    RandGenerator(v, n, k);
    for (int i = 0; i < n; i++)
        h.push_back(1);
    cout << endl;
    Hashing(v, h, DoubleFunc);
}