/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
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
	 �������ƣ�
	 ��    �ܣ���ӡ����
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void print_diamond(char start_ch, char end_ch)
{
	const char i = end_ch;
	const char j = 65;
	up(end_ch, start_ch, i, j);
	down(end_ch, start_ch, i, j);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main����������...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();

	/* ����(�м�ΪA) */
	cout << setfill('=') << setw((int)end_ch + (int)end_ch - (int)129) << "=" << endl; /* ��������������=(��������ѭ��) */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((int)end_ch + (int)end_ch - (int)129) << "=" << endl; /* ��������������=(��������ѭ��) */
	print_diamond('A', end_ch);
	cout << endl;

	return 0;
}