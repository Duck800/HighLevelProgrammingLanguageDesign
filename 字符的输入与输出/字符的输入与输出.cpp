#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    double f1 = 0.12345678901234;
    double f2 = 0.87654321098765;

    cout << f1 << ' ' << f2 << endl;
    cout << setiosflags(ios::fixed) << f1 << ' ' << f2 << endl;

    cout << endl;
    cout << setprecision(1) << f1 << ' ' << f2 << endl;
    cout << setprecision(6) << f1 << ' ' << f2 << endl;
    cout << setprecision(7) << f1 << ' ' << f2 << endl;
    cout << setprecision(15) << f1 << ' ' << f2 << endl;
    cout << setprecision(20) << f1 << ' ' << f2 << endl;

    return 0;
}
