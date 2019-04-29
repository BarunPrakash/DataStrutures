

#include <stdio.h>
#include <limits.h>

// Number of vertices in the GraphMatrix
#define V 9

/******************************************************/
void SloveThroughdijkstra(int GraphMatrix[V][V], int src);
int FindminMinDistance(int MinDist[], bool VistedNode[]);
int printSolution(int MinDist[], int n);
/***********************************************************/



int FindminMinDistance(int MinDist[], bool VistedNode[])
{
// Initialize min value
int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
	if (VistedNode[v] == false && MinDist[v] <= min)
		min = MinDist[v], min_index = v;

return min_index;
}

// A utility function to print the constructed MinDistance array
int printSolution(int MinDist[], int n)
{
printf("Vertex MinDistance from Source\n");
for (int i = 0; i < V; i++)
	printf("%d tt %d\n", i, MinDist[i]);
}

void SloveThroughdijkstra(int GraphMatrix[V][V], int src)
{
	int MinDist[V];	 // The output array. MinDist[i] will hold the shortest
					// MinDistance from src to i

	bool VistedNode[V]; // VistedNode[i] will be true if vertex i is included in shortest
					// path tree or shortest MinDistance from src to i is finalized

	// Initialize all MinDistances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		MinDist[i] = INT_MAX, VistedNode[i] = false;

	// MinDistance of source vertex from itself is always 0
	MinDist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V-1; count++)
	{
	// Pick the minimum MinDistance vertex from the set of vertices not
	// yet processed. u is always equal to src in the first iteration.
	int u = FindminMinDistance(MinDist, VistedNode);

	// Mark the picked vertex as processed
	VistedNode[u] = true;

	// Update MinDist value of the adjacent vertices of the picked vertex.
	for (int v = 0; v < V; v++)

		// Update MinDist[v] only if is not in VistedNode, there is an edge from
		// u to v, and total weight of path from src to v through u is
		// smaller than current value of MinDist[v]
		if (!VistedNode[v] && GraphMatrix[u][v] && MinDist[u] != INT_MAX
									&& MinDist[u]+GraphMatrix[u][v] < MinDist[v])
			MinDist[v] = MinDist[u] + GraphMatrix[u][v];
	}


	printSolution(MinDist, V);
}


int main()
{

int GraphMatrix[V][V] = {{0, 4, 0, 0, 0, 0, 0, 9, 0},
					{4, 0, 8, 0, 0, 0, 0, 11, 0},
					{0, 8, 0, 7, 0, 4, 0, 0, 2},
					{0, 0, 7, 0, 9, 14, 0, 0, 0},
					{0, 0, 0, 9, 0, 10, 0, 0, 0},
					{0, 0, 4, 14, 10, 0, 2, 0, 0},
					{0, 0, 0, 0, 0, 2, 0, 1, 6},
					{8, 11, 0, 0, 0, 0, 1, 0, 7},
					{0, 0, 2, 0, 0, 0, 6, 7, 0}
					};

SloveThroughdijkstra(GraphMatrix, 0);

	return 0;
}
