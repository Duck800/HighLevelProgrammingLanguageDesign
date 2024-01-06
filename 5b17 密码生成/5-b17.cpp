/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include <cstdio>
using namespace std;

void generate(int length, int upper, int lower, int number, int other)
{
	const char choose[] = "~!@#$%^&*()-_=+[],.?ABCDEFGHIJKLMNOPQRSTUVWXTZabcdefghijklmnopqrstuvwxyz0123456789";
	char password[16] = { 0 };
	/*ѭ������*/int i;
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
	cout << "���������볤��(12 - 16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;

	cin >> length;
	if (cin.fail())
		cout << "����Ƿ�" << endl;
	else if (length < 12 || length>16)
		cout << "���볤��[" << length << "]����ȷ" << endl;
	else {
		cin >> upper;
		if (cin.fail())
			cout << "����Ƿ�" << endl;
		else if (upper < 2 || upper>length)
			cout << "��д��ĸ����[" << upper << "]����ȷ" << endl;
		else {
			cin >> lower;
			if (cin.fail())
				cout << "����Ƿ�" << endl;
			else if (lower < 2 || lower > length)
				cout << "Сд��ĸ����[" << lower << "]����ȷ" << endl;
			else {
				cin >> number;
				if (cin.fail())
					cout << "����Ƿ�" << endl;
				else if (number < 2 || number > length)
					cout << "���ָ���[" << number << "]����ȷ" << endl;
				else {
					cin >> other;
					if (cin.fail())
						cout << "����Ƿ�" << endl;
					else if (other < 2 || other > length)
						cout << "�������Ÿ���[" << number << "]����ȷ" << endl;
					else {
						if (upper + lower + number + other > length)
							cout << "�����ַ�����֮��[" << upper << "+" << lower << "+" << number << "+" << other << "]���������볤��[" << length << "]" << endl;
						else {
							cout << length << " " << upper << " " << lower << " " << number << " " << other << endl;
							/*ѭ������*/int i;
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