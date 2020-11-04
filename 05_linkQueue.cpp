#include <iostream>
using namespace std;

typedef struct QueueNode
{
	int data;
	QueueNode* next;
}QNode;

typedef struct LinkQueue
{
	QNode* front;
	QNode* rear;
}liQueue;

void init(liQueue* Q)
{
	Q->front = NULL;
	Q->rear = NULL;
}

bool isEmpty(liQueue* Q)
{
	if (Q->front == NULL || Q->rear == NULL)
		return true;
	else
		return false;
}

void enQueue(liQueue*& Q, int x)
{
	QNode* p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;

	if (Q->front == NULL)
	{
		Q->front = p;
		Q->rear = p;
	}
	else
	{
		Q->rear->next = p;
		Q->rear = p;
	}
}

void deQueue(liQueue*& Q, int& x)
{
	if (isEmpty(Q))
		return;

	QNode* p = Q->front;
	x = p->data;
	if (Q->front == Q->rear)
	{
		Q->front = NULL;
		Q->rear = NULL;
	}
	else
	{
		Q->front = p->next;
	}
	free(p);
}

void showQueue(liQueue* Q)
{
	if (isEmpty(Q))
		cout << "The queue is empty now.";
	else
	{
		QNode* p = Q->front;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
	cout << endl;
}

int main()
{
	liQueue* Q = (liQueue*)malloc(sizeof(liQueue));
	init(Q);
	showQueue(Q);    //empty
	enQueue(Q, 1);
	enQueue(Q, 2);
	showQueue(Q);    //1,2
	int x = 0;
	deQueue(Q, x);
	showQueue(Q);
	deQueue(Q, x);
	showQueue(Q);    //empty
	deQueue(Q,x);    //do nothing
}

