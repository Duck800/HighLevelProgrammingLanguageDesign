/*2151133 �ﺫ�� ��07*/
#include <iostream>
using namespace std;

int palindrome(char* str)
{
    int i, same = 0;
    for (i = 0; (str + i) < (str + strlen(str) - 1 - i); i++) {
        if (*(str + i) == *(str + strlen(str) - 1 - i))
            same++;
    }
    if (same == strlen(str) / 2)
        return true;
    else
        return false;
}
int main()
{
    char str[80];
    cout << "������һ������С��80���ַ��������Ĵ���" << endl;
    fgets(str, 80, stdin);
    if (*(str + strlen(str) - 1) == '\n')
        *(str + strlen(str) - 1) = '\0';
    cout << (palindrome(str) ? "yes" : "no") << endl;
}