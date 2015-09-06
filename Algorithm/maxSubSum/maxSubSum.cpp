/**
最大连续子序列
*/

#include <iostream>
#include <string>

using namespace std;

int maxSum(int *array, int n, int &start, int &end)
{
	int *sum = new int[n];
	int temp = 0,maxsum=array[0];
	start = 0;
	end = 0;
	sum[0] = array[0];
	for (int i =1; i < n;i++)
	{
		if (sum[i - 1] <= 0)
		{
			temp = i;
			sum[i] = array[i];
		}
		else
			sum[i] = sum[i - 1] + array[i];
		if (sum[i] > maxsum)
		{
			maxsum = sum[i];
			start = temp;
			end = i;
		}
	}
	delete [] sum;
	return maxsum;
}

int main()
{
	int n, i;
	cout << "请输入数组大小：" ;
	cin >> n;
	cout << "请输入数组元素：" << endl;
	int *array = new int[n];
	for (i = 0; i < n;i++)
	{
		cin >> array[i];
	}

	int start=0, end = 0;
	cout << "最大连续子数组和为：" << maxSum(array, n, start, end) << endl;
	cout << "数组为：" << endl;
	for (i = start; i <= end;i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
	delete[] array;
	return 0;
}