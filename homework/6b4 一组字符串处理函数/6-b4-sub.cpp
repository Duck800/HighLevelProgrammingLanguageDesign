/*2151133 �ﺫ�� ��07*/

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�tj_strlen
  ��    �ܣ����ַ���str�ĳ���
  ����ֵ���ַ����ĳ���
***************************************************************************/
int tj_strlen(const char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length = 0;
    char* i = (char*)str;
    if (str != NULL) {
        for (; *i != '\0'; i++)
            length++;
    }
    return length;
}

/***************************************************************************
  �������ƣ�tj_strcat
  ��    �ܣ����ַ���s2׷�ӵ�s1���棬��/0
  �� �� ֵ���µ�s1
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i = s1+ tj_strlen(s1), * j = (char*)s2;
    if (s1 != NULL) {
        if (s2 != NULL) {
            for (; i < s1 + tj_strlen(s1) + tj_strlen(s2) + 1, j < s2 + tj_strlen(s2) + 1; i++, j++)
                *i = *j;
            return s1;
        }
        else
            return s1;
    }
    else
        return NULL;
}

/***************************************************************************
  �������ƣ�tj_strncat
  ��    �ܣ����ַ�����s2��ǰlen���ַ�׷�ӵ�s1���棬����\0
  �� �� ֵ���µ�s1
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i, * j;
    if (s1 != NULL) {
        if (s2 != NULL) {
            if (len > tj_strlen(s2)) {
                for (i = s1 + tj_strlen(s1), j = (char*)s2; i < s1 + tj_strlen(s1) + len + 1, j < s2 + tj_strlen(s2) + 1; i++, j++)
                    *i = *j;
            }
            else
                for (i = s1 + tj_strlen(s1), j = (char*)s2; i < s1 + tj_strlen(s1) + len + 1, j < s2 + len; i++, j++)
                    *i = *j;
            return s1;
        }
        else
            return s1;
    }
    else
        return NULL;
}

/***************************************************************************
 �������ƣ�tj_strcpy
  ��    �ܣ����ַ���src���Ƶ��ַ���dst��,����ԭdst��
  �� �� ֵ���µ�s1
  ˵    �����ַ�����dstҪ���㹻�Ŀռ�(��src��+1)
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i = s1, * j = (char*)s2;
    if (s1 != NULL) {
        if (s2 != NULL) {
            if (tj_strlen(s1) > tj_strlen(s2)) {
                for (; i < s1 + tj_strlen(s1) + 1; i++, j++) {
                    if (i < s1 + tj_strlen(s2) + 1)
                        *i = *j;
                }
            }
            else {
                for (; i < s1 + tj_strlen(s2) + 1; i++, j++) {
                    if (i < s1 + tj_strlen(s2))
                        *i = *j;
                    else
                        *i = '\0';
                }
            }
        }
        else {
            for (; i < s1 + tj_strlen(s1) + 1; i++)
                *i = '\0';
        }
        return s1;
    }
    else
        return NULL;
}

/***************************************************************************
  �������ƣ�tj_strncpy
  ��    �ܣ����ַ���src��ǰn�����Ƶ��ַ���dst��,����ԭdst��
  �� �� ֵ���µ�s1
  ˵    �����ַ�����dstҪ���㹻�Ŀռ�(min(��src��,n)+1)
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    char* i = s1, * j = (char*)s2;
    int min = (tj_strlen(s2) > len ? len : tj_strlen(s2));
    if (s1 != NULL) {
        if (s2 != NULL) {
            if (tj_strlen(s1) > min) {
                for (; i < s1 + tj_strlen(s1) + 1; i++, j++) {
                    if (*j == '\0')
                        break;
                    else if (i < s1 + min)
                        *i = *j;
                }
            }
            else
                for (; i < s1 + min + 1; i++, j++) {
                    if (i < s1 + min + 1)
                        *i = *j;
                }
        }
        return s1;
    }
    else
        return NULL;
}

/***************************************************************************
  �������ƣ�tj_strcmp
  ��    �ܣ��Ƚ��ַ���s1���ַ���s2�Ĵ�С��Ӣ����ĸ���ִ�Сд
  �� �� ֵ�����Ϊ0��������Ϊ��1��������ַ���ASCIIֵ
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int dif = 0;
    char* i = (char*)s1, * j = (char*)s2;
    int max = (tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2));
    if (s1 != NULL) {
        if (s2 != NULL) {
            for (; i < s1 + max + 1; i++, j++) {
                if (*i != *j) {
                    dif = *i - *j;
                    break;
                }
            }
            return dif;
        }
        else
            return 1;
    }
    else if (s2 != NULL)
        return -1;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�tj_strcasecmp
  ��    �ܣ��Ƚ��ַ���s1���ַ���s2�Ĵ�С��Ӣ����ĸ���ִ�Сд
  �� �� ֵ�����Ϊ0��������Ϊ��1��������ַ���ASCIIֵ
  ˵    ����������ȴ��Ǵ�д��ĸ��Сд��ĸ����ͳһת��ΪСд��ĸ��Ƚ�
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int dif = 0;
    char* i = (char*)s1, * j = (char*)s2;
    int max = (tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2));
    char fir, sec;
    if (s1 != NULL) {
        if (s2 != NULL) {
            for (; i < s1 + max + 1; i++, j++) {
                if (*i > 64 && *i < 91)
                    fir = *i + 32;
                else
                    fir = *i;
                if (*j > 64 && *j < 91)
                    sec = *j + 32;
                else
                    sec = *j;
                if (fir != sec) {
                    dif = fir - sec;
                    break;
                }
            }
            return dif;
        }
        else
            return 1;
    }
    else if (s2 != NULL)
        return -1;
    else
        return 0;
}

/***************************************************************************
 �������ƣ�tj_strncmp
  ��    �ܣ��Ƚ��ַ���s1���ַ���s2��ǰn���ַ��Ĵ�С,���ִ�Сд
  �� �� ֵ�����Ϊ0��������Ϊ��1��������ַ���ASCIIֵ
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int dif = 0;
    char* i = (char*)s1, * j = (char*)s2;
    int str_max = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2);
    int min = len < str_max ? len : str_max;
    if (s1 != NULL) {
        if (s2 != NULL) {
            for (; i < s1 + min; i++, j++) {
                if (*i != *j) {
                    dif = *i - *j;
                    break;
                }
            }
            return dif;
        }
        else
            return 1;
    }
    else if (s2 != NULL)
        return -1;
    else
        return 0;
}

/***************************************************************************
 �������ƣ�tj_strcasencmp
  ��    �ܣ��Ƚ��ַ���s1���ַ���s2��ǰn���ַ��Ĵ�С�����ִ�Сд
  �� �� ֵ�����Ϊ0��������Ϊ��1��������ַ���ASCIIֵ
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int dif = 0;
    char* i = (char*)s1, * j = (char*)s2;
    int str_max = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2);
    int min = len < str_max ? len : str_max;
    char fir, sec;
    if (s1 != NULL) {
        if (s2 != NULL) {
            for (; i < s1 + min; i++, j++) {
                if (*i > 64 && *i < 91)
                    fir = *i + 32;
                else
                    fir = *i;
                if (*j > 64 && *j < 91)
                    sec = *j + 32;
                else
                    sec = *j;
                if (fir != sec) {
                    dif = fir - sec;
                    break;
                }
            }
            return dif;
        }
        else
            return 1;
    }
    else if (s2 != NULL)
        return -1;
    else
        return 0;
}

/***************************************************************************
 �������ƣ�tj_strupr
  ��    �ܣ����ַ���str������Сд��ĸ��תΪ��д�������ַ����䣬ת�������ԭ����
  �� �� ֵ��ת����Ĵ�
***************************************************************************/
char* tj_strupr(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i = str;
    if (str != NULL) {
        for (; i < str + tj_strlen(str) + 1; i++) {
            if (*i > 96 && *i < 123)
                *i -= 32;
        }
        return str;
    }
    else
        return NULL;
}

/***************************************************************************
  �������ƣ�tj_strlwr
  ��    �ܣ����ַ���str�����д�д��ĸ��תΪСд�������ַ����䣬ת�������ԭ����
  �� �� ֵ��ת����Ĵ�
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i = str;
    if (str != NULL) {
        for (; i < str + tj_strlen(str) + 1; i++) {
            if (*i > 64 && *i < 91)
                *i += 32;
        }
        return str;
    }
    else
        return NULL;
}

/***************************************************************************
  �������ƣ�tj_strchr
  ��    �ܣ����ַ���str��Ѱ���ַ�ch��1�γ��ֵ�λ�ã�˳���Ǵ�����
  �� �� ֵ��position
  ˵    �����ҵ��ͷ���1-n(λ�ô�1��ʼ)��δ�ҵ��򷵻�0
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i = (char*)str;
    int position = 0;
    if (str != NULL) {
        for (; i < str + tj_strlen(str) + 1; i++) {
            if (*i == ch) {
                position = i - str + 1;
                break;
            }
        }
    }
    return position;
}

/***************************************************************************
  �������ƣ�tj_strstr
  ��    �ܣ����ַ���str��Ѱ���ַ���substr��1�γ��ֵ�λ�ã�˳���Ǵ�����
  �� �� ֵ��position
  ˵    �����ҵ��ͷ���1-n(λ�ô�1��ʼ)��δ�ҵ��򷵻�0
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i = (char*)str;
    int position = 0;
    if (str != NULL) {
        if (substr != NULL) {
            for (; i < str + tj_strlen(str) + 1; i++) {
                if (*i == *substr) {
                    if (tj_strncmp(i, substr, tj_strlen(substr)) == 0) {
                        position = i - str + 1;
                        break;
                    }
                }
            }
        }
    }
    return position;
}

/***************************************************************************
 �������ƣ�tj_strrchr
  ��    �ܣ����ַ���str��Ѱ���ַ�ch��1�γ��ֵ�λ�ã�˳���Ǵ��ҵ���
  �� �� ֵ��position
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i = (char*)str + tj_strlen(str) + 1;
    int position = 0;
    if (str != NULL) {
        for (; i >= str; i--) {
            if (*i == ch) {
                position = i - str + 1;
                break;
            }
        }
    }
    return position;
}

/***************************************************************************
  �������ƣ�tj_strrstr
  ��    �ܣ����ַ���str��Ѱ���ַ���substr��1�γ��ֵ�λ�ã�˳���Ǵ�������
  �� �� ֵ��position
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i = (char*)str + tj_strlen(str) + 1;
    int position = 0;
    if (str != NULL) {
        if (substr != NULL) {
            for (; i >= str; i--) {
                if (*i == *substr) {
                    if (tj_strncmp(i, substr, tj_strlen(substr)) == 0) {
                        position = i - str + 1;
                        break;
                    }
                }
            }
        }
    }
    return position;
}

/***************************************************************************
  �������ƣ�tj_strrev
  ��    �ܣ��ַ�����ת������ԭ�ַ�����
  �� �� ֵ����ת��Ĵ�
***************************************************************************/
char* tj_strrev(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* i = str;
    char mid;
    if (str != NULL) {
        for (; i < str + tj_strlen(str)/2 ; i++) {
            mid = *i;
            *i = *(str + (tj_strlen(str) - (i - str) - 1));
            *(str + (tj_strlen(str) - (i - str) - 1)) = mid;
        }
    }
    return str;
}