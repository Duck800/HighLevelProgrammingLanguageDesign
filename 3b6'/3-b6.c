/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
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

	printf("��д�����:\n");
	if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0 || l != 0 || m != 0) {
		if (a != 0 || b != 0) {
			switch ((int)a) {
			case 1:
				printf("Ҽʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 9:
				printf("��ʰ");
				break;
			}
			switch ((int)b) {
			case 1:
				printf("Ҽ");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 6:
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
			}
			printf("��");
		}
		/*��*/
		switch ((int)c) {
		case 0:
			if (((int)a != 0 || (int)b != 0) && ((int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0))
				printf("��");
			break;
		case 1:
			printf("Ҽǧ");
			break;
		case 2:
			printf("��ǧ");
			break;
		case 3:
			printf("��ǧ");
			break;
		case 4:
			printf("��ǧ");
			break;
		case 5:
			printf("��ǧ");
			break;
		case 6:
			printf("½ǧ");
			break;
		case 7:
			printf("��ǧ");
			break;
		case 8:
			printf("��ǧ");
			break;
		case 9:
			printf("��ǧ");
			break;
		}

		switch ((int)d) {
		case 0:
			if ((int)c != 0 && ((int)e != 0 || (int)f != 0 || (int)g != 0))
				printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
		}
		switch ((int)e) {
		case 0:
			if ((int)d != 0 && (int)f != 0)
				printf("��");
			break;
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		}
		switch ((int)f) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		if ((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0)
			printf("��");
		/*��*/
		switch ((int)g) {
		case 0:
			if (((int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0) && ((int)h != 0 || (int)j != 0 || (int)k != 0))
				printf("��");
			break;
		case 1:
			printf("Ҽǧ");
			break;
		case 2:
			printf("��ǧ");
			break;
		case 3:
			printf("��ǧ");
			break;
		case 4:
			printf("��ǧ");
			break;
		case 5:
			printf("��ǧ");
			break;
		case 6:
			printf("½ǧ");
			break;
		case 7:
			printf("��ǧ");
			break;
		case 8:
			printf("��ǧ");
			break;
		case 9:
			printf("��ǧ");
			break;
		}

		switch ((int)h) {
		case 0:
			if ((int)g != 0 && ((int)j != 0 || (int)k != 0))
				printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
		}
		switch ((int)j) {
		case 0:
			if ((int)h != 0 && (int)k != 0)
				printf("��");
			break;
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		}
		switch ((int)k) {
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0)
			printf("Բ");
		/*Բ*/
		switch ((int)l) {
		case 0:
			if ((int)a != 0 || (int)b != 0 || (int)c != 0 || (int)d != 0 || (int)e != 0 || (int)f != 0 || (int)g != 0 || (int)h != 0 || (int)j != 0 || (int)k != 0) {
				if ((int)m == 0)
					printf("��");
				else
					printf("��");
			}
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ƽ�");
			break;
		case 9:
			printf("����");
			break;
		}
		switch ((int)m) {
		case 0:
			if ((int)l != 0)
				printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�Ʒ�");
			break;
		case 9:
			printf("����");
			break;
		}
	}
	else
	printf("��Բ");

	return 0;
}