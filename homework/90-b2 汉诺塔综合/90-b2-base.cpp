/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include "cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include "90-b2.h"
using namespace std;
struct compound solution;

/*���������*/
void set()
{
	int i, j;
	srand((unsigned int)(time(0)));
	for (i = 0; i < solution.row; i++) {
		for (j = 0; j < solution.column; j++)
			solution.record[i][j] = rand() % 3 + 1;
	}
}

/*���Ǻź���*/
void assign_sign(int count, char choice)
{
	/*ѭ������*/int m, n, i;
	if (choice == '1') {
		while (1) {
			/*�ж��Ƿ��˳���ֵ*/int count = 0;
			for (m = 0; m < solution.row; m++) {
				for (n = 0; n < solution.column; n++) {
					if (solution.sign[m][n] == '*') {
						for (i = m - 1; i < m + 2; i++) {
							if (i >= 0 && i < solution.row && i != m && solution.sign[i][n] != '*') {
								if (solution.record[m][n] == solution.record[i][n]) {
									solution.sign[i][n] = '*';
									solution.count++;
									count++;
								}
							}
						}
						for (i = n - 1; i < n + 2; i++) {
							if (i >= 0 && i < solution.column && i != n && solution.sign[m][i] != '*') {
								if (solution.record[m][n] == solution.record[m][i]) {
									solution.sign[m][i] = '*';
									solution.count++;
									count++;
								}
							}
						}
					}
				}
			}
			if (count == 0) 
				break;
		}
	}
	else if (choice == '2') {
		if (count != 0) {
			count = 0;
			for (m = 0; m < solution.row; m++) {
				for (n = 0; n < solution.column; n++) {
					if (solution.sign[m][n] == '*') {
						for (i = m - 1; i < m + 2; i++) {
							if (i >= 0 && i < solution.row && i != m && solution.sign[i][n] != '*') {
								if (solution.record[m][n] == solution.record[i][n]) {
									solution.sign[i][n] = '*';
									solution.count++;
									count++;
								}
							}
						}
						for (i = n - 1; i < n + 2; i++) {
							if (i >= 0 && i < solution.column && i != n && solution.sign[m][i] != '*') {
								if (solution.record[m][n] == solution.record[m][i]) {
									solution.sign[m][i] = '*';
									solution.count++;
									count++;
								}
							}
						}
					}
				}
			}
			assign_sign(count, '2');
		}
	}
}

/*��������*/
void fall()
{
	/*ѭ������*/int m, n, i;
	/*�м����*/int mid;
	for (n = 0; n < solution.column; n++) {
		for (m = solution.row - 1; m >= 0; m--) {
			if (solution.record[m][n] == 0) {
				for (i = m; i >= 0; i--) {
					if (solution.record[i][n] != 0) {
						mid = solution.record[m][n];
						solution.record[m][n] = solution.record[i][n];
						solution.record[i][n] = mid;
						break;
					}
				}
			}
		}
	}
}
/*��ӡ���������*/
void output_fall()
{
	cout << endl << "���س����������������0����...";
	while (_getch() != '\r')
		;
	cout << endl;
	cout << endl << "��0�������(��ͬɫ��ʶ)��" << endl;
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
		for (j = 0; j < solution.column; j++) {
			if (solution.record[i][j] == 0) {
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
/*��ֵ���*/
void fill()
{
	cout << "���س���������ֵ���..." << endl;
	while (_getch() != '\r')
		;
	cout << endl;
	/*ѭ������*/int m, n;
	cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
	cout << "  |  ";
	for (m = 0; m < solution.column; m++)
		cout << m << "  ";
	cout << endl << "--+";
	for (m = 0; m < solution.column; m++)
		cout << "---";
	cout << endl;
	srand((unsigned int)(time(0)));
	for (m = 0; m < solution.row; m++) {
		cout << char(m + 'A') << " |  ";
		for (n = 0; n < solution.column; n++) {
			if (solution.record[m][n] == 0) {
				random(&solution.record[m][n]);
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << solution.record[m][n];
				cct_setcolor(COLOR_BLACK);
				cout << "  ";
			}
			else
				cout << solution.record[m][n] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
/*��������������*/
void random(int* result)
{
	int prob = rand() % 100;
	if (solution.combine_num < 4)
		*result = rand() % 3 + 1;
	else if (solution.combine_num == 4) {
		if (prob < 90)
			*result = rand() % 3 + 1;
		else
			*result = 4;
	}
	else if (solution.combine_num == 5) {
		if (prob < 75)
			*result = rand() % 3 + 1;
		else if (prob < 90)
			*result = 4;
		else
			*result = 5;
	}
	else if (solution.combine_num == 6) {
		if (prob < 80)
			*result = rand() % 4 + 1;
		else if (prob < 95)
			*result = 5;
		else
			*result = 6;
	}
	else if (solution.combine_num > 6) {
		if (prob < 80)
			*result = rand() % (solution.combine_num - 3) + 1;
		else if (prob < 90)
			*result = solution.combine_num - 2;
		else if (prob < 95)
			*result = solution.combine_num - 1;
		else
			*result = solution.combine_num;
	}
}

void project(char choice)
{
	cct_cls();
	reset();
	solution.row = input_row();
	solution.column = input_column();
	set();
	output_record_normal();
	while (1) {
		cout << endl << "������ĸ+������ʽ[����c2]����������꣺";
		/*��������*/char x = input_x(), y = input_y();
		cout << endl << "����Ϊ" << x << "��" << y << "��" << endl;
		x -= 65, y -= 48;
		solution.sign[x][y] = '*';
		assign_sign(1, choice);

		if (solution.count == 0) {
			cout << "����ľ�������λ�ô���������ֵͬ������������";
			solution.sign[x][y] = '0';
			continue;
		}
		else {
			output_sign();
			break;
		}
	}
	cout << endl;
	output_record_sign();
	to_be_continued(choice);
}

int display_3_4()
{
	output_record_normal();
	int result = 0;
	while (1) {
		if (check() == 0) {
			cct_setcolor(COLOR_HYELLOW, COLOR_RED);
			cout << "�޿ɺϲ������Ϸ����!";
			cct_setcolor(COLOR_BLACK);
			cout << endl;
			break;
		}
		int i, j;
		for (i = 0; i < ROW; i++) {
			for (j = 0; j < COLUMN; j++)
				solution.sign[i][j] = '0';
		}
		solution.count = 0;
		cout << endl << "������ĸ+������ʽ[����c2]����������꣺";
		/*��������*/char x = input_x(), y = input_y();
		cout << endl << "����Ϊ" << x << "��" << y << "��" << endl;
		x -= 65, y -= 48;
		result = solution.record[x][y] + 1;
		solution.sign[x][y] = '*';
		assign_sign(1, '1');
		if (solution.count == 0) {
			cout << "����ľ�������λ�ô���������ֵͬ������������";
			solution.sign[x][y] = '0';
			continue;
		}
		else {
			output_sign();
			output_record_sign();
			char in = confirm(x, y);
			if (in == 'Y' || in == 'y' || in == 'Q' || in == 'q')
				break;
			else {
				int i, j;
				for (i = 0; i < ROW; i++) {
					for (j = 0; j < COLUMN; j++)
						solution.sign[i][j] = '0';
				}
				continue;
			}
		}
	}
	cout << endl;
	return result;
}
void project_3(char choice)
{
	cct_cls();
	reset();
	solution.row = input_row();
	solution.column = input_column();
	solution.goal = input_goal();
	set();
	display_3_4();
	to_be_continued(choice);
}

void project_4(char choice)
{
	cct_cls();
	reset();
	solution.row = input_row();
	solution.column = input_column();
	solution.goal = input_goal();
	set();
	while (1) {
		int result = display_3_4();
		if (check() == 0)
			break;
		cout << "���κϳɽ��������س���������һ�εĺϳ�...";
		while (_getch() != '\r')
			;
		cout << endl;
		if (result >= solution.goal) {
			cct_setcolor(COLOR_HYELLOW, COLOR_RED);
			cout << "�Ѿ��ϳɵ�" << solution.goal;
			cct_setcolor(COLOR_BLACK);
			cout << endl << "���س������������Ŀ�����...";
			while (_getch() != '\r')
				;
			solution.goal++;
		}
	}
	to_be_continued(choice);
}

void project_5(char choice)
{
	cct_cls();
	reset();
	solution.row = input_row();
	solution.column = input_column();
	set();
	output_record_color();
	to_be_continued(choice);
}

void project_6_7(char choice)
{
	cct_cls();
	reset();
	solution.row = input_row();
	solution.column = input_column();
	set();
	output_record_color_line();
	if (choice == '7') {
		keyboard_mouse('7');
		to_be_continued('1');
	}
	else
		to_be_continued('6');
}

void project_8()
{
	cct_cls();
	reset();
	solution.row = input_row();
	solution.column = input_column();
	set();
	output_record_color_line();
	int MX, MY, MAction = 0, keycode1, keycode2/*�жϼ�����ָ����*/;
	while (1) {
		keyboard_mouse('8');
		show_color(solution.x, solution.y);
		cct_enable_mouse();
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (keycode1 == '\r' || MAction == MOUSE_MOVED) {
			combine_color();
			cct_showstr(0, 4 * (solution.row + 1) - 1, "�ϳ���ɣ��س���/�����������0                   ");
			cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
			if (keycode1 == '\r' || MAction == MOUSE_LEFT_BUTTON_CLICK) {
				fall_color();
				cct_showstr(0, 4 * (solution.row + 1) - 1, "����0��ɣ��س���/������������ֵ                  ");
				cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
				if (keycode1 == '\r' || MAction == MOUSE_MOVED) {
					if (keycode1 == '\r') {
						fill_color();
						break;
					}
					else {
						cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
						if (keycode1 == '\r' || MAction == MOUSE_LEFT_BUTTON_CLICK)
							fill_color();
						break;
					}
				}
			}
		}
	}
	cct_showstr(0, 4 * (solution.row + 1) - 1, "���κϳɽ�������C/������������һ�κϳ�", COLOR_BLACK, COLOR_YELLOW);
	cct_enable_mouse();
	MAction = 0;
	while (keycode1 != 'C' && keycode1 != 'c' && MAction != MOUSE_LEFT_BUTTON_CLICK)
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
	to_be_continued('6');
}

void project_9()
{
	cct_cls();
	reset();
	solution.row = input_row();
	solution.column = input_column();
	solution.goal = input_goal();
	set();
	output_record_color_line();
	while (1) {
		if (check() == 0) 
			break;
		keyboard_mouse('8');
		show_color(solution.x, solution.y);
		solution.score = 3 * solution.record[solution.x][solution.y] * (solution.count + 1);
		solution.total += solution.score;
		cct_gotoxy(0, 0);
		cct_setcolor();
		cout << "���ε÷֣�" << solution.score << " �ܵ÷֣�" << solution.total << " �ϳ�Ŀ�꣺" << solution.goal << "       ";
		combine_color();
		Sleep(DELAY * 10);
		fall_color();
		Sleep(DELAY * 10);
		fill_color();
		if (solution.combine_num >= solution.goal) {
			cct_gotoxy(0, 0);
			cct_setcolor(COLOR_HYELLOW, COLOR_RED);
			cout << "�Ѿ��ϳɵ�" << solution.goal;
			cct_setcolor(COLOR_BLACK);
			cout << "���������Ŀ�����...          ";
			solution.goal++;
		}
	}
	to_be_continued('6');
}
