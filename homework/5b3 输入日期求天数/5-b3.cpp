/*2151133 孙韩雅 信07*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int leap(int y)
{
	int leap = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
	return leap;
	/*1为闰年，0为平年*/
}

int day(int y, int m, int d)
{
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, sum = 0;
	if (leap(y))
		a[1] = 29;
	for (i = 0; i < m - 1; i++) {
		sum += a[i];
	}
	sum += d;
	return sum;
}

int correct(int y, int m, int d) {
	if (m > 0 && m < 13) {
		int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (leap(y))
			a[1] = 29;
		return 1;
		if (d > a[m - 1]) {
			cout << "输入错误-日与月的关系非法" << endl;
			return 0;
		}
	}
	else {
		cout << "输入错误-月份输入不正确" << endl;
		return 0;
	}
}

int main()
{
	cout << "请输入年，月，日" << endl;
	int y, m, d;
	cin >> y >> m >> d;
	if (correct(y, m, d))
		cout << y << "-" << m << "-" << d << "是" << y << "年的第" << day(y, m, d) << "天" << endl;
}