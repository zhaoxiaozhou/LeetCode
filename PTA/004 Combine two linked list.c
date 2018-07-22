List Merge(List L1, List L2)
{

	/*首先要申请一个头结点，并且把头结点下一个结点指向空*/
	/*头结点的目的是为了最后的返回*/
	List S;
	S = (List)malloc(sizeof(struct Node));
	S->Next = NULL;

	/*为链表定义一个尾结点，用于结点的插入*/
	List Rear;
	Rear = S;

	List p = L1->Next;
	List q = L2->Next;

	while(p != NULL && q != NULL)
	{
		if(p->Data < q->Data)
		{
			Rear->Next = p;
			p = p->Next;
		}
		else
		{
			Rear->Next = q;
			q = q->Next;
		}
		Rear = Rear->Next;
	}

	if(p != NULL)
	{
		Rear->Next = p;
	}

	if(q != NULL)
	{
		Rear->Next = q;
	}
	
	return S;
}