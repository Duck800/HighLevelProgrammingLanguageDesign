/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include <cmath>
using namespace std;

void a_is_0(double a)
{
	cout << "����һԪ���η���" << endl;
}

void unequal(double a, double b, double c)
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	cout << "����������ʵ����" << endl;
	cout << (x1 > x2 ? "x1" : "x2") << "=" << (x1 > x2 ? x1 : x2) << endl;
	cout << (x1 > x2 ? "x2" : "x1") << "=" << (x1 > x2 ? x2 : x1) << endl;
}

void equal(double a, double b, double c)
{
	double x1, x2;
	x1 = x2 = (-b) / (2 * a);
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << x1 << endl;
}

void imag(double a, double b, double c)
{
	double x1, x2, t;
	t = sqrt(-(b * b - 4 * a * c)) / (2 * a);
	x1 = (-b) / (2 * a);
	x2 = (-b) / (2 * a);
	cout << "�����������" << endl;
	cout << "x1=" << x1 << "+" << t << "i" << endl;
	cout << "x2=" << x2 << "-" << t << "i" << endl;
}