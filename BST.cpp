#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *Lchild;
    struct Node *Rchild;
} node;

typedef node *Tree;

node *NewNode(int data);
void InitTree(Tree *bst);
int AddData(Tree *bst, int data);
void Preorder(node *sr);
void Inorder(node *sr);
void Postorder(node *sr);
void Dispose(node *sr);
void ClearTree(Tree *bst);

int main()
{
    Tree tree;

    InitTree(&tree);

    AddData(&tree, 20);
    AddData(&tree, 10);
    AddData(&tree, 30);

    printf("전위 순회: ");
    Preorder(tree);
    printf("\n중위 순회: ");
    Inorder(tree);
    printf("\n후위 순회: ");
    Postorder(tree);

    ClearTree(&tree);
}

node *NewNode(int data)
{
    node *now = (node *)malloc(sizeof(node));
    now->data = data;
    now->Lchild = NULL;
    now->Rchild = NULL;
    return now;
}

void InitTree(Tree *bst)
{
    *bst = NULL;
}

int AddData(Tree *bst, int data)
{
    node *seek = *bst;
    int gap = 0;
    if (seek == NULL)
    {
        *bst = NewNode(data);
        return 1;
    }
    while (1)
    {
        gap = seek->data - data;
        if (gap == 0) // 트리에 존재하는 데이터와 똑같은 데이터를 삽입 시도하는 경우
            return 0;
        if (gap > 0) // 트리의 데이터보다 작을 경우, 즉 Lchild로 가는 경우
        {
            if (seek->Lchild)        // 데이터를 삽입 시도하는 위치에 데이터가 이미 존재할 경우
                seek = seek->Lchild; // 그 위치로 이동해서 다시 while문을 돌 때 그 위치의 데이터와 비교한다.
            else                     // 데이터를 삽입 시도하는 위치에 데이터가 존재하지 않을 경우
            {
                seek->Lchild = NewNode(data); // 그 위치에 데이터를 삽입한다.
                return 1;
            }
        }
        else // 트리의 데이터보다 클 경우, 즉 Rchild로 가는 경우
        {
            if (seek->Rchild)        // 데이터를 삽입 시도하는 위치에 데이터가 이미 존재할 경우
                seek = seek->Rchild; // 그 위치로 이동해서 다시 while문을 돌 때 그 위치의 데이터와 비교한다.
            else                     // 데이터를 삽입 시도하는 위치에 데이터가 존재하지 않을 경우
            {
                seek->Rchild = NewNode(data); // 그 위치에 데이터를 삽입한다.
                return 1;
            }
        }
    }
    return 1;
}

void Preorder(node *sr)
{
    if (sr)
    {
        printf("%d ", sr->data);
        Preorder(sr->Lchild);
        Preorder(sr->Rchild);
    }
}

void Inorder(node *sr)
{
    if (sr)
    {
        Inorder(sr->Lchild);
        printf("%d ", sr->data);
        Inorder(sr->Rchild);
    }
}

void Postorder(node *sr)
{
    if (sr)
    {
        Postorder(sr->Lchild);
        Postorder(sr->Rchild);
        printf("%d ", sr->data);
    }
}

void ClearTree(Tree *bst)
{
    Dispose(*bst);
    *bst = 0;
}

void Dispose(node *sr) // 후위 순회로 해제
{
    if (sr)
    {
        Dispose(sr->Lchild);
        Dispose(sr->Rchild);
        free(sr);
    }
}