/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "������[0..100 ��)֮�������:" << endl;
	double i, x, y, a, b, c, d, e, f, g, h, j, k, l, m;
	cin >> i;
	i += 0.005;
	x = i / 1000;
	y = x - (int)x;

	a = (int)x / 1000000;
	b = (int)(x - a * 1000000) / 100000;
	c = (int)(x - a * 1000000 - b * 100000) / 10000;
	d = (int)(x - a * 1000000 - b * 100000 - c * 10000) / 1000;
	e = (int)(x - a * 1000000 - b * 100000 - c * 10000 - d * 1000) / 100;
	f = (int)(x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100) / 10;
	g = (int)(x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10);
	h = (x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10 - g) / 0.1;
	j = (x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10 - g - 0.1 * (int)h) / 0.01;
	k = (x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10 - g - 0.1 * (int)h - 0.01 * (int)j) / 0.001;
	l = (int)(y * 10000) % 10;
	m = (int)(y * 100000) % 10;

	cout << "ʮ��λ : " << a << endl;
	cout << "��λ   : " << b << endl;
	cout << "ǧ��λ : " << c << endl;
	cout << "����λ : " << d << endl;
	cout << "ʮ��λ : " << e << endl;
	cout << "��λ   : " << f << endl;
	cout << "ǧλ   : " << g << endl;
	cout << "��λ   : " << (int)h << endl;
	cout << "ʮλ   : " << (int)j << endl;
	cout << "Բ     : " << (int)k << endl;
	cout << "��     : " << (int)l << endl;
	cout << "��     : " << (int)m << endl;

	return 0;
}