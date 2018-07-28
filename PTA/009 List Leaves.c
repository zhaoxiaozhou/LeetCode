#include<stdio.h>
#include<stdlib.h>


#define MAXTREE 10
#define Null -1
#define MAXSIZE 10

typedef char ElementType;
typedef int Tree; 

struct Node
{
	ElementType Data;
	Tree Left;
	Tree Right;
};
struct Node T1[MAXTREE];
Tree BuildTree(struct Node T[]);
void FindLeaves(Tree R);
void levelordertraversal(Tree R);
/*队列数据结构*/
typedef struct 
{	
	int Data[MAXSIZE];
	int front;
	int rear;	
}Queue;

/*队列的初始化*/
void InitQueue(Queue *PtrQ)
{
	/*这里队列采用的是循环队列*/
	/*这里空一个元素的方法，front指向为空*/
	PtrQ->front = PtrQ->rear = 0;
}

/*判断队列是否为空*/
int IsEmpty(Queue *PtrQ)
{
	return(PtrQ->front == PtrQ->rear);
}
/*入队的操作*/
int IsFull(Queue *PtrQ)
{
	return((PtrQ->rear + 1)%MAXSIZE == PtrQ->front);
}
/*入队的操作*/
void AddQ(Queue *PtrQ, int item)
{
	if((PtrQ->rear + 1)%MAXSIZE == PtrQ->front)
	{
		printf("队列满\n");
		return;
	}
	PtrQ->rear = (PtrQ->rear + 1) % MAXSIZE;
	PtrQ->Data[PtrQ->rear] = item;
}
/*出队的操作*/
int DelteQ(Queue *PtrQ)
{
	if(PtrQ->front == PtrQ->rear)
	{
		printf("队列为空\n");
		return -1;
	}
	else
	{
		PtrQ->front = (PtrQ->front + 1) % MAXSIZE;
		return PtrQ->Data[PtrQ->front];
	}
}


int main()
{
	Tree R1;
	R1 = BuildTree(T1);
	//levelordertraversal(R1);
	FindLeaves(R1);
	return 0;
}


void FindLeaves(Tree R)
{
	static int flag = 0;
	Queue Q1;
	int index;

	InitQueue(&Q1);
	if(R == -1)
	{
		return;
	}
	AddQ(&Q1, R);

	while(!IsEmpty(&Q1))
	{
		index = DelteQ(&Q1);
		if(T1[index].Left == -1 && T1[index].Right == -1)
		{
			if(flag == 0)
			{
				printf("%d", index);
				flag = 1;
			}
			else
			{
				printf(" %d", index);
			}
		}
		if(T1[index].Left != -1)
		{
			AddQ(&Q1, T1[index].Left);
		}
		if(T1[index].Right != -1)
		{
			AddQ(&Q1, T1[index].Right);
		}

	}
}

/*返回树根的index*/
/*找到树根是一个难点，树根就是不是，其他结点的左右子树*/
Tree BuildTree(struct Node T[])
{
	int N;
	int i;
	int check[MAXTREE];
	char cl, cr;
	Tree Root = Null;  /*初始化为-1，空树*/

	scanf("%d", &N);
	if(N)
	{ 
		for(i = 0; i < N; i++)
		{
			check[i] = 0;
		}
		for(i = 0; i < N; i++)
		{
			//把换行符放在前面吃掉前面scanf后的回车，而最后一个scanf不能有回车，一举两得
			scanf("\n%c %c", &cl, &cr);
			if(cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
			{
				T[i].Left = Null;
			}

			if(cr != '-')
			{
				T[i].Right = cr - '0';
				//错误的源头check[T[i].Left] = 1;
				check[T[i].Right] = 1;
			}
			else
			{
				T[i].Right = Null;
			}
		}

		for(i = 0; i < N; i++)
		{
			if(!check[i])
			{
				Root = i;
				break;
			}
		}		
	}
	//printf("Root is:%d\n", Root);
	return Root;
}

void levelordertraversal(Tree R)
{

	Queue Q1;
	int index;

	InitQueue(&Q1);
	if(R == -1)
	{
		return;
	}

	AddQ(&Q1, R);
	printf("The levelorder traversal is:");
	while(!IsEmpty(&Q1))
	{
		
		index = DelteQ(&Q1);
		printf("%d ", index);
		if(T1[index].Left != -1)
		{
			AddQ(&Q1, T1[index].Left);
		}
		if(T1[index].Right != -1)
		{
			AddQ(&Q1, T1[index].Right);
		}
	}
}

