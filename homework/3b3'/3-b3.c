/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������[0..100 ��)֮�������:\n");
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

	printf("ʮ��λ : %d\n", (int)a);
	printf("��λ   : %d\n", (int)b);
	printf("ǧ��λ : %d\n", (int)c);
	printf("����λ : %d\n", (int)d);
	printf("ʮ��λ : %d\n", (int)e);
	printf("��λ   : %d\n", (int)f);
	printf("ǧλ   : %d\n", (int)g);
	printf("��λ   : %d\n", (int)h);
	printf("ʮλ   : %d\n", (int)j);
	printf("Բ     : %d\n", (int)k);
	printf("��     : %d\n", (int)l);
	printf("��     : %d\n", (int)m);

	return 0;
}