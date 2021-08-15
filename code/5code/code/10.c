#include <stdio.h>
union person
{double num;
 char sex;
 int age;
 }; 
union person p1;
void main()  
{ 
 printf("%d\n",sizeof(p1));
 printf("输入学号："); 
 scanf("%lf",&p1.num);
 printf("%lf\n",p1.num);
 printf("age的地址：%d\n",&p1.age);
 printf("sex的地址：%d\n",&p1.sex);
 printf("num的地址：%d\n",&p1.num);
}

