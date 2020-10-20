
#include <iostream>
using namespace std;

using std::cin;
using std::cout;

typedef struct linkNode
{
	int data;
	linkNode* next;
}LNode;


void createListF(LNode*& C, int A[], int n)
{
	C = (LNode*)malloc(sizeof(LNode));
	C->next = NULL;

	for (int i = 0; i < n; ++i)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = A[i];
		s->next = C->next;
		C->next = s;
	}
}

void createListR(LNode*& C, int A[], int n)
{
	C = (LNode*)malloc(sizeof(LNode));
	C->next = NULL;
	LNode* r = C;

	for (int i = 0; i < n; ++i)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = A[i];
		r->next = s;
		r = r->next;
	}

	r->next = NULL;
}

void createListManual(LNode*& C)
{
	int n = 0;
	C = (LNode*)malloc(sizeof(LNode));
	C->data = 0;
	C->next = NULL;
	LNode* r = C;
	cout << "Enter the elements to create a linked list.\n";
	cout << "enter '-1' to finish:\n";
	cin >> n;

	while (n != -1)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = n;
		r->next = s;
		r = r->next;
		++(C->data);
		cin >> n;
	}
	r->next = NULL;
}

//带哨兵节点的链表就是有头节点的链表
//哨兵通常不存储数值，作用是简化（统一）操作。比如插入或删除某节点时不用考虑是否是表头的特殊情况。


void showList(LNode* C)
{
	LNode* p = C->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	LNode* list;
	int a[5] = { 1,2,3,4,5 };
	createListR(list,a,5);
	showList(list);


}