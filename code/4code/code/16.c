#include <stdio.h>
   #include <string.h>
   main( )
{   char str1[80],str2[80];
    int i=0,l1;
    printf("Input str1:");
    gets(str1);
    printf("Input str2:");
    gets(str2);
    l1=strlen(str1);   
    while(str2[i])
    {   str1[l1+i]=str2[i];  i++; }
    str1[l1+i]='\0';    
    puts(str1);   
}

