#include <stdio.h>
typedef struct
{
 int year;
 int month;
 int day;
}date; //全局变量 
int days(date d)
{
 int num = 0;
 int m, da, i;
 if ((d.year %4 == 0 && d.year %100!=0)||(d.year % 400 == 0))
 {
  for (m = 1; m <= d.month ; m++)
  {
   if (m == 2)
    da = 29;
   else if (m==4||m==6||m==8||m==11)
    da = 30;
   else
    da = 31;
   for (i = 1; i <= da;i++)
   {
    num++;
    if ( m == d.month && i == d.day )     return num;
   }
  }
     
 }
 else
 {
  for (m = 1; m <= d.month ; m++)
  {
   if (m == 2)
    da = 28;
   else if (m==4||m==6||m==8||m==11)
    da = 30;
   else
    da = 31;
   for (i = 1; i <= da;i++)
   {
    num++;
    if ( m == d.month && i == d.day )
     return num;
   }
  }
 }
 
}
int main()
{
 date d;
 scanf("%d%d%d",&d.year,&d.month,&d.day);
 printf("%d年%d月%d日是本年的第%d天",d.year,d.month,d.day,days(d));
 return 0;
}
