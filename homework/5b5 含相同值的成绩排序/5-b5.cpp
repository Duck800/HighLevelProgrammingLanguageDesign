/*2151133 �ﺫ�� ��07*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int a[1000] = { 0 };
	cout << "������ɼ������1000��������-1����" << endl;
	int i, time = -1;

	for (i = 0; i < 1000; i++) {
		cin >> a[i];
		time++;
		if (a[i] < 0)
			break;
	}

	a[time] = 0;
	if (a[0] < 0)
		cout << "����Ч����" << endl;

	else {
		cout << "���������Ϊ:" << endl;
		for (i = 0; i < time; i++) {
			cout << a[i] << " ";
			if ((i + 1) % 10 == 0 || i + 1 == time)
				cout << endl;
		}
		cout << "���������εĶ�Ӧ��ϵΪ:" << endl;

		int mid, j;
		for (i = 0; i < time; i++) {
			for (j = 0; j < time - i; j++) {
				if (a[j] < a[j + 1]) {
					mid = a[j];
					a[j] = a[j + 1];
					a[j + 1] = mid;
				}
			}
		}

		int sum, m;
		int total[1000] = { 0 };
		for (i = 0; i < time; i += sum) {
			for (j = i, sum = 0; j < time; j++) {
				if (a[i] == a[j])
					sum++;
			}
			for (m = i; m < i + sum; m++) {
				total[m] = sum;
			}
		}

		int rank = 1;
		for (i = 0; i < time; i++) {
			if (a[i] == a[i + 1])
				cout << a[i] << " " << rank << endl;
			else {
				cout << a[i] << " " << rank << endl;
				rank += total[i];
			}
		}
	}
}