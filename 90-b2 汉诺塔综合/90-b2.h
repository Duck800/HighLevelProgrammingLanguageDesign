#pragma once

#define ROW  8
#define COLUMN  10
#define DELAY  1

struct compound
{
	int row, column, goal;
	int record[ROW][COLUMN];
	char sign[ROW][COLUMN] = { 0 };
	/*ѡ���ĺ������꣨����8.9��*/int x, y;
	/*��ֵͬ��������������λ�ã�*/int count = 0;
	/*�ϲ����λ�õ�ֵ*/int combine_num = 0;
	/*���ε÷�*/int score = 0;
	/*�ܵ÷�*/int total = 0;
};
extern struct compound solution;

/*�ȴ����غ���*/
void to_be_continued(char choice);
/*�˵�����*/
char menu();
/*�������뺯��*/
int input_row();
int input_column();
int input_goal();
char input_x();
char input_y();
/*���ú���*/
void reset();
/*���������*/
void set();
/*�����ǰ����*/
void output_record_normal();
/*���ҽ������*/
void output_sign();
/*���Ǻź���*/
void assign_sign(int count, char choice);
/*�����ǰ���飨�����ɫ��*/
void output_record_sign();
/*�����ǰ���飨��ɫ���/�����ߣ�*/
void output_record_color();
/*�����ǰ���飨��ɫ���/�����ߣ�*/
void output_record_color_line();
/*����ϲ�������*/
void output_combine();

/*����һ�뷽�����ϲ�*/
void project(char choice);
/*����Ƿ��пɺϲ���ֵ*/
int check();
/*�ϲ�ֵ*/
void combine(int x, int y);
/*��������*/
void fall();
/*��ӡ���������*/
void output_fall();
/*��ֵ���*/
void fill();
void fill_color();
/*��������������*/
void random(int* result);

char confirm(char x, char y);

/*��ӡ�Ʊ��*/
void table_sign(int i, int j, int m, int n, int old_row, int old_column, const char* ch, int color);
void form(int i, int m, int old_row, int old_column,int color);
/*ѡ�к���ʾ���ϲ�������*/
void show_color(int i, int m);
void combine_color();
void fall_color();

/*�Ӽ���������*/
void keyboard_mouse(char choice);

void project_3(char choice);
void project_4(char choice);
void project_5(char choice);
void project_6_7(char choice);
void project_8();
void project_9();
