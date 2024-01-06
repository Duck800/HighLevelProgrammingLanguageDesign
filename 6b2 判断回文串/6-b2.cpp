/*2151133 孙韩雅 信07*/
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
    cout << "请输入一个长度小于80的字符串（回文串）" << endl;
    fgets(str, 80, stdin);
    if (*(str + strlen(str) - 1) == '\n')
        *(str + strlen(str) - 1) = '\0';
    cout << (palindrome(str) ? "yes" : "no") << endl;
}