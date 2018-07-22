#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
struct Node
{
	int data;
	int next;
};
struct Node Nodelist[MAX];
int list[MAX];

void reverse(int * i, int * j);

int main()
{
	int FirstAddress;
	int Address;
	int length;
	int K;   /*reverse the link every K elements*/

	int i;
	int j;

	scanf("%d %d %d", &FirstAddress, &length, &K);
	for(i = 0; i < length; i++)
	{
		scanf("%d", &Address);
		scanf("%d", &Nodelist[Address].data);
		scanf("%d", &Nodelist[Address].next); 
	}

	int m = 0;
	int p;
	p = FirstAddress;
	while(p != -1)
	{
		list[m++] = p;
		p = Nodelist[p].next;
	}

	int around = length / K;
	for(i = 0; i < around; i++)
	{
		int start = i * K;
		int end = (i + 1) * K - 1;
		for(j = 0; j < K/2; j++)
		{
			reverse(&list[start + j], &list[end - j]);			
		}
	}

	for(i = 0; i < length - 1; i++)
	{
		printf("%05d %d %05d\n", list[i], Nodelist[list[i]].data,list[i + 1]);
	}

	printf("%05d %d -1", list[i], Nodelist[list[i]].data);

	return 0;
}

void reverse(int * i, int * j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}