#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10001
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];

// typedef struct
// {
// 	ElementType Data;
// 	int Parent;
// }SetType;

/*这里的集合采用的是简化的集合表示方法，用下标代表N个元素*/
/*存储的是每个元素的父节点，对应到下标上面去*/
/*TSSN Too Simple Sometimes Naive*/
/*这个代码会运行超时*/
SetName Find1(SetType S, ElementType X)
{
	for(; S[X] >= 0; X = S[X])
	{

	}
	return X;
}

/*这个代码会运行超时*/
void Union1(SetType S, SetName Root1, SetName Root2)
{
	S[Root1] = Root2;
}

/*路径压缩方法*/
SetName Find(SetType S, ElementType X)
{
	if(S[X] < 0)
	{
		/*X这个元素已经是根了*/
		return X;
	}
	else
	{
		/*先找到根*/
		/*把根变为X的父节点*/
		/*再返回根*/
		/*这里是一个伪递归，会被编译器优化为循环算法*/
		return S[X] = Find(S, S[X]);
	}
}

void Initiliazation(SetType S, int n)
{
	int i;
	/*初始化把所有节点都认为是父节点，即都是独立的结点*/
	for(i = 0; i < n; i++)
	{
		S[i] = -1;
	}
}

/*按照树的高度来合并*/
void Union2(SetType S, SetName Root1, SetName Root2)
{
	/*根节点存储的是-树的高度*/
	/*Root2的高度大于Root1*/
	if(S[Root2] < S[Root1])
	{
		S[Root1] = Root2;
	}
	else 
	{
		if(S[Root1] == S[Root2])
		{
			S[Root1]--;
		}
		S[Root2] = Root1;
	}
}

/*按照树的规模来合并*/
/*推荐用这个方法来合并*/
void Union(SetType S, SetName Root1, SetName Root2)
{
	if(S[Root2] < S[Root1])
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else
	{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}


void Input_Connection(SetType S)
{
	ElementType u, v;
	SetName Root1, Root2;
	scanf("%d %d", &u, &v);
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if(Root2 != Root1)
	{
		Union(S, Root1, Root2);
	}
}


void Check_Connection(SetType S)
{
	ElementType u, v;
	SetName Root1, Root2;
	scanf("%d %d\n", &u, &v);
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if(Root1 == Root2)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
}


void Check_Network(SetType S, int n)
{
	int i;
	int counter = 0;
	for(i = 0; i < n; i++)
	{
		if(S[i] < 0)
		{
			counter++;
		}
	}
	if(counter == 1)
	{
		printf("The Network is connected.\n");
	}
	else
	{
		printf("There are %d components.\n", counter);
	}
}


int main()
{
	SetType S;
	int n;
	char in;

	scanf("%d", &n);
	Initiliazation(S, n);
	do
	{
		scanf("%c",&in);
		switch(in)
		{
			case 'I':
				Input_Connection(S);
				break;
			case 'C':
				Check_Connection(S);
				break;
			case 'S':
				Check_Network(S, n);
				break; 
		}

	}while(in != 'S');

	return 0;

}





