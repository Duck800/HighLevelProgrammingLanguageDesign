/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include "cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include "90-b2.h"
using namespace std;

/*��������*/
void reset()
{
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COLUMN; j++)
			solution.sign[i][j] = '0';
	}
	solution.row = 0;
	solution.column = 0;
	solution.count = 0;
	solution.combine_num = 0;
	solution.score = 0;
	solution.total = 0;
}

/*�ȴ����غ���*/
void to_be_continued(char choice)
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	if (choice == '5')
		cct_showstr(0, 3 * (solution.row + 1) + 1, "��С�������������End����...");
	else if (choice == '6')
		cct_showstr(0, 4 * (solution.row + 1), "��С�������������End����...");
	int X, Y;
	cct_getxy(X, Y);
	while (1) {
		char end[3];
		int i;
		for (i = 0; i < 3; i++)
			cin >> end[i];
		if (end[0] == 'e' || end[0] == 'E') {
			if (end[1] == 'n' || end[1] == 'N') {
				if (end[2] == 'd' || end[2] == 'D')
					break;
				else {
					cout << "�����������������";
					cct_gotoxy(X, Y);
					cout << "      ";
					cct_gotoxy(X, Y);
					continue;
				}
			}
			else {
				cout << "�����������������";
				cct_gotoxy(X, Y);
				cout << "      ";
				cct_gotoxy(X, Y);
				continue;
			}
		}
		else {
			cout << "�����������������";
			cct_gotoxy(X, Y);
			cout << "      ";
			cct_gotoxy(X, Y);
			continue;
		}
	}
}

/*�������뺯��*/
int input_row()
{
	int row;
	while (1) {
		cout << "����������(5-8)��" << endl;
		cin >> row;
		if (!(row > 4 && row < 9)) {
			cin.clear();
			cin.ignore(65535, '\n');
			continue;
		}
		else
			break;
	}
	return row;
}
int input_column()
{
	int column;
	while (1) {
		cout << "����������(5-10)��" << endl;
		cin >> column;
		if (!(column > 4 && column < 11)) {
			cin.clear();
			cin.ignore(65535, '\n');
			continue;
		}
		else
			break;
	}
	return column;
}
int input_goal()
{
	int goal;
	while (1) {
		cout << "������ϳ�Ŀ��(5-20)��";
		cin >> goal;
		if (!(goal > 4 && goal < 21)) {
			cin.clear();
			cin.ignore(65535, '\n');
			continue;
		}
		else
			break;
	}
	return goal;
}
char input_x()
{
	char x;
	while (1) {
		x = _getch();
		if (x > 64 && x < 65 + solution.row) {
			cout << x;
			break;
		}
		else if (x > 96 && x < 97 + solution.row) {
			cout << x;
			x -= 32;
			break;
		}
	}
	return x;
}
char input_y()
{
	char y;
	while (1) {
		y = _getch();
		if (y >= '0' && y <= '0' + solution.column - 1) {
			cout << y;
			break;
		}
	}
	return y;
}


/*�����������*/
/*�����ǰ���飨δ��ǣ�*/
void output_record_normal()
{
	/*ѭ������*/int i, j;
	cout << endl << "��ǰ���飺" << endl;
	cout << "  |  ";
	for (i = 0; i < solution.column; i++)
		cout << i << "  ";
	cout << endl << "--+";
	for (i = 0; i < solution.column; i++)
		cout << "---";
	cout << endl;
	for (i = 0; i < solution.row; i++) {
		cout << char(i + 'A') << " |  ";
		for (j = 0; j < solution.column; j++)
			cout << solution.record[i][j] << "  ";
		cout << endl;
	}
}
/*���ҽ������*/
void output_sign()
{
	cout << endl << "���ҽ�����飺" << endl;
	/*ѭ������*/int i, j;
	cout << "  |  ";
	for (i = 0; i < solution.column; i++)
		cout << i << "  ";
	cout << endl << "--+";
	for (i = 0; i < solution.column; i++)
		cout << "---";
	cout << endl;

	for (i = 0; i < solution.row; i++) {
		cout << char(i + 'A') << " |  ";
		for (j = 0; j < solution.column; j++)
			cout << solution.sign[i][j] << "  ";
		cout << endl;
	}
}
/*�����ǰ���飨�����ɫ��*/
void output_record_sign()
{
	/*ѭ������*/int i, j;
	cout << endl << "��ǰ���飺" << endl;
	cout << "  |  ";
	for (i = 0; i < solution.column; i++)
		cout << i << "  ";
	cout << endl << "--+";
	for (i = 0; i < solution.column; i++)
		cout << "---";
	cout << endl;
	for (i = 0; i < solution.row; i++) {
		cout << char(i + 'A') << " |  ";
		for (j = 0; j < solution.column; j++) {
			if (solution.sign[i][j] == '*') {
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << solution.record[i][j];
				cct_setcolor(COLOR_BLACK);
				cout << "  ";
			}
			else
				cout << solution.record[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
/*����ϲ�������*/
void output_combine()
{
	/*ѭ������*/int i, j;
	cout << endl << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
	cout << "  |  ";
	for (i = 0; i < solution.column; i++)
		cout << i << "  ";
	cout << endl << "--+";
	for (i = 0; i < solution.column; i++)
		cout << "---";
	cout << endl;

	for (i = 0; i < solution.row; i++) {
		cout << char(i + 'A') << " |  ";
		for (j = 0; j < solution.column; j++) {
			if (solution.sign[i][j] == '*' || solution.record[i][j] == 0) {
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << solution.record[i][j];
				cct_setcolor(COLOR_BLACK);
				cout << "  ";
			}
			else
				cout << solution.record[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

/*�Ӽ���������*/
void keyboard_mouse(char choice)
{
	/*ѭ������*/int i/*��¼��*/ = 0, j, m/*��¼��*/ = 0, n;
	int old_row = 0, old_column = 0;
	bool first = 0;
	int MX, MY, MAction = 0, keycode1, keycode2/*�жϼ�����ָ����*/;
	while (1) {
		for (j = 0; j < ROW; j++) {
			for (n = 0; n < COLUMN; n++)
				solution.sign[j][n] = '0';
		}
		solution.count = 0;
		form(i, m, old_row, old_column, COLOR_WHITE);
		if (first == 0) {
			cct_gotoxy(0, 4 * (solution.row + 1) - 1);
			cct_setcolor();
			cout << "��ͷ��/����ƶ����س���/�������ѡ�񲢽���                         ";
			first++;
		}
		cct_enable_mouse();
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (keycode1 == '\r') {
			if (choice == '7') {
				solution.count = 1;
				cct_gotoxy(0, 4 * (solution.row + 1) - 1);
				cct_setcolor();
				cout << "ѡ����" << char(i + 'A') << "��" << m << "��                             " << endl;
				break;
			}
			else if (choice == '8') {
				solution.sign[i][m] = '*';
				assign_sign(1, '1');
				if (solution.count == 0) {
					cct_gotoxy(0, 4 * (solution.row + 1) - 1);
					cct_showstr(0, 4 * (solution.row + 1) - 1, "��Χ����ֵͬ��", COLOR_BLACK, COLOR_YELLOW);
					cct_setcolor();
					cout << "��ͷ��/����ƶ����س���/������";
				}
				else {
					cct_gotoxy(0, 4 * (solution.row + 1) - 1);
					cct_setcolor();
					cout << "ѡ����" << char(i + 'A') << "��" << m << "��,�س�/����������ϲ�" << endl;
					break;
				}
			}
		}
		else if (keycode2 == 77) {
			if (m < solution.column - 1) {
				old_column = m;
				old_row = i;
				m++;//��
			}
			else {
				old_column = m;
				old_row = i;
				m = 0;
			}
		}
		else if (keycode2 == 75) {
			if (m > 0) {
				old_column = m;
				old_row = i;
				m--;//��
			}
			else {
				old_column = m;
				old_row = i;
				m = solution.column - 1;
			}
		}
		else if (keycode2 == 72) {
			if (i > 0) {
				old_column = m;
				old_row = i;
				i--;//��
			}
			else {
				old_column = m;
				old_row = i;
				i = solution.row - 1;
			}
		}
		else if (keycode2 == 80) {
			if (i < solution.row - 1) {
				old_column = m;
				old_row = i;
				i++;//��
			}
			else {
				old_column = m;
				old_row = i;
				i = 0;
			}
		}
		if (solution.count) {
			cct_gotoxy(0, 4 * (solution.row + 1) - 1);
			cct_setcolor();
			cout << "[��ǰ����]" << char(i + 'A') << "��" << m << "��                         ";
		}
		int mx = (MX - 4) / 8, my = (MY - 3) / 4;
		int k;
		bool legal = 1;
		cct_gotoxy(0, 4 * (solution.row + 1));
		cct_setcolor();
		if (MAction == MOUSE_MOVED) {
			for (k = 0; k < solution.row; k++) {
				if (MY == 4 * k + 6 || MY < 3 || MY>4 * (solution.row - 1) + 6) {
					cct_showstr(0, 4 * (solution.row + 1) - 1, "[��ǰ���]λ�÷Ƿ�                         ");
					legal = 0;
					break;
				}
			}
			for (k = 0; k < solution.column; k++) {
				if (MX == 8 * k + 10 || mx == 8 * k + 11 || MX < 4 || MX>8 * (solution.column - 1) + 10) {
					cct_showstr(0, 4 * (solution.row + 1) - 1, "[��ǰ���]λ�÷Ƿ�                         ");
					legal = 0;
					break;
				}
			}
			if (legal) {
				if (mx >= 0 && my >= 0) {
					old_row = i;
					old_column = m;
					m = mx;
					i = my;
				}
				cct_gotoxy(0, 4 * (solution.row + 1) - 1);
				cct_setcolor();
				cout << "[��ǰ���]" << char(i + 'A') << "��" << m << "��                         ";
			}
		}
		else if (MAction == MOUSE_LEFT_BUTTON_CLICK) {
			if (choice == '7') {
				solution.count = 1;
				cct_gotoxy(0, 4 * (solution.row + 1) - 1);
				cct_setcolor();
				cout << "ѡ����" << char(i + 'A') << "��" << m << "��                             " << endl;
				break;
			}
			else if (choice == '8') {
				solution.sign[i][m] = '*';
				assign_sign(1, '1');
				if (solution.count == 0) {
					cct_gotoxy(0, 4 * (solution.row + 1) - 1);
					cct_showstr(0, 4 * (solution.row + 1) - 1, "��Χ����ֵͬ��", COLOR_BLACK, COLOR_YELLOW);
					cct_setcolor();
					cout << "��ͷ��/����ƶ����س���/������";
				}
				else if (MAction == MOUSE_LEFT_BUTTON_CLICK) {
					cct_gotoxy(0, 4 * (solution.row + 1) - 1);
					cct_setcolor();
					cout << "ѡ����" << char(i + 'A') << "��" << m << "��,�س�/����������ϲ�" << endl;
						break;
				}
			}
		}
	}
	solution.x = i;
	solution.y = m;
}//�޸�

void combine(int x,int y)
{
	solution.combine_num = ++solution.record[x][y];
	/*ѭ������*/int m, n;
	for (m = 0; m < solution.row; m++) {
		for (n = 0; n < solution.column; n++) {
			if (solution.sign[m][n] == '*' && (m != x || n != y)) {
				solution.record[m][n] = 0;
				solution.sign[m][n] = '0';
			}
		}
	}
}
char confirm(char x, char y)
{
	cout << endl << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << char(x + 65) << char(y + 48) << "��(Y/N/Q)��";
	while (1) {
		char in = _getch();
		if (in == 'Y' || in == 'y') {
			cout << in << endl;
			combine(x, y);
			output_combine();
			/*����÷�*/
			solution.score = 3 * (solution.record[x][y] - 1) * (solution.count + 1);
			solution.total += solution.score;
			cout << "���ε÷֣�" << solution.score << " �ܵ÷֣�" << solution.total << " �ϳ�Ŀ�꣺" << solution.goal << endl;
			fall();
			output_fall();
			fill();
			return in;
		}
		else if (in == 'N' || in == 'n') {
			cout << in;
			return in;
		}
		else if (in == 'Q' || in == 'q') {
			return in;
		}
		else
			continue;
	}
}
/*����Ƿ��пɺϲ���ֵ*/
int check()
{
	int i, j, m;
	bool same = 0;
	for (i = 0; i < solution.row; i++) {
		for (j = 0; j < solution.column; j++) {
			for (m = i - 1; m < i + 1; m++) {
				if (m >= 0 && m < solution.row) {
					if (solution.record[i][j] == solution.record[m][j]) {
						same++;
						break;
					}
				}
			}
			for (m = j - 1; m < j + 1; m++) {
				if (m >= 0 && m < solution.column) {
					if (solution.record[i][j] == solution.record[i][m]) {
						same++;
						break;
					}
				}
			}
		}
	}
	return same;
}//����֤