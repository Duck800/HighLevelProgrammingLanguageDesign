/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

void min(int b = 65536, int c = 65536, int d = 65536, int e = 65536)
{
	cout << "min=" << (((b < c ? b : c) < d ? (b < c ? b : c) : d) < e ? ((b < c ? b : c) < d ? (b < c ? b : c) : d) : e);
}

int main()
{
	while (1) {
		int num, a, b, c, d;
		cout << "���������num��num����������" << endl;
		cin >> num;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (num < 2 || num > 4) {
			cout << "�����������";
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else if (num == 2) {
			cin >> a >> b;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else {
				min(a, b);
				break;
			}
		}
		else if (num == 3) {
			cin >> a >> b >> c;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else {
				min(a, b, c);
				break;
			}
		}
		else if (num == 4) {
			cin >> a >> b >> c >> d;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			else {
				min(a, b, c, d);
				break;
			}
		}
	}
	cout << endl;
}