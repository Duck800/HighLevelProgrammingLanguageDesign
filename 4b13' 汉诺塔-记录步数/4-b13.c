/*2151133 �ﺫ�� ��07*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ��
      ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

int i = 1;

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
    int a;
    char src, tmp = 65, dst;
    while (1) {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
        scanf("%d", &a);
        if (a >= 1 && a <= 16)
            break;
    }
    fflush(stdin);
    while (getchar() != '\n')
        continue;
    while (1) {
        printf("��������ʼ��(A-C)��\n");
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
        printf("������Ŀ����(A-C)��\n");
        scanf("%c", &dst);
        if (dst == src)
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
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
    printf("�ƶ�����Ϊ:\n");
    hanoi(a, src, tmp, dst);
}