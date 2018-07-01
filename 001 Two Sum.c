#include<stdio.h>

int *TwoSum(int *nums, int numsSize, int target);

int main()
{

	int a[] = {2, 7, 11, 15};
	int *b;
	int target = 9;
	int numsSize = 4;
	b = TwoSum(a, numsSize, target);
	printf("[%d %d]\n", b[0], b[1]);

}


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