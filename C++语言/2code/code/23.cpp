#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main(int argc, char** argv) {
	int i,sum=0;
	for( i=100;i>=1;i-- ) sum=sum+i;
	
	printf("%d",sum);
	
	return 0;
}
