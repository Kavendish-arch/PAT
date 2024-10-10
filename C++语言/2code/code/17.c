#include <stdio.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char c;
	c=getchar();
	printf("%c:%d\n%c:%d",c,c,c-32,c-32);
	
	return 0;
}
