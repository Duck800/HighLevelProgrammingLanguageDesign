/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	printf("�����������ε����߼���нǣ��Ƕȣ�\n");

	int a, b, alpha;
	double pi = 3.14159;
	scanf("%d %d %d", &a, &b, &alpha);
	float s = a * b * (float)sin(pi * alpha / 180) / 2;

	printf("���������Ϊ : %.3f\n", s);

	return 0;
}