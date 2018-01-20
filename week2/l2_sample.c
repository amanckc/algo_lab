#include <stdio.h>
#include <stdlib.h>
#define max(x,y) ((x>y)? x:y)
#define min(x,y) ((x<y)? x:y)

int gcd(int n, int m)
{
	int t,c=0;
	while(n!=0)
		{
			c++;
			t=m%n;
			m=n;
			n=t;
		}
		printf("opcount =%d\n",c );
		return m;


}

int main()
{
	int n,m,ans;
	printf("inset two numbers\n");
	scanf("%d",&n);
	scanf("%d",&m);
	ans=gcd(n,m);
	printf("GCD= %d \n",ans);
	return 0;
}