/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int leap(int y)
{
	int leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
	return leap;
	/*1Ϊ���꣬0Ϊƽ��*/
}

int day(int y, int m, int d)
{
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, sum = 0;
	if (leap(y))
		a[1] = 29;
	for (i = 0; i < m - 1; i++) {
		sum += a[i];
	}
	sum += d;
	return sum;
}

int correct(int y, int m, int d) {
	if (m > 0 && m < 13) {
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (leap(y))
			a[1] = 29;
		return 1;
		if (d > a[m - 1]) {
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			return 0;
		}
	}
	else {
		cout << "�������-�·����벻��ȷ" << endl;
		return 0;
	}
}

int main()
{
	cout << "�������꣬�£���" << endl;
	int y, m, d;
	cin >> y >> m >> d;
	if (correct(y, m, d))
		cout << y << "-" << m << "-" << d << "��" << y << "��ĵ�" << day(y, m, d) << "��" << endl;
}