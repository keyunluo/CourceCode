#include "dataStructure.h"
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
#define random(x) (rand()%x)

void InseretionSort(SqList &L)
{
	int i, j;
	for (i = 2; i <= L.length; i++)
	{
		if (L.r[i].key < L.r[i - 1].key)
		{
			L.r[0] = L.r[i];
			for (j = i - 1; L.r[0].key < L.r[j].key; --j)
				L.r[j + 1] = L.r[j];
			L.r[j + 1] = L.r[0];
		}
	}
}

void BiInsertionSort(SqList &L)
{
	int i, j, low, high, m;
	for (i = 2; i <= L.length; i++)
	{
		L.r[0] = L.r[i];
		low = 1;
		high = i - 1;
		while (low <= high)
		{
			m = (low + high) / 2;
			if (L.r[0].key < L.r[m].key)
				high = m - 1;
			else
				low = m + 1;
		}

		for (j = i - 1; j >= low; j--)
			L.r[j + 1] = L.r[j];
	}
}

/*
***øÏÀŸ≈≈–Ú
*/
template<class T>
void swapData(T &x, T &y)
{
	T temp=x;
	x = y;
	y = temp;
}

int partition(SqList &L, int low, int hight)
{
	RecType temp;
	int pivotKey = L.r[low].key;
	while (low < hight)
	{
		while (low < hight&&L.r[hight].key >= pivotKey) hight--;
		swapData<RecType>(L.r[low], L.r[hight]);
		while (low < hight&&L.r[low].key <= pivotKey) low++;
		swapData<RecType>(L.r[low], L.r[hight]);
	}
	return low;
}

int partitional(SqList& L, int low, int hight)
{
	L.r[0] = L.r[low];
	int pivotKey = L.r[low].key;
	while (low<hight)
	{
		while (low < hight&&L.r[hight].key >= pivotKey) --hight;
		L.r[low] = L.r[hight];
		while (low < hight&&L.r[low].key <= pivotKey) ++low;
		L.r[hight] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void QSort(SqList& L, int low, int hight)
{
	if (low < hight)
	{
		int pivotKey = partitional(L, low, hight);
		QSort(L, low, pivotKey - 1);
		QSort(L, pivotKey + 1, hight);
	}
}

void QuickSort(SqList&L)
{
	QSort(L, 1, L.length);
}

int main()
{
	SqList L;
	L.length = 0;
	srand((int)time(0));
	for (int i = 1; i <= 16; i++)
	{
		L.r[i].key = random(1000);
		L.length++;
		cout << L.r[i].key<<"\t";
	}
	cout << endl;
	QuickSort(L);
	for (int i = 1; i <=L.length; i++)
	{
		cout << L.r[i].key << "\t";
	}
	cout << endl;
	return 0;
}