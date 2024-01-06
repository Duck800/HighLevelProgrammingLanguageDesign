#include <iostream>
using namespace std;

int main()
{
    int i;
    char a[4] = { '\3','\4','\5','\6' };
    cout << "0         1         2         " << endl; //标尺
    cout << "012345678901234567890123456789" << endl; //标尺

    for (i = 0; i < 4; i++)
        cout << a[i] << endl; //确认a[i]是否输出

    cout << '#' << endl; //加行尾识别符


    return 0;
}
