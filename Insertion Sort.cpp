#include <iostream>

using namespace std;

int main()
{
	int n, tmp, index;
	cout << "배열의 개수를 입력하세요." << endl;
	cin >> n;
	int* array = new int[n];

	cout << "배열의 값을 입력하세요." << endl;
	for (int i = 0; i < n; i++)
		cin >> array[i];

	for (int i = 1; i < n; i++)
	{
		index = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (array[index] >= array[j])
				break;

			tmp = array[j];
			array[j] = array[index];
			array[index] = tmp;
			index = j;
		}

		cout << i << "회전 결과: ";
		for (int k = 0; k < n; k++)
			cout << array[k] << " ";
		cout << endl;
	}

	delete[] array;
}