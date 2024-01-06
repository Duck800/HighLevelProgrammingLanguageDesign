/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <string.h>

void input(char number[10][8], char name[10][9], int score[10])
{
	/*循环控制*/int i;
	for (i = 0; i < 10; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s", number[i]);
		strcat(number[i], "");
		scanf("%s", name[i]);
		strcat(name[i], "");
		scanf("%d", &score[i]);
		fflush(stdin);
	}
}

void output(char number[10][8], char name[10][9], int score[10])
{
	printf("\n");
	printf("全部学生(成绩降序):\n");
	/*循环控制*/int i;
	for (i = 0; i < 10; i++) {
		printf("%s", name[i]);
		printf(" ");
		printf("%s", number[i]);
		printf(" ");
		printf("%d\n", score[i]);
	}
}

void rank(char number[10][8], char name[10][9], int score[10])
{
	int i, j, m;
	int mid_sco;
	char mid_num[8], mid_name[9];
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (score[j] < score[j + 1]) {
				for (m = 0; m < 8; m++) {
					mid_num[m] = number[j + 1][m];
					number[j + 1][m] = number[j][m];
					number[j][m] = mid_num[m];
				}
				for (m = 0; m < 9; m++) {
					mid_name[m] = name[j + 1][m];
					name[j + 1][m] = name[j][m];
					name[j][m] = mid_name[m];
				}
				mid_sco = score[j + 1];
				score[j + 1] = score[j];
				score[j] = mid_sco;
			}
		}
	}
	output(number, name, score);
}


int main()
{
	char number[10][8] = { 0 };
	char name[10][9] = { 0 };
	int score[11] = { 0 };
	input(number, name, score);
	rank(number, name, score);
}