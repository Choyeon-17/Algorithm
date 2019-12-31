#include <iostream>

using namespace std;

template <typename TYPE>
class LinearQueue
{
private:
	TYPE* pArr;
	int rear, front, size;
public:
	LinearQueue(int n)
		: rear(0), front(0), size(n)
	{
		pArr = new TYPE[size];
	}

	void push(TYPE data)
	{
		if (rear == size)
		{
			cout << "Linear Queue is full" << endl;
			return;
		}

		pArr[rear++] = data;
	}

	void pop()
	{
		if (rear == front)
		{
			cout << "Linear Queue is empthy" << endl;
			return;
		}

		cout << "POP: " << pArr[front++] << endl;
	}

	void CurrentStatus()
	{
		cout << "Current Status: "
		for (int i = front; i < rear; i++)
			cout << pArr[i] << " ";
		cout << endl;
	}

	~LinerQueue()
	{
		delete[] pArr;
	}
};

int main()
{
	int n, flag = 1, data;

	cout << "Please enter a size for the Linear Queue." << endl;
	cin >> n;

	LinearQueue<int> LQ(n);

	while (flag)
	{
		cout << "Enter 1 for PUSH, 2 for POP, and 0 for Exit." << endl;
		cin >> flag;

		if (flag == 1)
		{
			cout << "PUSH: ";
			cin >> data;
			LQ.push(data);
			LQ.CurrentStatus();
		}

		else if (flag == 2)
		{
			LQ.pop();
			LQ.CurrentStatus();
		}

		else if (flag == 0)
			break;

		else
			cout << "Invalid Command." << endl;
	}

	cout << "Quit." << endl;

	return 0;
}
