/*
* @Author: 骆克云
* @Date:   2015-09-02 14:45:14
* @Last Modified by:   anchen
* @Last Modified time: 2015-09-02 15:27:56
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <memory.h>

using namespace std;
const int INF = 999999999;
const int N = 200;
int dpmax[N][N], dpmin[N][N], sum[N];

int main()
{
	int n, i, j, k, len, temp;
	sum[0] = 0;
	while (~scanf("%d", &n))
	{
		//获得累加和,从1开始，方便后面计算
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &temp);
			sum[i] = sum[i - 1] + temp;
		}

		//初始化dp表
		memset(dpmax, 0, sizeof(dpmax));
		memset(dpmin, 0, sizeof(dpmin));

		//区间长度枚举len,包括自身
		for (len = 2; len <= n; len++)
		{
			//起始位置i
			for (i = 1; i <= n - len + 1; i++)
			{
				//终止位置j
				j = i + len - 1;
				//固定的累积和
				temp = sum[j] - sum[i - 1];

				dpmax[i][j] = -INF;
				dpmin[i][j] = INF;

				for (k = i; k < j; k++)
				{
					dpmin[i][j] = std::min(dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j] + temp);
					dpmax[i][j] = std::max(dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j] + temp);
				}
			}
		}
		printf("dpmin:%d\n", dpmin[1][n]);
		printf("dpmax:%d\n", dpmax[1][n]);
	}
	system("pause");

	return 0;
}
