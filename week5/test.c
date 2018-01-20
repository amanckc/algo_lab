//source removal

#include <stdio.h>
#include <stdlib.h>
# include <math.h>

int main()
{
	int i,j,k,n,a[10][10],indeg[10],flag[10],count=0;
	printf("Enter the no of vertices:\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		for(i=0;i<n;i++)
		{
			indeg[i]=0;
			flag[i]=0;
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
		indeg[i]=indeg[i]+a[j][i];
			printf("The topological order is:\n");
			while(count<n)
			{
				for(k=0;k<n;k++)
				{
					if((indeg[k]==0) && (flag[k]==0))
					{
						printf("%d \t",(k+1));
					     flag [k]=1;
					}

					for(i=0;i<n;i++)
					{
						if(a[k][i]==1)
							indeg[i]--;
					}

				}
				count++;
			}
			return 0;

}

/*
0 1 1 1 0 0
0 0 0 0 1 1
0 1 0 1 1 0
0 0 0 0 1 1
0 0 0 0 0 1
0 0 0 0 0 0  
*/
