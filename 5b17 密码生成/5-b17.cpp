/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include <cstdio>
using namespace std;

void generate(int length, int upper, int lower, int number, int other)
{
	const char choose[] = "~!@#$%^&*()-_=+[],.?ABCDEFGHIJKLMNOPQRSTUVWXTZabcdefghijklmnopqrstuvwxyz0123456789";
	char password[16] = { 0 };
	/*循环控制*/int i;
	for (i = 0; i < upper; ) {
		int position = rand() % length;
		if (password[position] == 0) {
			password[position] = rand() % 26 + 65;
			i++;
		}
		else
			continue;
	}
	for (i = 0; i < lower; ) {
		int position = rand() % length;
		if (password[position] == 0) {
			password[position] = rand() % 26 + 97;
			i++;
		}
		else
			continue;
	}
	for (i = 0; i < number; ) {
		int position = rand() % length;
		if (password[position] == 0) {
			password[position] = rand() % 10 + 48;
			i++;
		}
		else
			continue;
	}
	for (i = 0; i < other; ) {
		int position = rand() % length;
		if (password[position] == 0) {
			strncpy(password + position, choose + rand() % 20, 1);
			i++;
		}
		else
			continue;
	}
	for (i = 0; i < length; i++) {
		if (password[i] == 0)
			strncpy(password + i, choose + rand() % 82, 1);
		cout << password[i];
	}
	cout << endl;
}

int main()
{
	int length, upper, lower, number, other;
	cout << "请输入密码长度(12 - 16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;

	cin >> length;
	if (cin.fail())
		cout << "输入非法" << endl;
	else if (length < 12 || length>16)
		cout << "密码长度[" << length << "]不正确" << endl;
	else {
		cin >> upper;
		if (cin.fail())
			cout << "输入非法" << endl;
		else if (upper < 2 || upper>length)
			cout << "大写字母个数[" << upper << "]不正确" << endl;
		else {
			cin >> lower;
			if (cin.fail())
				cout << "输入非法" << endl;
			else if (lower < 2 || lower > length)
				cout << "小写字母个数[" << lower << "]不正确" << endl;
			else {
				cin >> number;
				if (cin.fail())
					cout << "输入非法" << endl;
				else if (number < 2 || number > length)
					cout << "数字个数[" << number << "]不正确" << endl;
				else {
					cin >> other;
					if (cin.fail())
						cout << "输入非法" << endl;
					else if (other < 2 || other > length)
						cout << "其他符号个数[" << number << "]不正确" << endl;
					else {
						if (upper + lower + number + other > length)
							cout << "所有字符类型之和[" << upper << "+" << lower << "+" << number << "+" << other << "]大于总密码长度[" << length << "]" << endl;
						else {
							cout << length << " " << upper << " " << lower << " " << number << " " << other << endl;
							/*循环控制*/int i;
							for (i = 0; i < 10; i++) {
								srand(i);
								generate(length, upper, lower, number, other);
							}
						}
					}
				}
			}
		}
	}

}