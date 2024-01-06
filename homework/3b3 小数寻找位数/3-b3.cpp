/*2151133 孙韩雅 信07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入[0..100 亿)之间的数字:" << endl;
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

	cout << "十亿位 : " << a << endl;
	cout << "亿位   : " << b << endl;
	cout << "千万位 : " << c << endl;
	cout << "百万位 : " << d << endl;
	cout << "十万位 : " << e << endl;
	cout << "万位   : " << f << endl;
	cout << "千位   : " << g << endl;
	cout << "百位   : " << (int)h << endl;
	cout << "十位   : " << (int)j << endl;
	cout << "圆     : " << (int)k << endl;
	cout << "角     : " << (int)l << endl;
	cout << "分     : " << (int)m << endl;

	return 0;
}