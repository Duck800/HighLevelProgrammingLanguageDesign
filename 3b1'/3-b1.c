/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������뾶�͸߶�\n");
	int r, h;
	double pi = 3.14159;

	scanf("%d %d", &r, &h);

	double a = 2 * pi * r;
	double b = pi * r * r;
	double c = 4 * pi * r * r;
	double d = 4 * pi * r * r * r / 3;
	double e = pi * r * r * h;

	printf("Բ�ܳ�     : %.3g\n", a);
	printf("Բ���     : %.3g\n", b);
	printf("Բ������ : %.4g\n", c);
	printf("Բ�����   : %.3g\n", d);
	printf("Բ�����   : %.3g\n", e);

	return 0;
}