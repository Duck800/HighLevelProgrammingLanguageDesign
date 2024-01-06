#include <iostream>
using namespace std;

int main()
{
	int a = 5, n = 12;
	a *= a += a /= a;
	cout <<a<<" "<<n<< endl;

	return 0;
}