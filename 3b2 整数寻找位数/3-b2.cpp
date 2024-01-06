/*2151133 孙韩雅 信07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入一个[1..30000]间的整数:" << endl;

	int i;
	cin >> i;

	int a = i / 10000;
	int b = (i - 10000 * a) / 1000;
	int c = (i - 10000 * a - 1000 * b) / 100;
	int d = (i - 10000 * a - 1000 * b - 100 * c) / 10;
	int e = (i - 10000 * a - 1000 * b - 100 * c - 10 * d);

	cout << "万位 : " << a << endl;
	cout << "千位 : " << b << endl;
	cout << "百位 : " << c << endl;
	cout << "十位 : " << d << endl;
	cout << "个位 : " << e << endl;

	return 0;
}