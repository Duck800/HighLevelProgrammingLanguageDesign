/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	printf("请输入年，月，日\n");
	int y, m, d, i, leap;
	scanf("%d %d %d", &y, &m, &d);
	leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;

	if (leap == 1) {
		if (m < 13 && m > 0) {
			if (m == 1) {
				if (d <= 31) {
					i = d;
					printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, i);
				}
				else
					printf("输入错误-日与月的关系非法");
			}
			else if (m == 2) {
				if (d <= 29) {
					i = 31 + d;
					printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
				}
				else
					printf("输入错误-日与月的关系非法");
			}
			else if (m > 2 && m < 8) {
				switch (m % 2) {
				case 0:
					if (d < 31) {
						i = 31 * (m / 2) + 29 + 30 * (m / 2 - 2) + d;
						printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
					}
					else
						printf("输入错误-日与月的关系非法");
					break;
				case 1:
					if (d < 32) {
						i = 31 * (m / 2) + 29 + 30 * (m / 2 - 1) + d;
						printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
					}
					else
						printf("输入错误-日与月的关系非法");
					break;
				}
			}
			else if (m >= 8) {
				switch (m % 2) {
				case 0:
					if (d < 32) {
						i = 213 + 31 * (m / 2 - 4) + 30 * (m / 2 - 4) + d;
						printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
					}
					else
						printf("输入错误-日与月的关系非法");
					break;
				case 1:
					if (d < 31) {
						i = 213 + 31 * (m / 2 - 3) + 30 * (m / 2 - 4) + d;
						printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
					}
					else
						printf("输入错误-日与月的关系非法");
					break;
				}
			}
		}
		else
			printf("输入错误-月份输入不正确");
	}
	else if (m < 13 && m > 0) {
		if (m == 1) {
			if (d <= 31) {
				i = d;
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
			}
			else
				printf("输入错误-日与月的关系非法");
		}
		else if (m == 2) {
			if (d <= 28) {
				i = 31 + d;
				printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
			}
			else
				printf("输入错误-日与月的关系非法");
		}
		else if (m > 2 && m < 8) {
			switch (m % 2) {
			case 0:
				if (d < 31) {
					i = 31 * (m / 2) + 28 + 30 * (m / 2 - 2) + d;
					printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
				}
				else
					printf("输入错误-日与月的关系非法");
				break;
			case 1:
				if (d < 32) {
					i = 31 * (m / 2) + 28 + 30 * (m / 2 - 1) + d;
					printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
				}
				else
					printf("输入错误-日与月的关系非法");
				break;
			}
		}
		else if (m >= 8) {
			switch (m % 2) {
			case 0:
				if (d < 32) {
					i = 212 + 31 * (m / 2 - 4) + 30 * (m / 2 - 4) + d;
					printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
				}
				else
					printf("输入错误-日与月的关系非法");
				break;
			case 1:
				if (d < 31) {
					i = 212 + 31 * (m / 2 - 3) + 30 * (m / 2 - 4) + d;
					printf("%d-%d-%d是%d年的第%d天", y, m, d, y, i);
				}
				else
					printf("输入错误-日与月的关系非法");
				break;
			}
		}
	}
	else
	printf("输入错误-月份输入不正确");

	return 0;
}