/*2151133 �ﺫ�� ��07*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "5-b7.h"
using namespace std;

/*��¼��������*/int a[10], b[10], c[10];
/*����*/int i = 1;
/*ջ��ָ��*/int top_a = 0, top_b = 0, top_c = 0;
/*�ƶ���ʱ*/static int mov = 1000;

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
    /*ѭ������*/int j;
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
    cout << "��" << setw(4) << i << "��" << "(" << n << "#: " << src << "-->" << dst << ") ";
    output();
}
void shuru_0(char src, char dst, int n)
{
    cct_gotoxy(0, 17);
    cout << "��" << setw(4) << i << "��" << "(" << n << "#: " << src << "-->" << dst << ") ";
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
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
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
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
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
    /*ѭ������*/int j;
    cout << "��ʼ:               ";
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
    /*ѭ������*/int j;
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
    /*����*/while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
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
    /*��ʼ��*/while (1) {
        cout << "��������ʼ��(A-C)��" << endl;
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
    /*Ŀ����*/while (1) {
        cout << "������Ŀ����(A-C)��" << endl;
        cin >> dst;
        if (cin.good() == 0) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else if (dst == src) {
            cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
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

    /*�ƶ��ٶ�*/int v = speed();
    /*�Ƿ���ʾ*/int app = appear();
    /*����*/cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << v << "��" << (app == 0 ? "����ʾ" : "��ʾ") << "�ڲ�����ֵ" << endl;

    if (v == 0) {
        if (app == 1) {
            cct_gotoxy(0, 17);
            /*ѭ������*/int j;
            cout << "��ʼ:               ";
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
            /*ѭ������*/int j;
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