#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <limits.h>
int adj[100][100];

int v;

int visited[100];
int queue[100];
int f=0,r=0;
int dequeue()
{
	if (f==r)
	{
		return -1;
		/* code */
	}
	else
		return queue[f++];

}
void enqueue(int i)
{
	queue[r++]=i;

}

void bfsvertex(int x)
{
	printf("Visiting %d\n", x);
	visited[x] = 1;
	int i;
	for (i = 0; i < v; ++i) {
		if (!visited[i] && adj[x][i] && i != x) {
			enqueue(i);
		}
	}
}
void bfs()
{
	int i, j;
	enqueue(0);
	do {
		j = dequeue();
		if (j != -1 && !visited[j]) {
			bfsvertex(j);
		}
	} while (j != -1);
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
	bfs();


	return 0;
}