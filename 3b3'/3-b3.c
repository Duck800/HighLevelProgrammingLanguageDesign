/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("请输入[0..100 亿)之间的数字:\n");
	double i, x, y, a, b, c, d, e, f, g, h, j, k, l, m;
	scanf("%lf", &i);
	i += 0.005;
	x = i / 1000;
	y = x - (int)x;

	a = (int)x / 1000000;
	b = (int)(x - a * 1000000) / 100000;
	c = (int)(x - a * 1000000 - b * 100000) / 10000;
	d = (int)(x - a * 1000000 - b * 100000 - c * 10000) / 1000;
	e = (int)(x - a * 1000000 - b * 100000 - c * 10000 - d * 1000) / 100;
	f = (int)(x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100) / 10;
	g = (int)(x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10);
	h = (x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10 - g) / 0.1;
	j = (x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10 - g - 0.1 * (int)h) / 0.01;
	k = (x - a * 1000000 - b * 100000 - c * 10000 - d * 1000 - e * 100 - f * 10 - g - 0.1 * (int)h - 0.01 * (int)j) / 0.001;
	l = (int)(y * 10000) % 10;
	m = (int)(y * 100000) % 10;

	printf("十亿位 : %d\n", (int)a);
	printf("亿位   : %d\n", (int)b);
	printf("千万位 : %d\n", (int)c);
	printf("百万位 : %d\n", (int)d);
	printf("十万位 : %d\n", (int)e);
	printf("万位   : %d\n", (int)f);
	printf("千位   : %d\n", (int)g);
	printf("百位   : %d\n", (int)h);
	printf("十位   : %d\n", (int)j);
	printf("圆     : %d\n", (int)k);
	printf("角     : %d\n", (int)l);
	printf("分     : %d\n", (int)m);

	return 0;
}