/*2151133 孙韩雅 信07*/
#include<iostream>
#include <cmath>
using namespace std;

void imag(double a, double b, double c)
{
	double x1, x2, t;
	t = sqrt(-(b * b - 4 * a * c)) / (2 * a);
	x1 = (-b) / (2 * a);
	x2 = (-b) / (2 * a);
	cout << "有两个虚根：" << endl;
	cout << "x1=" << x1 << "+" << t << "i" << endl;
	cout << "x2=" << x2 << "-" << t << "i" << endl;
}