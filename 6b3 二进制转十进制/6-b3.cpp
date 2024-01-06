/*2151133 孙韩雅 信07*/
#include <iostream>
using namespace std;

unsigned int swap(char* bin_str)
{
    char* str = bin_str;
    unsigned int dec_[3] = { 0 }, * dec = dec_;
    for (; str < bin_str + 32; str++) {
        if (*str != 0)
            *dec = (*dec) * 2 + *str - '0';
        else
            break;
    }
    return *dec_ ;
}

int main()
{
    char bin_str[33] = { 0 };
    cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
    cin >> bin_str;
    unsigned int dec = swap(bin_str);
    cout << dec << endl;
}