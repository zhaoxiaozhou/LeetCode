#include<stdio.h>
#include<stdlib.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1 /*NULL 在stdio.h中定义为0*/

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
};

struct TreeNode T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);

int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	//printf("1\n");
	R2 = BuildTree(T2);
	if(Isomorphic(R1, R2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}

Tree BuildTree(struct TreeNode T[]) /*返回值为树根index*/
{
	int N;
	int i;
	int check[MaxTree];
	char cl, cr;
	Tree Root = Null; //初始化树根为-1，也就是空树

	scanf("%d",&N);
	if(N)
	{
		for(i = 0; i<N; i++)
		{
			check[i] = 0;
		}
		for(i = 0; i<N; i++)
		{
			
			scanf("\n%c %c %c",&T[i].Element, &cl, &cr);
			
			//printf("2\n");
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
				check[T[i].Right] = 1;
			}
			else
			{
				T[i].Right = Null;
			}
		}
		for(i = 0; i<N; i++)
			if(!check[i])
			{
				Root = i;
				break;
			}	
		
	}
	printf("The root is%d\n", Root);
	return Root;
}

/*同构的意思就是若干次左右结点的互换*/
int Isomorphic(Tree R1, Tree R2)
{
	/*both tree is empty*/
	/*这里对于空树是-1，不太确定？？？？*/
	if((R1 == Null) && (R2 == Null)) 
		return 1;

	/*one is empty, the other is not*/
	if(((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))
		return 0;

	/*roots are different*/
	if(T1[R1].Element != T2[R2].Element)
		return 0;

	/*both have no left subtree*/
	if((T1[R1].Left == Null) && T2[R2].Left == Null)
		return Isomorphic(T1[R1].Right, T2[R2].Right);

	//
	if((T1[R1].Left != Null) && (T2[R2].Left != Null) && ((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)))
		return(Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
		/*no need to swap the left and the right.*/
	else
		return(Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));
		/*need to swap the left and the right.*/
}