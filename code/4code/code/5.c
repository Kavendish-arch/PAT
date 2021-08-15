#include <stdio.h>
main()
{int i,q=1,qq=1,f;
printf("%7d%7d",q,qq);
 for(i=2; i<=19;i++)
        {
        	f=q+qq;
        	printf("%7d",f);
        	qq=q;
        	q=f;
		}
  
        

}

