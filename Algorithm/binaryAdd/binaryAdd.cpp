#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b) {
	int alen = a.size();
	int blen = b.size();
	bool carry = false;
	string result;
	while (alen > 0 || blen > 0) {
		int abit = alen <= 0 ? 0 : a[alen - 1] - '0';
		int bbit = blen <= 0 ? 0 : b[blen - 1] - '0';
		int cbit = carry ? 1 : 0;
		result.insert(result.begin(), '0' + ((abit + bbit + cbit) & 1));
		carry = (abit + bbit + cbit > 1);
		alen--; blen--;
	}
	if (carry) {
		result.insert(result.begin(), '1');
	}
	return result;
}


int main(int argc, char** argv)
{
	string a = "1101";
	string b = "1011";
	if (argc > 2) {
		a = argv[1];
		b = argv[2];
	}

	cout << a << "+" << b << "=" << addBinary(a, b) << endl;
	char temp;
	scanf("%c",&temp);
	return 0;

}