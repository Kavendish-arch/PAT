#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j;
	for(i=1;i<=5;i++)
	 {for(j=1;j<=6-i;j++) putchar(' ');
	  for(j=1;j<=2*i-1;j++) printf("%d",j);
	  for(j=i;j>=1;j--) printf("%d",j);
	  putchar('\n');
	 }
	
	return 0;
}
