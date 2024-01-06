/*2151133 孙韩雅 信07*/
#include<iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
   ----------------------------------------------------------------------------------- */
void left(char end_ch,char start_ch,char i)
{
	if (end_ch >= start_ch) {
		if (i > end_ch) {
			cout << " ";
			i--;
			left(end_ch, start_ch, i);
		}
		else {
			cout << end_ch;
			left(end_ch - 1, start_ch, i - 1);
		}
	}
}

void right(char end_ch, char start_ch, char i)
{
	if (end_ch > start_ch) {
		if (i >= end_ch) {
			cout << char(start_ch + 1);
			start_ch++;
			right(end_ch, start_ch, i);
		}
	}
}

void down_left(char end_ch, char start_ch, char i)
{
	if (end_ch >= start_ch) {
		if (i > end_ch) {
			cout << " ";
			i--;
			left(end_ch, start_ch, i);
		}
		else {
			cout << end_ch;
			left(end_ch - 1, start_ch, i - 1);
		}
	}
}

void up(char end_ch, char start_ch, char i, char j)
{
	if (j <= i) {
		left(j, start_ch, i);
		right(j, start_ch, i);
		cout << endl;
		j++;
		up(end_ch, start_ch, i, j);
	}
}

void down(char end_ch, char start_ch, char i, char j)
{
	if (j <= i) {
		down_left(i - 1, start_ch, end_ch);
		right(i - 1, start_ch, end_ch);
		if (j < i)
			cout << endl;
		down(end_ch, start_ch, i - 1, j);
	}
}


   /***************************************************************************
	 函数名称：
	 功    能：打印菱形
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
void print_diamond(char start_ch, char end_ch)
{
	const char i = end_ch;
	const char j = 65;
	up(end_ch, start_ch, i, j);
	down(end_ch, start_ch, i, j);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中两处...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();

	/* 菱形(中间为A) */
	cout << setfill('=') << setw((int)end_ch + (int)end_ch - (int)129) << "=" << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((int)end_ch + (int)end_ch - (int)129) << "=" << endl; /* 按菱形最大宽度输出=(不允许用循环) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}