/*2151133 Ëïº«ÑÅ ĞÅ07*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	printf("ÇëÊäÈë[0..100 ÒÚ)Ö®¼äµÄÊı×Ö:\n");
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

	printf("´óĞ´½á¹ûÊÇ:\n");
	if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0 || l != 0 || m != 0) {
		if (a != 0 || b != 0) {
			switch ((int)a) {
			case 1:
				printf("Ò¼Ê°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 3:
				printf("ÈşÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 9:
				printf("¾ÁÊ°");
				break;
			}
			switch ((int)b) {
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èş");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
			}
			printf("ÒÚ");
		}
		/*ÒÚ*/
		switch ((int)c) {
		case 0:
			if (((int)a != 0 || (int)b != 0) && ((int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0))
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Ç§");
			break;
		case 2:
			printf("·¡Ç§");
			break;
		case 3:
			printf("ÈşÇ§");
			break;
		case 4:
			printf("ËÁÇ§");
			break;
		case 5:
			printf("ÎéÇ§");
			break;
		case 6:
			printf("Â½Ç§");
			break;
		case 7:
			printf("ÆâÇ§");
			break;
		case 8:
			printf("°ÆÇ§");
			break;
		case 9:
			printf("¾ÁÇ§");
			break;
		}

		switch ((int)d) {
		case 0:
			if ((int)c != 0 && ((int)e != 0 || (int)f != 0 || (int)g != 0))
				printf("Áã");
			break;
		case 1:
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èş°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
		}
		switch ((int)e) {
		case 0:
			if ((int)d != 0 && (int)f != 0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		}
		switch ((int)f) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		if ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0)
			printf("Íò");
		/*Íò*/
		switch ((int)g) {
		case 0:
			if (((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0) && ((int)h != 0 || (int)j != 0 || (int)k != 0))
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Ç§");
			break;
		case 2:
			printf("·¡Ç§");
			break;
		case 3:
			printf("ÈşÇ§");
			break;
		case 4:
			printf("ËÁÇ§");
			break;
		case 5:
			printf("ÎéÇ§");
			break;
		case 6:
			printf("Â½Ç§");
			break;
		case 7:
			printf("ÆâÇ§");
			break;
		case 8:
			printf("°ÆÇ§");
			break;
		case 9:
			printf("¾ÁÇ§");
			break;
		}

		switch ((int)h) {
		case 0:
			if ((int)g != 0 && ((int)j != 0 || (int)k != 0))
				printf("Áã");
			break;
		case 1:
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èş°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
		}
		switch ((int)j) {
		case 0:
			if ((int)h != 0 && (int)k != 0)
				printf("Áã");
			break;
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		}
		switch ((int)k) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0)
			printf("Ô²");
		/*Ô²*/
		switch ((int)l) {
		case 0:
			if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0) {
				if ((int)m == 0)
					printf("Õû");
				else
					printf("Áã");
			}
			break;
		case 1:
			printf("Ò¼½Ç");
			break;
		case 2:
			printf("·¡½Ç");
			break;
		case 3:
			printf("Èş½Ç");
			break;
		case 4:
			printf("ËÁ½Ç");
			break;
		case 5:
			printf("Îé½Ç");
			break;
		case 6:
			printf("Â½½Ç");
			break;
		case 7:
			printf("Æâ½Ç");
			break;
		case 8:
			printf("°Æ½Ç");
			break;
		case 9:
			printf("¾Á½Ç");
			break;
		}
		switch ((int)m) {
		case 0:
			if ((int)l != 0)
				printf("Õû");
			break;
		case 1:
			printf("Ò¼·Ö");
			break;
		case 2:
			printf("·¡·Ö");
			break;
		case 3:
			printf("Èş·Ö");
			break;
		case 4:
			printf("ËÁ·Ö");
			break;
		case 5:
			printf("Îé·Ö");
			break;
		case 6:
			printf("Â½·Ö");
			break;
		case 7:
			printf("Æâ·Ö");
			break;
		case 8:
			printf("°Æ·Ö");
			break;
		case 9:
			printf("¾Á·Ö");
			break;
		}
	}
	else
	printf("ÁãÔ²");

	return 0;
}