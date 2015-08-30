/***
����������ۺ�ʵ����
���һ�����ʹ����࣬���ܸ���ְ��������¼��Ͳ�ѯְ���Ĺ��ʣ�ÿ��ְ���Ļ���������ְ�������͹��ʡ�
**/

#include <iostream>
#include <string>
using namespace std;

struct Person						//ְ���������ݽṹ
{
	double salary;
	string name;
};

class SalaryManage
{
	Person *employ;				//���ְ����Ϣ������
	int max;								//�����±��Ͻ�
	int n;									//�����е�ʵ��ְ����
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
	s["����"] = 2345.6;
	s["����"] = 2345.3;
	s["����"] = 2312;
	cout << s["����"] << endl;
	cout << s["����"] << endl;
	cout << s["����"] << endl;
	return 0;
}