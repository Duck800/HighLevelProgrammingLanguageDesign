/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include "cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include "90-b2.h"
using namespace std;

char menu()
{
    cct_setcolor();
    char choice;
    cout << " ---------------------------------------" << endl;
    cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
    cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
    cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
    cout << "4.�����������棨�ֲ�����ʾ��" << endl;
    cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
    cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
    cout << "7.αͼ�ν������ü�ͷ�� / ���ѡ��ǰɫ��" << endl;
    cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
    cout << "9.αͼ�ν���������(֧�����)" << endl;
    cout << "---------------------------------------" << endl;
    cout << "0.�˳�" << endl;
    cout << "---------------------------------------" << endl;
    cout << "[��ѡ��:]";
    while (1) {
        char input = _getch();
        if (input >= '0' && input <= '9'|| input >= 'A' && input <= 'C'|| input >= 'a' && input <= 'c') {
            choice = input;
            cout << choice;
            break;
        }
    }
    return choice;
}

int main()
{
    cct_setcolor();
    while (1) {
        cct_cls();
        char choice = menu();
        if (choice == '0')
            break;
        else {
            switch (choice) {
            case '1':
                project(choice);
                break;
            case '2':
                project(choice);
                break;
            case '3':
                project_3(choice);
                break;
            case '4':
                project_4(choice);
                break;
            case '5':
                project_5(choice);
                break;
            case '6':
                project_6_7(choice);
                break;
            case '7':
                project_6_7(choice);
                break;
            case '8':
                project_8();
                break;
            case '9':
                project_9();
                break;
            }
        }
    }
}