#include<stdio.h>
#include<math.h>

#define MAXN 100

/*Global variable*/
int Dist;
int N;
int Visited[MAXN];
double ISLAND_RADIUS = 15.0/2;

/*coord*/
typedef struct Node
{
	int x;
	int y;
}Coord;
Coord List[MAXN];


int Jump(Coord A, Coord B)
{
	double z;
	z = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
	return (z <= Dist)? 1 : 0;
}


int FirstJump(Coord A)
{
	double z;
	z = sqrt(pow(A.x, 2) + pow(A.y, 2)) - ISLAND_RADIUS;
	return (z <= Dist)? 1 : 0;
}


int IsSafe(Coord A)
{
	return ((50 -fabs(A.x) <= Dist || (50 - fabs(A.y)) <= Dist)) ? 1 : 0;
}

int DFS(int V)
{
	int i;
	int answer = 0;
	Visited[V] = 1;
	if(IsSafe(List[V]))
	{
		answer = 1;
	}
	else
	{
		for(i = 0; i < N; i++)
		{
			if(!Visited[i] && Jump(List[V], List[i]))
			{
				answer = DFS(i);
				if(answer)
				{
					break;
				}
			}
		}
	}

	return answer;
}

void Save007()
{
	int save = 0;
	if(Dist + ISLAND_RADIUS >= 50)
	{
		printf("Yes\n");
		return;
	}
	for(int i = 0; i < N; i++)
	{
		if(!Visited[i] && FirstJump(List[i]))
		{
			save = DFS(i);
			if(save)
			{
				break;
			}
		}
	}

	if(save)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}

int main()
{
	int i;
	scanf("%d %d", &N, &Dist);
	for(i = 0; i < N; i++)
	{
		scanf("%d %d", &List[i].x, &List[i].y);
	}
	Save007();
	return 0;
}