#include "stdio.h"
#include "string.h"
#include "stdlib.h"
/**
 * 模拟用户登录 
 */ 
// define struct of user (id , password)
typedef struct
{
   long id;
   char pwd[6];
}user;

// a list of users(id ,password)
user users[50];

void init(int n)
{
   /**
    * init the list of users, the lenth of list is n 
    */ 
	user *p;
	int i;
	p = users;
   //ָinput user(id, pwd)
	printf("input your id and your password():\n");
	for(i = 0; i < n; i++)
	{
       scanf("%ld%s",&p[i].id, p[i].pwd);
	}
}
int main()
{
   long stuid;
   char stupwd[6];
   int i;
   int n;
   printf("input num of users:\n");
   scanf("%d",&n);
   init(n);
   //init users
	printf("input your id and your password():\n");
   scanf("%ld%s",&stuid,stupwd);
   for(i=0;i<n;i++)
   {
      
      if(stuid == users[i].id && strcmp(stupwd,users[i].pwd)==0)
	   {
		   printf("correct ");	
	      system("pause");
		   break;
	   }
   }
   if(i==5)
      printf("the pwd is to long");
   return 0;
}
