/*2151133 孙韩雅 信07*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int main()
{
	int a[20];
	int i, sum = 0, tim = -1, j, mid;
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	for (i = 0; i < 20; i++) {
		cin >> a[i];
		sum += a[i];
		tim++;
		if (a[i] <= 0)
			break;
		if (i > 1) {
			if (cin.good() == 0)
				break;
		}
	}
	if (a[0] <= 0 )
		cout << "无有效输入" << endl;
	else {
		cin.clear();
		cin.ignore(65536, '\n');
		a[tim] = 0;
		cout << "原数组为：" << endl;
		for (i = 0; i < 20; i++) {
			if (a[i] > 0)
				cout << a[i] << " ";
		}
		cout << endl;
		cout << "请输入要插入的正整数" << endl;
		cin >> j;
		for (i = 0; i < tim + 1; i++) {
			if (j <= a[i]) {
				mid = a[i];
				a[i] = j;
				for (i; i < tim + 1; i++) {
					int cent = a[i + 1];
					a[i + 1] = mid;
					mid = cent;
				}
			}
		}
		cout << "插入后的数组为：" << endl;
		for (i = 0; i < tim + 1; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
