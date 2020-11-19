#include<iostream>
using namespace std;

#define ElemType    int 
#define charToNum(x)    ((int)x-48)

typedef struct BiNode
{
	ElemType data;
	BiNode* lchild;
	BiNode* rchild;
}BiNode;

void createTree(BiNode* &T)
{
	char c;
	cin >> c;
	if (c == '#')
		T = NULL;
	else
	{
		T = (BiNode*)malloc(sizeof(BiNode));
		T->data = charToNum(c);
		createTree(T->lchild);
		createTree(T->rchild);
	}
}

void preOrder(BiNode* T)
{
	if (T == NULL)
		return;
	else
	{
		cout << T->data;
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(BiNode* T)
{
	if (T == NULL)
		return;
	else
	{
		inOrder(T->lchild);
		cout << T->data;
		inOrder(T->rchild);
	}
}

//排序二叉树的插入（递归）
void insertBST(BiNode* &T, int key)
{
	if (T == NULL)
	{
		T = (BiNode*)malloc(sizeof(BiNode));
		T->data = key;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else if (T->data > key)
		insertBST(T->lchild, key);
	else if (T->data < key)
		insertBST(T->rchild, key);
	else
		return;
}

//排序二叉树的查找（非递归）
bool searchBST(BiNode* T, int key)
{
	while (T != NULL)
	{
		if (T->data > key)
			T = T->lchild;
		else if (T->data < key)
			T = T->rchild;
		else
			return true;
	}
	if (T == NULL)
		return false;
}


//建树测试
//012##3##45###
//0123##4##5#6##7##
//0123##4##5##6##
//*+a##b##-#c##

int main()
{
	BiNode* root = (BiNode*)malloc(sizeof(BiNode));
	root = NULL;
	//createTree(root);

	int x;
	cin >> x;
	while (x != 99)
	{
		insertBST(root, x);
		cin >> x;
	}

	inOrder(root);
	cout << endl;
	cin >> x;
	while (x != 99)
	{
		if (searchBST(root, x))
			cout << x << " found.\n";
		else
			cout << x << " not found.\n";
		cin >> x;
	}

}