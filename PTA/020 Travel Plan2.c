#include<stdio.h>
#include<stdlib.h>

#define MAXV 500
#define INFINITY 65536

typedef struct
{
	/*图的两个权值 距离 和 费用*/
	int Dist[MAXV][MAXV];
	int Cost[MAXV][MAXV];
	/*顶点的标记*/
	int Visited[MAXV];
	/*到该顶点的最短距离*/
	int MinDist[MAXV];
	/*到该顶点的最小费用*/
	int MinCost[MAXV];

	int VertexN, EdgeN;
}Graph;


void InitalizeG(Graph * G)
{
	int i, j;
	for(i = 0; i < MAXV; i++)
	{
		for(j = 0; j < MAXV; j++)
		{
			G->Dist[i][j] = G->Cost[i][j] = INFINITY;
		}

		G->Visited[i] = 0;
		G->MinDist[i] = G->MinCost[i] = INFINITY;
	}

	G->VertexN = G->EdgeN = 0;
}


void ReadG(Graph * G, int * S, int * D)
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
	
	for(i = 0; i < G->VertexN; i++)
	{
		for(int j = 0; j < G->VertexN; j++)
		{
			printf("%d ",G->Dist[i][j]);
			//printf("%d ",G->Cost[i][j]);
		}
		printf("\n");
	}
}

/*S means the start of the vertex*/
void Dijkstra(Graph *G, int S)
{
	int v, w, minD, minV;

	/*针对起点初始化*/
	G->Visited[S] = 1;
	G->MinDist[S] = G->MinCost[S] = 0;

	for(v = 0; v < G->VertexN; v++)
	{
		G->MinDist[v] = G->Dist[S][v];
		G->MinCost[v] = G->Cost[S][v];
	}

	for(w = 1;  w < G->VertexN; w++)
	{
		minD = INFINITY;

		for(v = 0; v < G->VertexN; v++)
		{
			/*找当前未访问过的距离最短的顶点*/
			if(!G->Visited[v] && G->MinDist[v] <= minD)
			{
				minD = G->MinDist[v];
				minV = v;
			}
		}

		if(minD < INFINITY)
		{
			/*minV加入已经访问集合*/
			G->Visited[minV] = 1;
		}
		else
		{
			/*图不连通*/
			break;
		}

		/*更新最短路径*/
		for(v = 0; v < G->VertexN; v++)
		{
			if(!G->Visited[v])
			{
				if(G->MinDist[minV] + G->Dist[minV][v] < G->MinDist[v])
				{
					G->MinDist[v] = G->MinDist[minV] + G->Dist[minV][v];
					G->MinCost[v] = G->MinCost[minV] + G->Cost[minV][v];
				}
				else if ((G->MinDist[minV] + G->Dist[minV][v] == G->MinDist[v])&&
						(G->MinCost[minV] + G->Cost[minV][v] < G->MinCost[v]))
				{
					/*如果路径长度相同，但是费用更少*/
					G->MinCost[v] = G->MinCost[minV] + G->Cost[minV][v];
				}
			}
		}
	}
}


int main()
{
	int S, D;

	Graph *G = malloc(sizeof(Graph));

	InitalizeG(G);
	ReadG(G, &S, &D);

	// for(int i = 0; i < G->VertexN; i++)
	// 	for(int j = 0; j < i; j++)
	// 	{
	// 		printf("Dist between %d and %d is :%d\n", i, j, G->Dist[i][j]);
	// 		printf("Cost between %d and %d is :%d\n", i, j, G->Cost[i][j]);
	// 	}
	Dijkstra(G, S);

	printf("%d %d\n", G->MinDist[D], G->MinCost[D]);
	return 0;
}