/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ret, y, m, leap, w, d, i;
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d %d", &y, &m);
		if (ret == 0) {
			fflush(stdin);
			while (getchar() != '\n')
				continue;
		}
		else if (y < 2000 || y>2030 || m < 1 || m>12) {
			printf("����Ƿ�������������\n");
			fflush(stdin);
			continue;
		}
		else
			break;
	}
	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", y, m);
		ret = scanf("%d", &w);
		if (ret == 0) {
			fflush(stdin);
			while (getchar() != '\n')
				continue;
		}
		else if (w > 6 || w < 0) {
			printf("����Ƿ�������������\n");
			fflush(stdin);
			while (getchar() != '\n')
				continue;
		}
		else 
			break;
	}
	printf("\n%d��%d�µ�����Ϊ:\n", y, m);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	i = 8 * w + 4;
	printf("%id", 1);
	if (leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
		if (m == 2) {
			for (d = 2; d < 30; d++) {
				if ((d + w - 1) % 7 == 0)
					printf("%4d", d);
				else
					printf("%8d", d);
				if ((d + w) % 7 == 0) 
					printf("\n");
			}
		}
		else if (m < 8) {
			switch (m % 2) {
			case 0:
				for (d = 2; d < 31; d++) {
					if ((d + w - 1) % 7 == 0)
						printf("%4d", d);
					else
						printf("%8d", d);
					if ((d + w) % 7 == 0) 
						printf("\n");
				}
				break;
			case 1:
				for (d = 2; d < 32; d++) {
					if ((d + w - 1) % 7 == 0)
						printf("%4d", d);
					else
						printf("%8d", d);
					if ((d + w) % 7 == 0) 
						printf("\n");
				}
				break;
			}
		}
		else
			switch (m % 2) {
			case 1:
				for (d = 2; d < 31; d++) {
					if ((d + w - 1) % 7 == 0)
						printf("%4d", d);
					else
						printf("%8d", d);
					if ((d + w) % 7 == 0) 
						printf("\n");
				}
				break;
			case 0:
				for (d = 2; d < 32; d++) {
					if ((d + w - 1) % 7 == 0)
						printf("%4d", d);
					else
						printf("%8d", d);
					if ((d + w) % 7 == 0)
						printf("\n");
				}
				break;
			}
	}
	else if (m == 2) {
		for (d = 2; d < 29; d++) {
			if ((d + w - 1) % 7 == 0)
				printf("%4d", d);
			else
				printf("%8d", d);
			if ((d + w) % 7 == 0)
				printf("\n");
		}
	}
	else if (m < 8) {
		switch (m % 2) {
		case 0:
			for (d = 2; d < 31; d++) {
				if ((d + w - 1) % 7 == 0)
					printf("%4d", d);
				else
					printf("%8d", d);
				if ((d + w) % 7 == 0)
					printf("\n");
			}
			break;
		case 1:
			for (d = 2; d < 32; d++) {
				if ((d + w - 1) % 7 == 0)
					printf("%4d", d);
				else
					printf("%8d", d);
				if ((d + w) % 7 == 0)
					printf("\n");
			}
			break;
		}
	}
	else
		switch (m % 2) {
		case 1:
			for (d = 2; d < 31; d++) {
				if ((d + w - 1) % 7 == 0)
					printf("%4d", d);
				else
					printf("%8d", d);
				if ((d + w) % 7 == 0)
					printf("\n");
			}
			break;
		case 0:
			for (d = 2; d < 32; d++) {
				if ((d + w - 1) % 7 == 0)
					printf("%4d", d);
				else
					printf("%8d", d);
				if ((d + w) % 7 == 0)
					printf("\n");
			}
			break;
		}
}