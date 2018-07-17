#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int Position;
typedef int ElementType;

typedef struct LNode* List;
struct LNode
{
	ElementType Data[MAXSIZE];
	Position Last;
};

Position BinarySearch(List L, ElementType X)
{
	Position Left, Right, Center;
	Left = 1;
	Right = L->Last;
	while(Left <= Right)
	{
		Center = (Left + Right) / 2;
		if(L->Data[Center] < X)
		{
			Left = Center + 1;
		}
		else if(L->Data[Center] > X)
		{
			Right = Center - 1;
		}
		else if(L->Data[Center] == X)
		{
			return Center;
		}
	}

	return NotFound;
}

int main()
{
	List L;
	L->Last = 0;
	int i;
	int N;
	int X;
	int Pos;
	scanf("%d %d", &N, &X);
	for(i = 1; i < N; i++)
	{
		scanf("%d", &L->Data[i]);
		L->Last ++;
	}
	Pos = BinarySearch(L, X);
	if(Pos)
	{
		printf("The Position of the Number is : %d\n", Pos);
	}
	else
	{
		printf("Not Found\n");
	}

}