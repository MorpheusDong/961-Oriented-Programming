#include<iostream>
using namespace std;

typedef char ElemType;

//数据类型定义
typedef struct BinaryNode
{
	ElemType data;
	BinaryNode* lchild;
	BinaryNode* rchild;
}BiNode;

//基本方法
//二叉树建树（先序），用#表示空指针域
void createBiTree(BiNode*& bNode)
{
	ElemType c;
	cin >> c;
	if (c == '#')
		bNode = NULL;
	else
	{
		bNode = (BiNode*)malloc(sizeof(BiNode));
		bNode->data = c;
		createBiTree(bNode->lchild);
		createBiTree(bNode->rchild);
	}
}

void preOrder(BiNode* T)
{
	if (T == NULL)
		cout << "#";
	else
	{
		cout << T->data;
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

//链栈定义。注意data域是一个指向二叉树节点的指针。
typedef struct linkStack
{
	BiNode* pt;
	linkStack* next;
}liStack, LNode;

void initStack(liStack*& S)
{
	S = (liStack*)malloc(sizeof(liStack));
	S->next = NULL;
}

bool isStackEmpty(liStack* S)
{
	if (S->next == NULL)
		return true;
	else
		return false;
}

void push(liStack*& S, BiNode* bt)
{
	LNode* p = (LNode*)malloc(sizeof(LNode));
	p->pt = bt;
	p->next = S->next;
	S->next = p;
}

void pop(liStack*& S, BiNode*& bt)
{
	if (isStackEmpty(S))
		return;
	else
	{
		LNode* u = S->next;
		bt = u->pt;
		S->next = u->next;
		free(u);
	}
}

//链队的定义，给层次遍历使用
typedef struct linkQueue
{
	LNode* node;
	LNode* front;
	LNode* rear;
}liQueue;

void initQueue(liQueue* Q)    //队列初始化
{
	Q->node = (LNode*)malloc(sizeof(LNode));
	Q->node->next = NULL;
	Q->front = NULL;
	Q->rear = NULL;
}

void enQueue(liQueue* Q, BiNode* bNode)    //入队
{
	LNode* q = (LNode*)malloc(sizeof(LNode));
	q->pt = bNode;
	q->next = NULL;

	if (Q->rear == NULL)
	{
		Q->front = q;
		Q->rear = q;
	}
	else
	{
		Q->rear->next = q;
		Q->rear = q;
	}
}

void deQueue(liQueue* Q, BiNode*& bNode)    //出队
{
	if (Q->rear == NULL)
		return;

	if (Q->front == Q->rear)
	{
		LNode* u;
		u = Q->front;
		bNode = u->pt;
		Q->front = NULL;
		Q->rear = NULL;
	}
	else
	{
		LNode* u;
		u = Q->front;
		bNode = u->pt;
		Q->front = u->next;
	}
}

bool isQueueEmpty(liQueue* Q)    //队空
{
	if (Q->rear == NULL)
		return true;
	else
		return false;
}

//二叉树先序遍历的非递归写法
void preOrder2(BiNode* T)
{
	liStack* S;
	initStack(S);
	BiNode* p = T;    //遍历树的工作指针
	while (p || !isStackEmpty(S))
	{
		if (p)
		{
			cout << p->data;
			push(S, p);    //一边输出一边入栈
			p = p->lchild;    //p遍历到左下角
		}
		else    //遇到空节点，左子树遍历完成
		{
			pop(S, p);    //回到当前子树的父节点
			p = p->rchild;    //转向右子树
		}
	}
}

//二叉树中序遍历的非递归写法
//（只要把输出移到出栈后面）
void inOrder2(BiNode* T)
{
	liStack* S;
	initStack(S);
	BiNode* p = T;    //遍历树的工作指针
	while (p || !isStackEmpty(S))
	{
		if (p)
		{
			push(S, p);
			p = p->lchild;    //p遍历到左下角
		}
		else    //遇到空节点，左子树遍历完成
		{
			pop(S, p);
			cout << p->data;
			p = p->rchild;    //转向右子树
		}
	}
}

//层次遍历
//（正向，使用队列）
void levelOrder(BiNode* T)
{
	BiNode* p = T;
	liQueue* Q = (liQueue*)malloc(sizeof(liQueue));
	initQueue(Q);
	enQueue(Q, p);
	
	while (!isQueueEmpty(Q))
	{
		deQueue(Q, p);
		cout << p->data;
		if (p->lchild)
			enQueue(Q, p->lchild);
		if (p->rchild)
			enQueue(Q, p->rchild);
	}
}

//层次遍历
//（反向，从右下到左上，使用队列和栈）
void levelOrder2(BiNode* T)
{
	BiNode* p = T;
	liStack* S;
	initStack(S);
	liQueue* Q = (liQueue*)malloc(sizeof(liQueue));
	initQueue(Q);
	enQueue(Q, p);

	while (!isQueueEmpty(Q))
	{
		deQueue(Q, p);
		push(S, p);
		if (p->lchild)
			enQueue(Q, p->lchild);
		if (p->rchild)
			enQueue(Q, p->rchild);
	}

	while (!isStackEmpty(S))
	{
		pop(S, p);
		cout << p->data;
	}
}

//求二叉树的深度
int treeDepth(BiNode* T)
{
	BiNode* p = T;
	BiNode* last = T;
	liQueue* Q = (liQueue*)malloc(sizeof(liQueue));
	initQueue(Q);
	int levels = 0;
	enQueue(Q, p);

	while (!isQueueEmpty(Q))
	{
		deQueue(Q, p);
		if (p->lchild)
			enQueue(Q, p->lchild);
		if (p->rchild)
			enQueue(Q, p->rchild);

		if (p == last)    //走到层最右
		{
			++levels;
			if (Q->rear != NULL)
				last = Q->rear->pt;    //更新下一层的最右节点
		}
	}
	return levels;
}

//求二叉树的宽度
//（在上面略作修改）
int treeWidth(BiNode* T)
{
	BiNode* p = T;
	BiNode* last = T;
	liQueue* Q = (liQueue*)malloc(sizeof(liQueue));
	initQueue(Q);
	enQueue(Q, p);
	int levelNodes = 0;    //单层节点统计
	int maxWidth = 0;    //最大宽度

	while (!isQueueEmpty(Q))
	{
		deQueue(Q, p);
		++levelNodes;
		if (p->lchild)
			enQueue(Q, p->lchild);
		if (p->rchild)
			enQueue(Q, p->rchild);

		if (p == last)
		{
			if (levelNodes > maxWidth)
				maxWidth = levelNodes;    //更新最大宽度
			levelNodes = 0;    //重置单层节点统计

			if (Q->rear != NULL)
				last = Q->rear->pt;
		}
	}
	return maxWidth;
}

//统计二叉树的叶子节点(无分支)数量
static int leaves = 0;
void countLeaves(BiNode* T)
{
	if (T == NULL)
		return;
	else
	{
		if (T->lchild == NULL && T->rchild == NULL)
			++leaves;
		countLeaves(T->lchild);
		countLeaves(T->rchild);
	}
}

//判断一棵树是否是完全二叉树
//(完全二叉树应满足：层次遍历时遇到空节点，空节点后面不应该再有节点）
bool isComplete(BiNode* T)
{
	if (T == NULL)
		return true;    //空树是完全二叉树

	BiNode* p = T;
	liQueue* Q = (liQueue*)malloc(sizeof(liQueue));
	initQueue(Q);
	enQueue(Q, p);
	while (!isQueueEmpty(Q))
	{
		deQueue(Q, p);
		if (p)
		{
			enQueue(Q, p->lchild);
			enQueue(Q, p->rchild);
		}
		else   
			while (!isQueueEmpty(Q))
			{
				deQueue(Q, p);
				if (p)
					return false;
			}
	}
	return true;
}

//输出中缀表达式
void treeToExp(BiNode* T,int deep)    //deep控制括号
{
    if(T == NULL)
	    return;
	else if(T->lchild == NULL && T->rchild == NULL)
	{
	    cout<<T->data;
	}
	else
	{
	    if(deep>1)
		    cout<<"(";
		treeToExp(T->lchild,deep+1);
		cout<<T->data;
		treeToExp(T->rchild,deep+1);
		if(deep>1)
		    cout<<")";
	}
}

void BiTreeToExp(BiNode* T)
{
    treeToExp(T,1);
}

//建树测试
//012##3##45###
//0123##4##5#6##7##
//0123##4##5##6##
//*+a##b##-#c##

int main()
{
	BiNode* root = (BiNode*)malloc(sizeof(BiNode));
	createBiTree(root);
	//preOrder(root);
	preOrder2(root);
	cout << endl;
	levelOrder(root);
	cout << endl;
	levelOrder2(root);
}





