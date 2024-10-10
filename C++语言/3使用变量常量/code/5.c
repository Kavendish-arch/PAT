#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t,count; 
	for (t=0; t<10; t++)
   { count=1;
     for( ;  ; )
         { printf("%4d",count);
           count++;
           if (count==10) break;
         }
    }

	return 0;
}
