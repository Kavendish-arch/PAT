#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int g,s,b;
	for(b=1;b<=9;b++)
	  for(s=0;s<=9;s++)
	    for(g=0;g<=9;g++)
	      if(b*b*b+s*s*s+g*g*g==b*100+s*10+g) printf("%4d",b*100+s*10+g);
	
	return 0;
}
