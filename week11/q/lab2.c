#include <stdio.h>
#include <limits.h>

#define V 9

typedef enum { NO, YES } BOOL;
int graph[V][V];
	
int minDistance(int dist[], BOOL sptSet[]) {

	int min = INT_MAX, min_index;
	
	int v;
	for (v = 0; v < V; v++) {
		if (sptSet[v] == NO && dist[v] <= min) {
			min = dist[v], min_index = v;
		}
	}

	 return min_index;
}
	
int printshit(int dist[], int n) {
	printf("Vertex   Distance from Source\n");
	int i;
	for (i = 0; i < n; i++) {
		printf("%d \t\t %d\n", i, dist[i]);
	}
}

void dijkstra(int graph[V][V], int src) {
		int dist[V];
	
		BOOL sptSet[V];
		
		int i;
		for (i = 0; i < V; i++)
			dist[i] = INT_MAX, sptSet[i] = NO;
	
		dist[src] = 0;

		int count;
		for (count = 0; count < V-1; ++count) {

			int u = minDistance(dist, sptSet);

			sptSet[u] = YES;
			int v;
			for (v = 0; v < V; v++) {
				if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) {
					dist[v] = dist[u] + graph[u][v];
				}
			}

		}

		printshit(dist, V);
}

int main(int argc, char const *argv[]) {

	
	int n;
	printf("Enter the number of vertices: ");
	scanf(" %d", &n);
	int i, j;
	printf("enter values\n");
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			scanf(" %d", &graph[i][j]);
		}
	}
	
	dijkstra(graph, 0);
	
	return  0;
}