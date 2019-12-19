#include <iostream>

using namespace std;

template <typename TYPE>
class DummyNodeList
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
    Node<TYPE> *position

public:
    DummyNodeList()
    {
        head = new Node<TYPE>;
        head->data = NULL;
        head->next = NULL;
    }

    bool FirstNode()
    {
        if (head->next)
            return true;

        return false;
    }

    void PrintList()
    {
        position = head->next;

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

        position = head->next;

        if (!FirstNode())
            head->next = NewNode;

        else if (NewNode->data <= position->data)
        {
            NewNode->next = position;
            head->next = NewNode;
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
        before = head;
        current = head->next;

        if (!FirstNode())
            cout << "There are no nodes to delete." << endl;

        else
        {
            while (current != NULL)
            {
                if (current->data == TargetData && current->next == NULL)
                {
                    before->next = NULL;
                    return;
                }

                else if (current->data == TargetData && current->next)
                {
                    before->next = current->next;
                    return;
                }

                before = current;
                current = current->next;
            }
        }
    }
};

int main()
{
    int array[10] = {1, 3, 2, 5, 6, 4, 9, 7, 8, 0};

    DummyNodeList<int> list;

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
