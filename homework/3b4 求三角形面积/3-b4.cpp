/*2151133 孙韩雅 信07*/
#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	cout << "请输入三角形的两边及其夹角（角度）" << endl;

	int a, b, alpha;
	double pi = 3.14159;
	cin >> a >> b >> alpha;
	float s = a * b * (float)sin(pi * alpha / 180) / 2;

	cout << "三角形面积为 : " << fixed << setprecision(3) << s << endl;

	return 0;
}