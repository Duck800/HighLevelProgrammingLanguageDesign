/*2151133 孙韩雅 信07*/
/*2153069 刘潇 2151780 袁皓玥 2152367 姜宁 2154295 李舒扬 2154057 汪清濯*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <string.h>

int main()
{
	char mc[10][26];
	char comp[10][26];
	/*循环控制*/int i, j, a, b;
	/*计数*/int count = 0;
	/*检验数组全部赋值为0*/
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 26; j++) {
			comp[i][j] = '0';
		}
	}
	/*获取数值*/
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
	/*错误1*/
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 26; j++) {
			if (mc[i][j] == '*')
				count++;
		}
	}
	if (count != 50)
		printf("错误1\n");
	/*错误2*/
	else {
		/*计算周围雷数（中间板块）*/
		for (i = 1; i < 9; i++) {
			for (j = 1; j < 25; j++) {
				if (comp[i][j] != '*') {
					/*雷的个数*/char num = '0';
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
		/*计算周围雷数（四周板块不含角）*/
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
		/*计算周围雷数（四角）*/
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
		/*检验*/
		int error = 0;
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 26; j++) {
				if (comp[i][j] != mc[i][j])
					error++;
			}
		}
		if (error != 0)
			printf("错误2\n");
		else
			printf("正确\n");
	}
}