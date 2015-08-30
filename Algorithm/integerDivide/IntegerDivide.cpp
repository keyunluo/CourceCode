/*
整数划分问题：
将正整数n表示成一系列的正整数之和：n=n1+n2+······+nk;其中n1>=n2>=n3>=······>=nk>=1;
例如，正整数6有如下11种不同的划分：
6
5+1 
4+2 4+1+1
3+3 3+2+1 3+1+1+1
2+2+2 2+2+1+1 2+1+1+1+1 
1+1+1+1+1+1

在正整数n的所有不同的划分中，将最大加数n1不大于m的划分个数记为q(n,m),则
								  |     1				n=1,m=1            
								  |		q(n,n)		m>n
					q(n,m)= |		1+q(n,n-1)    m=n
								  |      q(n,m-1)+q(n-m,m)    m<n
*/

#include <iostream>
#include <cstdio>
using namespace std;

int divide(int n, int m)
{
	if (n < 1 || m < 1)
		return 0;
	if (n == 1 || m == 1)
		return 1;
	if (n < m)
		return divide(n, n);
	if (n == m)
		return divide(n, n - 1) + 1;
	if (n > m)
		return divide(n, m - 1) + divide(n - m, m);
}

int main()
{
	int n;
	cout << "请输入数n:" << endl;
	cin >>n ;
	cout << "划分数有" << divide(n, n) << endl;
	return 0;
}