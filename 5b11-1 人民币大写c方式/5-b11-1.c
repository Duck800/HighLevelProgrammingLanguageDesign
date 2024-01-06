/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <string.h>

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; 
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
	/* --允许添加需要的内容 --*/
	printf("请输入[0-100亿)之间的数字:\n");
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

	/*赋值*/
	if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0 || l != 0 || m != 0) {
		assign((int)a, (int)a);
		if ((int)a != 0)
			strncat(result, "拾", 3);
		//
		assign((int)b, (int)b);
		if ((int)a != 0 || (int)b != 0)
			strncat(result, "亿", 3);
		/*亿*/
		assign((int)c, ((int)a != 0 || (int)b != 0) && (int)d);
		if ((int)c != 0)
			strncat(result, "仟", 3);
		//
		assign((int)d, (int)c != 0 && ((int)e != 0 || (int)f != 0 || (int)g != 0));
		if ((int)d != 0)
			strncat(result, "佰", 3);
		//
		assign((int)e, (int)d != 0 && (int)f != 0);
		if ((int)e != 0)
			strncat(result, "拾", 3);
		//
		assign((int)f, 0);
		if ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0)
			strncat(result, "万", 3);
		/*万*/
		assign((int)g, ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0) && (int)h);
		if ((int)g != 0)
			strncat(result, "仟", 3);
		//
		assign((int)h, (int)g != 0 && ((int)j != 0 || (int)k != 0));
		if ((int)h != 0)
			strncat(result, "佰", 3);
		//
		assign((int)j, (int)h != 0 && (int)k != 0);
		if ((int)j != 0)
			strncat(result, "拾", 3);
		//
		assign((int)k, 0);
		if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0)
			strncat(result, "圆", 3);
		/*圆*/
		if (m != 0 || l != 0) {
			assign((int)l, ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0) && (int)m);
			if ((int)l != 0)
				strncat(result, "角", 3);
			assign((int)m, 0);
			if ((int)m != 0)
				strncat(result, "分", 3);
			else
				strncat(result, "整", 3);
		}
		else
			strncat(result, "整", 3);
	}
	else
	strncat(result, "零圆", 5);

	printf("大写结果是:\n");

	printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
	return 0;
}
