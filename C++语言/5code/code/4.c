#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int  a,*p,**pp;
       a=5;
       p=&a;
       pp=&p;
    printf("%d,%d\n",a,*p);
    printf("%d,%d,%d,%d\n",&a,p,&p,pp);//&a==p,&p==pp 
    printf("%d",**pp);//**pp==a==*p 
	
	return 0;
}
