/*2151133 孙韩雅 信07*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include "cmd_console_tools.h"
#include "lib_mto10_net_tools.h"
#include "90-b2.h"
using namespace std;


/*输出当前数组（纯色输出/无虚线）*/
void output_record_color()
{
    cct_setconsoleborder(37 + 6 * (solution.column - 5), 23 + 3 * (solution.row - 5), 37 + 6 * (solution.column - 5), 23 + 3 * (solution.row - 5));
    cct_setcursor(CURSOR_INVISIBLE);
    /*循环控制*/int i, j, m, n;
    //PART 1.布置白色背景
    cct_gotoxy(0, 1);
    cout << "      ";
    for (i = 0; i < solution.column; i++)
        cout << i << "     ";
    cct_showstr(2, 2, "┏", COLOR_HWHITE, COLOR_BLACK);
    for (j = 0; j < solution.column; j++) {
        cct_showstr(4 + 6 * j, 2, "━━━", COLOR_HWHITE, COLOR_BLACK);
        Sleep(DELAY);
    }
    cct_showstr(4 + 6 * solution.column, 2, "┓", COLOR_HWHITE, COLOR_BLACK);
    //
    for (i = 0; i < solution.row; i++) {
        for (j = 0; j < 3; j++) {
            if (j == 1) {
                cout << endl;
                cct_showch(0, 4 + 3 * i, i + 'A', COLOR_BLACK, COLOR_HWHITE);
            }
            cct_showstr(2, 3 + 3 * i + j, "┃", COLOR_HWHITE, COLOR_BLACK);
            for (m = 0; m < solution.column; m++) {
                for (n = 0; n < 6; n++)
                    cct_showstr(4 + 6 * m + n, 3 + 3 * i + j, " ", COLOR_HWHITE, COLOR_BLACK);
                if (m == solution.column - 1) {
                    cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
                    cout << "┃";
                }
                Sleep(DELAY);
            }
        }
        if (i != solution.row - 1)
            cct_showstr(2, 6 + 3 * i, "┣", COLOR_HWHITE, COLOR_BLACK);
    }
    //
    cct_showstr(2, 3 + 3 * solution.row, "┗", COLOR_HWHITE, COLOR_BLACK);
    for (j = 0; j < solution.column; j++) {
        cct_showstr(4 + 6 * j, 3 + 3 * solution.row, "━━━", COLOR_HWHITE, COLOR_BLACK);
        Sleep(DELAY);
    }
    cct_showstr(4 + 6 * solution.column, 3 + 3 * solution.row, "┛", COLOR_HWHITE, COLOR_BLACK);
    //
    //PART 2.覆盖色块
    for (i = 0; i < solution.row; i++) {
        for (j = 0; j < 3; j++) {
            for (m = 0; m < solution.column; m++) {
                for (n = 0; n < 6; n++) {
                    switch (n) {
                    case 0:
                        if (j == 0)
                            cct_showstr(4 + 6 * m + n, 3 + 3 * i + j, "┏", solution.record[i][m] , COLOR_BLACK);
                        else if (j == 1)
                            cct_showstr(4 + 6 * m + n, 3 + 3 * i + j, "┃", solution.record[i][m], COLOR_BLACK);
                        else if (j == 2)
                            cct_showstr(4 + 6 * m + n, 3 + 3 * i + j, "┗", solution.record[i][m], COLOR_BLACK);
                        break;
                    case 2:
                        if (j == 0 || j == 2)
                            cct_showstr(4 + 6 * m + n, 3 + 3 * i + j, "━", solution.record[i][m], COLOR_BLACK);
                        else if (j == 1)
                            cct_showint(4 + 6 * m + n, 3 + 3 * i + j, solution.record[i][m], solution.record[i][m], COLOR_BLACK);
                        break;
                    case 3:
                        if (j == 1)
                            cct_showstr(4 + 6 * m + n, 3 + 3 * i + j, " ", solution.record[i][m], COLOR_BLACK);
                        break;
                    case 4:
                        if (j == 0)
                            cct_showstr(4 + 6 * m + n, 3 + 3 * i + j, "┓", solution.record[i][m], COLOR_BLACK);
                        else if (j == 1)
                            cct_showstr(4 + 6 * m + n, 3 + 3 * i + j, "┃", solution.record[i][m], COLOR_BLACK);
                        else if (j == 2)
                            cct_showstr(4 + 6 * m + n, 3 + 3 * i + j, "┛", solution.record[i][m], COLOR_BLACK);
                        break;
                    }
                }
            }
        }
    }
    //PART 3.打印屏幕设置
    cct_gotoxy(0, 0);
    cct_setcolor(); //恢复缺省颜色
    cout << "屏幕当前设置为：" << 37 + 6 * (solution.column - 5) << "行" << 23 + 3 * (solution.row - 5) << "列" << endl;
}
/*输出当前数组（纯色输出/有虚线）*/
void output_record_color_line()
{
    cct_setconsoleborder(45 + 8 * (solution.column - 5), 27 + 4 * (solution.row - 5), 45 + 8 * (solution.column - 5), 27 + 4 * (solution.row - 5));
    cct_setcursor(CURSOR_INVISIBLE);
    /*循环控制*/int i, j, m, n;
    //PART 1.布置白色背景
    cct_gotoxy(0, 1);
    cout << "      ";
    for (i = 0; i < solution.column; i++)
        cout << i << "       ";
    //
    cct_showstr(2, 2, "┏", COLOR_HWHITE, COLOR_BLACK);
    for (j = 0; j < solution.column; j++) {
            cct_showstr(4 + 8 * j, 2, "━━━━", COLOR_HWHITE, COLOR_BLACK);
        if (j != solution.column - 1)
            cct_showstr(10 + 8 * j, 2, "┳", COLOR_HWHITE, COLOR_BLACK);
        else
            cct_showstr(10 + 8 * j, 2, "┓", COLOR_HWHITE, COLOR_BLACK);
        Sleep(DELAY);
    }
    //
    for (i = 0; i < solution.row; i++) {
        for (j = 0; j < 3; j++) {
            if (j == 1) {
                cout << endl;
                cct_showch(0, 4 + 4 * i, i + 'A', COLOR_BLACK, COLOR_HWHITE);
            }
            cct_showstr(2, 3 + 4 * i + j, "┃", COLOR_HWHITE, COLOR_BLACK);
            for (m = 0; m < solution.column; m++) {
                for (n = 0; n < 6; n++)
                    cct_showstr(4 + 8 * m + n, 3 + 4 * i + j, " ", COLOR_HWHITE, COLOR_BLACK);
                cct_showstr(10 + 8 * m, 3 + 4 * i + j, "┃", COLOR_HWHITE, COLOR_BLACK);
                Sleep(DELAY);
            }
        }
        if (i != solution.row - 1) {
            cct_showstr(2, 3 + 4 * i + j, "┣", COLOR_HWHITE, COLOR_BLACK);
            for (m = 0; m < solution.column; m++) {
                    cct_showstr(4 + 8 * m , 3 + 4 * i + j, "━━━━", COLOR_HWHITE, COLOR_BLACK);
                if (m != solution.column - 1)
                    cct_showstr(4 + 8 * m + n, 3 + 4 * i + j, "╋", COLOR_HWHITE, COLOR_BLACK);
                else
                    cct_showstr(10 + 8 * m, 3 + 4 * i + j, "┫", COLOR_HWHITE, COLOR_BLACK);
                Sleep(DELAY);
            }
        }
        else {
            cct_showstr(2, 3 + 4 * i + j, "┗", COLOR_HWHITE, COLOR_BLACK);
            for (m = 0; m < solution.column; m++) {
                cct_showstr(4 + 8 * m, 3 + 4 * i + j, "━━━━", COLOR_HWHITE, COLOR_BLACK);
                if (m != solution.column - 1)
                    cct_showstr(4 + 8 * m + n, 3 + 4 * i + j, "┻", COLOR_HWHITE, COLOR_BLACK);
                else
                    cct_showstr(10 + 8 * m, 3 + 4 * i + j, "┛", COLOR_HWHITE, COLOR_BLACK);
                Sleep(DELAY);
            }
        }
    }
    //PART 2.覆盖色块
    for (i = 0; i < solution.row; i++) {
        for (m = 0; m < solution.column; m++)
            form(i, m, 0, 0, COLOR_BLACK);
    }
    //PART 3.打印屏幕设置
    cct_gotoxy(0, 0);
    cct_setcolor(); //恢复缺省颜色
    cout << "屏幕当前设置为：" << 45 + 8 * (solution.column - 5) << "行" << 27 + 4 * (solution.row - 5) << "列" << endl;
}
/*打印制表符*/
void table_sign(int i, int j, int m, int n, int old_row, int old_column, const char* ch,int color)
{
    if (n != 2 || j != 1) {
        if (old_row > -1 && old_row < solution.row && old_column>-1 && old_column < solution.column)
            cct_showstr(4 + 8 * old_column + n, 3 + 4 * old_row + j, ch, solution.record[old_row][old_column], COLOR_BLACK);
        cct_showstr(4 + 8 * m + n, 3 + 4 * i + j, ch, solution.record[i][m], color);
    }
    else {
        if (old_row > -1 && old_row < solution.row && old_column>-1 && old_column < solution.column)
            cct_showint(4 + 8 * old_column + n, 3 + 4 * old_row + j, solution.record[old_row][old_column], solution.record[old_row][old_column], COLOR_BLACK);
        cct_showint(4 + 8 * m + n, 3 + 4 * i + j, solution.record[i][m], solution.record[i][m], color);
    }
}
void form(int i,int m,int old_row,int old_column,int color)
{
    int j, n;
    for (j = 0; j < 4; j++) {
        for (n = 0; n < 5; n++) {
            switch (n) {
            case 0:
                if (j == 0)
                    table_sign(i, j, m, n, old_row, old_column, "┏", color);
                else if (j == 1)
                    table_sign(i, j, m, n, old_row, old_column, "┃", color);
                else if (j == 2)
                    table_sign(i, j, m, n, old_row, old_column, "┗", color);
                break;
            case 2:
                if (j == 0 || j == 2)
                    table_sign(i, j, m, n, old_row, old_column, "━", color);
                else if (j == 1) 
                    table_sign(i, j, m, n, old_row, old_column, "", color);
                break;
            case 3:
                if (j == 1) {
                    cct_showstr(4 + 8 * old_column + n, 3 + 4 * old_row + j, " ", solution.record[old_row][old_column], COLOR_BLACK);
                    cct_showstr(4 + 8 * m + n, 3 + 4 * i + j, " ", solution.record[i][m], color);
                }
                break;
            case 4:
                if (j == 0)
                    table_sign(i, j, m, n, old_row, old_column, "┓", color);
                else if (j == 1)
                    table_sign(i, j, m, n, old_row, old_column, "┃", color);
                else if (j == 2)
                    table_sign(i, j, m, n, old_row, old_column, "┛", color);
                break;
            }
        }
    }
}
void table_sign_delay(int i, int j, int m, int n, int old_row, int old_column, const char* ch, int color,int count)
{
    int k ;
    for (k = 0; k <= 4 * i; k++) {
        if (n != 2 || j != 1) {
            if (old_row > -1 && old_row < solution.row && old_column>-1 && old_column < solution.column)
                cct_showstr(4 + 8 * old_column + n, count + 4 * old_row + j, ch, solution.record[old_row][old_column], COLOR_BLACK);
            cct_showstr(4 + 8 * m + n, count + k + j, ch, solution.record[i][m], color);
        }
        else {
            if (old_row > -1 && old_row < solution.row && old_column>-1 && old_column < solution.column)
                cct_showint(4 + 8 * old_column + n, count + 4 * old_row + j, solution.record[old_row][old_column], solution.record[old_row][old_column], COLOR_BLACK);
            cct_showint(4 + 8 * m + n, count + k + j, solution.record[i][m], solution.record[i][m], color);
        }
        Sleep(DELAY);
    }
}
void form_delay(int i, int m, int old_row, int old_column, int color)
{
    int j, n, count = 0;
    while (count < 4) {
        for (j = 0; j < 4; j++) {
            for (n = 0; n < 5; n++) {
                switch (n) {
                case 0:
                    if (j == 0)
                        table_sign_delay(i, j, m, n, old_row, old_column, "┏", color, count);
                    else if (j == 1)
                        table_sign_delay(i, j, m, n, old_row, old_column, "┃", color, count);
                    else if (j == 2)
                        table_sign_delay(i, j, m, n, old_row, old_column, "┗", color, count);
                    break;
                case 2:
                    if (j == 0 || j == 2)
                        table_sign_delay(i, j, m, n, old_row, old_column, "━", color, count);
                    else if (j == 1)
                        table_sign_delay(i, j, m, n, old_row, old_column, "", color, count);
                    break;
                case 3:
                    if (j == 1) {
                        cct_showstr(4 + 8 * old_column + n, count + 4 * old_row + j, " ", solution.record[old_row][old_column], COLOR_BLACK);
                        cct_showstr(4 + 8 * m + n, count + 4 * i + j, " ", solution.record[i][m], color);
                    }
                    break;
                case 4:
                    if (j == 0)
                        table_sign_delay(i, j, m, n, old_row, old_column, "┓", color, count);
                    else if (j == 1)
                        table_sign_delay(i, j, m, n, old_row, old_column, "┃", color, count);
                    else if (j == 2)
                        table_sign_delay(i, j, m, n, old_row, old_column, "┛", color, count);
                    break;
                }
            }
        }
        count++;
        Sleep(DELAY);
    }
}
/*选中后显示、合并与下落*/
void show_color(int i, int m)
{
    int x, y;
    form(i, m, i, m, COLOR_HWHITE);
    for (x = 0; x < solution.row; x++) {
        for (y = 0; y < solution.column; y++) {
            if (solution.sign[x][y] == '*' && (x != i || y != m))
                form(x, y, x, y, COLOR_WHITE);
        }
    }
}
void combine_color()
{
    int x, y, j, n;
    for (x = 0; x < solution.row; x++) {
        for (y = 0; y < solution.column; y++) {
            if (solution.sign[x][y] == '*') {
                for (j = 0; j < 3; j++) {
                    for (n = 0; n < 6; n++)
                        cct_showstr(4 + 8 * y + n, 3 + 4 * x + j, " ", COLOR_HWHITE);
                    Sleep(DELAY);
                }
            }
        }
    }
    combine(solution.x, solution.y);
    int count = 0;
    while (count < 6) {
        for (j = 0; j < 3; j++) {
            for (n = 0; n < 6; n++)
                form(solution.x, solution.y, 0, 0, COLOR_BLACK);
        }
        Sleep(DELAY * 10);
        for (j = 0; j < 3; j++) {
            for (n = 0; n < 6; n++)
                cct_showstr(4 + 8 * solution.y + n, 3 + 4 * solution.x + j, " ", COLOR_HWHITE, COLOR_BLACK);
        }
        Sleep(DELAY * 10);
        for (j = 0; j < 3; j++) {
            for (n = 0; n < 6; n++)
                form(solution.x, solution.y, 0, 0, COLOR_BLACK);
        }
        count++;
    }
}
void fall_color()
{
    fall();
    int x, y, j, n;
    for (y = 0; y < solution.column; y++) {
        for (x = 0; x < solution.row; x++) {
            if (solution.record[x][y] == 0) {
                for (j = 0; j < 3; j++) {
                    for (n = 0; n < 6; n++)
                        cct_showstr(4 + 8 * y + n, 3 + 4 * x + j, " ", COLOR_HWHITE, COLOR_BLACK);
                    Sleep(DELAY);
                }
            }
            else {
                for (j = 0; j < 3; j++) {
                    for (n = 0; n < 6; n++)
                        form(x, y, x, y, COLOR_BLACK);
                    Sleep(DELAY);
                }
            }
        }
    }
}
/*新值填充*/
void fill_color()
{
    int x, y;
    srand((unsigned int)(time(0)));
    for (x = 0; x < solution.row; x++) {
        for (y = 0; y < solution.column; y++) {
            if (solution.record[x][y] == 0) {
                random(&solution.record[x][y]);
                form(x, y, x, y, COLOR_BLACK);
            }
        }
    }
}
