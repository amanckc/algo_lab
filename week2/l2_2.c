#include <stdio.h>
#include <stdlib.h>
#define max(x,y) ((x>y)? x:y)
#define min(x,y) ((x<y)? x:y)


int middleschool(int a, int b) {
	if (a > b)
		middleschool(b, a);
	int fact = 2;
	int gcd = 1;
	//int z = min(a,b);
	gcd=(a==0) ? b :(b==0) ? a:1;
	//if(a==0 )
		//return b;
	//else if(b==0)
		//return a;
	//else{
	for (fact = 2; fact <= min(a,b); fact ++) {
		while (((a % fact) == 0) && ((b % fact) == 0)) {
			gcd = gcd * fact;
			b = b / fact;
			a = a / fact;
			if (a == 0 || b == 0) 
				return gcd;
		}
	}

	return gcd;
}

int main(int argc, char const *argv[])
{
	int n,m,ans;
	printf("inset two numbers\n");
	scanf("%d",&n);
	scanf("%d",&m);
	ans=middleschool(n,m);
	printf("GCD= %d \n",ans);
	return 0;
}
