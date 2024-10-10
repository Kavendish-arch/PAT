#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	
	for(i=1;i<1000;i=i+5)
	{
	 printf("%ld,",2*i*i);
	 printf("%ld\n",2*i*i+2*i+1);}
	return 0;
}
