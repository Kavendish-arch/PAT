#include <stdio.h>
#define MAXSIZE 5 
int main(int argc, char *argv[]) {
	int a[MAXSIZE];
	int n,count=0;
	int i;
	scanf("%d",&n); 
	while(n!=0)
	{ a[count]=n%10;
	  n=n/10;
	  count++;	}
	for(i=count-1;i>=0;i--) printf("%-5d",a[i]);
	return 0;
}   

