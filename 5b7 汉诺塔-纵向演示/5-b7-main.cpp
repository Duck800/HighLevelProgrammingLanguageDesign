/*2151133 孙韩雅 信07*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "5-b7.h"
using namespace std;

/*记录柱的内容*/int a[10], b[10], c[10];
/*次数*/int i = 1;
/*栈顶指针*/int top_a = 0, top_b = 0, top_c = 0;
/*移动延时*/static int mov = 1000;

void output()
{
    int j;
    cout << " A:";
    for (j = 0; j < 10; j++) {
        if (a[j] != 0)
            cout << setw(2) << a[j];
        else
            cout << "  ";
    }
    cout << " B:";
    for (j = 0; j < 10; j++) {
        if (b[j] != 0)
            cout << setw(2) << b[j];
        else
            cout << "  ";
    }
    cout << " C:";
    for (j = 0; j < 10; j++) {
        if (c[j] != 0)
            cout << setw(2) << c[j];
        else
            cout << "  ";
    }
    cout << endl;
}
void image(int a[], int b[], int c[], int n)
{
    /*循环控制*/int j;
    cct_gotoxy(12, 13);
    cout << "A         B         C";
    cct_gotoxy(8, 12);
    cout << "=========================";
    for (j = 9; j >= 0; j--) {
        cct_gotoxy(11, 11 - j);
        if (a[j] != 0)
            cout << setw(2) << a[j];
        else
            cout << "  ";
        cct_gotoxy(21, 11 - j);
        if (b[j] != 0)
            cout << setw(2) << b[j];
        else
            cout << "  ";
        cct_gotoxy(31, 11 - j);
        if (c[j] != 0)
            cout << setw(2) << c[j];
        else
            cout << "  ";
    }
}

void swap(char src,char tmp,char dst)
{
    if (src == 65) {
        if (dst == 66) {
            b[top_b++] = a[--top_a];
            a[top_a] = 0;
        }
        else {
            c[top_c++] = a[--top_a];
            a[top_a] = 0;
        }
    }
    else if (src == 66) {
        if (dst == 65) {
            a[top_a++] = b[--top_b];
            b[top_b] = 0;
        }
        else {
            c[top_c++] = b[--top_b];
            b[top_b] = 0;
        }
    }
    else if (src == 67) {
        if (dst == 65) {
            a[top_a++] = c[--top_c];
            c[top_c] = 0;
        }
        else {
            b[top_b++] = c[--top_c];
            c[top_c] = 0;
        }
    }
}

void shuru_1(char src, char dst, int n)
{
    cct_gotoxy(0, 17);
    cout << "第" << setw(4) << i << "步" << "(" << n << "#: " << src << "-->" << dst << ") ";
    output();
}
void shuru_0(char src, char dst, int n)
{
    cct_gotoxy(0, 17);
    cout << "第" << setw(4) << i << "步" << "(" << n << "#: " << src << "-->" << dst << ") ";
}

void hanoi_0_1(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        swap(src, tmp, dst);
        while (1) {
            int shuru = _getch();
            if (shuru == 13) {
                shuru_1(src, dst, n);
                break;
            }
            else
                continue;
        }
        while (1) {
            int shuru = _getch();
            if (shuru == 13) {
                image(a, b, c, n);
                break;
            }
            else
                continue;
        }
        i++;
    }
    else {
        hanoi_0_1(n - 1, src, dst, tmp);
        swap(src, tmp, dst);
        while (1) {
            int shuru = _getch();
            if (shuru == 13) {
                shuru_1(src, dst, n);
                break;
            }
            else
                continue;
        }
        while (1) {
            int shuru = _getch();
            if (shuru == 13) {
                image(a, b, c, n);
                break;
            }
            else
                continue;
        }
        i++;
        hanoi_0_1(n - 1, tmp, src, dst);
    }
}
void hanoi_0_0(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        swap(src, tmp, dst);
        while (1) {
            int shuru = _getch();
            if (shuru == 13) {
                shuru_0(src, dst, n);
                break;
            }
            else
                continue;
        }
        while (1) {
            int shuru = _getch();
            if (shuru == 13) {
                image(a, b, c, n);
                break;
            }
            else
                continue;
        }
        i++;
    }
    else {
        hanoi_0_0(n - 1, src, dst, tmp);
        swap(src, tmp, dst);
        while (1) {
            int shuru = _getch();
            if (shuru == 13) {
                shuru_0(src, dst, n);
                break;
            }
            else
                continue;
        }
        while (1) {
            int shuru = _getch();
            if (shuru == 13) {
                image(a, b, c, n);
                break;
            }
            else
                continue;
        }
        i++;
        hanoi_0_0(n - 1, tmp, src, dst);
    }
}
void hanoi_v_1(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        swap(src, tmp, dst);
        Sleep(mov);
        shuru_1(src, dst, n);
        image(a, b, c, n);
        i++;
    }
    else {
        hanoi_v_1(n - 1, src, dst, tmp);
        swap(src, tmp, dst);
        Sleep(mov);
        shuru_1(src, dst, n);
        image(a, b, c, n);
        i++;
        hanoi_v_1(n - 1, tmp, src, dst);
    }
}
void hanoi_v_0(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        swap(src, tmp, dst);
        Sleep(mov);
        shuru_0(src, dst, n);
        image(a, b, c, n);
        i++;
    }
    else {
        hanoi_v_0(n - 1, src, dst, tmp);
        swap(src, tmp, dst);  
        Sleep(mov);
        shuru_0(src, dst, n);              
        image(a, b, c, n);
        i++;
        hanoi_v_0(n - 1, tmp, src, dst);
    }
}


int speed()
{
    int v;
    while (1) {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> v;
        if (cin.good() == 0) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else if (v < 0 || v > 5) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else
            break;
    }
    return v;
}
int appear()
{
    int app;
    while (1) {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> app;
        if (cin.good() == 0) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else if (app > 1 || app < 0) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else
            break;
    }
    return app;
}

void again_1(char src, char tmp, char dst, int n)
{
    cct_gotoxy(0, 17);
    /*循环控制*/int j;
    cout << "初始:               ";
    cout << " A:";
    if (src == 65) {
        for (j = n; j > 0; j--)
            a[top_a++] = j;
    }
    for (j = 0; j < 10; j++) {
        if (a[j] != 0)
            cout << setw(2) << a[j];
        else
            cout << "  ";
    }
    cout << " B:";
    if (src == 66) {
        for (j = n; j > 0; j--)
            b[top_b++] = j;
    }
    for (j = 0; j < 10; j++) {
        if (b[j] != 0)
            cout << setw(2) << b[j];
        else
            cout << "  ";
    }
    cout << " C:";
    if (src == 67) {
        for (j = n; j > 0; j--)
            c[top_c++] = j;
    }
    for (j = 0; j < 10; j++) {
        if (c[j] != 0)
            cout << setw(2) << c[j];
        else
            cout << "  ";
    }
}
void again_2(char src, char tmp, char dst, int n)
{
    cct_gotoxy(0, 17);
    /*循环控制*/int j;
    if (src == 65) {
        for (j = n; j > 0; j--)
            a[top_a++] = j;
    }
    if (src == 66) {
        for (j = n; j > 0; j--)
            b[top_b++] = j;
    }
    if (src == 67) {
        for (j = n; j > 0; j--)
            c[top_c++] = j;
    }
    cct_gotoxy(12, 13);
    cout << "A         B         C";
    cct_gotoxy(8, 12);
    cout << "=========================";
    for (j = 9; j >= 0; j--) {
        cct_gotoxy(11, 11 - j);
        if (a[j] != 0)
            cout << setw(2) << a[j];
        else
            cout << "  ";
        cct_gotoxy(21, 11 - j);
        if (b[j] != 0)
            cout << setw(2) << b[j];
        else
            cout << "  ";
        cct_gotoxy(31, 11 - j);
        if (c[j] != 0)
            cout << setw(2) << c[j];
        else
            cout << "  ";
    }
}

int main()
{
    int n;
    char src, tmp, dst;
    /*层数*/while (1) {
        cout << "请输入汉诺塔的层数(1-10)：" << endl;
        cin >> n;
        if (cin.good() == 0) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else if (n >= 1 && n <= 10) {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
    }
    /*起始柱*/while (1) {
        cout << "请输入起始柱(A-C)：" << endl;
        cin >> src;
        if (cin.good() == 0) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else if (src >= 65 && src <= 67) {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        else if (src >= 97 && src <= 99) {
            src -= 32;
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
    }
    /*目标柱*/while (1) {
        cout << "请输入目标柱(A-C)：" << endl;
        cin >> dst;
        if (cin.good() == 0) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else if (dst == src) {
            cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else if (dst >= 65 && dst <= 67) {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        else if (dst >= 97 && dst <= 99) {
            dst -= 32;
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        else {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
    }
    if (src == 65) {
        if (dst == 66)
            tmp = 67;
        else
            tmp = 66;
    }
    else if (src == 66) {
        if (dst == 65)
            tmp = 67;
        else
            tmp = 65;
    }
    else if (src == 67) {
        if (dst == 65)
            tmp = 66;
        else
            tmp = 65;
    }

    /*移动速度*/int v = speed();
    /*是否显示*/int app = appear();
    /*清屏*/cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << v << "，" << (app == 0 ? "不显示" : "显示") << "内部数组值" << endl;

    if (v == 0) {
        if (app == 1) {
            cct_gotoxy(0, 17);
            /*循环控制*/int j;
            cout << "初始:               ";
            cout << " A:";
            if (src == 65) {
                for (j = n; j > 0; j--)
                    a[top_a++] = j;
            }
            for (j = 0; j < 10; j++) {
                if (a[j] != 0)
                    cout << setw(2) << a[j];
                else
                    cout << "  ";
            }
            cout << " B:";
            if (src == 66) {
                for (j = n; j > 0; j--)
                    b[top_b++] = j;
            }
            for (j = 0; j < 10; j++) {
                if (b[j] != 0)
                    cout << setw(2) << b[j];
                else
                    cout << "  ";
            }
            cout << " C:";
            if (src == 67) {
                for (j = n; j > 0; j--)
                    c[top_c++] = j;
            }
            for (j = 0; j < 10; j++) {
                if (c[j] != 0)
                    cout << setw(2) << c[j];
                else
                    cout << "  ";
            }
            cout << endl;
            while (1) {
                int shuru = _getch();
                if (shuru == 13) {
                    image(a, b, c, n);
                    break;
                }
                else
                    continue;
            }
            hanoi_0_1(n, src, tmp, dst);
        }
        else {
            cct_gotoxy(0, 17);
            /*循环控制*/int j;
            if (src == 65) {
                for (j = n; j > 0; j--)
                    a[top_a++] = j;
            }
            if (src == 66) {
                for (j = n; j > 0; j--)
                    b[top_b++] = j;
            }
            if (src == 67) {
                for (j = n; j > 0; j--)
                    c[top_c++] = j;
            }
            cct_gotoxy(12, 13);
            cout << "A         B         C";
            cct_gotoxy(8, 12);
            cout << "=========================";
            for (j = 9; j >= 0; j--) {
                cct_gotoxy(11, 11 - j);
                if (a[j] != 0)
                    cout << setw(2) << a[j];
                else
                    cout << "  ";
                cct_gotoxy(21, 11 - j);
                if (b[j] != 0)
                    cout << setw(2) << b[j];
                else
                    cout << "  ";
                cct_gotoxy(31, 11 - j);
                if (c[j] != 0)
                    cout << setw(2) << c[j];
                else
                    cout << "  ";
            }
            hanoi_0_0(n, src, tmp, dst);
        }
    }
    else if (v != 5) {
        mov = mov / v;
        if (app == 1) {
            again_1(src, tmp, dst, n);
            cout << endl;
            image(a, b, c, n);
            hanoi_v_1(n, src, tmp, dst);
        }
        else {
            again_2(src, tmp, dst, n);
            hanoi_v_0(n, src, tmp, dst);
        }
    }
    else {
        mov = 0;
        if (app == 1) {
            again_1(src, tmp, dst, n);
            cout << endl;
            image(a, b, c, n);
            hanoi_v_1(n, src, tmp, dst);
        }
        else {
            again_2(src, tmp, dst, n);
            hanoi_v_0(n, src, tmp, dst);
        }
    }
    cct_gotoxy(0, 20);
}