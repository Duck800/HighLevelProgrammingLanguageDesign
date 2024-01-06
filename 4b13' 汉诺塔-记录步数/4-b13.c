/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环
      如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

int i = 1;

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
    static int i = 1;
    if (n == 1) {
        printf("%5d:%3d# %c-->%c\n", i, n, src, dst);
        i++;
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        printf("%5d:%3d# %c-->%c\n", i, n, src, dst);
        i++;
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
        printf("请输入汉诺塔的层数(1-16)\n");
        scanf("%d", &a);
        if (a >= 1 && a <= 16)
            break;
    }
    fflush(stdin);
    while (getchar() != '\n')
        continue;
    while (1) {
        printf("请输入起始柱(A-C)：\n");
        scanf("%c", &src);
        if (src >= 65 && src <= 67)
            break;
        else if (src >= 97 && src <= 99) {
            src -= 32;
            break;
        }
    }
    fflush(stdin);
    while (getchar() != '\n')
        continue;
    while (1) {
        printf("请输入目标柱(A-C)：\n");
        scanf("%c", &dst);
        if (dst == src)
            printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
        else if (dst >= 65 && dst <= 67)
            break;
        else if (dst >= 97 && dst <= 99) {
            dst -= 32;
            break;
        }
    }
    fflush(stdin);
    while (getchar() != '\n')
        continue;
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
    printf("移动步骤为:\n");
    hanoi(a, src, tmp, dst);
}