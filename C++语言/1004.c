/** 
 * 1004 成绩排名 (20 分)读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
 * 简单：
 * 知识点：结构体
 */

#include<stdio.h>

struct stu
{
    char name[12];
    char stuNo[12];
    int grade;
};

int getMaxAndMin(struct stu *list, int len) ;

int main() {
    int n = 0;
    scanf("%d",&n);
    struct stu stus[1000] = {};
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%d", stus[i].name, stus[i].stuNo, &stus[i].grade);
    }
    getMaxAndMin(stus, n);
    return 0;
}

int getMaxAndMin(struct stu *list, int len) 
{
    int max = 0;
    int min = 0;
    for (int i = 1; i < len; i ++ )
    {
        if(list[i].grade > list[max].grade)
        {
            max = i;
        }
        if(list[i].grade < list[min].grade)
        {
            min = i;
        }
    }
    printf("%s %s\n",list[max].name, list[max].stuNo);
    printf("%s %s\n",list[min].name, list[min].stuNo);
    return 0;
}
