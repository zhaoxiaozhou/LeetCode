// #include<stdio.h>
// #define MAXN 10000

// int MaxSubseqSum(int List[], int N);

// int main()
// {
// 	int Array[MAXN];
// 	int n;
// 	int i;
// 	scanf("%d", &n);
// 	for(i = 0; i < n; i++)
// 	{
// 		scanf("%d",&Array[i]);
// 	}
// 	MaxSubseqSum(Array, n);
// 	return 0;
// }

// int MaxSubseqSum(int List[], int N)
// {
// 	int thissum = 0;
// 	int maxsum = 0;

// 	int i;
// 	int lefttemp = 0;
// 	int left = 0;
// 	int right = 0;
// 	int flag = 0;

// 	for(i = 0; i < N; i++)
// 	{
// 		thissum += List[i];

// 		if (thissum < 0)
// 		{
// 			thissum = 0;
// 			lefttemp = i + 1;
// 		}

// 		else if(thissum > maxsum)
// 		{
// 			maxsum = thissum;
// 			left = lefttemp;
// 			right = i;
// 		}

// 		else if(thissum == 0 )
// 		{
// 			if(maxsum == 0 && flag == 0)
// 			{
// 				left = right = i;
// 				flag = 1;
// 			}			
// 		}		 
// 	}

// 	if (maxsum == 0 && flag == 0)
// 	{
// 		printf("0 %d %d", List[0],List[N-1]);
// 	}

// 	else
// 	{
// 		printf("%d %d %d",maxsum, List[left],List[right]);
// 	}
// 	return maxsum;
// }


#include <stdio.h>
#define  MAX 100000ul
int MaxSubsequenceSum(int *p, int N, int *start, int *end)
{
    int i = 0, count = 0;
    int tmp_start = 0;
    int ThisSum = 0, MaxSum = 0;
    for (i = 0; i < N; i++)
    {
        ThisSum += *(p + i);

        if (ThisSum < 0)
        {
            count++;
            ThisSum = 0;
            tmp_start = i + 1;
        }
        else if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
            *start = *(p + tmp_start);
            *end = *(p + i);
        }
    }

    if (count == N)
    {
        MaxSum = 0;
        *start = *(p + 0);
        *end = *(p + N - 1);
    }
    return MaxSum;
}

int main(void)
{
    int i;
    int k = 0;
    int arr[MAX] = { 0 };
    int start = 0, end = 0;
    scanf("%d", &k);
    for(i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d ", MaxSubsequenceSum(arr, k, &start, &end));
    printf("%d %d", start, end);

    return 0;
}