/**
 * @file 反转字符串.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<stdio.h>
using namespace std;

void reverseString(char* s, int sSize){
    int left = 0, right = sSize - 1;
    char tmp = ' ';
    while (left <= right)
    {
        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left ++;
        right --;
    }
}

char * reverseWords(char * s){
    char word[10000];
    int top = 0;
    int sz = 0;
    while (s[sz++] != '\0');
    for(int i = 0; i < sz; i++)
    {
        if(s[i] == ' ' || s[i] == '\0')
        {
            int h = i - top;

            for(int j = h; j < i; j++)
            {
                s[j] = word[--top];
            }
        }
        else
        {
            word[top++] = s[i];
        }
    }
    return s;
}
void reverSubStr(char * s, int head, int tail )
{
    int left = head, right = tail;
    while (left <= right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left ++;
        right --;
    }
    
}
char * reverseWords2(char * s){
    int sz = 0;
    while (s[sz++] != '\0');

    int head = 0, tail = 0;
    for (int i = 0; i < sz; i++){
        if(s[i] == ' ' || s[i] == '\0')
        {
            // printf("(%d,%d) \n",head, tail);
            while (head <= tail)
            {
                char tmp = s[tail];
                s[tail] = s[head];
                s[head] = tmp;
                tail --;
                head ++;
            }
            head = i+1;
        }
        else
        {
            tail = i;
        }
    }
    // printf("%s\n",s);
    return s;
}
int main(int argc, char const *argv[])
{
    char s[] = "Let's take LeetCode contest";
    char *b = reverseWords2(s);
    return 0;
}
