/*2151133 �ﺫ�� ��07*/
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
    cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
    cin >> bin_str;
    unsigned int dec = swap(bin_str);
    cout << dec << endl;
}