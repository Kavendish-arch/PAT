#include <stdio.h>
int char2int(char num);
int num2pinyin(int num);
int main()
{
    char tmp;
    int sum = 0;
    do
    {
        tmp = getchar();
        sum += char2int(tmp);
    } while (tmp != '\n');
    // printf("%d",sum);
    int num[1000], i = 0;
    while (sum != 0)
    {
        num[i++] = sum % 10;
        sum = sum / 10;
    }
    //
    for (int j = --i; j >= 0; j--)
    {
        num2pinyin(num[j]);
        // 最后空格会出格式错误
        if (j != 0)
        {
            printf(" ");
        }
    }
    return 0;
}
// 输入的数字字符转数字，必须没有负数
int char2int(char num)
{
    if (num < '0' || num > '9')
    {
        return 0;
    }
    return num - '0';
}
// 结果用拼音表示
int num2pinyin(int num)
{
    switch (num)
    {
    case 0:
        printf("ling");
        break;
    case 1:
        printf("yi");
        break;
    case 2:
        printf("er");
        break;
    case 3:
        printf("san");
        break;
    case 4:
        printf("si");
        break;
    case 5:
        printf("wu");
        break;
    case 6:
        printf("liu");
        break;
    case 7:
        printf("qi");
        break;
    case 8:
        printf("ba");
        break;
    case 9:
        printf("jiu");
        break;
    default:
        break;
    }
    return 0;
}
