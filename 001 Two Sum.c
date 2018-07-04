#include<stdio.h>

int *TwoSum(int *nums, int numsSize, int target);

int main()
{
	int a[] = {2, 7, 11, 15};
	int *b;
	int target = 2;
	int numsSize = 4;
	b = TwoSum(a, numsSize, target);
	printf("[%d %d]\n", b[0], b[1]);
}

/*approach 1: brute force*/
/*Time complexity O(n^2), Space complexity O(1)*/
/*if the answer doesn't exit , return a NULL pointer, printf will break down.*/
int *TwoSum(int *nums, int numsSize, int target)
{
	static int a[2];
	int index0, index1;
	int i, j;
	for(i = 0; i < numsSize - 1; i++)
	{
		index0 = i;
		for(j = i+1; j < numsSize; j++)
		{
			if(target == nums[i] + nums[j])
			{
				index1 = j;
				a[0]= index0;
				a[1] = index1;
				return a;
			}
		}

	}
	return NULL;	
}

/*hash table*/
int *TwoSum(int *nums, int numsSize, int target)
{
	int i;
	for(i = 0; i < numsSize; i++)
	{

	}
}