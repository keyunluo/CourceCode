#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define random(x) (rand()%x)

using namespace std;

typedef struct LNode 
{
	int data;
	struct LNode * next;
}LNode,*LinkList;

void CreateList(LinkList &L,int n)
{
	srand((int)time(0));
	L = new LNode();
	L->next= NULL;
	if (n < 1)
		return;
	LNode *p = L;
	for (int i = 0; i < n;i++)
	{
		LNode *node = new LNode;
		node->data = random(100);
		node->next = NULL;
		p->next = node;
		p = p->next;
	}
}

void DestroyList(LinkList&L)
{
	LNode *p = L->next;
	while (p)
	{
		L->next = p->next;
		delete p;
		p = L->next;
	}
	delete L;
}

void PrintList(LinkList L)
{
	LNode *p = L->next;
	while (p)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}

void CreateArray(int array[], int n)
{
	srand((int)time(0));
	for (int i = 0; i < n;i++)
	{
		array[i] = random(100);
	}
}

void PrintArray(int array[], int n)
{
	for (int i = 0; i < n;i++)
	{
		cout << array[i] << "  ";
		if ((i + 1) % 16 == 0)
			cout << endl;
	}
	cout << endl;
}

void ReverseArray(int array[],int begin,int end)
{
	int temp;
	while (begin<end)
	{
		temp = array[begin];
		array[begin] = array[end];
		array[end] = temp;
		begin++;
		end--;
	}
}

void ShiftArray(int array[],int n,int k)
{
	if (k>0&&k<n)
	{
		ReverseArray(array, 0, n - 1);
		ReverseArray(array, 0, n - k - 1);
		ReverseArray(array, n - k, n - 1);
	}
}

int main()
{
	LinkList L;
	int array[127] = { '\0' };
	int k,n;
	cout << "��ʼ����һ���������������Сn��";
	cin >> n;
	CreateList(L,n);
	PrintList(L);
	cout << "��ʼ����һ�����飬���������Сn��" << endl;
	cin >> n;
	CreateArray(array, n);
	PrintArray(array, n);
	cout << "ѭ������kλ��������k��ֵ:";
	cin >> k;
	ShiftArray(array,n, k);
	PrintArray(array,n);
	DestroyList(L);
	return 0;
}