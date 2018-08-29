#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 500
#define INFINITY 65535

int LowCost[MaxVertexNum];
int MinDist[MaxVertexNum];

typedef struct 
{
	int Dist[MaxVertexNum][MaxVertexNum];
	int Cost[MaxVertexNum][MaxVertexNum];
	int n, e;
}MGraph;

void CreateGraph(MGraph *G)
{
	int i, j;
	for(i = 0; i < G->n; i++)
	{
		for(j = 0; j < G->n; j++)
		{
			G->Dist[i][j] = INFINITY;
			G->Cost[i][j] = INFINITY;
		}
	}
}
void Prim(MGraph *G, int Parent[]);
int main()
{
	int i;
	int V1, V2;
	int Cost, Distance;

	MGraph *G = (MGraph *)malloc(sizeof(MGraph));
	int N, M, S, D;
	scanf("%d %d %d %d", &N, &M, &S, &D);
	G->n = N;
	G->e = M;
	CreateGraph(G);
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &V1, &V2);
		scanf("%d %d", &Distance, &Cost);
		G->Dist[V1][V2] = Distance;
		G->Dist[V2][V1] = Distance;

		G->Cost[V1][V2] = Cost;
		G->Cost[V2][V1] = Cost;
	}

	int Parent[MaxVertexNum];
	Prim(G, Parent);
	// for(i = 0; i < G->n; i++)
	// {
	// 	printf("%d ", MinDist[i]);
	// }
	return 0;
}

int FindMin(int MinDist[], int n);

void Prim(MGraph *G, int Parent[])
{
	/*start with Vertex 0*/
	int i, j, k;
	for(i = 1; i < G->n; i++)
	{
		LowCost[i] = G->Cost[0][i];
		MinDist[i] = G->Dist[0][i];
	}
	LowCost[0] = 0;
	MinDist[0] = 0;
	Parent[0] = 0;

	for(i = 1; i < G->n; i++)
	{
		k = FindMin(MinDist, G->n);
		if(k)
		{
			MinDist[k] = 0;
			for(j = 1; j < G->n; j++)
			{
				if(MinDist[j] && G->Dist[k][j] < MinDist[j])
				{
					MinDist[j] = G->Dist[k][j];
					Parent[j] = k;
				}
			} 
		}
		else
		{
			printf("Graph Not Connected");
			break;
		}
	}
	for(j = 0; j < G->n; j++)
	{
		printf("%d ", Parent[i]);
	}
}


int FindMin(int MinDist[], int n)
{
	int j, k;
	int Min = INFINITY;
	for(k = 0, j = 0; j < n; j++)
	{
		if(MinDist[j] && MinDist[j] < Min)
		{
			k = j;
			Min = MinDist[j];
		}
	}

	return k;
}


