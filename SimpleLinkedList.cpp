#include <iostream>

using namespace std;

template <typename TYPE>
class SimpleLinkedList
{
private:
    template <typename TYPE>
    class Node
    {
    public:
        TYPE data;
        Node *next;
    };
    Node<TYPE> *head;
    Node<TYPE> *position;

public:
    SimpleLinkedList()
    {
        head = NULL;
    }

    bool FirstNode()
    {
        if (head)
            return true;

        return false;
    }

    void PrintList()
    {
        position = head;

        while (position)
        {
            cout << position->data << " ";
            position = position->next;
        }

        cout << endl
             << endl;
    }

    void InsertNode(TYPE NewData)
    {
        Node<TYPE> *NewNode = new Node<TYPE>;
        NewNode->data = NewData;
        NewNode->next = NULL;

        position = head;

        if (!FirstNode())
            head = NewNode;

        else if (NewNode->data <= head->data)
        {
            NewNode->next = head;
            head = NewNode;
        }

        else
        {
            while (position->next && NewData > position->next->data)
                position = position->next;

            if (position->next)
            {
                NewNode->next = position->next;
                position->next = NewNode;
            }

            else
                position->next = NewNode;
        }
    }

    void DeleteNode(TYPE TargetData)
    {
        position = head;
        Node<TYPE> *rPos;

        if (!FirstNode())
            cout << "There are no nodes to delete." << endl;

        else if (TargetData == head->data)
        {
            head = head->next;
            delete position;
        }

        else
        {
            while (position->next && position->next->data != TargetData)
                position = position->next;

            if (position->next->data == TargetData)
            {
                rPos = position->next;
                position->next = rPos->next;
                delete rPos;
                return;
            }
        }
    }
};

int main()
{
    int array[10] = {1, 3, 2, 5, 6, 4, 9, 7, 8, 0};

    SimpleLinkedList<int> list;

    cout << "Insert" << endl;

    for (int i = 0; i < 10; i++)
    {
        list.InsertNode(array[i]);
        list.PrintList();
    }

    cout << endl
         << endl;

    cout << "Delete" << endl;

    for (int i = 0; i < 10; i++)
    {
        list.DeleteNode(array[i]);
        list.PrintList();
    }
}
