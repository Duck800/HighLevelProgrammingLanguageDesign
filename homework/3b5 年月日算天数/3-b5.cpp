/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	cout << "�������꣬�£���" << endl;
	int y, m, d, i, leap;
	cin >> y >> m >> d;
	leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;

	if (leap == 1) {
		if (m < 13 && m > 0) {
			if (m == 1) {
				if (d <= 31) {
					i = d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else if (m == 2) {
				if (d <= 29) {
					i = 31 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else if (m > 2 && m < 8) {
				switch (m % 2) {
				case 0:
					if (d < 31) {
						i = 31 * (m / 2) + 29 + 30 * (m / 2 - 2) + d;
						cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
					}
					else
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					break;
				case 1:
					if (d < 32) {
						i = 31 * (m / 2) + 29 + 30 * (m / 2 - 1) + d;
						cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
					}
					else
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					break;
				}
			}
			else if (m >= 8) {
				switch (m % 2) {
				case 0:
					if (d < 32) {
						i = 213 + 31 * (m / 2 - 4) + 30 * (m / 2 - 4) + d;
						cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
					}
					else
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					break;
				case 1:
					if (d < 31) {
						i = 213 + 31 * (m / 2 - 3) + 30 * (m / 2 - 4) + d;
						cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
					}
					else
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					break;
				}
			}
		}
		else
			cout << "�������-�·����벻��ȷ" << endl;
	}
	else if (m < 13 && m > 0) {
			if (m == 1) {
				if (d <= 31) {
					i = d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else if (m == 2) {
				if (d <= 28) {
					i = 31 + d;
					cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
				}
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			}
			else if (m > 2 && m < 8) {
				switch (m % 2) {
				case 0:
					if (d < 31) {
						i = 31 * (m / 2) + 28 + 30 * (m / 2 - 2) + d;
						cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
					}
					else
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					break;
				case 1:
					if (d < 32) {
						i = 31 * (m / 2) + 28 + 30 * (m / 2 - 1) + d;
						cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
					}
					else
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					break;
				}
			}
			else if (m >= 8) {
				switch (m % 2) {
				case 0:
					if (d < 32) {
						i = 212 + 31 * (m / 2 - 4) + 30 * (m / 2 - 4) + d;
						cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
					}
					else
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					break;
				case 1:
					if (d < 31) {
						i = 212 + 31 * (m / 2 - 3) + 30 * (m / 2 - 4) + d;
						cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << i << "��";
					}
					else
						cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
					break;
				}
			}
	}
	else
		cout << "�������-�·����벻��ȷ" << endl;

		return 0;
}