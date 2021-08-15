#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[10],*p1,*p2;
	p1=a,p2=&a[3];
     if(p2>p1) printf("T");
     else printf("F");

	return 0;
}
