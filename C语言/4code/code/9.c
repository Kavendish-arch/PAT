#include <stdio.h>
main()
{char a[]="how are you?";
 int i;
 for(i=0;i<12;i++) printf("%c",a[i]);
 printf("\n");
 for(i=0;a[i]!='\0';i++) printf("%c",a[i]);
 printf("\n%s",a);
}

