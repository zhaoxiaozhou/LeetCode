#include<stdio.h>
#include<stdlib.h>

#define MAXV 500
#define INFINITY 65536

typedef struct 
{
	int Dist[MAXV][MAXV];
	int Cost[MAXV][MAXV];
	int Visited[MAXV];

	int MinDist[MAXV];
	int MinCost[MAXV];

	int VertexN, EdgeN;	
}Graph;

void InitalizeG(Graph * G)
{
	int i, j;
	/*错误终于找到了*/
	/*这里初始化Graph时候，G->VertexN未知，导致初始化错误*/
	// for(i = 0; i < G->VertexN; i++)
	// {
	// 	for(j = 0; j < G->VertexN; j++)
	// 	{
	// 		G->Dist[i][j] = INFINITY;
	// 		G->Cost[i][j] = INFINITY;
	// 	}
	// 	G->Visited[i] = 0;
	// 	G->MinDist[i] = INFINITY;
	// 	G->MinCost[i] = INFINITY;
	// }

	for(i = 0; i < MAXV; i++)
	{
		for(j = 0; j < MAXV; j++)
		{
			G->Dist[i][j] = INFINITY;
			G->Cost[i][j] = INFINITY;
		}
		G->Visited[i] = 0;
		G->MinDist[i] = INFINITY;
		G->MinCost[i] = INFINITY;
	}

	/*the graph has no vertex and edge*/
	G->VertexN = 0;
	G->EdgeN = 0;
}

void ReadGraph(Graph *G, int *S, int *D)
{
	int i, V1, V2;
	scanf("%d %d %d %d", &G->VertexN, &G->EdgeN, S, D);
	for(i = 0; i < G->EdgeN; i++)
	{
		scanf("%d %d", &V1, &V2);
		scanf("%d %d", &G->Dist[V1][V2], &G->Cost[V1][V2]);
		G->Dist[V2][V1] = G->Dist[V1][V2];
		G->Cost[V2][V1] = G->Cost[V1][V2];
	}

	// for(i = 0; i < G->VertexN; i++)
	// {
	// 	for(int j = 0; j < G->VertexN; j++)
	// 	{
	// 		printf("%d ",G->Dist[i][j]);
	// 		//printf("%d ",G->Cost[i][j]);
	// 	}
	// 	printf("\n");
	// }
}


void Dijkstra(Graph *G, int S)
{
	int v, w, minD, minV;

	/*S as start vertex*/
	G->Visited[S] = 1;
	G->MinCost[S] = G->MinDist[S] = 0;

	for(v = 0; v < G->VertexN; v++)
	{
		G->MinDist[v] = G->Dist[S][v];
		G->MinCost[v] = G->Cost[S][v];
	}

	for(w = 1; w < G->VertexN; w++)
	{
		minD = INFINITY;

		for(v = 0; v < G->VertexN; v++)
		{
			if(!G->Visited[v] && G->MinDist[v] <= minD)
			{
				minD = G->MinDist[v];
				minV = v;
				// printf("Round %d :", w);
				// printf("MinV is %d\n", minV);

			}
		}

		if(minD < INFINITY)
		{
			G->Visited[minV] = 1;
		}
		else
		{
			/*Graph is not connected*/
			break;
		}

		/*update the path*/
		for(v = 0; v < G->VertexN; v++)
		{
			if(!G->Visited[v])
			{
				if((G->MinDist[minV] + G->Dist[minV][v]) < G->MinDist[v])
				{
					G->MinDist[v] = G->MinDist[minV] + G->Dist[minV][v];
					G->MinCost[v] = G->MinCost[minV] + G->Cost[minV][v];
				}
				else if(G->MinDist[minV] + G->Dist[minV][v] == G->MinDist[v] && 
						G->MinCost[minV] + G->Cost[minV][v] < G->MinCost[v])
				{
					G->MinCost[v] = G->MinCost[minV] + G->Cost[minV][v];
				}
			}
		}		
	}
}

int main()
{

	int S, D;
	Graph *G = (Graph *) malloc(sizeof(Graph));
	InitalizeG(G);

	ReadGraph(G, &S, &D);

	Dijkstra(G, S);
	printf("%d %d\n", G->MinDist[D], G->MinCost[D]);
	return 0;
}



