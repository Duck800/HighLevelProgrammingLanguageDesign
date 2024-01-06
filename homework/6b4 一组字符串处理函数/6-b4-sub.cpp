/*2151133 孙韩雅 信07*/

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：tj_strlen
  功    能：求字符串str的长度
  返回值：字符串的长度
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length = 0;
    char* i = (char*)str;
    if (str != NULL) {
        for (; *i != '\0'; i++)
            length++;
    }
    return length;
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：将字符串s2追加到s1后面，含/0
  返 回 值：新的s1
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strncat
  功    能：将字符串的s2的前len个字符追加到s1后面，并加\0
  返 回 值：新的s1
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
 函数名称：tj_strcpy
  功    能：将字符串src复制到字符串dst中,覆盖原dst串
  返 回 值：新的s1
  说    明：字符数组dst要有足够的空间(串src长+1)
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strncpy
  功    能：将字符串src的前n个复制到字符串dst中,覆盖原dst串
  返 回 值：新的s1
  说    明：字符数组dst要有足够的空间(min(串src长,n)+1)
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
  函数名称：tj_strcmp
  功    能：比较字符串s1和字符串s2的大小，英文字母区分大小写
  返 回 值：相等为0，不等则为第1个不相等字符的ASCII值
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strcasecmp
  功    能：比较字符串s1和字符串s2的大小，英文字母不分大小写
  返 回 值：相等为0，不等则为第1个不相等字符的ASCII值
  说    明：若不相等处是大写字母和小写字母，则统一转换为小写字母后比较
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
 函数名称：tj_strncmp
  功    能：比较字符串s1和字符串s2的前n个字符的大小,区分大小写
  返 回 值：相等为0，不等则为第1个不相等字符的ASCII值
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
 函数名称：tj_strcasencmp
  功    能：比较字符串s1和字符串s2的前n个字符的大小，不分大小写
  返 回 值：相等为0，不等则为第1个不相等字符的ASCII值
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
 函数名称：tj_strupr
  功    能：将字符串str中所有小写字母均转为大写，其他字符不变，转换后放在原串中
  返 回 值：转换后的串
***************************************************************************/
char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strlwr
  功    能：将字符串str中所有大写字母均转为小写，其他字符不变，转换后放在原串中
  返 回 值：转换后的串
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strchr
  功    能：在字符串str中寻找字符ch第1次出现的位置，顺序是从左到右
  返 回 值：position
  说    明：找到就返回1-n(位置从1开始)，未找到则返回0
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strstr
  功    能：在字符串str中寻找字符串substr第1次出现的位置，顺序是从左到右
  返 回 值：position
  说    明：找到就返回1-n(位置从1开始)，未找到则返回0
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
 函数名称：tj_strrchr
  功    能：在字符串str中寻找字符ch第1次出现的位置，顺序是从右到左
  返 回 值：position
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strrstr
  功    能：在字符串str中寻找字符串substr第1次出现的位置，顺序是从右往左
  返 回 值：position
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：tj_strrev
  功    能：字符串反转，放入原字符串中
  返 回 值：反转后的串
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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