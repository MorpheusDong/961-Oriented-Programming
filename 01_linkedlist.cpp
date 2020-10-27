#include <iostream>

using std::cin;
using std::cout;

typedef struct linkNode
{
	int data;
	linkNode* next;
}LNode;

//头插法建立链表
//【链表的头插法】
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

//尾插法建立链表
//【链表的尾插法】
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

//手动建立链表
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

//输出链表元素
void showList(LNode* C)
{
	LNode* p = C->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

//查找并删除值为x的节点
//【单链表遍历，删除节点】
int findAndDelete(LNode* C, int x)
{
	LNode* p = C;
	while (p)
	{
		if (p->next->data == x)
		{
			break;
		}
		else
		{
			p = p->next;
		}
	}

	if (p == NULL)
	{
		return 0;    //false
	}
	else
	{
		LNode* q;
		q = p->next;
		p->next = p->next->next;
		free(q);
		return 1;    //true
	}
}

//在第n个位置插入值为x的节点
//【单链表遍历，插入节点】
int insertX(LNode* C,int n,int x)
{
	LNode* p = C;
	for (int i = 0; i < n && p->next != NULL; ++i)    //找到插入的位置
	{
		p = p->next;
	}
	if (p)    //若n不大于表长，则正常插入；若n大于表长，则会在末尾插入
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 1;    //true
	}
	else
	{
		return 0;    //false
	}
}

//删除最小值节点
//【单链表遍历和删除节点，前继指针的使用】
void delMin(LNode* C)
{
	if (C->next == NULL)
		return;
	LNode* p = C->next;
	LNode* pre = C;
	LNode* min = C->next;
	LNode* minp = C;

	while (p)
	{
		if (p->data < min->data)
		{
			min = p;
			minp = pre;
		}
		pre = p;
		p = p->next;
	}

	minp->next = min->next;
	free(min);
}

int main()
{
	LNode* list;
	int a[5] = { 1,2,3,4,5 };
	createListR(list,a,5);
	showList(list);
}