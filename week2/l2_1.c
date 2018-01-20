#include <stdio.h>
#include <stdlib.h>
#define max(x,y) ((x>y)? x:y)
#define min(x,y) ((x<y)? x:y)

int consecutive(int m, int n)
        {
        	if(m==0)
        		return n;
        	else if(n==0)
        		return m;
        

           int t=min(n,m);
               //t=(n==0) ? m :(m==0) ? n:1;
            while (t != 1)
            {
                if (m % t == 0)
                {
                    if (n % t == 0)
                    {
                        return t;
                    }
                    t = t - 1;
                }
                else t = t-1;
            }
            return t;
        }  

int main(int argc, char const *argv[])
{
	int n,m,ans;
	printf("inset two numbers\n");
	scanf("%d",&n);
	scanf("%d",&m);
	ans=consecutive(n,m);
	printf("GCD= %d \n",ans);
	return 0;
}


