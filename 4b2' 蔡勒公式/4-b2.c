/* 2151133 �ﺫ�� ��07 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d) {
	int w, c, i;
	if (m > 2) {
		i = y % 100;
		c = (y - i) / 100;
	}
	else {
		m += 12;
		y -= 1;
		i = y % 100;
		c = (y - i) / 100;
	}
	w = i + (int)(i / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d - 1;
	w = (w + 28) % 7;
	return w;
}

int main() {
	int ret,y, m, d, leap;
	while (1) {
		printf("��������[1900-2100]���¡��գ�\n");
		ret = scanf("%d %d %d", &y, &m, &d);
		if (ret!=3) {
			printf("�����������������\n" );
			fflush(stdin);
			while (getchar() != '\n')
				continue;
		}
		else if (y > 2100 || y < 1900) {
			printf("��ݲ���ȷ������������\n");
			fflush(stdin);
			while (getchar() != '\n')
				continue;
		}
		else if (m > 12) {
			printf("�·ݲ���ȷ������������\n");
			fflush(stdin);
			while (getchar() != '\n')
				continue;
		}
		else if (leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
			if (m == 2) {
				if (d < 30)
					break;
				else {
					printf("�ղ���ȷ������������\n");
					fflush(stdin);
					while (getchar() != '\n')
						continue;
				}
			}
			else if (m < 8) {
				if (m % 2 == 0) {
					if (d < 31)
						break;
					else
						printf("�ղ���ȷ������������\n");
				}
				else {
					if (d < 32)
						break;
					else
						printf("�ղ���ȷ������������\n");
				}
			}
			else  {
				if (m % 2 == 0) {
					if (d < 32)
						break;
					else {
						printf("�ղ���ȷ������������\n");
						fflush(stdin);
						while (getchar() != '\n')
							continue;
					}
				}
				else {
					if (d < 31)
						break;
					else {
						printf("�ղ���ȷ������������\n");
						fflush(stdin);
						while (getchar() != '\n')
							continue;
					}
				}
			}
		}
		else {
			if (m == 2) {
				if (d < 29)
					break;
				else {
					printf("�ղ���ȷ������������\n");
					fflush(stdin);
					while (getchar() != '\n')
						continue;
				}
			}
			else if (m < 8) {
				if (m % 2 == 0) {
					if (d < 31)
						break;
					else
						printf("�ղ���ȷ������������\n");
				}
				else {
					if (d < 32)
						break;
					else
						printf("�ղ���ȷ������������\n");
				}
			}
			else  {
				if (m % 2 == 0) {
					if (d < 32)
						break;
					else {
						printf("�ղ���ȷ������������\n");
						fflush(stdin);
						while (getchar() != '\n')
							continue;
					}
				}
				else {
					if (d < 31)
						break;
					else {
						printf("�ղ���ȷ������������\n");
						fflush(stdin);
						while (getchar() != '\n')
							continue;
					}
				}
			}
		}
	}
	printf("����");
	switch (zeller(y, m, d)) {
	case 0:
		printf("��");
		break;
	case 1:
		printf("һ");
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
		printf("��");
		break;
	}
	printf("\n");

	return 0;
}