/*2151133 Ëïº«ÑÅ ÐÅ07*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int main() 
{
	int a[100] = { 0 };
	int i, j;
	for (j = 1; j < 101; j++) {
		for (i = 0; i < 100; i++) {
			if ((i + 1) % j == 0)
				a[i] += 1;
		}
	}
	for (i = 0; i < 100; i++) {
		if (a[i] % 2 == 1 && i != 99)
			cout << i + 1 << " ";
		else if (a[i] % 2 == 1)
			cout << i + 1;
	}
	cout << endl;
}