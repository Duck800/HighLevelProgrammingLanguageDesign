/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "������뾶�͸߶�" << endl;
	int r, h;
	double pi = 3.14159;
	cin >> r >> h;
	cout << "Բ�ܳ�     : " << fixed << setprecision(2) << 2 * pi * r << endl;
	cout << "Բ���     : " << pi * r * r << endl;
	cout << "Բ������ : " << 4 * pi * r * r << endl;
	cout << "Բ�����   : " << 4 * pi * r * r * r / 3 << endl;
	cout << "Բ�����   : " << pi * r * r * h << endl;

	return 0;
}