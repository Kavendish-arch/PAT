#include <stdio.h>
#include <cstdlib>
#include <cstring>
/**
 * KMP算法
 */
void GetNext(char s[], int len);
int KMP(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    return 0;
}

/**
 * next 求解
 *
 * s[0-i]
 * s[0----k] == s[i-k --- i]
 */

int[] GetNext(char s[], int len)
{
    int next[len] = {0};
    int j = -1;
    next[0] = -1;
    for (int i = 1; i < len; i++)
    {
        while (j != -1 && s[i] != s[j + 1])
        {
            j = next[j];
        }
        if (s[i] == s[j + 1])
        {
            j++;
        }
        next[i] = j;
    }
    return next;
}

int main(int argc, char const *argv[])
{
    const int len = 10;
    // int *next = malloc(sizeof(int) * len);
    // int *next = malloc(sizeof(int) * len);
    int next[len] = {0};
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", next[i]);
    }
    return 0;
}
