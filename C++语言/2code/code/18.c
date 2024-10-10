#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n1,n2,n3;
	char c;
	scanf("%d%d%d",&n1,&n2,&n3);
	c=(abs(n1%2)+abs(n2%2)+abs(n3%2))==2?'Y':'N';
	printf("%c",c);

	
	return 0;
}
