/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

void max(int a, int b) 
{
	cout << "max=" << (a > b ? a : b) << endl;
}

void max(int a, int b, int c)
{
	cout << "max=" << ((a > b ? a : b) > c ? (a > b ? a : b) : c);
}

void max(int b, int c, int d, int e)
{
	cout << "max=" << (((b > c ? b : c) > d ? (b > c ? b : c) : d) > e ? ((b > c ? b : c) > d ? (b > c ? b : c) : d) : e);
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
			cout<<"�����������";
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
				max(a, b);
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
				max(a, b, c);
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
				max(a, b, c, d);
				break;
			}
		}
	}
	cout << endl;
}