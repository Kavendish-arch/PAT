#include <iostream>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int i = 5;
	
	int* p = &i;
	
	printf("%0x", p);
	return 0;
}
