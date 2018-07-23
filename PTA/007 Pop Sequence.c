#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1000

typedef struct
{
	int data[MAXSIZE];
	int top;
}SqStack;


int InitStack(SqStack *s)
{
	s->top = -1;
	return 0;
}


int Push(SqStack *s, int e)
{
	if(s->top == MAXSIZE)
	{
		return 1;
	}
	s->top++;
	s->data[s->top] = e;
	return 0;
}


int Pop(SqStack *s)
{
	int e;
	if(s->top == -1)
	{
		return 1;
	}
	e = s->data[s->top--];
	return e;
}


int main()
{
	int m, n, k;
	SqStack s, t;
	int i;
	scanf("%d %d %d", &m, &n, &k);
	while(k--)
	{
		InitStack(&s);
		InitStack(&t);
		/*将给出的序列依次压入栈t中(首元素为栈顶)*/ 
		for(i = n - 1; i >= 0; i--)
		{
			scanf("%d", &(t.data[i]));
		}
		t.top = n-1;

		i = 0;
		while(i <= n)
		{
			/*如果s的栈顶元素和t的栈顶元素相同*/  
			if(s.data[s.top] == t.data[t.top] && s.top != -1)
			{
				Pop(&s);
				Pop(&t);
			}
			/*如果s的栈顶元素和t的栈顶元素不相同*/  
			/*s.top < m - 1判断堆栈未满*/
			else if (s.top < m - 1 && i < n)	
			{
				i++;
				Push(&s, i);
			}
			else
			{
				break;
			}
		}
		if(s.top == -1 && t.top == -1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}

	return 0;
}