#include <iostream>
using namespace std;

//类型定义
typedef struct LinkNode
{
	int data;
	LinkNode* next;
}LNode,liStack;

//初始化
void initStack(liStack*& S)
{
	S = (LNode*)malloc(sizeof(LNode));
	S->next = NULL;
}

//判空
bool isEmpty(liStack* S)
{
	if (S->next == NULL)
		return true;
	else
		return false;
}

//入栈
void push(liStack* &S,int x)
{
	LNode* u = (LNode*)malloc(sizeof(LNode));
	u->data = x;
	u->next = S->next;    //头插
	S->next = u;
}

//出栈
void pop(liStack*& S, int& x)
{
	if (isEmpty(S))
		return;
	else
	{
		LNode* u = S->next;
		x = u->data;
		S->next = S->next->next;
		free(u);
	}
}

//显示
void showStack(liStack* S)
{
	if (isEmpty(S))
		cout << "The stack is empty now.";
	else
	{
		cout << "(top) ";
		LNode* p = S->next;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << " (bottom)";
	}
	cout << endl;
}

int main()
{
	liStack* T;
	initStack(T);
	showStack(T);
	push(T, 1);
	push(T, 2);
	showStack(T);
	int x = 0;
	pop(T, x);
	cout << "poped " << x << " from stack.\n";
	showStack(T);
	pop(T, x);
	cout << "poped " << x << " from stack.\n";
	showStack(T);
}
