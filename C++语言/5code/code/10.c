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
 printf("����ѧ�ţ�"); 
 scanf("%lf",&p1.num);
 printf("%lf\n",p1.num);
 printf("age�ĵ�ַ��%d\n",&p1.age);
 printf("sex�ĵ�ַ��%d\n",&p1.sex);
 printf("num�ĵ�ַ��%d\n",&p1.num);
}

