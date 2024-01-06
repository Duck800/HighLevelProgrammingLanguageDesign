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

int calendar(int w,int y,int m) {
	int i, leap, d = 1;
	i = 8 * w + 4;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	cout << setw(i) << "1";
	if ((d + w) % 7 == 0)
		cout << "    " << endl;
	if (leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
		if (m == 2) {
			for (d = 2; d < 30; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0 || d ==29) {
					cout << "    " << endl;
					if ((d + w) % 7 == 0 && d == 29)
						cout << endl;
				}
			}
		}
		else if (m < 8) {
			switch (m % 2) {
			case 0:
				for (d = 2; d < 31; d++) {
					if ((d + w - 1) % 7 == 0)
						cout << setw(4) << d;
					else
						cout << setw(8) << d;
					if ((d + w) % 7 == 0 || d == 30) {
						cout << "    " << endl;
						if ((d + w) % 7 == 0 && d == 30)
							cout << endl;
					}
				}
				break;
			case 1:
				for (d = 2; d < 32; d++) {
					if ((d + w - 1) % 7 == 0)
						cout << setw(4) << d;
					else
						cout << setw(8) << d;
					if ((d + w) % 7 == 0 || d == 31) {
						cout << "    " << endl;
						if ((d + w) % 7 == 0 && d == 31)
							cout << endl;
					}
				}
				break;
			}
		}
		else {
			switch (m % 2) {
			case 1:
				for (d = 2; d < 31; d++) {
					if ((d + w - 1) % 7 == 0)
						cout << setw(4) << d;
					else
						cout << setw(8) << d;
					if ((d + w) % 7 == 0 || d == 30) {
						cout << "    " << endl;
						if ((d + w) % 7 == 0 && d == 30)
							cout << endl;
					}
				}
				break;
			case 0:
				for (d = 2; d < 32; d++) {
					if ((d + w - 1) % 7 == 0)
						cout << setw(4) << d;
					else
						cout << setw(8) << d;
					if ((d + w) % 7 == 0 || d == 31) {
						cout << "    " << endl;
						if ((d + w) % 7 == 0 && d == 31)
							cout << endl;
					}
				}
				break;
			}
		}
	}
	else if (m == 2) {
		for (d = 2; d < 29; d++) {
			if ((d + w - 1) % 7 == 0)
				cout << setw(4) << d;
			else
				cout << setw(8) << d;
			if ((d + w) % 7 == 0 || d == 28) {
				cout << "    " << endl;
				if ((d + w) % 7 == 0 && d == 28)
					cout << endl;
			}
		}
	}
	else if (m < 8) {
		switch (m % 2) {
		case 0:
			for (d = 2; d < 31; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0 || d == 30) {
					cout << "    " << endl;
					if ((d + w) % 7 == 0 && d == 30)
						cout << endl;
				}
			}
			break;
		case 1:
			for (d = 2; d < 32; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0 || d == 31) {
					cout << "    " << endl;
					if ((d + w) % 7 == 0 && d == 31)
						cout << endl;
				}
			}
			break;
		}
	}
	else
		switch (m % 2) {
		case 1:
			for (d = 2; d < 31; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0 || d == 30) {
					cout << "    " << endl;
					if ((d + w) % 7 == 0 && d == 30)
						cout << endl;
				}
			}
			break;
		case 0:
			for (d = 2; d < 32; d++) {
				if ((d + w - 1) % 7 == 0)
					cout << setw(4) << d;
				else
					cout << setw(8) << d;
				if ((d + w) % 7 == 0 || d == 31) {
					cout << "    " << endl;
					if ((d + w) % 7 == 0 && d == 31)
						cout << endl;
				}
			}
			break;
		}

	return 0;
}

int main() {
	int year, m, d = 1;
	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> m;
		if (cin.fail()) {
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (year > 2100 || year < 1900) {
			cout << "年份不正确，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (m > 12) {
			cout << "月份不正确，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else
			break;
	}
	cout << endl;
	cout << year << "年" << m << "月" << endl;
	calendar(zeller(year, m, d), year, m);
	cout << endl;

	return 0;
}