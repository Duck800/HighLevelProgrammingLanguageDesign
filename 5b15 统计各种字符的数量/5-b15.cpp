/*2151133 孙韩雅 信07*/
#include <iostream>
#include <cstdio>
#include <conio.h>
using namespace std;


int main()
{
	char str[3][128] = { 0 };
	cout << "请输入第1行" << endl;
	/*循环控制*/int i, j;
	for (i = 0; i < 128; i++) {
		str[0][i] = cin.get();
		if (str[0][i] == '\n')
			break;
	}
	cout << "请输入第2行" << endl;
	for (i = 0; i < 128; i++) {
		str[1][i] = cin.get();
		if (str[1][i] == '\n')
			break;
	}
	cout << "请输入第3行" << endl;
	for (i = 0; i < 128; i++) {
		str[2][i] = cin.get();
		if (str[2][i] == '\n')
			break;
	}
	/*大小写*/int upper = 0, lower = 0;
	/*数字*/int num = 0;
	/*空格*/int space = 0;
	/*其他*/int other = 0;
	for (j = 0; j < 3; j++) {
		for (i = 0; i < 128; i++) {
			if (str[j][i] >= 'A' && str[j][i] <= 'Z')
				upper++;
			else if (str[j][i] >= 'a' && str[j][i] <= 'z')
				lower++;
			else if (str[j][i] >= '0' && str[j][i] <= '9')
				num++;
			else if (str[j][i] == ' ')
				space++;
			else if (str[j][i] != 0)
				other++;
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 128; j++) {
			cout << str[i][j] << " ";
		}
	}

	cout << "大写 : " << upper << endl;
	cout << "小写 : " << lower << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << other - 3 << endl;
}