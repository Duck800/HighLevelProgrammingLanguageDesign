#include <iostream>
using namespace std;

int main()
{
    int i;
    char a[4] = { '\3','\4','\5','\6' };
    cout << "0         1         2         " << endl; //���
    cout << "012345678901234567890123456789" << endl; //���

    for (i = 0; i < 4; i++)
        cout << a[i] << endl; //ȷ��a[i]�Ƿ����

    cout << '#' << endl; //����βʶ���


    return 0;
}
