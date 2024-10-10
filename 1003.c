/**
 * 答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
  得到“答案正确”的条件是：
  字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
  任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
  如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
  现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
 */

/**
 * 1. 字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符
 * 2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
 * 3. P之前的 T之后的A个数相同，
 * 重点在于条件二三
 * 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、b、c 均或者是空字符串，或者是仅由字母 A 组成的字符串
 * aPbTc  a=c b=A
 * APATA  a=A b=A c=A  APAATAA
 * AAPATAA a=AA b=A c=AA  AAPAATAAAA
 * 要想 aPbTc 满足 则 aP(b-1)T(c-a)要满足
 * 最终 aP(b-n)T(c-na) 满足 xPATx
 * a = x, b - n = 1, c - na = x
 * c -(b-1)a = a
 * c = a * b
 */

#include <stdio.h>
int pat_2(char *a);

int main()
{
    int n = 0;
    scanf("%d", &n);
    char a[102];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a);
        if (pat_2(a) != 1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}
int pat_2(char *a)
{
    int i = 0;
    int p = 0, t = 0;

    while (a[i] != '\0')
    {
        if (a[i] != 'P' && a[i] != 'A' && a[i] != 'T')
        {
            return 0;
        }
        i++;
    }
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'P')
        {
            p = i;
        }
        if (a[i] == 'T')
        {
            t = i;
        }
    }
    if (t - p < 2)
    {
        return 0;
    }
    if (p * (t - p - 1) == i - t - 1)
    {
        return 1;
    }
}
