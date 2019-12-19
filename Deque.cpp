#include <iostream>

using namespace std;

struct node
{
    int data;
    node* prev, *next;

    static node* GetNode(int data)
    {
        node* NewNode = new node();

        NewNode->data = data;
        NewNode->prev = NULL;
        NewNode->next = NULL;

        return NewNode;
    }
};

class Deque
{
private:
    node* front;
    node* rear;
    int size;

public:
    Deque() :front(NULL), rear(NULL), size(0) { }

    void InsertFront(int data);
    void InsertRear(int data);
    void DelFront();
    void DelRear();
    int GetFront();
    int GetRear();
    int GetSize();
    bool IsEmpty();
    void Erase();
    void Display();
};

bool Deque::IsEmpty()
{
    return (front == NULL);
}

int Deque::GetSize()
{
    return size;
}

void Deque::InsertFront(int data)
{
    node* NewNode = node::GetNode(data);

    if (NewNode == NULL)
        cout << "Deque overflow";
    
    else
    {
        cout << "Insert Front: " << data;

        if (front == NULL)
        {
            rear = NewNode;
            front = NewNode;
        }
        
        else
        {
            NewNode->next = front;
            front->prev = NewNode;
            front = NewNode;
        }

        size++;
    }

    cout << endl;
}

void Deque::InsertRear(int data)
{
    node* NewNode = node::GetNode(data);

    if (NewNode == NULL)
        cout << "Deque overflow";

    else
    {
        cout << "Insert Rear: " << data;

        if (rear == NULL)
        {
            front = NewNode;
            rear = NewNode;
        }
        
        else
        {
            NewNode->prev = rear;
            rear->next = NewNode;
            rear = NewNode;
        }

        size++;
    }

    cout << endl;
}

void Deque::DelFront()
{
    if (IsEmpty())
        cout << "Deque underflow";

    else
    {
        cout << "Del Front: " << front->data;

        node* tmp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        else
            front->prev = NULL;

        free(tmp);
        
        size--;
    }

    cout << endl;
}

void Deque::DelRear()
{
    if (IsEmpty())
        cout << "Deque underflow";
        
    else
    {
        cout << "Del Rear: " << rear->data;

        node* tmp = rear;
        rear = rear->prev;

        if (rear == NULL)
            front = NULL;

        else
            rear->next = NULL;

        free(tmp);

        size--;
    }

    cout << endl;
}

int Deque::GetFront()
{
    if (IsEmpty())
        return -1;

    else
        return front->data;
}

int Deque::GetRear()
{
    if (IsEmpty())
        return -1;

    else
        return rear->data;
}

void Deque::Erase()
{
    rear = NULL;
    node* tmp = front;

    while (tmp != NULL)
    {
        free(tmp);
        tmp = tmp->next;
    }

    size = 0;
}

void Deque::Display()
{
    node* tmp = front;

    cout << "Deque element: ";

    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

int main()
{
    deque dq;

    dq.insertFront(-1);
    dq.insertFront(-2);
    dq.insertFront(-3);

    dq.display();

    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertRear(3);

    dq.display();

    cout << "current front: " << dq.getFront()
         << " current rear: " << dq.getRear() << endl;

    dq.delFront();
    dq.delRear();

    dq.display();

    cout << "current front: " << dq.getFront()
         << " current rear: " << dq.getRear() << endl;

    return 0;
}
