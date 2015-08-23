#include <iostream>
#include <unordered_map>
#include <cstdio>
#include <vector>
#include <ctype.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, const int target)
{
	unordered_map<int, int > m;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (m.find(numbers[i]) == m.end())
			m[target - numbers[i]] = i;
		else
		{
			result.push_back(m[numbers[i]] );
			result.push_back(i );
			break;
		}
	}
	return result;
}

int main()
{
	vector<int> numbers,result;
	int target;
	int count = 0;
	printf("�����������С:\n");
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &target);
		numbers.push_back(target);
	}

	printf("������Ŀ��ͣ�\n");
	scanf("%d", &target);
	result = twoSum(numbers, target);
	if (result.size() < 2)
		printf("�����ڣ�\n");
	printf("����������:\n");
	printf("%d + %d = %d\n", numbers[result[0]], numbers[result[1]], target);

	return 0;
}
