/*2151133 �ﺫ�� ��07*/
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
    /* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
    char str[256], * p;
    int  a[N] = { 0 }, * pnum, * pa;
    bool is_num;

    /* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
    cout << "�����������������������ֵ��ַ���" << endl;
    gets_s(str, 256);
    p = str, pa = a;
    for (; p < str + 256 && pa - a < N;) {
        is_num = (*p >= '0' && *p <= '9' ? 1 : 0);
        if (is_num) {
            *pa = (*pa) * 10 + *p - '0';
            p++;
            is_num = (*p >= '0' && *p <= '9' ? 1 : 0);
            if (!is_num)
                pa++;
        }
        else
            p++;
    }
    cout << "����" << pa - a << "������" << endl;
    for (pnum = a; pnum - a < pa - a; pnum++)
        cout << *pnum << " ";
    cout << endl;
    return 0;
}