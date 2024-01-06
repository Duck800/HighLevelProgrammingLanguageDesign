/*2151133 孙韩雅 信07*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	cout << "请输入年，月，日" << endl;
	int y, m, d, i, leap;
	cin >> y >> m >> d;
	leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;

	if (leap == 1) {
		if (m < 13 && m > 0) {
			if (m == 1) {
				if (d <= 31) {
					i = d;
					cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
				}
				else
					cout << "输入错误-日与月的关系非法" << endl;
			}
			else if (m == 2) {
				if (d <= 29) {
					i = 31 + d;
					cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
				}
				else
					cout << "输入错误-日与月的关系非法" << endl;
			}
			else if (m > 2 && m < 8) {
				switch (m % 2) {
				case 0:
					if (d < 31) {
						i = 31 * (m / 2) + 29 + 30 * (m / 2 - 2) + d;
						cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
					}
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 1:
					if (d < 32) {
						i = 31 * (m / 2) + 29 + 30 * (m / 2 - 1) + d;
						cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
					}
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				}
			}
			else if (m >= 8) {
				switch (m % 2) {
				case 0:
					if (d < 32) {
						i = 213 + 31 * (m / 2 - 4) + 30 * (m / 2 - 4) + d;
						cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
					}
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 1:
					if (d < 31) {
						i = 213 + 31 * (m / 2 - 3) + 30 * (m / 2 - 4) + d;
						cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
					}
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				}
			}
		}
		else
			cout << "输入错误-月份输入不正确" << endl;
	}
	else if (m < 13 && m > 0) {
			if (m == 1) {
				if (d <= 31) {
					i = d;
					cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
				}
				else
					cout << "输入错误-日与月的关系非法" << endl;
			}
			else if (m == 2) {
				if (d <= 28) {
					i = 31 + d;
					cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
				}
				else
					cout << "输入错误-日与月的关系非法" << endl;
			}
			else if (m > 2 && m < 8) {
				switch (m % 2) {
				case 0:
					if (d < 31) {
						i = 31 * (m / 2) + 28 + 30 * (m / 2 - 2) + d;
						cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
					}
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 1:
					if (d < 32) {
						i = 31 * (m / 2) + 28 + 30 * (m / 2 - 1) + d;
						cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
					}
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				}
			}
			else if (m >= 8) {
				switch (m % 2) {
				case 0:
					if (d < 32) {
						i = 212 + 31 * (m / 2 - 4) + 30 * (m / 2 - 4) + d;
						cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
					}
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				case 1:
					if (d < 31) {
						i = 212 + 31 * (m / 2 - 3) + 30 * (m / 2 - 4) + d;
						cout << y << "-" << m << "-" << d << "是" << y << "年的第" << i << "天";
					}
					else
						cout << "输入错误-日与月的关系非法" << endl;
					break;
				}
			}
	}
	else
		cout << "输入错误-月份输入不正确" << endl;

		return 0;
}