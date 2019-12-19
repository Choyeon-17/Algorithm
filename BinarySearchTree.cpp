#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* Lchild;
    Node* Rchild;
};

typedef Node* Tree;

class BinarySearchTree
{
public:
    Node* NewNode(int data);
    void InitTree(Tree* bst);
    int AddData(Tree* bst, int data);
    void Preorder(Node* sr);
    void Inorder(Node* sr);
    void Postorder(Node* sr);
    void Dispose(Node* sr);
    void ClearTree(Tree* bst);
};

int main()
{
    Tree tree;
    BinarySearchTree BST;

    BST.InitTree(&tree);

    BST.AddData(&tree, 20);
    BST.AddData(&tree, 10);
    BST.AddData(&tree, 30);

    cout << "Preorder: ";
    BST.Preorder(tree);

    cout << "\nInorder: ";
    BST.Inorder(tree);

    cout << "\nPostorder: ";
    BST.Postorder(tree);

    BST.ClearTree(&tree);
}

Node* BinarySearchTree::NewNode(int data)
{
    Node* now = new Node;

    now->data = data;
    now->Lchild = NULL;
    now->Rchild = NULL;

    return now;
}

void BinarySearchTree::InitTree(Tree* bst)
{
    *bst = NULL;
}

int BinarySearchTree::AddData(Tree* bst, int data)
{
    Node* seek = *bst;
    int gap = 0;

    if (seek == NULL)
    {
        *bst = NewNode(data);
        return 1;
    }

    while (1)
    {
        gap = seek->data - data;

        if (gap == 0)
            return 0;
        
        if (gap > 0)
        {
            if (seek->Lchild)
                seek = seek->Lchild;

            else
            {
                seek->Lchild = NewNode(data);
                return 1;
            }
        }
        
        else
        {
            if (seek->Rchild)
                seek = seek->Rchild;
            
            else
            {
                seek->Rchild = NewNode(data);
                return 1;
            }
        }
    }

    return 1;
}

void BinarySearchTree::Preorder(Node* sr)
{
    if (sr)
    {
        cout << sr->data << " ";
        Preorder(sr->Lchild);
        Preorder(sr->Rchild);
    }
}

void Inorder(Node* sr)
{
    if (sr)
    {
        Inorder(sr->Lchild);
        cout << sr->data << " ";
        Inorder(sr->Rchild);
    }
}

void Postorder(Node* sr)
{
    if (sr)
    {
        Postorder(sr->Lchild);
        Postorder(sr->Rchild);
        cout << sr->data << " ";
    }
}

void ClearTree(Tree* bst)
{
    Dispose(*bst);
    *bst = 0;
}

void Dispose(Node* sr)
{
    if (sr)
    {
        Dispose(sr->Lchild);
        Dispose(sr->Rchild);
        
        free(sr);
    }
}
