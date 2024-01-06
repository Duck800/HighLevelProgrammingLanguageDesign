/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入一个[1..30000]间的整数:\n");

	int i;
	scanf("%d", &i);

	int a = i / 10000;
	int b = (i - 10000 * a) / 1000;
	int c = (i - 10000 * a - 1000 * b) / 100;
	int d = (i - 10000 * a - 1000 * b - 100 * c) / 10;
	int e = (i - 10000 * a - 1000 * b - 100 * c - 10 * d);

	printf("万位 : %d\n", a);
	printf("千位 : %d\n", b);
	printf("百位 : %d\n", c);
	printf("十位 : %d\n", d);
	printf("个位 : %d\n", e);

	return 0;
}