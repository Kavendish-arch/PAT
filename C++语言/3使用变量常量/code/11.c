#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float i,z,m,t,sum=0;
	z=1;
	m=2;
	for(i=1;i<=20;i++)
	  {
	  	sum=sum+z/m;
	  	t=z;
	  	z=m;
	  	m=m+t;    //m=z+m;z=m-z; 
	  }
	printf("%.2f",sum);
	
	return 0;
}
