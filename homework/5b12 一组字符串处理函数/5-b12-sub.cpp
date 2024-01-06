/*2151133 孙韩雅 信07*/

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：tj_strlen
  功    能：求字符串的长度
  返 回 值：length
  说    明：返回第一个'\0'前的字符数量,不含'\0'
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length = 0, i;
    for (i = 0; i < 65536; i++) {
        if (str[i] != '\0') {
            length++;
            continue;
        }
        else
            break;
    }
    return length; 
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：将字符串src连接到字符串dst的尾部(含尾零)
  返 回 值：0
  说    明：字符数组dst要有足够的空间(两串总长+1)
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, j;
    for (i = tj_strlen(s1), j = 0; i < tj_strlen(s1) + tj_strlen(s2) + 1, j < tj_strlen(s2) + 1; i++, j++)
        s1[i] = s2[j];
    return 0; 
}

/***************************************************************************
  函数名称：tj_strncat
  功    能：将字符串src的前n个字符连接到字符串dst的尾部
  返 回 值：0
  说    明：字符数组dst要有足够的空间(原dst长度+n+1)
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, j;
    if (len > tj_strlen(s2)) {
        for (i = tj_strlen(s1), j = 0; i < tj_strlen(s1) + len + 1, j < tj_strlen(s2) + 1; i++, j++)
            s1[i] = s2[j];
    }
    else
        for (i = tj_strlen(s1), j = 0; i < tj_strlen(s1) + len + 1, j < len; i++, j++)
            s1[i] = s2[j];
    return 0; 
}

/***************************************************************************
  函数名称：tj_strcpy
  功    能：将字符串src复制到字符串dst中,覆盖原dst串
  返 回 值：0
  说    明：字符数组dst要有足够的空间(串src长+1)
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    if (tj_strlen(s1) > tj_strlen(s2)) {
        for (i = 0; i < tj_strlen(s1) + 1; i++) {
            if (i < tj_strlen(s2) + 1)
                s1[i] = s2[i]; 
        }
    }
    else {
        for (i = 0; i < tj_strlen(s2) + 1; i++) {
            if (i < tj_strlen(s2))
                s1[i] = s2[i];
            else
                s1[i] = '\0';
        }
    }
    return 0; 
}

/***************************************************************************
  函数名称：tj_strncpy
  功    能：将字符串src的前n个复制到字符串dst中,覆盖原dst串
  返 回 值：0
  说    明：字符数组dst要有足够的空间(min(串src长,n)+1)
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    int min = (tj_strlen(s2) > len ? len : tj_strlen(s2));
    if (tj_strlen(s1) > min) {
        for (i = 0; i < tj_strlen(s1) + 1; i++) {
            if (s2[i] == '\0')
                break;
            else if (i < min)
                s1[i] = s2[i];
        }
    }
    else
        for (i = 0; i < min + 1; i++) {
            if (i < min + 1)
                s1[i] = s2[i];
        }
    return 0; 
}

/***************************************************************************
  函数名称：tj_strcmp
  功    能：比较字符串s1和字符串s2的大小，英文字母区分大小写
  返 回 值：dif
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, dif = 0;
    int max = (tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2));
    for (i = 0; i < max + 1; i++) {
        if (s1[i] != s2[i]) {
            dif = (int)s1[i] - (int)s2[i];
            break;
        }
    }
    return dif; 
}

/***************************************************************************
  函数名称：tj_strcasecmp
  功    能：比较字符串s1和字符串s2的大小，英文字母不分大小写
  返 回 值：dif
  说    明：若不相等处是大写字母和小写字母，则统一转换为小写字母后比较
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, dif = 0;
    int max = (tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2));
    char fir, sec;
    for (i = 0; i < max + 1; i++) {
        if (s1[i] > 64 && s1[i] < 91)
            fir = s1[i] + 32;
        else
            fir = s1[i];
        if (s2[i] > 64 && s2[i] < 91)
            sec = s2[i] + 32;
        else
            sec = s2[i];
        if (fir != sec) {
            dif = (int)fir - (int)sec;
            break;
        }
    }
    return dif;
}

/***************************************************************************
  函数名称：tj_strncmp
  功    能：比较字符串s1和字符串s2的前n个字符的大小,区分大小写
  返 回 值：dif
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, dif = 0;
    int str_max = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2);
    int min = len < str_max ? len : str_max;
    for (i = 0; i < min; i++) {
        if (s1[i] != s2[i]) {
            dif = (int)s1[i] - (int)s2[i];
            break;
        }
    }
    return dif; 
}

/***************************************************************************
  函数名称：tj_strcasencmp
  功    能：比较字符串s1和字符串s2的前n个字符的大小，不分大小写
  返 回 值：dif
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i, dif = 0;
    int str_max = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2);
    int min = len < str_max ? len : str_max;
    char fir, sec;
    for (i = 0; i < min; i++) {
        if (s1[i] > 64 && s1[i] < 91)
            fir = s1[i] + 32;
        else
            fir = s1[i];
        if (s2[i] > 64 && s2[i] < 91)
            sec = s2[i] + 32;
        else
            sec = s2[i];
        if (fir != sec) {
            dif = (int)fir - (int)sec;
            break;
        }
    }
    return dif;
}

/***************************************************************************
  函数名称：tj_strupr
  功    能：将字符串str中所有小写字母均转为大写，其他字符不变，转换后放在原串中
  返 回 值：0
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    for (i = 0; i < tj_strlen(str) + 1; i++) {
        if (str[i] > 96 && str[i] < 123)
            str[i] -= 32;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strlwr
  功    能：将字符串str中所有大写字母均转为小写，其他字符不变，转换后放在原串中
  返 回 值：0
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    for (i = 0; i < tj_strlen(str) + 1; i++) {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strchr
  功    能：在字符串str中寻找字符ch第1次出现的位置，顺序是从左到右
  返 回 值：position
  说    明：找到就返回1-n(位置从1开始)，未找到则返回0
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    int position = 0;
    for (i = 0; i < tj_strlen(str) + 1; i++) {
        if (str[i] == ch) {
            position = i + 1;
            break;
        }
    }
    return position; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strstr
  功    能：在字符串str中寻找字符串substr第1次出现的位置，顺序是从左到右
  返 回 值：position
  说    明：找到就返回1-n(位置从1开始)，未找到则返回0
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    int position = 0;
    for (i = 0; i < tj_strlen(str) + 1; i++) {
        if (str[i] == substr[0]) {
            if (tj_strncmp(&str[i], substr, tj_strlen(substr)) == 0) {
                position = i + 1;
                break;
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
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    int position = 0;
    for (i = tj_strlen(str) + 1; i >= 0; i--) {
        if (str[i] == ch) {
            position = i + 1;
            break;
        }
    }
    return position;
}

/***************************************************************************
  函数名称：tj_strrstr
  功    能：在字符串str中寻找字符串substr第1次出现的位置，顺序是从右往左
  返 回 值：position
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    int position = 0;
    for (i = tj_strlen(str) + 1; i >= 0; i--) {
        if (str[i] == substr[0]) {
            if (tj_strncmp(&str[i], substr, tj_strlen(substr)) == 0) {
                position = i + 1;
                break;
            }
        }
    }
    return position;
}

/***************************************************************************
  函数名称：tj_strrev
  功    能：字符串反转，放入原字符串中
  返 回 值：0
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    char mid;
    for (i = 0; i < tj_strlen(str)/2; i++) {
        mid = str[i];
        str[i] = str[tj_strlen(str) - i - 1];
        str[tj_strlen(str) - i - 1] = mid;
    }
    return 0; //return值可根据需要修改
}