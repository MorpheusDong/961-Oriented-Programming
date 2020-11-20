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

//查找某个值所在的层次
int keyLevel(BiNode* T, BiNode* p)
{
	int n = 0;
	if (T)
	{
		++n;    //开始计数
		while (T->data != p->data)    
		{
			if (T->data > p->data)
				T = T->lchild;
			else
				T = T->rchild;
			++n;
		}
	}
	return n;
}

//输出不小于k的节点
//（从右下角中序遍历，依次比较）
void aboveK(BiNode* T, int k)
{
	if (T == NULL)
		return;
	if (T->rchild)
		aboveK(T->rchild, k);
	if (T->data >= k)
		cout << T->data;
	if (T->lchild)
		aboveK(T->lchild, k);
}

//输出第k小的节点
//（从左下角中序遍历，逐个计数）
void minK(BiNode* T, int k)
{
	static int count = 0;
	if (T == NULL)
		return;
	if (T->lchild)
		minK(T->lchild, k);
	if (++count == k)
	{
		cout << T->data;
		exit(1);
	}
	if (T->rchild)
		minK(T->rchild, k);
}

//判断一棵二叉树是否平衡
void checkAVL(BiNode* T, int& balance, int& height)
{
	int bl = 0, br = 0, hl = 0, hr = 0;
	if (T == NULL)
	{
		height = 0;    //空树高度为0，平衡
		balance = 1;
	}
	else if (T->lchild == NULL && T->rchild == NULL)
	{
		height = 1;    //只有一个节点/叶节点，高度为1，平衡
		balance = 1;
	}
	else
	{
		checkAVL(T->lchild, bl, hl);    //返回左子树的平衡情况和高度
		checkAVL(T->rchild, br, hr);    //返回右子树的平衡情况和高度
		height = (hl > hr ? hl : hr) + 1;    //计算当前节点的高度
		if (abs(hl - hr) < 2)    //检查此节点是否平衡
			balance = bl && br;    //检查子树节点是否也平衡
		else
			balance = 0;
	}
}

bool isBalance(BiNode* T)
{
	int b, h;
	checkAVL(T, b, h);
	if (b == 1)
		return true;
	else
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