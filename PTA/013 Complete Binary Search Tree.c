/*A Complete Binary Tree*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXSIZE 1000
#define min(a, b)  (a) < (b) ? (a) : (b)

int T[MAXSIZE];
int A[MAXSIZE];

/*得到左子树的长度*/
int GetLeftLength(int n)
{
	int height;
	int LeftNum;
	int LastLevelNum;
	/*floor get the largest integral that is not greater than x*/
	/*get the height of the complete binary tree*/
	/*整个树的完全部分高度是height*/
	height = floor(log(n + 1) / log(2));
	LastLevelNum = n - (pow(2, height) - 1);
	LastLevelNum = min(LastLevelNum, pow(2, height-1));
	/*根节点左子树的高度*/
	LeftNum = pow(2, height - 1) - 1 + LastLevelNum;
	return LeftNum;
}

void solve(int ALeft, int ARight, int TRoot)
{
	int LeftTRoot;
	int RightTRoot;
	int n;
	n = ARight - ALeft + 1;
	if(n == 0)
	{
		return;
	}
	/*获得完全二叉树左子树结点的个数*/
	int L = GetLeftLength(n);
	T[TRoot] = A[ALeft + L];

	LeftTRoot = 2 * TRoot + 1;
	RightTRoot = LeftTRoot + 1;

	solve(ALeft, ALeft + L - 1, LeftTRoot);
	solve(ALeft + L + 1, ARight, RightTRoot);
}

int compare(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int main()
{
	int N;
	scanf("%d", &N);

	int i;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	/*sort elements of array*/
	/*compare function to determine the order*/
	qsort(A, N, sizeof(int), compare);
	
	solve(0, N - 1, 0);

	for(i = 0; i < N - 1; i++)
	{
		printf("%d ", T[i]);
	}
	printf("%d", T[N - 1]);
}

