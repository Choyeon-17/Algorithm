#include <iostream>

using namespace std;

template <typename TYPE> class Stack
{
private:
	int n, top;
	TYPE data;
	TYPE* array;

public:
	Stack(int n) : n(n), top(0)
	{
		array = new TYPE[n];
	}

	void push(TYPE d)
	{
		data = d;

		if (top >= n)
		{
			cout << "Stack is full" << endl;
			return;
		}

		array[top++] = data;
	}

	void pop()
	{
		if (top == 0)
		{
			cout << "Stack is empty" << endl;
			return;
		}

		cout << "POP: " << array[--top] << endl;
	}

	void CurrentStatus()
	{
		cout << "Stack: ";
		for (int i = 0; i < top; i++)
			cout << array[i] << " ";
		cout << endl << endl;
	}

	~Stack()
	{
		delete[] array;
	}
};

int main()
{
	int n, flag = 1, data;

	cout << "스택의 크기를 입력하세요." << endl;
	cin >> n;

	Stack<int> stack(n);

	while (flag)
	{
		cout << "PUSH는 1, POP은 2, 종료는 0을 입력하세요." << endl;
		cin >> flag;

		if (flag == 1)
		{
			cout << "PUSH: ";
			cin >> data;
			stack.push(data);
			stack.CurrentStatus();
		}

		else if (flag == 2)
		{
			stack.pop();
			stack.CurrentStatus();
		}

		else if (flag == 0)
			break;

		else
			cout << "잘못된 명령입니다." << endl;
	}

	cout << "종료합니다." << endl;

	return 0;
}