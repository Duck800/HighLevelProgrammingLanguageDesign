/*2151133 孙韩雅 信07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout << "请输入半径和高度" << endl;
	int r, h;
	double pi = 3.14159;
	cin >> r >> h;
	cout << "圆周长     : " << fixed << setprecision(2) << 2 * pi * r << endl;
	cout << "圆面积     : " << pi * r * r << endl;
	cout << "圆球表面积 : " << 4 * pi * r * r << endl;
	cout << "圆球体积   : " << 4 * pi * r * r * r / 3 << endl;
	cout << "圆柱体积   : " << pi * r * r * h << endl;

	return 0;
}