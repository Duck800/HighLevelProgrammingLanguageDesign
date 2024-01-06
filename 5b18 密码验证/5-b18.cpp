/*2151133 Ëïº«ÑÅ ÐÅ07*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include <cstdio>
using namespace std;

int main()
{
	const char choose[] = "~!@#$%^&*()-_=+[],.?";
	int length, upper, lower, number, other;
	char password[11][16] = { 0 };
	cin.ignore(65535, '\n');
	cin >> length;
	cin.clear();
	cin.ignore(65535, ' ');
	cin >> upper;
	cin.clear();
	cin.ignore(65535, ' ');
	cin >> lower;
	cin.clear();
	cin.ignore(65535, ' ');
	cin >> number;
	cin.clear();
	cin.ignore(65535, ' ');
	cin >> other;
	cin.clear();
	cin.ignore(65535, '\n');
	/*Ñ­»·¿ØÖÆ*/int i, j;
	for (i = 0; i < 10; i++)
		cin >> password[i];

	int correct = 0;
	for (i = 0; i < 10; i++) {
		int count = 0, up = 0, low = 0, num = 0, oth = 0;
		for (j = 0; j < 16; j++) {
			if (password[i][j] != 0) {
				count++;
				if (password[i][j] > 47 && password[i][j] < 58)
					num++;
				else if (password[i][j] > 64 && password[i][j] < 91)
					up++;
				else if (password[i][j] > 96 && password[i][j] < 123)
					low++;
				else {
					int m ;
					for (m = 0; m < 20; m++) {
						if (strncmp(password[i] + j, choose + m, 1) == 0)
							oth++;
					}
				}
				
			}
		}
		if (count != up + low + num + oth) {
			cout << "´íÎó" << endl;
			break;
		}
		else if (count != length) {
			cout << "´íÎó" << endl;
			break;
		}
		else if (up < upper) {
			cout << "´íÎó" << endl;
			break;
		}
		else if (low < lower) {
			cout << "´íÎó" << endl;
			break;
		}
		else if (num < number) {
			cout << "´íÎó" << endl;
			break;
		}
		else if (oth < other) {
			cout << "´íÎó" << endl;
			break;
		}
		else 
			correct++;
	}
	if (correct == 10)
		cout << "ÕýÈ·" << endl;
}