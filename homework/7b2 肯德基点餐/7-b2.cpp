/*2151133 孙韩雅 信07*/
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
	{'A', "香辣鸡腿堡",         18.5},
	{'B', "劲脆鸡腿堡",         18.5},
	{'C', "新奥尔良烤鸡腿堡",   19},
	{'D', "老北京鸡肉卷",       17},
	{'E', "川辣嫩牛卷",         19.5},
	{'F', "深海鳕鱼堡",         18.5},
	{'G', "吮指原味鸡(1块)",    11.5},
	{'H', "芝芝肉酥热辣脆皮鸡", 12.5},
	{'I', "新奥尔良烤翅(2块)",  12.5},
	{'J', "劲爆鸡米花",         11.5},
	{'K', "香辣鸡翅(2块)",      12.0},
	{'L', "藤椒无骨大鸡柳(2块)",12.5},
	{'M', "鲜蔬色拉",           13},
	{'N', "薯条(小)",           9},
	{'O', "薯条(中)",           12},
	{'P', "薯条(大)",           14},
	{'Q', "芙蓉蔬荟汤",         9},
	{'R', "原味花筒冰激凌",     6},
	{'S', "醇香土豆泥",         7},
	{'T', "香甜粟米棒",         9.0},
	{'U', "葡式蛋挞",           8.0},
	{'V', "百事可乐(小)",       7.0},
	{'W', "百事可乐(中)",       9.5},
	{'X', "百事可乐(大)",       11.5},
	{'Y', "九珍果汁饮料",       12.5},
	{'Z', "纯纯玉米饮",         11.5},
	{'\0', NULL,                0}
};
const struct SPECIAL special[] = {
	//	{"ANV", "香辣鸡腿堡工作日午餐",  24 }, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
		{"BMV", "劲脆鸡腿堡超值套餐",    26},
		{"ABCGGIIKKOUWWW", "超值全家桶", 115},
		{"KIIRRJUWW", "缤纷小吃桶",      65},
		{"JJ","劲爆鸡米花(2份小)",       12.5},
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
	cout << "                       KFC 2021秋季菜单                       " << endl;
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

	cout << endl << "【优惠信息】：" << endl;
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

	cout << endl << "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl << endl;

}

void clear()
{
	int  j;
	for (j = 0; j < 26; j++)
		use.letter[j] = 0;
	use.num = 0;

}//重置

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
		cout << "请点单: ";
		cin >> order;
		if (order[0] == '0')
			break;
		for (i = 0; order[i] != 0; i++) {
			if (!(order[i] > 64 && order[i] < 91) && !(order[i] < 123 && order[i]>96)) {
				wait_for_enter("输入错误，按任意键继续.");
				right = 0;
				break;
			}
			else if (order[i] < 123 && order[i]>96)
				order[i] -= 32;
		}
		if (right) {
			cout << "您的点餐=";
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
			//开始思维炼狱
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
			cout << endl << "共计" << total << "元" << endl;
			wait_for_enter("点单完成，按任意键继续.");
		}
	}
}
//abcdefghasdgasjhdskhxja;