/*2151133 孙韩雅 信07*/
#include <iostream>
#include <cmath>
#include "4-b16.h"
using namespace std;

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	double a, b, c;
	cin >> a >> b >> c;
	if (a == 0)
		a_is_0(a);
	else if (b * b - 4 * a * c > 0)
		unequal(a, b, c);
	else if (b * b - 4 * a * c == 0)
		equal(a, b, c);
	else if (b * b - 4 * a * c < 0)
		imag(a, b, c);

}