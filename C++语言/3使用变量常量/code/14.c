#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	long i,m=1;
	float sum=0;
	for(i=1;i<=10;i++)
	   { 
	     sum=sum+1.0/m;
	     m=m*(i+1); //Î´ÐÞ¸ÄiµÄÖµ 
		}
	printf("%.2f",sum);	
	return 0;
}
