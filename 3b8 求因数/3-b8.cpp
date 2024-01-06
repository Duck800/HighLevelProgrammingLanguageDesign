/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
	int i;
	for (i = 2; i < 1000; i++) {
		int sum = 0, fac;
		for (fac = 1; fac < i; fac++) {
			if (i % fac == 0)
				sum += fac;
		}
		if (sum == i) {
			printf("%d,its factors are ", i);
			for (fac = 1; fac < i; fac++) {
				if (i % fac == 0) {
					if (fac < i / 2)
                        cout << fac;
					else
                        cout << fac;
				}
			}
            cout << endl;
		}
	}
	return 0;
}