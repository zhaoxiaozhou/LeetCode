#include<stdio.h>
#define MAXN 100000
int MaxSubseqSum(int Array[], int N);

int main()
{
	int i;
	int N;
	int Max;
	int Array[MAXN];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &Array[i]);
	}
	Max = MaxSubseqSum(Array, N);
	printf("%d\n", Max);
	return 0;
}

int MaxSubseqSum(int Array[], int N)
{
	int i;
	int sum = 0;
	int maxsum = 0;

	for(i = 0; i < N; i++)
	{
		sum += Array[i];
		if(sum < 0)
		{
			sum = 0;
		}
		else if(sum > maxsum)
		{
			maxsum = sum;
		}
	}
	return maxsum;	
}