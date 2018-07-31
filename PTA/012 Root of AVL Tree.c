#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct AVLTreeNode *AVLTree;
struct AVLTreeNode
{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int PostOrderGetHeight(AVLTree Tree);
AVLTree AVL_Insert(AVLTree T, ElementType X);
int main()
{
	int i;
	int N;
	int Value;

	scanf("%d", &N);
	AVLTree Tree;
	Tree = NULL;

	for(i = 0; i < N; i++)
	{
		scanf("%d", &Value);
		Tree = AVL_Insert(Tree, Value);
	}
	printf("%d", Tree->Data);
	return 0;
}

int MAXH(int A, int B)
{
	return (A > B) ? (A) : (B);
}

int PostOrderGetHeight(AVLTree Tree)
{
	int HL, HR, MAXH;
	if(Tree)
	{
		HL = PostOrderGetHeight(Tree->Left);
		HR = PostOrderGetHeight(Tree->Right);
		MAXH = (HL > HR) ? HL : HR;
		return (MAXH + 1);
	}
	else
	{
		return 0;
	}
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	/*A->Height 加1为了求得B左子树的高度*/
	A->Height = MAXH(PostOrderGetHeight(A->Left),PostOrderGetHeight(A->Right)) + 1;
	B->Height = MAXH(PostOrderGetHeight(B->Right), A->Height);
	return B;
}

AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;

	A->Height = MAXH(PostOrderGetHeight(A->Left), PostOrderGetHeight(A->Right)) + 1;
	B->Height = MAXH(PostOrderGetHeight(B->Left), A->Height);
	return B;
}

AVLTree SingleLeftRightRotation(AVLTree A)
{
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}


AVLTree singleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
} 



AVLTree AVL_Insert(AVLTree T, ElementType X)
{
	if(!T)
	{
		T = (AVLTree)malloc(sizeof(struct AVLTreeNode));
		T->Data = X;
		T->Left = T->Right = NULL;
	}
	else if(X < T->Data)
	{
		T->Left = AVL_Insert(T->Left, X);
		if(PostOrderGetHeight(T->Left) - PostOrderGetHeight(T->Right) == 2)
		{
			if(X < T->Left->Data)
			{
				T = SingleLeftRotation(T);
			}
			else
			{
				T = SingleLeftRightRotation(T);
			}
		}
	}
	else if(X > T->Data)
	{
		T->Right = AVL_Insert(T->Right, X);
		if(PostOrderGetHeight(T->Right) - PostOrderGetHeight(T->Left) == 2)
		{
			if(X < T->Right->Data)
			{
				T = singleRightLeftRotation(T);
			}
			else
			{
				T = SingleRightRotation(T);
			}
		}
	}
	T->Height = MAXH(PostOrderGetHeight(T->Left), PostOrderGetHeight(T->Right));
	return T;
}