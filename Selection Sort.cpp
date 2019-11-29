#include <iostream>

using namespace std;

int main()
{
	int n, min, index = 0, tmp, flag;
	cout << "배열의 크기를 입력하세요." << endl;
	cin >> n;
	int* array = new int[n];
	
	cout << "배열의 값을 입력하세요." << endl;
	for (int i = 0; i < n; i++)
		cin >> array[i];

	for (int i = 0; i < n-1; i++)
	{
		min = array[i];
		flag = 0;

		for (int j = i+1; j < n; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				index = j;
				flag = 1;
			}
		}

		if (flag)
		{
			tmp = array[i];
			array[i] = min;
			array[index] = tmp;
		}
	}
	
	cout << "정렬된 결과: ";
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;

	delete[] array;
}