#include<stdio.h>
#include<stdlib.h>

#define MAXTREE 10
#define ElementType char
#define Tree int
/*NULL 代表0*/
#define Null -1
/*本题的思想：*/
/*结构数组表示二叉树*/
/*静态链表存储，物理上面用数组存储，逻辑上面是链表的*/
struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
};

struct TreeNode T1[MAXTREE], T2[MAXTREE];

Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);

int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if(Isomorphic(R1, R2))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}

/*返回树根的index*/
/*找到树根是一个难点，树根就是不是，其他结点的左右子树*/
Tree BuildTree(struct TreeNode T[])
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
			scanf("\n%c %c %c", &T[i].Element, &cl, &cr);
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
	printf("Root is:%d\n", Root);
	return Root;

}

/*R1 R2 is the root of the tree*/
int Isomorphic(Tree R1, Tree R2)
{
	/*空树是同构的*/
	if(R1 == Null && R2 == Null)
	{
		return 1;
	}

	/*一个是空树，一个不是空树，非同构*/
	if((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))
	{
		return 0;
	}

	/*树根不同*/
	if(T1[R1].Element != T2[R2].Element)
	{
		return 0;
	}

	/*都没有左子树*/
	if(T1[R1].Left == Null && T2[R2].Left == Null)
	{
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	}

	if((T1[R1].Left != Null) && (T2[R2].Left != Null)&&((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
	{
		return(Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	}
	else
	{
		return(Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
	}
}