/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "����������ֵ��" << endl;
	double i, a, b, c, d, e, f, g, h, j, k, l;
	cin >> i;
	a = (int)i / 50;
	b = (int)(i - a * 50) / 20;
	c = (int)(i - a * 50 - b * 20) / 10;
	d = (int)(i - a * 50 - b * 20 - c * 10) / 5;
	e = (int)(i - a * 50 - b * 20 - c * 10 - d * 5);
	f = (int)((i - a * 50 - b * 20 - c * 10 - d * 5 - e) * 100);
	g = (int)(f / 50);
	h = (int)((f - g * 50) / 10);
	j = (int)((f - g * 50 - h * 10) / 5);
	k = (int)((f - g * 50 - h * 10 - j * 5) / 2);
	l = (int)(f - g * 50 - h * 10 - j * 5 - k * 2);

	cout << "��" << (a + b + c + d + e + g + h + j + k + l) << "�����㣬�������£�" << endl;

	if (a != 0)
		cout << "50Ԫ : " << a << "��" << endl;
	if (b != 0)
		cout << "20Ԫ : " << b << "��" << endl;
	if (c != 0)
		cout << "10Ԫ : " << c << "��" << endl;
	if (d != 0)
		cout << "5Ԫ  : " << d << "��" << endl;
	if (e != 0)
		cout << "1Ԫ  : " << e << "��" << endl;
	if (g != 0)
		cout << "5��  : " << g << "��" << endl;
	if (h != 0)
		cout << "1��  : " << h << "��" << endl;
	if (j != 0)
		cout << "5��  : " << j << "��" << endl;
	if (k != 0)
		cout << "2��  : " << k << "��" << endl;
	if (l != 0)
		cout << "1��  : " << l << "��" << endl;

	return 0;
}