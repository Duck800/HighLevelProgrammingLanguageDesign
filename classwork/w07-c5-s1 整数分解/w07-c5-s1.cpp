/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "������һ��[0..99999]֮�������" << endl;
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
					cout << "1λ��" << endl;
				}
				else
					cout << "2λ��" << endl;
			}
			else
				cout << "3λ��" << endl;
		}
		else
			cout << "4λ��" << endl;
	}
	else
		cout << "5λ��" << endl;
	cout << "ÿλ���ֱַ��� : " << endl;
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
	cout << "���������ÿλ���ֱַ��� : " << endl;
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