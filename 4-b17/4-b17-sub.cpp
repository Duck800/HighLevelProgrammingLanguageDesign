/*2151133 孙韩雅 信07*/
#include<iostream>
#include <cmath>
using namespace std;

extern double a, b, c;
void a_is_0()
{
	cout << "不是一元二次方程" << endl;
}

void unequal()
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	cout << "有两个不等实根：" << endl;
	cout << (x1 > x2 ? "x1" : "x2") << "=" << (x1 > x2 ? x1 : x2) << endl;
	cout << (x1 > x2 ? "x2" : "x1") << "=" << (x1 > x2 ? x2 : x1) << endl;
}

void equal()
{
	double x1, x2;
	x1 = x2 = (-b) / (2 * a);
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x1 << endl;
}

void imag()
{
	double x1, x2, t;
	t = sqrt(-(b * b - 4 * a * c)) / (2 * a);
	x1 = (-b) / (2 * a);
	x2 = (-b) / (2 * a);
	cout << "有两个虚根：" << endl;
	cout << "x1=" << x1 << "+" << t << "i" << endl;
	cout << "x2=" << x2 << "-" << t << "i" << endl;
}