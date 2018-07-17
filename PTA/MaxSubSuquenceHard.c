/*有一个case过不了，包含负数和0，应该输出0 0 0*/
#include<stdio.h>
//#include<stdlib.h>

#define MAXN 100000
int MaxSubseqSum(int Array[], int N);

int main()
{
	int i;
	int N;
	
	int Array[MAXN];	
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &Array[i]);
	}
	MaxSubseqSum(Array, N);
	return 0;
}

int MaxSubseqSum(int Array[], int N)
{

	int i;
	int sum;
	int maxsum;
	int left;
	int lefttemp;
	int right;
	int count;
	count = 0;
	sum = maxsum = 0;
	left = right = lefttemp = 0;
	for(i = 0; i < N; i++)
	{
		sum += Array[i];
		if(sum < 0)
		{ 
			count++;
			sum = 0;
			lefttemp = i + 1;
		}

		else if(sum > maxsum)
		{
			maxsum = sum;
			left = lefttemp;
			right = i;
		}
	}
	/*case: all the data is negative*/
	if(count == N)
	{
		maxsum = 0;
		left = 0;
		right = N - 1;

		// left = Array[0];
		// right = Array[N - 1];
	}
	/*case: all the data is 0 and negative*/
	if(maxsum == 0 && left == 0 && right == 0)
	{
		printf("%d %d %d", maxsum, left, right);
	}
	else
	{
		printf("%d %d %d", maxsum, Array[left], Array[right]);
	}
	return 0;
}

/*case1 : -1 0 -2 -3 -4*/