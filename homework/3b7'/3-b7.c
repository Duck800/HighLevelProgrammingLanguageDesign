/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入找零值：\n");
	double i, a, b, c, d, e, f, g, h, j, k, l;
	scanf("%lf", &i);
	a = (int)i / 50;
	b = (int)(i - a * 50) / 20;
	c = (int)(i - a * 50 - b * 20) / 10;
	d = (int)(i - a * 50 - b * 20 - c * 10) / 5;
	e = (int)(i - a * 50 - b * 20 - c * 10 - d * 5);
	f = (int)((i - a * 50 - b * 20 - c * 10 - d * 5 - e) * 100);
	g = (int)(f / 50);
	h = (int)((f - g * 50) / 10);
	j = (int)((f - g * 50 - h * 10) / 5);
	k = (int)((f - g * 50 - h * 10 - j * 5) / 2);
	l = (int)(f - g * 50 - h * 10 - j * 5 - k * 2);

	printf("共%d张找零，具体如下：\n", (int)(a + b + c + d + e + g + h + j + k + l));

	if (a != 0)
		printf("50元 : %d 张\n", (int)a);
	if (b != 0)
		printf("20元 : %d 张\n", (int)b);
	if (c != 0)
		printf("10元 : %d 张\n", (int)c);
	if (d != 0)
		printf("5元  : %d 张\n", (int)d);
	if (e != 0)
		printf("1元  : %d 张\n", (int)e);
	if (g != 0)
		printf("5角  : %d 张\n", (int)g);
	if (h != 0)
		printf("1角  : %d 张\n", (int)h);
	if (j != 0)
		printf("5分  : %d 张\n", (int)j);
	if (k != 0)
		printf("2分  : %d 张\n", (int)k);
	if (l != 0)
		printf("1分  : %d 张\n", (int)l);

	return 0;
}