#include <iostream>

using namespace std;

template <typename TYPE> class Node
{
public:
 TYPE data;
 Node* next;
};

template <typename TYPE> class DummyNodeList
{
private:
 Node <TYPE>* head;
 Node <TYPE>* before;
 Node <TYPE>* current;
public:
 DummyNodeList()
 {
  head = new Node <TYPE>;
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
  current = head->next;

  while (current)
  {
   cout << current->data << " ";
   current = current->next;
  }

  cout << endl << endl;
 }

 void InsertNode(TYPE NewData)
 {
  Node <TYPE>* NewNode = new Node <TYPE>;
  NewNode->data = NewData;
  NewNode->next = NULL;

  before = head;
  current = head->next;

  if (!FirstNode())
   head->next = NewNode;

  else
  {
   if (NewData <= current->data)
   {
    NewNode->next = before->next;
    before->next = NewNode;
   }

   else
   {
    while (current->next && NewData > current->next->data)
    {
     before = current;
     current = current->next;
    }

    if (current->next)
    {
     NewNode->next = current->next;
     current->next = NewNode;
    }

    else
     current->next = NewNode;
   }
  }
 }

 void DeleteNode(TYPE TargetData)
 {
  before = head;
  current = head->next;

  if (!FirstNode())
   cout << "삭제할 노드가 없습니다." << endl;

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
 int array[10] = { 1, 3, 2, 5, 6, 4, 9, 7, 8, 0 };

 DummyNodeList<int> list;

 cout << "Insert" << endl;

 for (int i = 0; i < 10; i++)
 {
  list.InsertNode(array[i]);
  list.PrintList();
 }

 cout << endl << endl;

 cout << "Delete" << endl;

 for (int i = 0; i < 10; i++)
 {
  list.DeleteNode(array[i]);
  list.PrintList();
 }
}
