/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "������һ��[1..30000]�������:" << endl;

	int i;
	cin >> i;

	int a = i / 10000;
	int b = (i - 10000 * a) / 1000;
	int c = (i - 10000 * a - 1000 * b) / 100;
	int d = (i - 10000 * a - 1000 * b - 100 * c) / 10;
	int e = (i - 10000 * a - 1000 * b - 100 * c - 10 * d);

	cout << "��λ : " << a << endl;
	cout << "ǧλ : " << b << endl;
	cout << "��λ : " << c << endl;
	cout << "ʮλ : " << d << endl;
	cout << "��λ : " << e << endl;

	return 0;
}