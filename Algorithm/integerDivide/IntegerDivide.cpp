/*
�����������⣺
��������n��ʾ��һϵ�е�������֮�ͣ�n=n1+n2+������������+nk;����n1>=n2>=n3>=������������>=nk>=1;
���磬������6������11�ֲ�ͬ�Ļ��֣�
6
5+1 
4+2 4+1+1
3+3 3+2+1 3+1+1+1
2+2+2 2+2+1+1 2+1+1+1+1 
1+1+1+1+1+1

��������n�����в�ͬ�Ļ����У���������n1������m�Ļ��ָ�����Ϊq(n,m),��
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
	cout << "��������n:" << endl;
	cin >>n ;
	cout << "��������" << divide(n, n) << endl;
	return 0;
}