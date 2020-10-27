#include <iostream>
#define maxsize   10
using namespace std;

//数据类型定义
typedef struct SequenceStack
{
	int data[maxsize];
	int top;
}stack;

//初始化
void initStack(stack& S)
{
	S.top = -1;
}

//判空
bool isEmpty(stack S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}

//入栈
void push(stack& S,int x)
{
	if (S.top < maxsize)
	{
		S.data[++S.top] = x;
	}
}

//出栈
void pop(stack& S, int& x)
{
	if (isEmpty(S))
		cout << "The stack is empty now.\n";
	else
	{
		x = S.data[S.top--];
	}
}

//展示
void showStack(stack S)
{
	if (isEmpty(S))
		cout << "The stack is empty now.";
	else
	{
		cout << "(bottom) ";
		for (int i = 0; i <= S.top; ++i)
			cout << S.data[i] << " ";
		cout << "(top) ";
	}
	cout << endl;
}

int main()
{
	stack T;
	initStack(T);
	showStack(T);
	push(T, 1);
	push(T, 2);
	showStack(T);
	int x = 0;
	pop(T, x);
	cout << "poped " << x << " from the stack.\n";
	showStack(T);
	pop(T, x);
	cout << "poped " << x << " from the stack.\n";
	showStack(T);
}
