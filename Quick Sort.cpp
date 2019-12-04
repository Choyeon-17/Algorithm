#include <iostream>

using namespace std;

int partition(int list[], int left, int right)
{
 int pivot, tmp;
 int low, high;

 low = left;
 high = right + 1; // n
 pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 설정
 
 // low와 high가 교차할 때까지 반복한다.
 do
 {
  // list[low]가 피벗보다 작으면 계속 low를 증가시킨다.
  do
  {
   low++; // low는 left + 1(피벗 + 1)에서 시작한다.
  } while (low <= right && list[low] < pivot);

  // list[high]가 피벗보다 크면 계속 high를 감소시킨다.
  do
  {
   high--; // high는 right에서 시작한다.
  } while (high >= left && list[high] > pivot);

  // low와 high가 교차하지 않았을 경우,
  // list[low]와 list[high]를 교환한다.
  if (low < high)
   swap(list[low], list[high]);
 } while (low < high);

 // low와 high가 교차했을 경우, 반복문을 빠져나와서
 // list[left]와 list[high]를 교환한다.
 swap(list[left], list[high]);

 // 피벗의 위치인 high를 반환한다.
 return high;
}

void quick_sort(int list[], int left, int right)
{
 // list의 크기가 0과 1이 아닐 경우
 if (left < right)
 {
  // 피벗을 받는다.
  int q = partition(list, left, right);

  // 피벗을 기준으로 왼쪽을 정렬한다.
  // left ~ 피벗의 바로 앞
  quick_sort(list, left, q - 1);

  // 피벗을 기준으로 오른쪽을 정렬한다.
  // 피벗의 바로 뒤 ~ right
  quick_sort(list, q + 1, right);
 }
}

int main()
{
 int n;
 cout << "배열의 크기를 입력하세요." << endl;
 cin >> n;
 int* array = new int[n];

 cout << "배열의 값을 입력하세요." << endl;
 for (int i = 0; i < n; i++)
  cin >> array[i];

 // left: 배열의 맨 왼쪽
 // right: 배열의 맨 오른쪽
 quick_sort(array, 0, n - 1);

 for (int i = 0; i < n; i++)
  cout << array[i] << " ";
 cout << endl;

 delete[] array;
}