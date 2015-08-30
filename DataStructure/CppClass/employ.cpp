/***
运算符重载综合实例：
设计一个工资管理类，它能根据职工的姓名录入和查询职工的工资，每个职工的基本数据有职工姓名和工资。
**/

#include <iostream>
#include <string>
using namespace std;

struct Person						//职工基本数据结构
{
	double salary;
	string name;
};

class SalaryManage
{
	Person *employ;				//存放职工信息的数组
	int max;								//数组下标上界
	int n;									//数组中的实际职工数
public:
	SalaryManage(int Max = 0)
	{
		max = Max;
		n = 0;
		employ = new Person[max];
	}

	double &operator[](string Name)
	{
		Person * person;
		for (person = employ; person < employ + n; person++)
			if (person->name == Name)
				return person->salary;

		person = employ + n++;
		person->name = Name;
		person->salary = 0;
		return person->salary;
	}

	void display()
	{
		for (int i = 0; i < n; i++)
			cout << employ[i].name << "\t" << employ[i].salary << endl;
	}
};

int main()
{
	SalaryManage s(3);
	s["张三"] = 2345.6;
	s["李四"] = 2345.3;
	s["王五"] = 2312;
	cout << s["张三"] << endl;
	cout << s["李四"] << endl;
	cout << s["王五"] << endl;
	return 0;
}