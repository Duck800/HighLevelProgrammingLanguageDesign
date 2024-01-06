/*2151133 孙韩雅 信07*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include "cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include "90-b2.h"
using namespace std;

/*重置数组*/
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

/*等待返回函数*/
void to_be_continued(char choice)
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setcolor(); //恢复缺省颜色
	if (choice == '5')
		cct_showstr(0, 3 * (solution.row + 1) + 1, "本小题结束，请输入End继续...");
	else if (choice == '6')
		cct_showstr(0, 4 * (solution.row + 1), "本小题结束，请输入End继续...");
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
					cout << "输入错误，请重新输入";
					cct_gotoxy(X, Y);
					cout << "      ";
					cct_gotoxy(X, Y);
					continue;
				}
			}
			else {
				cout << "输入错误，请重新输入";
				cct_gotoxy(X, Y);
				cout << "      ";
				cct_gotoxy(X, Y);
				continue;
			}
		}
		else {
			cout << "输入错误，请重新输入";
			cct_gotoxy(X, Y);
			cout << "      ";
			cct_gotoxy(X, Y);
			continue;
		}
	}
}

/*共用输入函数*/
int input_row()
{
	int row;
	while (1) {
		cout << "请输入行数(5-8)：" << endl;
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
		cout << "请输入列数(5-10)：" << endl;
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
		cout << "请输入合成目标(5-20)：";
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


/*共用输出函数*/
/*输出当前数组（未标记）*/
void output_record_normal()
{
	/*循环控制*/int i, j;
	cout << endl << "当前数组：" << endl;
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
/*查找结果数组*/
void output_sign()
{
	cout << endl << "查找结果数组：" << endl;
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
		for (j = 0; j < solution.column; j++)
			cout << solution.sign[i][j] << "  ";
		cout << endl;
	}
}
/*输出当前数组（标记颜色）*/
void output_record_sign()
{
	/*循环控制*/int i, j;
	cout << endl << "当前数组：" << endl;
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
/*输出合并后数组*/
void output_combine()
{
	/*循环控制*/int i, j;
	cout << endl << "相同值归并后的数组(不同色标识)：" << endl;
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

/*从键盘鼠标读数*/
void keyboard_mouse(char choice)
{
	/*循环变量*/int i/*记录行*/ = 0, j, m/*记录列*/ = 0, n;
	int old_row = 0, old_column = 0;
	bool first = 0;
	int MX, MY, MAction = 0, keycode1, keycode2/*判断键盘所指方向*/;
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
			cout << "箭头键/鼠标移动，回车键/单击左键选择并结束                         ";
			first++;
		}
		cct_enable_mouse();
		cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (keycode1 == '\r') {
			if (choice == '7') {
				solution.count = 1;
				cct_gotoxy(0, 4 * (solution.row + 1) - 1);
				cct_setcolor();
				cout << "选中了" << char(i + 'A') << "行" << m << "列                             " << endl;
				break;
			}
			else if (choice == '8') {
				solution.sign[i][m] = '*';
				assign_sign(1, '1');
				if (solution.count == 0) {
					cct_gotoxy(0, 4 * (solution.row + 1) - 1);
					cct_showstr(0, 4 * (solution.row + 1) - 1, "周围无相同值，", COLOR_BLACK, COLOR_YELLOW);
					cct_setcolor();
					cout << "箭头键/鼠标移动，回车键/单击左";
				}
				else {
					cct_gotoxy(0, 4 * (solution.row + 1) - 1);
					cct_setcolor();
					cout << "选中了" << char(i + 'A') << "行" << m << "列,回车/单击左继续合并" << endl;
					break;
				}
			}
		}
		else if (keycode2 == 77) {
			if (m < solution.column - 1) {
				old_column = m;
				old_row = i;
				m++;//→
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
				m--;//←
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
				i--;//↑
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
				i++;//↓
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
			cout << "[当前键盘]" << char(i + 'A') << "行" << m << "列                         ";
		}
		int mx = (MX - 4) / 8, my = (MY - 3) / 4;
		int k;
		bool legal = 1;
		cct_gotoxy(0, 4 * (solution.row + 1));
		cct_setcolor();
		if (MAction == MOUSE_MOVED) {
			for (k = 0; k < solution.row; k++) {
				if (MY == 4 * k + 6 || MY < 3 || MY>4 * (solution.row - 1) + 6) {
					cct_showstr(0, 4 * (solution.row + 1) - 1, "[当前鼠标]位置非法                         ");
					legal = 0;
					break;
				}
			}
			for (k = 0; k < solution.column; k++) {
				if (MX == 8 * k + 10 || mx == 8 * k + 11 || MX < 4 || MX>8 * (solution.column - 1) + 10) {
					cct_showstr(0, 4 * (solution.row + 1) - 1, "[当前鼠标]位置非法                         ");
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
				cout << "[当前鼠标]" << char(i + 'A') << "行" << m << "列                         ";
			}
		}
		else if (MAction == MOUSE_LEFT_BUTTON_CLICK) {
			if (choice == '7') {
				solution.count = 1;
				cct_gotoxy(0, 4 * (solution.row + 1) - 1);
				cct_setcolor();
				cout << "选中了" << char(i + 'A') << "行" << m << "列                             " << endl;
				break;
			}
			else if (choice == '8') {
				solution.sign[i][m] = '*';
				assign_sign(1, '1');
				if (solution.count == 0) {
					cct_gotoxy(0, 4 * (solution.row + 1) - 1);
					cct_showstr(0, 4 * (solution.row + 1) - 1, "周围无相同值，", COLOR_BLACK, COLOR_YELLOW);
					cct_setcolor();
					cout << "箭头键/鼠标移动，回车键/单击左";
				}
				else if (MAction == MOUSE_LEFT_BUTTON_CLICK) {
					cct_gotoxy(0, 4 * (solution.row + 1) - 1);
					cct_setcolor();
					cout << "选中了" << char(i + 'A') << "行" << m << "列,回车/单击左继续合并" << endl;
						break;
				}
			}
		}
	}
	solution.x = i;
	solution.y = m;
}//修改

void combine(int x,int y)
{
	solution.combine_num = ++solution.record[x][y];
	/*循环控制*/int m, n;
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
	cout << endl << "请确认是否把相邻的相同值合并到" << char(x + 65) << char(y + 48) << "中(Y/N/Q)：";
	while (1) {
		char in = _getch();
		if (in == 'Y' || in == 'y') {
			cout << in << endl;
			combine(x, y);
			output_combine();
			/*计算得分*/
			solution.score = 3 * (solution.record[x][y] - 1) * (solution.count + 1);
			solution.total += solution.score;
			cout << "本次得分：" << solution.score << " 总得分：" << solution.total << " 合成目标：" << solution.goal << endl;
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
/*检查是否有可合并的值*/
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
}//待验证