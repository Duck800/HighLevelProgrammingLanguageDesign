/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include <cmath>
using namespace std;

void unequal(double a, double b, double c)
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	cout << "����������ʵ����" << endl;
	cout << (x1 > x2 ? "x1" : "x2") << "=" << (x1 > x2 ? x1 : x2) << endl;
	cout << (x1 > x2 ? "x2" : "x1") << "=" << (x1 > x2 ? x2 : x1) << endl;
}