/*2151133 孙韩雅 信07*/
#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	cout << "请输入a值" << endl;
	int a;
	double x, y = 0;
	cin >> a;
	for (x = 1; x < a; x = (x + a / x) / 2) {
		y = (x + a / x) / 2;
		if (fabs(y - x) < 1e-5)
			break;
	}
	cout << a << "的平方根=" << setiosflags(ios::fixed) << setprecision(3) << y << endl;
	
	return 0; 
}
