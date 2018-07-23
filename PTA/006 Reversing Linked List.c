/*这个题目最后一个
case是：有多余的结点并不在聊表上面*/
/*所以最后用m来计算count，而不是输入的length*/
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

	/*m用来存储能够首尾相连的节点数*/
	/*length表示所有的长度*/
	int m = 0;
	int p = 0;
	p = FirstAddress;
	while(p != -1)
	{
		list[m++] = p;
		p = Nodelist[p].next;
	}

	int around = m / K;
	for(i = 0; i < around; i++)
	{
		int start = i * K;
		int end = (i + 1) * K - 1;
		for(j = 0; j < K/2; j++)
		{
			reverse(&list[start + j], &list[end - j]);			
		}
	}

	for(i = 0; i < m - 1; i++)
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

// /*网上参考答案，全部case正确*/
// #include<iostream>  
// #include<stdio.h>  
// #include<algorithm>    ///使用到reverse 翻转函数
// /*注意algorithm函数中的reverse是翻转整个从开始到结束*/
// /*会把1 2 3 4 5 6翻转为6 5 4 3 2 1*/
// using namespace std;  

// #define MAXSIZE 1000010   ///最大为五位数的地址  

// struct node    ///使用顺序表存储data和下一地址next  
// {  
//    int data;     
//    int next;  
// }node[MAXSIZE];  

// int List[MAXSIZE];   ///存储可以连接上的顺序表  
// int main()  
// {
//     int First, n, k;    
//     cin>>First>>n>>k;   ///输入头地址 和 n，k；  
//     int Address,Data,Next;  
//     for(int i=0;i<n;i++)  
//     {  
//         cin>>Address>>Data>>Next;  
//         node[Address].data=Data;  
//         node[Address].next=Next;  
//     }  

//     int j=0;  ///j用来存储能够首尾相连的节点数  
//     int p=First;   ///p指示当前结点  
//     while(p!=-1)  
//     {  
//         List[j++]=p;  
//         p=node[p].next;  
//     }  
//     int i=0;  
//     while(i+k<=j)   ///每k个节点做一次翻转  
//     {
//     	/*void reverse (BidirectionalIterator first, BidirectionalIterator last)*/
//     	/*[first,last), which contains all the elements between first and last, 
//     	including the element pointed by first but not the element pointed by last.*/
//         reverse(&List[i],&List[i+k]);  
//         i=i+k;  
//     }  
//     for(i=0;i<j-1;i++)  
//         printf("%05d %d %05d\n",List[i],node[List[i]].data,List[i+1]);  
//     printf("%05d %d -1\n",List[i],node[List[i]].data);  
//     return 0;  
// } 