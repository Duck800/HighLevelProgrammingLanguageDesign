/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <cstdio>
#include <conio.h>
using namespace std;


int main()
{
	char str[3][128] = { 0 };
	cout << "�������1��" << endl;
	/*ѭ������*/int i, j;
	for (i = 0; i < 128; i++) {
		str[0][i] = cin.get();
		if (str[0][i] == '\n')
			break;
	}
	cout << "�������2��" << endl;
	for (i = 0; i < 128; i++) {
		str[1][i] = cin.get();
		if (str[1][i] == '\n')
			break;
	}
	cout << "�������3��" << endl;
	for (i = 0; i < 128; i++) {
		str[2][i] = cin.get();
		if (str[2][i] == '\n')
			break;
	}
	/*��Сд*/int upper = 0, lower = 0;
	/*����*/int num = 0;
	/*�ո�*/int space = 0;
	/*����*/int other = 0;
	for (j = 0; j < 3; j++) {
		for (i = 0; i < 128; i++) {
			if (str[j][i] >= 'A' && str[j][i] <= 'Z')
				upper++;
			else if (str[j][i] >= 'a' && str[j][i] <= 'z')
				lower++;
			else if (str[j][i] >= '0' && str[j][i] <= '9')
				num++;
			else if (str[j][i] == ' ')
				space++;
			else if (str[j][i] != 0)
				other++;
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 128; j++) {
			cout << str[i][j] << " ";
		}
	}

	cout << "��д : " << upper << endl;
	cout << "Сд : " << lower << endl;
	cout << "���� : " << num << endl;
	cout << "�ո� : " << space << endl;
	cout << "���� : " << other - 3 << endl;
}