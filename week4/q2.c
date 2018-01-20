#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <limits.h>
int adj[100][100];

int v;

int visited[100];

void dfsvertex(int j)
{
	printf("Visiting %d\n", j);
	visited[j] = 1;
	int i;
	for (i = 0; i < v; ++i)
	{

		if (!(visited[i]) && (adj[j][i] == 1) && (i != j)) {
			dfsvertex(i);
		
	}
	

	}
}

void dfs()
{
	int i;
	for(i=0;i<v;i++)
	{
		if(!visited[i])
			
			{
				dfsvertex(i);
			}
		//else printf("pop>> %d\n", i);
	}

}


int main(int argc, char const *argv[])
{
	int i,j;

	printf("enter the no of vertices\n");
	scanf("%d",&v);
	//int adj[v][v];
	printf("enter the adjacency matrix\n");
	for(i=0;i<v;i++)
	{
		for (j = 0; j < v; ++j)
		{
			scanf("%d",&adj[i][j]);
		}

	}

	dfs();

	return 0;
}

/*
0 1 0 0 1 1
1 0 1 0 0 1
0 1 0 1 1 0
0 0 1 0 1 0
1 0 1 1 0 0
1 1 0 0 0 0
*/