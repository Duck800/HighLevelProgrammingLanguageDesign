/*2151133 孙韩雅 信07*/
#include<iostream>
#include <cmath>
using namespace std;

double a, b, c;
void a_is_0();
void unequal();
void equal();
void imag();

int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (a == 0)
		a_is_0();
	else if (b * b - 4 * a * c > 0)
		unequal();
	else if (b * b - 4 * a * c == 0)
		equal();
	else if (b * b - 4 * a * c < 0)
		imag();

}