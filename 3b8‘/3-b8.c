/*2151133 Ëïº«ÑÅ ÐÅ07*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
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
						printf("%d,", fac);
					else
						printf("%d", fac);
				}
			}
			printf("\n");
		}
	}
	return 0;
}