/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <string.h>

const char chnstr[] = "��Ҽ��������½��ƾ�"; 
char result[256]; 

void assign(int num,int flag_of_zero)
{
	if (num == 0) {
		if (flag_of_zero)
			strncat(result, chnstr, 2);
	}
	else
		strncat(result, &chnstr[num * 2], 2);
}

int main()
{
	/* --���������Ҫ������ --*/
	printf("������[0-100��)֮�������:\n");
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

	/*��ֵ*/
	if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0 || l != 0 || m != 0) {
		assign((int)a, (int)a);
		if ((int)a != 0)
			strncat(result, "ʰ", 3);
		//
		assign((int)b, (int)b);
		if ((int)a != 0 || (int)b != 0)
			strncat(result, "��", 3);
		/*��*/
		assign((int)c, ((int)a != 0 || (int)b != 0) && (int)d);
		if ((int)c != 0)
			strncat(result, "Ǫ", 3);
		//
		assign((int)d, (int)c != 0 && ((int)e != 0 || (int)f != 0 || (int)g != 0));
		if ((int)d != 0)
			strncat(result, "��", 3);
		//
		assign((int)e, (int)d != 0 && (int)f != 0);
		if ((int)e != 0)
			strncat(result, "ʰ", 3);
		//
		assign((int)f, 0);
		if ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0)
			strncat(result, "��", 3);
		/*��*/
		assign((int)g, ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0) && (int)h);
		if ((int)g != 0)
			strncat(result, "Ǫ", 3);
		//
		assign((int)h, (int)g != 0 && ((int)j != 0 || (int)k != 0));
		if ((int)h != 0)
			strncat(result, "��", 3);
		//
		assign((int)j, (int)h != 0 && (int)k != 0);
		if ((int)j != 0)
			strncat(result, "ʰ", 3);
		//
		assign((int)k, 0);
		if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0)
			strncat(result, "Բ", 3);
		/*Բ*/
		if (m != 0 || l != 0) {
			assign((int)l, ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0) && (int)m);
			if ((int)l != 0)
				strncat(result, "��", 3);
			assign((int)m, 0);
			if ((int)m != 0)
				strncat(result, "��", 3);
			else
				strncat(result, "��", 3);
		}
		else
			strncat(result, "��", 3);
	}
	else
	strncat(result, "��Բ", 5);

	printf("��д�����:\n");

	printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ���������֮ǰ�������κ���ʽ�Ĳ������ */
	return 0;
}
