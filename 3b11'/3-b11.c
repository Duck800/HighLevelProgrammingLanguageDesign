/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int ret, x;
	while (1) {
		printf("������x��ֵ[0-100] : ");
		ret = scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (ret==0) {
			fflush(stdin);
			while (getchar() != '\n')
				continue;
		}
		else if (ret == 1 && (x >= 0 && x <= 100))
			break;
		else
			continue;
	}
	printf("x=%d\n", x);

	return 0;
}