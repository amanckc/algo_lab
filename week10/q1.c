#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int n;

void transitiveClosure(int R[n][n])
{


	int i,j,k,reach[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			reach[i][j] = R[i][j];
	for (k= 0; k < n; ++k)
	{
		for (i = 0; i < n; ++i)
		{
			for (j=0;j<n;j++)
			{
				reach[i][j]=reach[i][j] ||(reach[i][k] && reach[k][j]);
			}
		}
	}

	printf("the  transitiveClosure is------\n");
	for(i=0;i<n;i++){
		for (j = 0; j< n; ++j)
		{
			printf("%d \t",reach[i][j]);
		}
		printf("\n");
	}


}
int main(int argc, char const *argv[])
{
	int i,j;
	printf("enter the size of matrix <10\n");
	scanf("%d",&n);
	

	int adj[n][n];
	for(i=0;i<n;i++){
		for (j = 0; j< n; ++j)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	

	transitiveClosure(adj);
	return 0;
}


	
