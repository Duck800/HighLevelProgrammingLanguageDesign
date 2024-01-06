/*2151133 孙韩雅 信07*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        cout << setw(2) << n << "# " << src << "-->" << dst << endl;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
    int a;
    char src, tmp = 65, dst;
    while (1) {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> a;
        if (a >= 1 || a <= 16)
            break;
    }
    cin.clear();
    cin.ignore(65536, '\n');
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (src >= 65 && src <= 67)
            break;
        else if (src >= 97 && src <= 99) {
            src -= 32;
            break;
        }
    }
    cin.clear();
    cin.ignore(65536, '\n');
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (dst == src)
            cout << "目标柱(A)不能与起始柱(A)相同" << endl;
        else if (dst >= 65 && dst <= 67)
            break;
        else if (dst >= 97 && dst <= 99) {
            dst -= 32;
            break;
        }
    }
    cin.clear();
    cin.ignore(65536, '\n');
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
    cout << "移动步骤为:" << endl;
    hanoi(a, src, tmp, dst);
}