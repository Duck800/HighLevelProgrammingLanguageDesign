#pragma once

#define ROW  8
#define COLUMN  10
#define DELAY  1

struct compound
{
	int row, column, goal;
	int record[ROW][COLUMN];
	char sign[ROW][COLUMN] = { 0 };
	/*选定的横纵坐标（用于8.9）*/int x, y;
	/*相同值个数（不包括该位置）*/int count = 0;
	/*合并后该位置的值*/int combine_num = 0;
	/*本次得分*/int score = 0;
	/*总得分*/int total = 0;
};
extern struct compound solution;

/*等待返回函数*/
void to_be_continued(char choice);
/*菜单函数*/
char menu();
/*共用输入函数*/
int input_row();
int input_column();
int input_goal();
char input_x();
char input_y();
/*重置函数*/
void reset();
/*设置随机数*/
void set();
/*输出当前数组*/
void output_record_normal();
/*查找结果数组*/
void output_sign();
/*赋星号函数*/
void assign_sign(int count, char choice);
/*输出当前数组（标记颜色）*/
void output_record_sign();
/*输出当前数组（纯色输出/无虚线）*/
void output_record_color();
/*输出当前数组（纯色输出/有虚线）*/
void output_record_color_line();
/*输出合并后数组*/
void output_combine();

/*方案一与方案二合并*/
void project(char choice);
/*检查是否有可合并的值*/
int check();
/*合并值*/
void combine(int x, int y);
/*数组下落*/
void fall();
/*打印下落后数组*/
void output_fall();
/*新值填充*/
void fill();
void fill_color();
/*按概率输出随机数*/
void random(int* result);

char confirm(char x, char y);

/*打印制表符*/
void table_sign(int i, int j, int m, int n, int old_row, int old_column, const char* ch, int color);
void form(int i, int m, int old_row, int old_column,int color);
/*选中后显示、合并与下落*/
void show_color(int i, int m);
void combine_color();
void fall_color();

/*从键盘鼠标读数*/
void keyboard_mouse(char choice);

void project_3(char choice);
void project_4(char choice);
void project_5(char choice);
void project_6_7(char choice);
void project_8();
void project_9();
