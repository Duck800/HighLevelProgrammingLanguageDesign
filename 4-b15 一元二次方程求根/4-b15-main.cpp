/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include <cmath>
using namespace std;

void a_is_0(double a);
void unequal(double a, double b, double c);
void equal(double a, double b, double c);
void imag(double a, double b, double c);

int main()
{
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
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