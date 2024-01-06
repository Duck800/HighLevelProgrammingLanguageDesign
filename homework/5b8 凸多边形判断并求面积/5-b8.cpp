/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <cmath>
using namespace std;

void tell(double a[][2], int num)
{
	int j;
	double s = 0;
	bool error = 0;
	double v0 = (a[1][0] - a[0][0]) * (a[2][1] - a[0][1]) - (a[2][0] - a[0][0]) * (a[1][1] - a[0][1]);
	for (j = 0; j < num - 2; j++) {
		double x1 = a[j + 1][0] - a[j][0], x2 = a[j + 2][0] - a[j][0];
		double y1 = a[j + 1][1] - a[j][1], y2 = a[j + 2][1] - a[j][1];
		double v = x1 * y2 - x2 * y1;
		if (v == 0 || v * v0 < 0) {
			cout << "����͹" << num << "����" << endl;
			error = 1;
			break;
		}
	}
	if (!error) {
		for (j = 1; j < num - 1; j++) {
			double x1 = a[j][0] - a[0][0], x2 = a[j + 1][0] - a[0][0];
			double y1 = a[j][1] - a[0][1], y2 = a[j + 1][1] - a[0][1];
			s += fabs(x1 * y2 - x2 * y1);
		}
		cout << "͹" << num << "���ε����=" << s / 2;
	}
}

int main()
{
	int num, i;
	double coor[7][2];
	while (1) {
		cout << "���������εĶ�������(4-7)" << endl;
		cin >> num;
		if (num < 4 || num > 7) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else
			break;
	}
	cout << "�밴˳ʱ��/��ʱ�뷽������5�������x, y���꣺" << endl;

	for (i = 0; i < num; ) {
		cout << "�������" << i + 1 << "����������꣺" << endl;
		cin >> coor[i][0];
		cin >> coor[i][1];
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else
			i++;
	}
	tell(coor, num);
}