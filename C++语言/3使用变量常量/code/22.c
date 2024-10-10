 #include "stdio.h"
  int gcd(int m,int n)
  { if (m%n == 0)   return  n ;
   else  return  gcd(n, m % n);
 }

void main()
{  int m,n,t;
   scanf("%d%d",&m,&n);
   if (m<n)  {t=m; m=n; n=t; }      //±£Ö¤m>n
    t= gcd( m,  n);      
    printf("\n gcd=%d",t);
}

