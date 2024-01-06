/* 2151133 孙韩雅 信07 */
#include <iostream>
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

int main() {
	int y, m, d, leap;
	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
		if (cin.fail()) {
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (y > 2100 || y < 1900) {
			cout << "年份不正确，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (m > 12) {
			cout << "月份不正确，请重新输入" << endl;
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
			if (m == 2) {
				if (d < 30)  
					break;
				else {
					cout << "日不正确，请重新输入" << endl;
					cin.clear();
					cin.ignore(65536, '\n');
				}
			}
			else if (m < 8) {
				if (m % 2 == 0) {
					if (d < 31)
						break;
					else
						cout << "日不正确，请重新输入" << endl;
				}
				else {
					if (d < 32)
						break;
					else
						cout << "日不正确，请重新输入" << endl;
				}
			}
			else {
				if (m % 2 == 0) {
					if (d < 32)
						break;
					else {
						cout << "日不正确，请重新输入" << endl;
						cin.clear();
						cin.ignore(65536, '\n');
					}
				}
				else {
					if (d < 31)
						break;
					else {
						cout << "日不正确，请重新输入" << endl;
						cin.clear();
						cin.ignore(65536, '\n');
					}
				}
			}
		}
		else {
			if (m == 2) {
				if (d < 29)
					break;
				else {
					cout << "日不正确，请重新输入" << endl;
					cin.clear();
					cin.ignore(65536, '\n');
				}
			}
			else if (m < 8) {
				if (m % 2 == 0) {
					if (d < 31)
						break;
					else
						cout << "日不正确，请重新输入" << endl;
				}
				else {
					if (d < 32)
						break;
					else
						cout << "日不正确，请重新输入" << endl;
				}
			}
			else {
				if (m % 2 == 0) {
					if (d < 32)
						break;
					else {
						cout << "日不正确，请重新输入" << endl;
						cin.clear();
						cin.ignore(65536, '\n');
					}
				}
				else {
					if (d < 31)
						break;
					else {
						cout << "日不正确，请重新输入" << endl;
						cin.clear();
						cin.ignore(65536, '\n');
					}
				}
			}
		}
	}
	cout << "星期";
	switch (zeller(y, m, d)) {
	case 0:
		cout << "日";
		break;
	case 1:
		cout << "一";
		break;
	case 2:
		cout << "二";
		break;
	case 3:
		cout << "三";
		break;
	case 4:
		cout << "四";
		break;
	case 5:
		cout << "五";
		break;
	case 6:
		cout << "六";
		break;
	}
	cout << endl;

	return 0;
}