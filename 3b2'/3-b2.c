/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������һ��[1..30000]�������:\n");

	int i;
	scanf("%d", &i);

	int a = i / 10000;
	int b = (i - 10000 * a) / 1000;
	int c = (i - 10000 * a - 1000 * b) / 100;
	int d = (i - 10000 * a - 1000 * b - 100 * c) / 10;
	int e = (i - 10000 * a - 1000 * b - 100 * c - 10 * d);

	printf("��λ : %d\n", a);
	printf("ǧλ : %d\n", b);
	printf("��λ : %d\n", c);
	printf("ʮλ : %d\n", d);
	printf("��λ : %d\n", e);

	return 0;
}