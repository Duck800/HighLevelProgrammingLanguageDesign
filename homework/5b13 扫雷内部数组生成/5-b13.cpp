/*2151133 �ﺫ�� ��07*/
#include <iostream> 
#include <windows.h>
using namespace std;

int main() 
{
	char mc[10][26];
	/*ѭ������*/int i, j, a, b;
	/*char������ȫ����ֵΪ0*/
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 26; j++) {
			mc[i][j] = '0';
		}
	}
	/*��������ף���50����*/
	srand((unsigned int)(time(0)));
	for (i = 0; i < 50;) {
		int row = rand() % 10, column = rand() % 26;
		if (mc[row][column] != '*') {
			mc[row][column] = '*';
			i++;
		}
	}
	/*������Χ�������м��飩*/
	for (i = 1; i < 9; i++) {
		for (j = 1; j < 25; j++) {
			if (mc[i][j] != '*') {
				/*�׵ĸ���*/char num = '0';
				for (a = i - 1; a < i + 2; a++) {
					for (b = j - 1; b < j + 2; b++) {
						if (mc[a][b] == '*')
							num++;
					}
				}
				mc[i][j] = num;
			}
		}
	}
	/*������Χ���������ܰ�鲻���ǣ�*/
	for (j = 1; j < 25; j++) {
		if (mc[0][j] != '*') {
			char num = '0';
			for (a = 0; a < 2; a++) {
				for (b = j - 1; b < j + 2; b++) {
					if (mc[a][b] == '*')
						num++;
				}
			}
			mc[0][j] = num;
		}
		if (mc[9][j] != '*') {
			char num = '0';
			for (a = 9; a > 7; a--) {
				for (b = j - 1; b < j + 2; b++) {
					if (mc[a][b] == '*')
						num++;
				}
			}
			mc[9][j] = num;
		}
	}
	for (i = 1; i < 9; i++) {
		if (mc[i][0] != '*') {
			char num = '0'; 
			for (b = 0; b < 2; b++) {
				for (a = i - 1; a < i + 2; a++) {
					if (mc[a][b] == '*')
						num++;
				}
			}		
			mc[i][0] = num;
		}
		if (mc[i][25] != '*') {
			char num = '0';
			for (b = 25; b > 23; b--) {
				for (a = i - 1; a < i + 2; a++) {
					if (mc[a][b] == '*')
						num++;
				}
			}
			mc[i][25] = num;
		}
	}
	/*������Χ�������Ľǣ�*/
	if (mc[0][0] != '*') {
		char num = '0';
		for (a = 0; a < 2; a++) {
			for (b = 0; b < 2; b++) {
				if (mc[a][b] == '*')
					num++;
			}
			mc[0][0] = num;
		}
	}
	if (mc[0][25] != '*') {
		char num = '0';
		for (a = 0; a < 2; a++) {
			for (b = 25; b > 23; b--) {
				if (mc[a][b] == '*')
					num++;
			}
			mc[0][25] = num;
		}
	}
	
	if (mc[9][0] != '*') {
		char num = '0';
		for (a = 9; a > 7; a--) {
			for (b = 0; b < 2; b++) {
				if (mc[a][b] == '*')
					num++;
			}
			mc[9][0] = num;
		}
	}
	if (mc[9][25] != '*') {
		char num = '0';
		for (a = 9; a > 7; a--) {
			for (b = 25; b > 23; b--) {
				if (mc[a][b] == '*')
					num++;
			}
			mc[9][25] = num;
		}
	}

	/*��ӡ*/
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 26; j++) {
			cout << mc[i][j] << " ";
		}
		cout << endl;
	}
}