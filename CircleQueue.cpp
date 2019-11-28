#include <iostream>

using namespace std;

template <typename TYPE>
class CircleQueue
{
private:
	int size;
	TYPE* array;
	int rear, front;

public:
	CircleQueue(int size) : size(size), rear(0), front(0)
	{
		array = new TYPE[size];
	}

	void push(TYPE data)
	{
		if ((rear + 1) % size == front % size)
		{
			cout << "Circle Queue is full" << endl;
			return;
		}

		array[rear % size] = data;
		rear++;
	}

	void pop()
	{
		if (rear % size == front % size)
		{
			cout << "Circle Queue is empty" << endl;
			return;
		}

		cout << "POP: " << array[front % size] << endl;
		front++;
	}
	
	void OutCircleQueue()
	{
		if ((rear) % size == front % size)
			return;

		else if (front % size < rear % size)
		{
			cout << "Circle Queue: ";
			for (int i = front % size; i < rear % size; i++)
				cout << array[i] << " ";
			cout << endl;
		}

		else if (front % size > rear% size)
		{
			cout << "Circle Queue: ";
			for (int i = front % size; i < size; i++)
				cout << array[i] << " ";

			for (int j = 0; j < rear % size; j++)
				cout << array[j] << " ";
			cout << endl;
		}

		else
			return;
	}

	~CircleQueue()
	{
		delete[] array;
	}
};

int main()
{
	int size;
	int flag, data;
	cout << "원형 큐의 크기를 입력하세요." << endl;
	cin >> size;
	CircleQueue<int> circle_queue(size);

	while (true)
	{
		cout << "PUSH는 1, POP은 2, 종료는 0을 누르세요." << endl;
		cin >> flag;

		if (flag == 0)
			break;

		else if (flag == 1)
		{
			cout << "PUSH: ";
			cin >> data;
			circle_queue.push(data);
			circle_queue.OutCircleQueue();
			cout << endl;
		}

		else if (flag == 2)
		{
			circle_queue.pop();
			circle_queue.OutCircleQueue();
			cout << endl;
		}

		else
			cout << "잘못된 명령입니다." << endl << endl;
	}

	cout << "\n종료합니다." << endl;
}