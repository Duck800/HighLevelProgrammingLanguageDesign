/*2151133 �ﺫ�� ��07*/
/*2153069 ���� 2151780 Ԭ�h 2152367 ���� 2154295 ������ 2154057 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <string.h>

int main()
{
	char mc[10][26];
	char comp[10][26];
	/*ѭ������*/int i, j, a, b;
	/*����*/int count = 0;
	/*��������ȫ����ֵΪ0*/
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 26; j++) {
			comp[i][j] = '0';
		}
	}
	/*��ȡ��ֵ*/
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 26; j++) {
			scanf("%c", &mc[i][j]);
			if (!(mc[i][j] >= '0' && mc[i][j] <= '9' || mc[i][j] == '*')) {
				j--;
				continue;
			}
			else if (mc[i][j] == '*')
				comp[i][j] = '*';
		}
	}
	/*����1*/
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 26; j++) {
			if (mc[i][j] == '*')
				count++;
		}
	}
	if (count != 50)
		printf("����1\n");
	/*����2*/
	else {
		/*������Χ�������м��飩*/
		for (i = 1; i < 9; i++) {
			for (j = 1; j < 25; j++) {
				if (comp[i][j] != '*') {
					/*�׵ĸ���*/char num = '0';
					for (a = i - 1; a < i + 2; a++) {
						for (b = j - 1; b < j + 2; b++) {
							if (comp[a][b] == '*')
								num++;
						}
					}
					comp[i][j] = num;
				}
			}
		}
		/*������Χ���������ܰ�鲻���ǣ�*/
		for (j = 1; j < 25; j++) {
			if (comp[0][j] != '*') {
				char num = '0';
				for (a = 0; a < 2; a++) {
					for (b = j - 1; b < j + 2; b++) {
						if (comp[a][b] == '*')
							num++;
					}
				}
				comp[0][j] = num;
			}
			if (comp[9][j] != '*') {
				char num = '0';
				for (a = 9; a > 7; a--) {
					for (b = j - 1; b < j + 2; b++) {
						if (comp[a][b] == '*')
							num++;
					}
				}
				comp[9][j] = num;
			}
		}
		for (i = 1; i < 9; i++) {
			if (comp[i][0] != '*') {
				char num = '0';
				for (b = 0; b < 2; b++) {
					for (a = i - 1; a < i + 2; a++) {
						if (comp[a][b] == '*')
							num++;
					}
				}
				comp[i][0] = num;
			}
			if (comp[i][25] != '*') {
				char num = '0';
				for (b = 25; b > 23; b--) {
					for (a = i - 1; a < i + 2; a++) {
						if (comp[a][b] == '*')
							num++;
					}
				}
				comp[i][25] = num;
			}
		}
		/*������Χ�������Ľǣ�*/
		if (comp[0][0] != '*') {
			char num = '0';
			for (a = 0; a < 2; a++) {
				for (b = 0; b < 2; b++) {
					if (comp[a][b] == '*')
						num++;
				}
				comp[0][0] = num;
			}
		}
		if (comp[0][25] != '*') {
			char num = '0';
			for (a = 0; a < 2; a++) {
				for (b = 25; b > 23; b--) {
					if (comp[a][b] == '*')
						num++;
				}
				comp[0][25] = num;
			}
		}

		if (comp[9][0] != '*') {
			char num = '0';
			for (a = 9; a > 7; a--) {
				for (b = 0; b < 2; b++) {
					if (comp[a][b] == '*')
						num++;
				}
				comp[9][0] = num;
			}
		}
		if (comp[9][25] != '*') {
			char num = '0';
			for (a = 9; a > 7; a--) {
				for (b = 25; b > 23; b--) {
					if (comp[a][b] == '*')
						num++;
				}
				comp[9][25] = num;
			}
		}
		/*����*/
		int error = 0;
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 26; j++) {
				if (comp[i][j] != mc[i][j])
					error++;
			}
		}
		if (error != 0)
			printf("����2\n");
		else
			printf("��ȷ\n");
	}
}