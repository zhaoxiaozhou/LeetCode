#include<stdio.h>
#include<stdlib.h>

#define MAXN 1001
/*最小堆的哨兵，放一个肯定比所有数都小的数字*/
#define MINH -10001

int H[MAXN], size;
/*最小堆初始化*/
void Create()
{
	size = 0;
	/*哨兵*/
	H[0] = MINH;

}

/*最小堆的插入*/
void Insert(int X)
{
	if(size >= MAXN)
	{
		printf("Heap is full");
		return;
	}
	int i;
	for(i = ++size; H[i/2] > X; i /= 2)
	{
		H[i] = H[i/2];		
	}

	H[i] = X;
}

int main()
{
	int N;
	int M;
	int i;
	int Value;

	scanf("%d %d", &N, &M);
	Create();

	for(i = 0; i < N; i++)
	{
		scanf("%d", &Value);
		Insert(Value);
	}
	int j = 0;
	for(i = 0; i < M; i++)
	{
		scanf("%d", &j);
		printf("%d", H[j]);
		while(j > 1)
		{
			j /= 2;
			printf(" %d",H[j]);			
		}
		printf("\n");

	}
	return 0;
}
