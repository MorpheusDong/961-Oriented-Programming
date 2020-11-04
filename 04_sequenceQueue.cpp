#include <iostream>
using namespace std;
#define MAXSIZE    5

typedef struct SequenceQueue
{
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void init(SqQueue& sq)
{
	sq.front = 0;
	sq.rear = 0;
}

bool isEmpty(SqQueue sq)
{
	if (sq.front == sq.rear)
		return true;
	else
		return false;
}

bool isFull(SqQueue sq)
{
	if ((sq.rear + 1) % MAXSIZE == sq.front)
		return true;
	else
		return false;
}

void enQueue(SqQueue& sq, int x)
{
	if (isFull(sq))
		return;
	else
	{
		sq.data[sq.rear] = x;
		sq.rear = (sq.rear + 1) % MAXSIZE;
	}
}

void deQueue(SqQueue& sq, int& x)
{
	if (isEmpty(sq))
		return;
	else
	{
		x = sq.data[sq.front];
		sq.front = (sq.front + 1) % MAXSIZE;
	}
}

void showQueue(SqQueue sq)
{
	for (int i = sq.front; i != sq.rear; i = (i + 1) % MAXSIZE)
	{
		cout << sq.data[i] << " ";
	}
	cout << endl;
}

int main()
{
	SqQueue Q;
	init(Q);
	enQueue(Q, 1);
	enQueue(Q, 2);
	showQueue(Q);
	enQueue(Q, 3);
	enQueue(Q, 4);
	enQueue(Q, 5);    //不显示
	showQueue(Q);
	int x = 0;
	deQueue(Q, x);
	deQueue(Q, x);
	showQueue(Q);
}