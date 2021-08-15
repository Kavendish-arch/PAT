#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	int b,s,g;
	scanf("%d",&i);
	b=i/100;
	s=(i%100)/10;
	g=i%10;
	printf("%d",g*100+s*10+b); 
	
	
	
	return 0;
}
