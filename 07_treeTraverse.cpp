#include <iostream>
using namespace std;

typedef struct BinaryNode
{
	int data;
	BinaryNode* lchild;
	BinaryNode* rchild;
}BiNode;

void createTree(BiNode*& T)
{
	int c;
    cin>>c;
	if(c == '#')
		T = NULL;
	else
	{
		T = (BiNode*)malloc(sizeof(BiNode));
		T->data = c;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}

void preOrder(BiNode* T)
{
	if(T == NULL)
		cout<<"#";
	else
	{
		cout<<T->data;
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(BiNode* T)
{
	if(T == NULL)
		cout<<"#";
	else
	{
		inOrder(T->lchild);
		cout<<T->data;
		inOrder(T->rchild);
	}
}

void postOrder(BiNode* T)
{
	if(T == NULL)
		cout<<"#";
	else
	{
		postOrder(T->lchild);
		postOrder(T->rchild);
		cout<<T->data;
	}
}

