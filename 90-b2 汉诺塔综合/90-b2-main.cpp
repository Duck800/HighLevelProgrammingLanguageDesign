/*2151133 孙韩雅 信07*/
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
    cout << "1.命令行找出可合成项并标识（非递归）" << endl;
    cout << "2.命令行找出可合成项并标识（递归）" << endl;
    cout << "3.命令行完成一次合成（分步骤显示）" << endl;
    cout << "4.命令行完整版（分步骤显示）" << endl;
    cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
    cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
    cout << "7.伪图形界面下用箭头键 / 鼠标选择当前色块" << endl;
    cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
    cout << "9.伪图形界面完整版(支持鼠标)" << endl;
    cout << "---------------------------------------" << endl;
    cout << "0.退出" << endl;
    cout << "---------------------------------------" << endl;
    cout << "[请选择:]";
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