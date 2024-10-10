#include <stdio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int i;
	long sum=0;
	for(i=10;i<=150;i++)
	  if(fabs(i%2)==1)  sum=sum+i*i;
	printf("%ld",sum);  
	return 0;
}
