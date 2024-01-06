/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入半径和高度\n");
	int r, h;
	double pi = 3.14159;

	scanf("%d %d", &r, &h);

	double a = 2 * pi * r;
	double b = pi * r * r;
	double c = 4 * pi * r * r;
	double d = 4 * pi * r * r * r / 3;
	double e = pi * r * r * h;

	printf("圆周长     : %.3g\n", a);
	printf("圆面积     : %.3g\n", b);
	printf("圆球表面积 : %.4g\n", c);
	printf("圆球体积   : %.3g\n", d);
	printf("圆柱体积   : %.3g\n", e);

	return 0;
}