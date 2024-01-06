/*2151133 孙韩雅 信07*/
#include<iostream>
#include<iomanip>
using namespace std;

int zeller(int y, int m, int d) {
	int w, c, i;
	if (m > 2) {
		i = y % 100;
		c = (y - i) / 100;
	}
	else {
		m += 12;
		y -= 1;
		i = y % 100;
		c = (y - i) / 100;
	}
	w = i + (int)(i / 4) + (int)(c / 4) - 2 * c + (int)(13 * (m + 1) / 5) + d - 1;
	w = (w + 28) % 7;
	return w;
}

void calendar(int y, int mon1, int mon2, int mon3) {
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int row[6][21];/*这个数组是在CSDN看到的，属于醍醐灌顶级别的*/
	int i, j/*循环控制*/, leap/*闰年判断*/;
	int w1 = zeller(y, mon1, 1), w2 = zeller(y, mon2, 1), w3 = zeller(y, mon3, 1);

	leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0 ? mon[1] = 29 : mon[1] = 28;

	int sum = 0;
	for (i = 0; i < 6; i++) {
		
		for (j = 0; j < 7; j++) {
			row[i][j] = i * 7 + j - w1 + 1;
			if (row[i][j] > mon[mon1 - 1] || row[i][j] < 0)
				row[i][j] = 0;
		}
		for (j = 7; j < 14; j++) {
			row[i][j] = i * 7 + j - w2 - 6;
			if (row[i][j] > mon[mon2 - 1] || row[i][j] < 0)
				row[i][j] = 0;
		}
		for (j = 14; j < 21; j++) {
			row[i][j] = i * 7 + j - w3 - 13;
			if (row[i][j] > mon[mon3 - 1] || row[i][j] < 0)
				row[i][j] = 0;
		}
		for (j = 0; j < 21; j++) {
			if (row[5][j] == 0)
				sum++;
		}
	}
	cout << "           " << setiosflags(ios::right) <<setw(2) << mon1 << "月                            " << setw(2) << mon2 << "月                            " << setw(2) << mon3 << "月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	cout << resetiosflags(ios::right);
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 21; j++) {
			if (row[i][j] != 0)
				cout << setiosflags(ios::left) << setw(4) << row[i][j];
			else if (i != 5 || sum != 21)
				cout << "    ";
			if (j == 6 || j == 13)
				if (i != 5 || sum != 21)
					cout << setw(4) << " ";
			if (j == 20) {
				if (i != 5 || sum != 21)
					cout << endl;
			}
		}
	}
	cout << endl;
}

int main() {
	system("mode con cols=120 lines=45");
	int year;
	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		if (cin.fail()|| year > 2100 || year < 1900) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			break;
	}
	cout << year << "年的日历:" << endl << endl;

	calendar(year, 1, 2, 3);
	calendar(year, 4, 5, 6);
	calendar(year, 7, 8, 9);
	calendar(year, 10, 11, 12);

	cout << endl;
	return 0;
}