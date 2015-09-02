/*
* @Author: �����
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
		//����ۼӺ�,��1��ʼ������������
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &temp);
			sum[i] = sum[i - 1] + temp;
		}

		//��ʼ��dp��
		memset(dpmax, 0, sizeof(dpmax));
		memset(dpmin, 0, sizeof(dpmin));

		//���䳤��ö��len,��������
		for (len = 2; len <= n; len++)
		{
			//��ʼλ��i
			for (i = 1; i <= n - len + 1; i++)
			{
				//��ֹλ��j
				j = i + len - 1;
				//�̶����ۻ���
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
