/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int y, m, leap, w, d, i;
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> y >> m;
		if (cin.fail()) {
			cin.clear();
			while (getchar() != '\n')
				continue;
		}
		else if (y < 2000 || y>2030 || m < 1 || m>12) {
			cout << "����Ƿ�������������" << endl;
			cin.clear();
			continue;
		}
		else
			break;
	}
	while (1) {
		cout << "������" << y << "��" << m << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> w;
		if (cin.fail()) {
			cin.clear();
			while (getchar() != '\n')
				continue;
		}
		else if (w > 6 || w < 0) {
			cout << "����Ƿ�������������" << endl;
			cin.clear();
			while (getchar() != '\n')
				continue;
		}
		else 
			break;
	}
	cout << endl << y << "��" << m << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������  " << endl;
	i = 8 * w + 4;
	cout << setw(i) << "1";
	if (leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
		if (m == 2) {
			for (d = 2; d < 30; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0)
					cout << endl;
			}
		}
		else if (m < 8) {
			switch (m % 2) {
			case 0:
				for (d = 2; d < 31; d++) {
					if ((d + w - 1) % 7 == 0)
						cout << setw(4) << d;
					else
						cout << setw(8) << d;
					if ((d + w) % 7 == 0)
						cout << endl;
				}
				break;
			case 1:
				for (d = 2; d < 32; d++) {
					if ((d + w - 1) % 7 == 0)
						cout << setw(4) << d;
					else
						cout << setw(8) << d;
					if ((d + w) % 7 == 0)
						cout << endl;
				}
				break;
			}
		}
		else {
			switch (m % 2) {
			case 1:
				for (d = 2; d < 31; d++) {
					if ((d + w - 1) % 7 == 0)
						cout << setw(4) << d;
					else
						cout << setw(8) << d;
					if ((d + w) % 7 == 0)
						cout << endl;
				}
				break;
			case 0:
				for (d = 2; d < 32; d++) {
					if ((d + w - 1) % 7 == 0)
						cout << setw(4) << d;
					else
						cout << setw(8) << d;
					if ((d + w) % 7 == 0)
						cout << endl;
				}
				break;
			}
		}
	}
	else if (m == 2) {
		for (d = 2; d < 29; d++) {
			if ((d + w - 1) % 7 == 0)
				cout << setw(4) << d;
			else
				cout << setw(8) << d;
			if ((d + w) % 7 == 0)
				cout << endl;
		}
	}
	else if (m < 8) {
		switch (m % 2) {
		case 0:
			for (d = 2; d < 31; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0)
					cout << endl;
			}
			break;
		case 1:
			for (d = 2; d < 32; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0)
					cout << endl;
			}
			break;
		}
	}
	else
		switch (m % 2) {
		case 1:
			for (d = 2; d < 31; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0)
					cout << endl;
			}
			break;
		case 0:
			for (d = 2; d < 32; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0) 
					cout << endl;
			}
			break;
		}
}