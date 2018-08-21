#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 10
typedef int EdgeType;
typedef int DataType;
typedef int VertexType;

typedef struct 
{
	int Nv;
	int Ve;
	VertexType Ver[MaxVertexNum];
	EdgeType Edge[MaxVertexNum][MaxVertexNum];
}MGraph;

void InitGraph(MGraph *G)
{
	int i;
	int j;
	int Vertex1;
	int Vertex2;

	scanf("%d %d", &G->Nv, &G->Ve);
	for(i = 0; i < G->Nv; i++)
	{

		for(j = 0; j < G->Nv; j++)
		{
			G->Edge[i][j] = 0;
		}
	}

	for(i = 0; i < G->Ve; i++)
	{
		scanf("%d %d", &Vertex1, &Vertex2);
		G->Edge[Vertex1][Vertex2] = 1;
		G->Edge[Vertex2][Vertex1] = 1;
	}

}

void PrintGraph(MGraph *G)
{
	int i;
	int j;
	for(i = 0; i < G->Nv; i++)
	{
		for(j = 0; j < G->Nv; j++)
		{
			printf("%d ", G->Edge[i][j]);
		}
		printf("\n");		
	}
}

int Visited[MaxVertexNum] = {0};

void DFS(MGraph *G, int V)
{
	Visited[V] = 1;
	printf(" %d", V);
	for(int i = 0; i < G->Nv; i++)
	{
		if((!Visited[i]) && (G->Edge[V][i]))
		{
			DFS(G, i);
		}
	}
}

void BFS(MGraph *G, int V)
{
	int Q[G->Nv];
	int front = -1;
	int rear = -1;
	/*入队的操作*/
	Q[++rear] = V;
	Visited[V] = 1;
	while(front < rear)
	{
		/*出队的操作*/
		int de = Q[++front];
		printf(" %d", de);
		for(int i = 0; i < G->Nv; i++)
		{
			if(!Visited[i] && G->Edge[de][i])
			{
				Visited[i] = 1;
				Q[++rear] = i;
			}
		}
	}
}

int main()
{

	int i;
	MGraph G;
	InitGraph(&G);
	//PrintGraph(&G);
	for(i = 0; i < G.Nv; i++)
	{

		if(!Visited[i])
		{
			printf("{");
			DFS(&G, i);
			printf(" }\n");
		}
	}
	for(i = 0; i < G.Nv; i++)
	{
		Visited[i] = 0;
	}

	for(i = 0; i < G.Nv; i++)
	{
		if(!Visited[i])
		{
			printf("{");
			BFS(&G, i);
			printf(" }\n");
		}
	}

	return 0;
}

