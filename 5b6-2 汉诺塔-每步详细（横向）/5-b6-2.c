/*2151133 孙韩雅 信07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*记录柱的内容*/int cont[3][10];
/*次数*/int i = 1;
/*栈顶指针数组*/int top[3] = { 0 };

void hanoi(int n, char src, char tmp, char dst)
{
    int j;
    if (n == 1) {
        printf("第%4d 步(%2d): %c-->%c", i, n, src, dst);
        i++;
        if (src == 65) {
            if (dst == 66) {
                cont[1][top[1]++] = cont[0][--top[0]];
                cont[0][top[0]] = 0;
            }
            else {
                cont[2][top[2]++] = cont[0][--top[0]];
                cont[0][top[0]] = 0;
            }
        }
        else if (src == 66) {
            if (dst == 65) {
                cont[0][top[0]++] = cont[1][--top[1]];
                cont[1][top[1]] = 0;
            }
            else {
                cont[2][top[2]++] = cont[1][--top[1]];
                cont[1][top[1]] = 0;
            }
        }
        else if (src == 67) {
            if (dst == 65) {
                cont[0][top[0]++] = cont[2][--top[2]];
                cont[2][top[2]] = 0;
            }
            else {
                cont[1][top[1]++] = cont[2][--top[2]];
                cont[2][top[2]] = 0;
            }
        }
        printf(" A:");
        for (j = 0; j < 10; j++) {
            if (cont[0][j] != 0)
                printf("%2d", cont[0][j]);
            else
                printf("  ");
        }
        printf(" B:");
        for (j = 0; j < 10; j++) {
            if (cont[1][j] != 0)
                printf("%2d", cont[1][j]);
            else
                printf("  ");
        }
        printf(" C:");
        for (j = 0; j < 10; j++) {
            if (cont[2][j] != 0)
                printf("%2d", cont[2][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c", i, n, src, dst);
        if (src == 65) {
            if (dst == 66) {
                cont[1][top[1]++] = cont[0][--top[0]];
                cont[0][top[0]] = 0;
            }
            else {
                cont[2][top[2]++] = cont[0][--top[0]];
                cont[0][top[0]] = 0;
            }
        }
        else if (src == 66) {
            if (dst == 65) {
                cont[0][top[0]++] = cont[1][--top[1]];
                cont[1][top[1]] = 0;
            }
            else {
                cont[2][top[2]++] = cont[1][--top[1]];
                cont[1][top[1]] = 0;
            }
        }
        else if (src == 67) {
            if (dst == 65) {
                cont[0][top[0]++] = cont[2][--top[2]];
                cont[2][top[2]] = 0;
            }
            else {
                cont[1][top[1]++] = cont[2][--top[2]];
                cont[2][top[2]] = 0;
            }
        }
        printf(" A:");
        for (j = 0; j < 10; j++) {
            if (cont[0][j] != 0)
                printf("%2d", cont[0][j]);
            else
                printf("  ");
        }
        printf(" B:");
        for (j = 0; j < 10; j++) {
            if (cont[1][j] != 0)
                printf("%2d", cont[1][j]);
            else
                printf("  ");
        }
        printf(" C:");
        for (j = 0; j < 10; j++) {
            if (cont[2][j] != 0)
                printf("%2d", cont[2][j]);
            else
                printf("  ");
        }
        printf("\n");
        i++;
        hanoi(n - 1, tmp, src, dst);
    }
}

int main()
{
    int n, ret;
    char src, tmp = 65, dst;
    while (1) {
        printf("请输入汉诺塔的层数(1-10)：\n");
        ret = scanf("%d", &n);
        if (ret == 0) {
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            continue;
        }
        else if (n >= 1 && n <= 10) {
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
                break;
        }
        else {
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            continue;
        }
    }
    while (1) {
        printf("请输入起始柱(A-C)：\n");
        ret = scanf("%c", &src);
        if (ret == 0) {
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            continue;
        }
        else if (src >= 65 && src <= 67) {
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            break;
        }
        else if (src >= 97 && src <= 99) {
            src -= 32;
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            break;
        }
        else {
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            continue;
        }
    }
    while (1) {
        printf("请输入目标柱(A-C)：\n");
        ret = scanf("%c", &dst);
        if (ret == 0) {
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            continue;
        }
        else if (dst == src) {
            printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            continue;
        }
        else if (dst >= 65 && dst <= 67) {
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            break;
        }
        else if (dst >= 97 && dst <= 99) {
            dst -= 32;
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
            break;
        }
        else {
            fflush(stdin);
            while (getchar() != '\n') {
                continue;
            }
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
    printf("初始:               ");
    printf(" A:");
    if (src == 65)
        for (j = n; j > 0; j--)
            cont[0][top[0]++] = j;
    for (j = 0; j < 10; j++) {
        if (cont[0][j] != 0)
            printf("%2d", cont[0][j]);
        else
            printf("  ");
    }
    printf(" B:");
    if (src == 66)
        for (j = n; j > 0; j--)
            cont[1][top[1]++] = j;
    for (j = 0; j < 10; j++) {
        if (cont[1][j] != 0)
            printf("%2d", cont[1][j]);
        else
            printf("  ");
    }
    printf(" C:");
    if (src == 67)
        for (j = n; j > 0; j--)
            cont[2][top[2]++] = j;
    for (j = 0; j < 10; j++) {
        if (cont[2][j] != 0)
            printf("%2d", cont[2][j]);
        else
            printf("  ");
    }
    printf("\n");
    hanoi(n, src, tmp, dst);
}
