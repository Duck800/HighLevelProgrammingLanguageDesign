/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include<iomanip>
#include <conio.h>
#include"cmd_console_tools.h"
using namespace std;

const int N = 4;
const int M = 6666;

const struct KFC {
	char choice;
	const char name[65535];
	double price;
};
const struct SPECIAL {
	const char choice[65535];
	const char combine[65535];
	double price;
};
const struct KFC list[] = {
	{'A', "�������ȱ�",         18.5},
	{'B', "���༦�ȱ�",         18.5},
	{'C', "�°¶��������ȱ�",   19},
	{'D', "�ϱ��������",       17},
	{'E', "������ţ��",         19.5},
	{'F', "����㱤",         18.5},
	{'G', "˱ָԭζ��(1��)",    11.5},
	{'H', "֥֥����������Ƥ��", 12.5},
	{'I', "�°¶�������(2��)",  12.5},
	{'J', "�������׻�",         11.5},
	{'K', "��������(2��)",      12.0},
	{'L', "�ٽ��޹Ǵ���(2��)",12.5},
	{'M', "����ɫ��",           13},
	{'N', "����(С)",           9},
	{'O', "����(��)",           12},
	{'P', "����(��)",           14},
	{'Q', "ܽ��������",         9},
	{'R', "ԭζ��Ͳ������",     6},
	{'S', "����������",         7},
	{'T', "�������װ�",         9.0},
	{'U', "��ʽ��̢",           8.0},
	{'V', "���¿���(С)",       7.0},
	{'W', "���¿���(��)",       9.5},
	{'X', "���¿���(��)",       11.5},
	{'Y', "�����֭����",       12.5},
	{'Z', "����������",         11.5},
	{'\0', NULL,                0}
};
const struct SPECIAL special[] = {
	//	{"ANV", "�������ȱ����������",  24 }, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"BMV", "���༦�ȱ���ֵ�ײ�",    26},
		{"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115},
		{"KIIRRJUWW", "�ͷ�С��Ͱ",      65},
		{"JJ","�������׻�(2��С)",       12.5},
		{NULL, NULL, 0}
};
struct LETTER {
	double sletter[N][26] = { 0 };
	int stop;
	int snum[N] = { 0 };
	double letter[26] = { 0 };
	int num = 0;
}use;

void wait_for_enter(const char *str)
{
	cout << endl << str;
	while (_getch() == 0)
		;
	cout << endl << endl;
}
void menu()
{
	cout << "==============================================================" << endl;
	cout << "                       KFC 2021�＾�˵�                       " << endl;
	cout << "==============================================================" << endl;
	int i, j;
	for (i = 0; i < 26; i++) {
		cout << " " << list[i].choice << " " << setiosflags(ios::left) << setw(20) << list[i].name << " " << setw(7) << list[i].price;
		cout << resetiosflags(ios::right);
		if (i % 2 != 0)
			cout << endl;
		else
			cout << "|";
	}

	cout << endl << "���Ż���Ϣ����" << endl;
	for (i = 0; i < N; i++) {
		for (j = 0; special[i].choice[j] != 0; j++) 
			use.sletter[i][special[i].choice[j] - 'A']++;
		cout << special[i].combine << "=";
		for (j = 0; j < 26; j++) {
			if (use.sletter[i][j] != 0) {
				use.snum[i]++;
				use.stop = j;
			}
		}
		for (j = 0; j < 26; j++) {
			if (use.sletter[i][j] != 0) {
				if (use.sletter[i][j] == 1)
					cout << list[j].name;
				else
					cout << list[j].name << "*" << use.sletter[i][j];
				if (j != use.stop)
					cout << "+";
			}
		}
		cout << "=" << special[i].price;
		cout << endl;
	}

	cout << endl << "���������˵������" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl << endl;

}

void clear()
{
	int  j;
	for (j = 0; j < 26; j++)
		use.letter[j] = 0;
	use.num = 0;

}//����

int main()
{
	system("mode con cols=120 lines=35");
	while (1) {
		cct_cls();
		clear();
		menu();	
		char order[M] = { 0 };
		int i, j, top = 0;
		double total = 0;
		bool right = 1;
		cout << "��㵥: ";
		cin >> order;
		if (order[0] == '0')
			break;
		for (i = 0; order[i] != 0; i++) {
			if (!(order[i] > 64 && order[i] < 91) && !(order[i] < 123 && order[i]>96)) {
				wait_for_enter("������󣬰����������.");
				right = 0;
				break;
			}
			else if (order[i] < 123 && order[i]>96)
				order[i] -= 32;
		}
		if (right) {
			cout << "���ĵ��=";
			for (i = 0; order[i] != 0; i++) 
				use.letter[order[i] - 'A']++;
			for (i = 0; i < 26; i++) {
				if (use.letter[i] != 0)
					top = i;
			}
			for (i = 0; i < 26; i++) {
				if (use.letter[i] != 0) {
					if (use.letter[i] == 1)
						cout << list[i].name;
					else
						cout << list[i].name << "*" << use.letter[i];
					if (i != top)
						cout << "+";
				}
			}
			//��ʼ˼ά����
			for (i = 0; i < N;) {
				for (j = 0; j < 26; j++) {
					if (use.sletter[i][j] != 0) {
						if (use.letter[j] >= use.sletter[i][j])
							use.num++;
					}
				}
				if (use.num == use.snum[i]) {
					total += special[i].price;
					for (j = 0; j < 26; j++) 
						use.letter[j] -= use.sletter[i][j];
				}
				else 
					i++;
				use.num = 0;
				
			}
			for (j = 0; j < 26; j++) 
				total += (list[j].price) * use.letter[j];
			//
			cout << endl << "����" << total << "Ԫ" << endl;
			wait_for_enter("�㵥��ɣ������������.");
		}
	}
}
//abcdefghasdgasjhdskhxja;