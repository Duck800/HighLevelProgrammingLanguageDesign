#include <iostream>
#include <iomanip>
using namespace std;

long long count(int n) {
	long long i;
	if (n == 1)
		i = 1;
	else if (n == 2)
		i = 3;
	else
		i = count(n - 1) + count(n - 2) + 1;
	return i;
}

int main()
{
	int n ,f;
	for (n = 1; n < 47; n++) {
		f = count(n);
		cout<<"第"<<setw(2)<<n<<"项的递归次数:"<<setw(15)<<f<<"次"<<endl;
	}

	return 0;
}