#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *prev;
    Node *next;
};

Node *head;

class DoublyLinkedList
{
private:
public:
    DoublyLinkedList()
    {
        head = new Node;
        head->prev = NULL;
        head->next = NULL;
    }

    Node *InsertNodeRight(Node *Target, Node *aNode)
    {
        Node *New;
        Node *Right;
        New = new Node;

        *New = *aNode;
        Right = Target->next;
        New->next = Right;
        New->prev = Target;
        Target->next = New;

        if (Right)
            Right->prev = New;

        return New;
    }

    Node *InsertNodeLeft(Node *Target, Node *aNode)
    {
        Node *Left;

        Left = Target->prev;

        if (Left)
            return InsertNodeRight(Left, aNode);

        return NULL;
    }

    void AppendNode(Node *aNode)
    {
        Node *tail;

        for (tail = head; tail->next; tail = tail->next)
        {
            ;
        }

        InsertNodeRight(tail, aNode);
    }

    bool DeleteNode(Node *Target)
    {
        Node *Left, *Right;

        if (Target == NULL || Target == head)
            return false;

        Left = Target->prev;
        Right = Target->next;
        Left->next = Right;

        if (Right)
            Right->prev = Left;

        delete Target;

        return true;
    }

    Node *FindNodeByIndex(int idx)
    {
        Node *Now;
        int Index = 0;

        for (Now = head->next; Now; Now = Now->next)
        {
            if (Index == idx)
                return Now;

            Index++;
        }

        return NULL;
    }

    int GetNodeIndex(Node *Target)
    {
        Node *Now;
        int Index = 0;

        for (Now = head->next; Now; Now = Now->next)
        {
            if (Now == Target)
                return Index;

            Index++;
        }

        return -1;
    }

    int GetListCount()
    {
        Node *Now;
        int Count = 0;

        for (Now = head->next; Now; Now = Now->next)
            Count++;

        return Count;
    }

    void UnInitList()
    {
        while (DeleteNode(head->next))
        {
            ;
        }

        delete head;

        head = NULL;
    }
};

int main()
{
    Node *Now, Temp;
    DoublyLinkedList DLL;

    for (int i = 1; i <= 5; i++)
    {
        Temp.value = i;
        DLL.AppendNode(&Temp);
    }

    for (Now = head->next; Now; Now = Now->next)
        cout << Now->value << "    ";

    cout << endl;

    cout << "노드 개수 = " << DLL.GetListCount() << endl;

    for (Now = head->next; Now; Now = Now->next)
        if (Now->value == 3)
            break;

    if (Now)
        cout << "Mid = " << Now->value << ", Forward = " << Now->prev->value << ", Backward = " << Now->next->value << endl;

    cout << "3번 노드 = " << DLL.FindNodeByIndex(3)->value << endl;

    DLL.UnInitList();
}