/*2151133 孙韩雅 信07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入找零值：" << endl;
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

	cout << "共" << (a + b + c + d + e + g + h + j + k + l) << "张找零，具体如下：" << endl;

	if (a != 0)
		cout << "50元 : " << a << "张" << endl;
	if (b != 0)
		cout << "20元 : " << b << "张" << endl;
	if (c != 0)
		cout << "10元 : " << c << "张" << endl;
	if (d != 0)
		cout << "5元  : " << d << "张" << endl;
	if (e != 0)
		cout << "1元  : " << e << "张" << endl;
	if (g != 0)
		cout << "5角  : " << g << "张" << endl;
	if (h != 0)
		cout << "1角  : " << h << "张" << endl;
	if (j != 0)
		cout << "5分  : " << j << "张" << endl;
	if (k != 0)
		cout << "2分  : " << k << "张" << endl;
	if (l != 0)
		cout << "1分  : " << l << "张" << endl;

	return 0;
}