#include <iostream>

using namespace std;

int main()
{
 int n, tmp, idx = 1;
 cout << "배열의 크기를 입력하세요." << endl;
 cin >> n;
 int* array = new int[n];
 cout << "배열의 값을 입력하세요." << endl;
 for (int i = 0; i < n; i++)
  cin >> array[i];
 for (int i = n - 1; i > 0; i--)
 {
  for (int j = 0; j < i; j++)
  {
   if (array[j] > array[j + 1])
   {
    tmp = array[j];
    array[j] = array[j + 1];
    array[j + 1] = tmp;
   }
  }
  cout << idx << "회전 결과: ";
  for (int k = 0; k < n; k++)
   cout << array[k] << " ";
  cout << endl;
  idx++;
 }
 delete[] array;
}