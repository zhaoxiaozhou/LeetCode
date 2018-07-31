#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode
{
	int v;
	Tree Left, Right;
	int flag;
};

void FreeTree(Tree T);
Tree MakeTree(int N);
Tree NewNode(int V);
Tree Insert(Tree T, int V);
int Judge(Tree T, int N);
void Reset(Tree T);

int main()
{
	int N;
	int L;
	int i;
	Tree T;
	scanf("%d", &N);
	while(N)
	{
		scanf("%d", &L);
		T = MakeTree(N);
		for(i = 0; i < L; i++)
		{
			if(Judge(T, N))
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
			Reset(T);
		}
		FreeTree(T);
		scanf("%d", &N);
	}

	return 0;
}

Tree MakeTree(int N)
{
	Tree T;
	int i, V;
	scanf("%d", &V);
	T = NewNode(V);
	/*一个非常小的细节问题，花了很长时间*/
	/*i < N 不是i < V*/
	for(i = 1; i < N; i++)
	{
		scanf("%d", &V);
		Insert(T, V);
	}
	return T;
}

Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag	= 0;
	return T;
}

Tree Insert(Tree T, int V)
{
	if(!T)
	{
		T = NewNode(V);
	}
	else
	{
		if(V > T->v)
		{
			T->Right = Insert(T->Right, V);
		}
		else
		{
			T->Left = Insert(T->Left, V);
		}
	}

	return T;
}

int Check(Tree T, int V)
{
	/*根节点查找过了*/
	if(T->flag)
	{
		if(V < T->v)
		{
			return Check(T->Left, V);
		}
		else if(V > T->v)
		{
			return Check(T->Right, V);
		}
		/*重复出现，认为是有问题的*/
		else
		{
			return 0;
		}
	}
	/*根节点还没有访问*/
	else
	{
		if(V == T->v)
		{
			T->flag = 1;
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int Judge(Tree T, int N)
{
	int i, V;
	int flag = 0;
	/*flag = 0目前还一致，1表示已经不一样了*/
	scanf("%d", &V);
	if(V != T->v)
	{
		flag = 1;
	}
	else
	{
		T->flag = 1;
	}

	for(i = 1; i < N; i++)
	{
		scanf("%d", &V);
		if((!flag) && (!Check(T, V)))
		{
			flag = 1;
		}
	}
	if(flag)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void Reset(Tree T)
{
	if(T->Left)
	{
		Reset(T->Left);
	}
	if(T->Right)
	{
		Reset(T->Right);
	}
	T->flag = 0;
}

void FreeTree(Tree T)
{

	if(T->Left)
	{
		FreeTree(T->Left);
	}

	if(T->Right)
	{
		FreeTree(T->Right);
	}

	free(T);

}
