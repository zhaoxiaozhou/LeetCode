#include<stdio.h>

typedef int ElementType;

typedef struct Node*PtrToNoe;
struct Node
{
	ElementType Data;
	PtrToNode Next; 
};
typedef PtrToNode List;

List Reverse(List L)
{
	List p, q, t;
	p = L;
	q = NULL;
	while(p != NULL)
	{
		t = p->Next;
		p->Next = q;
		q = p;
		p = t;
	}
	return q;
}

List Reverse(List L)
{
	List p, q, t;
	p = L;
	q = NULL;
	while(p != NULL)
	{
		t = p->Next;
		p->Next = q;
		q = p;
		p = t;
	}
	return q;
}