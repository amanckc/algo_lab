#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a>b)?a:b)

int max(int a, int b) { return (a > b)? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
 
int main()
{

	
	int i,n,W;
	printf("enter no of items<10\n");
	scanf("%d",&n);
	printf("enter the capacity of knapsack\n");
	scanf("%d",&W);
	int v[n+1][W];

    int val[n], wt[n] ;
    printf("enter weight\n");
    for(i=0;i<n;i++)
    	scanf("%d",&wt[i]);
    printf("enter corresponding values\n");
    for(i=0;i<n;i++)
    	scanf("%d",&val[i]);
    
    
    n = sizeof(val)/sizeof(val[0]);
    printf("\n %d \n", knapSack(W, wt, val, n));
    return 0;
}