#include <stdio.h>
enum color
{red,yellow,bule,white,black};
void main()  
{ int c;
  for(c=red;c<=4;c++)
   switch(c)
    {case red:printf("red\n");break;
     case yellow:printf("yellow\n");break;
     case bule:printf("bule\n");break;
     case white:printf("white\n");break;
     case black:printf("black\n");break;
    }
}

