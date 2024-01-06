/*2151133 孙韩雅 信07*/
#include <iostream>
#include <iomanip>
using namespace std;

/*记录柱的内容*/int a[10], b[10], c[10];
/*次数*/int i = 1;
/*栈顶指针*/int top_a = 0, top_b = 0, top_c = 0;

void hanoi(int n, char src, char tmp, char dst)
{
    int j;
    if (n == 1) {
        cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "): " << src << "-->" << dst;
        i++;
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
    else {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << i << " 步" << "(" << setw(2) << n << "): " << src << "-->" << dst;
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
        i++;
        hanoi(n - 1, tmp, src, dst);
    }
}

int main()
{
    int n;
    char src, tmp = 65, dst;
    while (1) {
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
    while (1) {
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
    while (1) {
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

    /*循环控制*/int j;
    cout << "初始:               ";
    cout << " A:";
    if (src == 65)
        for (j = n; j > 0; j--)
            a[top_a++] = j;
    for (j = 0; j < 10; j++) {
        if (a[j] != 0)
            cout << setw(2) << a[j];
        else
            cout << "  ";
    }
    cout << " B:";
    if (src == 66)
        for (j = n; j > 0; j--)
            b[top_b++] = j;
    for (j = 0; j < 10; j++) {
        if (b[j] != 0)
            cout << setw(2) << b[j];
        else
            cout << "  ";
    }
    cout << " C:";
    if (src == 67)
        for (j = n; j > 0; j--)
            c[top_c++] = j;
    for (j = 0; j < 10; j++) {
        if (c[j] != 0)
            cout << setw(2) << c[j];
        else
            cout << "  ";
    }
    cout << endl;
    hanoi(n, src, tmp, dst);
}
