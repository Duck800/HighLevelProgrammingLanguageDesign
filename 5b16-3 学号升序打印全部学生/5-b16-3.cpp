/*2151133 �ﺫ�� ��07*/
#include <iostream> 
#include <iomanip> 
using namespace std;

void input(string number[10], string name[10], int score[10])
{
	/*ѭ������*/int i;
	for (i = 0; i < 10; i++) {
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> number[i];
		cin >> name[i];
		cin >> score[i];
		fflush(stdin);
	}
}

void output(string number[10], string name[10], int score[10])
{
	cout << endl;
	cout << "ȫ��ѧ��(ѧ������):" << endl;
	/*ѭ������*/int i;
	for (i = 0; i < 10; i++) {
		cout << name[i] << " ";
		cout << number[i] << " ";
		cout << score[i] << endl;

	}
}

void rank_(string number[10], string name[10], int score[10])
{
	int i, j;
	int mid_sco;
	string mid_num, mid_name;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (number[j] > number[j + 1]) {
				mid_num = number[j + 1];
				number[j + 1] = number[j];
				number[j] = mid_num;
				mid_name = name[j + 1];
				name[j + 1] = name[j];
				name[j] = mid_name;
				mid_sco = score[j + 1];
				score[j + 1] = score[j];
				score[j] = mid_sco;
			}
		}
	}
	output(number, name, score);
}


int main()
{
	string number[10];
	string name[10];
	int score[11] = { 0 };
	input(number, name, score);
	rank_(number, name, score);
}
