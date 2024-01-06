/*2151133 孙韩雅 信07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入一个[0..99999]之间的整数" << endl;
	int i, a, b, c, d, e;
	cin >> i;
	a = (int)i / 10000;
	b = (int)(i - a * 10000) / 1000;
	c = (int)(i - a * 10000 - b * 1000) / 100;
	d = (int)(i - a * 10000 - b * 1000 - c * 100) / 10;
	e = (int)(i - a * 10000 - b * 1000 - c * 100 - d * 10);
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				if (d == 0) {
					cout << "1位数" << endl;
				}
				else
					cout << "2位数" << endl;
			}
			else
				cout << "3位数" << endl;
		}
		else
			cout << "4位数" << endl;
	}
	else
		cout << "5位数" << endl;
	cout << "每位数字分别是 : " << endl;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				if (d == 0) {
					cout << e << endl;
				}
				else
					cout << d << " " << e << endl;
			}
			else
				cout << c << " " << d << " " << e << endl;
		}
		else
			cout << b << " " << c << " " << d << " " << e << endl;
	}
	else
		cout << a << " " << b << " " << c << " " << d << " " << e << endl;
	cout << "逆序输出的每位数字分别是 : " << endl;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				if (d == 0) {
					cout << e << endl;
				}
				else
					cout << e << " " << d << endl;
			}
			else
				cout << e << " " << d << " " << c << endl;
		}
		else
			cout << e << " " << d << " " << c << " " << b << endl;
	}
	else
		cout << e << " " << d << " " << c << " " << b << " " << a << endl;

	return 0;
}