/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	printf("请输入三角形的两边及其夹角（角度）\n");

	int a, b, alpha;
	double pi = 3.14159;
	scanf("%d %d %d", &a, &b, &alpha);
	float s = a * b * (float)sin(pi * alpha / 180) / 2;

	printf("三角形面积为 : %.3f\n", s);

	return 0;
}