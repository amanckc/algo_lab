#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 99999
#define MIN(a,b) ((a<b)?a:b)

int n;

void shortestPath(int R[n][n])
{


	int i,j,k,D[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			D[i][j] = R[i][j];
	for (k= 0; k < n; ++k)
	{
		for (i = 0; i < n; ++i)
		{
			for (j=0;j<n;j++)
			{
				D[i][j]=MIN(D[i][j],(D[i][k]+D[k][j]));
			}
		}
	}

	printf("the  transitiveClosure is------\n");
	for(i=0;i<n;i++){
		for (j = 0; j< n; ++j)
		{
			printf("%d \t",D[i][j]);
		}
		printf("\n");
	}


}


int main(int argc, char const *argv[])
{
	int i,j;
	printf("enter the size of matrix <10\n");
	scanf("%d",&n);
	printf("enter 9999 for Infinity\n");


	int adj[n][n];
	for(i=0;i<n;i++){
		for (j = 0; j< n; ++j)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	/*for(i=0;i<n;i++){
		for (j = 0; j< n; ++j)
		{
			if(adj[i][j]=9999)
			{
				adj[i][j]=INF;
			}
		}
	}

for(i=0;i<n;i++){
		for (j = 0; j< n; ++j)
		{
			printf("%d \t",adj[i][j]);
		}
		printf("\n");
	}*/


	

	shortestPath(adj);
	return 0;
}


	
