/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int main()
{
	int a[20];
	int i, sum = 0, tim = -1, j, mid;
	cout << "��������������������������20��������-1����" << endl;
	for (i = 0; i < 20; i++) {
		cin >> a[i];
		sum += a[i];
		tim++;
		if (a[i] <= 0)
			break;
		if (i > 1) {
			if (cin.good() == 0)
				break;
		}
	}
	if (a[0] <= 0 )
		cout << "����Ч����" << endl;
	else {
		cin.clear();
		cin.ignore(65536, '\n');
		a[tim] = 0;
		cout << "ԭ����Ϊ��" << endl;
		for (i = 0; i < 20; i++) {
			if (a[i] > 0)
				cout << a[i] << " ";
		}
		cout << endl;
		cout << "������Ҫ�����������" << endl;
		cin >> j;
		for (i = 0; i < tim + 1; i++) {
			if (j <= a[i]) {
				mid = a[i];
				a[i] = j;
				for (i; i < tim + 1; i++) {
					int cent = a[i + 1];
					a[i + 1] = mid;
					mid = cent;
				}
			}
		}
		cout << "����������Ϊ��" << endl;
		for (i = 0; i < tim + 1; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
