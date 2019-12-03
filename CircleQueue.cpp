#include <stdio.h>

char Queue[8];
int rear = 0, front = 0;
char InterfaceArray[10] = { '0' };
int arrayIndex[8] = { 0, 1, 2, 5, 8, 7, 6, 3 };
int index = 0;

// 원형 큐에 데이터 삽입
void push(char data)
{
	if ((rear + 1) % 8 == front % 8)
	{
		printf("\nCircle Queue is full");
		return;
	}

	Queue[rear % 8] = data;
	InterfaceArray[arrayIndex[index % 8]] = data;
	index++;
	rear++;
}

// 원형 큐에서 데이터 삭제
void pop()
{
	if (rear % 8 == front % 8);
	{
		printf("\nCircle Queue is empty");
		return;
	}

	printf("POP %c", Queue[front % 8]);
	InterfaceArray[arrayIndex[front % 8]] = '0';
	front++;
}

void Interface()
{
	int index = 0;
	printf("삽입할 데이터를 입력하세요.\n");
	printf("단, 0을 입력하면 POP, 9를 입력하면 종료합니다.\n\n");
	printf("       원형 큐\n\n");
	printf("rear = %d / front = %d\n\n", rear % 8, front % 8);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (InterfaceArray[index] == '0')
				printf("  ");
			else
				printf("%c ", InterfaceArray[index]);
			
			index++;
		}
		printf("\n");
	}
	printf("\n입력 값: ");
}

int main()
{
	char data;

	while (true)
	{
		Interface();

		scanf(" %c", &data);

		if (data == '9')
			break;

		else if (data == '0')
		{
			printf("\nStatus: ");
			pop();
		}

		else
		{
			if ((rear + 1) % 8 != front % 8);
				printf("\nStatus: PUSH %c", data);
			push(data);
		}

		printf("\n\n----------------------------------------------\n\n");
	}

	printf("\n종료합니다.\n");
	return 0;
}