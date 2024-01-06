/*2151133 Ëïº«ÑÅ ÐÅ07*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a, b;
	for (a = 1; a < 10; a++) {
		for (b = 1; (b < a || b == a) && b < 10; b++) {
			if (b * a / 10 > 0)
				cout << b << "x" << a << "=" << b * a << "  ";
			else
				cout << b << "x" << a << "=" << b * a << "   ";
		}
		cout << endl;
	}
	return 0;
}