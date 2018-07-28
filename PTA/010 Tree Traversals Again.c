#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 30
#define ERROR -1
void solve(int preL, int inL, int PostL, int n);

typedef int ElementType;
typedef struct 
{
	ElementType Data[MAXSIZE];
	int Top;
}Stack;

void Push(Stack *PtrS, ElementType item)
{
	if(PtrS->Top == MAXSIZE)
	{
		//printf("Stack Full");
	}
	else
	{
		PtrS->Data[++(PtrS->Top)] = item;
	}

	return;
}

ElementType Pop(Stack *PtrS)
{
	if(PtrS->Top == -1)
	{
		printf("Stack is empty");
		return ERROR;
	}
	else
	{
		return(PtrS->Data[(PtrS->Top)--]);
	}
}

int pre[MAXSIZE];
int in[MAXSIZE];
int post[MAXSIZE];
#define STR_LEN 5

int main()
{
	int n;
	int i;
	int value;
	int count1 = 0;
	int count2 = 0;
	char operation[STR_LEN];

	Stack S;
	S.Top = -1;

	scanf("%d", &n);
	for(i = 0; i < 2 * n; i++)
	{
		scanf("%s", operation);
		/*strcmp() returns 0 when two string is the same*/
		/*这里花了非常多的时间，还以为什么错了呢*/
		if(!strcmp(operation, "Push"))
		{
			scanf("%d", &value);
			Push(&S, value);
			pre[count1++] = value;
		}
		else
		{
			value = Pop(&S);
			in[count2++] = value;
		}
	}

	solve(0, 0, 0, n);
	for(int i = 0; i < n - 1; i++)
	{
		printf("%d ", post[i]);
	}
	printf("%d", post[n-1]);
}

void solve1(int preL, int inL, int PostL, int n)
{
	int root;
	int L;
	int R;
	int i;

	/*斜二叉树*/
	if(n == 0)
	{
		return;
	}
	if(n == 1)
	{
		post[PostL] = pre[preL];
		return;
	}
	root = pre[preL];
	post[PostL + n - 1] = root;

	/*find the position of root in inorder tree*/
	/*thus the tree can be divide into left tree and right tree*/
	for(i = 0; i < n; i++)
	{
		if(in[inL+i] == root)
		{
			break;
		}
	}

	L = i; 				/*左子树的个数*/
	R = n - L - 1;		/*右子树的个数*/
	solve(preL + 1, inL, PostL, L);

	solve(preL + L + 1, inL + L + 1, PostL + L, R);
}

void solve(int preL, int inL, int PostL, int n)
{
	int root;
	int i;
	int L;
	int R;
	if(n == 0)
	{
		return;
	}
	if(n == 1)
	{
		post[PostL] = pre[preL];
		return;
	}
	root = pre[preL];
	post[PostL + n - 1] = root;

	for(i = 0; i < n; i++)
	{
		if(in[inL + i] == root)
		{
			break;
		}
	}

	L = i;
	R = n - L - 1;

	solve(preL + 1, inL, PostL, L);
	solve(preL + L + 1, inL + L + 1, PostL + L, R);
}


