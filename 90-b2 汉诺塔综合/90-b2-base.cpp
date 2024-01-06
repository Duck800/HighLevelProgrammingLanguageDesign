/*2151133 孙韩雅 信07*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include "cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include "90-b2.h"
using namespace std;
struct compound solution;

/*设置随机数*/
void set()
{
	int i, j;
	srand((unsigned int)(time(0)));
	for (i = 0; i < solution.row; i++) {
		for (j = 0; j < solution.column; j++)
			solution.record[i][j] = rand() % 3 + 1;
	}
}

/*赋星号函数*/
void assign_sign(int count, char choice)
{
	/*循环控制*/int m, n, i;
	if (choice == '1') {
		while (1) {
			/*判断是否退出赋值*/int count = 0;
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

/*数组下落*/
void fall()
{
	/*循环控制*/int m, n, i;
	/*中间变量*/int mid;
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
/*打印下落后数组*/
void output_fall()
{
	cout << endl << "按回车键进行数组下落除0操作...";
	while (_getch() != '\r')
		;
	cout << endl;
	cout << endl << "除0后的数组(不同色标识)：" << endl;
	/*循环控制*/int i, j;
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
/*新值填充*/
void fill()
{
	cout << "按回车键进行新值填充..." << endl;
	while (_getch() != '\r')
		;
	cout << endl;
	/*循环控制*/int m, n;
	cout << "新值填充后的数组(不同色标识)：" << endl;
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
/*按概率输出随机数*/
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
		cout << endl << "请以字母+数字形式[例：c2]输入矩阵坐标：";
		/*矩阵坐标*/char x = input_x(), y = input_y();
		cout << endl << "输入为" << x << "行" << y << "列" << endl;
		x -= 65, y -= 48;
		solution.sign[x][y] = '*';
		assign_sign(1, choice);

		if (solution.count == 0) {
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入";
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
			cout << "无可合并的项，游戏结束!";
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
		cout << endl << "请以字母+数字形式[例：c2]输入矩阵坐标：";
		/*矩阵坐标*/char x = input_x(), y = input_y();
		cout << endl << "输入为" << x << "行" << y << "列" << endl;
		x -= 65, y -= 48;
		result = solution.record[x][y] + 1;
		solution.sign[x][y] = '*';
		assign_sign(1, '1');
		if (solution.count == 0) {
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入";
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
		cout << "本次合成结束，按回车键继续新一次的合成...";
		while (_getch() != '\r')
			;
		cout << endl;
		if (result >= solution.goal) {
			cct_setcolor(COLOR_HYELLOW, COLOR_RED);
			cout << "已经合成到" << solution.goal;
			cct_setcolor(COLOR_BLACK);
			cout << endl << "按回车键继续向更高目标进发...";
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
	int MX, MY, MAction = 0, keycode1, keycode2/*判断键盘所指方向*/;
	while (1) {
		keyboard_mouse('8');
		show_color(solution.x, solution.y);
		cct_enable_mouse();
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (keycode1 == '\r' || MAction == MOUSE_MOVED) {
			combine_color();
			cct_showstr(0, 4 * (solution.row + 1) - 1, "合成完成，回车键/单击左键下落0                   ");
			cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
			if (keycode1 == '\r' || MAction == MOUSE_LEFT_BUTTON_CLICK) {
				fall_color();
				cct_showstr(0, 4 * (solution.row + 1) - 1, "下落0完成，回车键/单击左键填充新值                  ");
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
	cct_showstr(0, 4 * (solution.row + 1) - 1, "本次合成结束，按C/鼠标左键继续下一次合成", COLOR_BLACK, COLOR_YELLOW);
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
		cout << "本次得分：" << solution.score << " 总得分：" << solution.total << " 合成目标：" << solution.goal << "       ";
		combine_color();
		Sleep(DELAY * 10);
		fall_color();
		Sleep(DELAY * 10);
		fill_color();
		if (solution.combine_num >= solution.goal) {
			cct_gotoxy(0, 0);
			cct_setcolor(COLOR_HYELLOW, COLOR_RED);
			cout << "已经合成到" << solution.goal;
			cct_setcolor(COLOR_BLACK);
			cout << "继续向更高目标进发...          ";
			solution.goal++;
		}
	}
	to_be_continued('6');
}
