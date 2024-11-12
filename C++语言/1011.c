/**
1011 A+B 和 C (15 分)
给定区间 [−2**31 ,2**31 ] 内的 3 个整数 A、B 和 C，请判断 A+B 是否大于 C。

输入格式：
输入第 1 行给出正整数 T (≤10)，是测试用例的个数。随后给出 T 组测试用例，每组占一行，顺序给出 A、B 和 C。整数间以空格分隔。

输出格式：
对每组测试用例，在一行中输出 Case #X: true 如果 A+B>C，否则输出 Case #X: false，其中 X 是测试用例的编号（从 1 开始）。
 */
/**
  重点，大数的处理
  如果是python就很简单
*/
#include<stdio.h>
int main(){
    long int a = 0, b = 0, c = 0;
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%ld%ld%ld", &a, &b, &c);
        if (a+b>c)
        {
            printf("Case #%d: true\n",i+1);
        } 
        else
        {
            printf("Case #%d: false\n",i+1);
        }
    }
    return 0;
}

/**
提交结果
提交时间	状态	分数	题目	编译器	耗时	用户
2021/04/12 12:55:21	答案正确  15	编程题	C++ (g++)	3 ms	chen
测试点	结果	分数	耗时	内存
0	  答案正确  9	  2 ms	196 KB
1	  答案正确  3 	3 ms	336 KB
2	  答案正确  3	  3 ms	164 KB
*/

