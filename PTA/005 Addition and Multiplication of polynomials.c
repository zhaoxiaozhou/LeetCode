#include<stdio.h>
#include<stdlib.h>

/*什么时候需要使用malloc来分配动态内存空间*/

typedef int ElementType;

typedef struct PolyNode *PtrToPolyNode;
struct PolyNode
{
	ElementType Coef;
	ElementType Expon;
	PtrToPolyNode Link;
};
typedef PtrToPolyNode Polynominal;

void Attach(int c, int e, Polynominal *PRear);
Polynominal ReadPoly();
Polynominal Add(Polynominal P1, Polynominal P2);
Polynominal Mult(Polynominal P1, Polynominal P2);
void PrintPoly(Polynominal P1);

int main()
{

	Polynominal P1;
	Polynominal P2;
	Polynominal Pmult;
	Polynominal PAdd;
	P1 = ReadPoly();
	P2 = ReadPoly();
	//PrintPoly(P1);
	//PrintPoly(P2);
	PAdd = Add(P1, P2);
	Pmult = Mult(P1, P2);
	PrintPoly(Pmult);
	PrintPoly(PAdd);
	return 0;
}

void Attach(int c, int e, Polynominal *PRear)/*这里是指针的指针啊*/
{
	Polynominal P;
	P = (Polynominal)malloc(sizeof(struct PolyNode));
	P->Coef = c;
	P->Expon = e;
	P->Link = NULL;
	(*PRear)->Link = P;
	(*PRear) = P;
}

Polynominal ReadPoly()
{
	int length;
	ElementType Coef;
	ElementType Expon;
	Polynominal P;
	Polynominal Rear;

	P = (Polynominal)malloc(sizeof(struct PolyNode));
	P->Link = NULL;
	Rear = P;

	scanf("%d", &length);
	while(length--)
	{
		scanf("%d", &Coef);
		scanf("%d", &Expon);
		/**/
		Attach(Coef, Expon, &Rear);
	}
	/*去掉链表头部有一个头结点*/
	P = P->Link;
	return P;
}

/*printf函数默认没有头结点的*/
void PrintPoly(Polynominal P1)
{
	int flag = 0;
	if(!P1)
	{
		printf("0 0\n");
		return;
	}
	while(P1)
	{
		if(!flag)
		{
			flag = 1;
		}
		else
		{
			/*Add a space before the num*/
			printf(" ");
		}
		printf("%d %d", P1->Coef, P1->Expon);
		P1 = P1->Link;
	}
	printf("\n");
}

/*要注意链表带不带头结点*/
Polynominal Add1(Polynominal P1, Polynominal P2)
{
	Polynominal P, t1, t2, Rear;
	t1 = P1;
	t2 = P2;
	/*申请一个空的头结点*/
	P = (Polynominal)malloc(sizeof(struct PolyNode));
	P->Link = NULL;
	Rear = P;

	while(t1&&t2)
	{
		if(t1->Expon == t2->Expon)
		{
			/*系数为0项目要去掉*/
			if((t1->Coef + t2->Coef)!=0)
			{
				Attach((t1->Coef + t2->Coef),t1->Expon,&Rear);
			}			
			t1 = t1->Link;
			t2 = t2->Link;
		}
		else if(t1->Expon > t2->Expon)
		{
			Attach(t1->Coef,t1->Expon,&Rear);
			t1 = t1->Link;

		}
		else
		{
			Attach(t2->Coef,t2->Expon,&Rear);
			t2 = t2->Link;
		}
	}
	while(t1)
	{
		Attach(t1->Coef,t1->Expon,&Rear);
		t1 = t1->Link;
	}
	while(t2)
	{
		Attach(t2->Coef,t2->Expon,&Rear);
		t2 = t2->Link;
	}

	t2 = P;
	P = P->Link;
	free(t2);
	return P;

}


Polynominal Add(Polynominal P1, Polynominal P2)
{
	Polynominal P;
	Polynominal Rear;
	/*这里有一个问题，我函数参数又不是指针，为什么不可以直接*/
	P = (Polynominal)malloc(sizeof(struct PolyNode));
	P->Link = NULL;
	Rear = P;

	Polynominal t;
	
	while(P1 && P2)
	{
		
		t = (Polynominal)malloc(sizeof(struct PolyNode));		
		if(P1->Expon == P2->Expon)
		{
			if((P1->Coef + P2->Coef) != 0)
			{
				t->Coef = P1->Coef + P2->Coef;
				t->Expon = P1->Expon;
				t->Link = NULL;
				//Attach((P1->Coef + P2->Coef), P1->Expon, &Rear);
			}
			P1 = P1->Link;
			P2 = P2->Link;
		}
		else if(P1->Expon > P2->Expon)
		{
			t->Coef = P1->Coef;
			t->Expon = P1->Expon;
			t->Link = NULL;
			P1 = P1->Link;
		}
		else
		{
			t->Coef = P2->Coef;
			t->Expon = P2->Expon;
			t->Link = NULL;
			P2 = P2->Link;
		}

		Rear->Link = t;
		Rear = t;

	}

	if(P1 != NULL)
	{
		Rear->Link = P1;
	}
	if(P2 != NULL)
	{
		Rear->Link = P2;
	}

	P = P->Link;
	//free(t);
	/*不能free，一用free就有错误发生*/
	return P;
}


Polynominal Mult(Polynominal P1, Polynominal P2)
{
	Polynominal P, Rear;
	Polynominal t1, t2, t;
	t1 = P1;
	t2 = P2;

	ElementType Coef;
	ElementType Expon;

	P = (Polynominal)malloc(sizeof(struct PolyNode));
	Rear = P;

	if(!P1 || !P2)
	{
		/*0乘以任何多项式都为0*/
		return NULL;
	}

	/*P1的第一项和P2的每一项相乘得到一个初始的多项式P*/
	/*然后P1的后面的多项式和P2每一项相乘，和P比较，插入正确的位置*/
	while(t2)
	{
		Attach(t1->Coef * t2->Coef, t1->Expon + t2->Expon, &Rear);
		t2 = t2->Link;
	}

	t1 = t1->Link;
	while(t1)
	{
		Rear = P;
		t2 = P2;

		while(t2)
		{
			Coef = t1->Coef * t2->Coef;
			Expon = t1->Expon + t2->Expon;

			while(Rear->Link && Rear->Link->Expon > Expon)
			{
				Rear = Rear->Link;
			}
			if(Rear->Link && Rear->Link->Expon == Expon)
			{
				/*这里是不是有错误的情况，应该是不等于0吧*/
				if(Rear->Link->Coef + Coef)
				{
					Rear->Link->Coef += Coef;
				}
				else
				{
					Rear->Link = Rear->Link->Link;
				}

			}
			else
			{	
				t = (Polynominal)malloc(sizeof(struct PolyNode));
				t->Coef =Coef;
				t->Expon = Expon;
				t->Link = Rear->Link;
				Rear->Link = t;
				Rear = Rear->Link;
				//Attach(Coef, Expon, &Rear);
			}

			t2 = t2->Link;
		}
		t1 = t1->Link;

	}
	/*去掉表头的结点*/
	P = P->Link;
	return P;
}

Polynominal Mult1(Polynominal P1, Polynominal P2)
{
	Polynominal t1, t2, P, Rear,t;
	ElementType c,e;

	if(!P1 || !P2) /*判断P1， P2是否为空结点*/
	{
		return NULL;
	}
	t1 = P1;
	t2 = P2;
	P = (Polynominal)malloc(sizeof(struct PolyNode));
	Rear = P;

	while(t2)/*用P1的第一项先乘以P2的每一项,得到P*/
	{
		Attach(t1->Coef*t2->Coef, t1->Expon+t2->Expon,&Rear);
		t2 = t2->Link;
	}
	t1 = t1->Link;
	while(t1)
	{
		t2 = P2;
		Rear = P;
		while(t2)
		{	
			c = t1->Coef * t2->Coef;
			e = t1->Expon + t2->Expon;

			while(Rear->Link && Rear->Link->Expon > e)
			{
				Rear = Rear->Link;
			}
			if(Rear->Link && Rear->Link->Expon == e)
			{
				if(Rear->Link->Coef +c)
				{
					Rear->Link->Coef += c;
				}
				else
				{
					t = Rear->Link;
					Rear->Link = t->Link;
					free(t);
				}
			}
			else
			{
				t = (Polynominal)malloc(sizeof(struct PolyNode));
				t->Coef = c;
				t->Expon = e;
				t->Link = Rear->Link;
				Rear->Link = t;
				Rear = Rear->Link;
			}

			t2 = t2->Link;

		}
		t1 = t1->Link;
	}
	/*表头的空结点去掉*/
	t2 = P;
	P = P->Link;
	free(t2);

	return P;
}


/*PTA 正确答案，上面有一点问题*/
#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct PolyNode *Polynomial;
struct PolyNode
{
	ElementType Coef;
	ElementType Expon;
	Polynomial Link;
};

void Attach(int c, int e, Polynomial * PRear);
Polynomial ReadPoly();
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult();
void PrintPoly(Polynomial L);

int main()
{
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	//PrintPoly(P1);
	PP = Mult(P1,P2);
	PrintPoly(PP);
	
	PS = Add(P1,P2);
	PrintPoly(PS);


	return 0;
}

void Attach(int c, int e, Polynomial * PRear)/*这里是指针的指针啊*/
{
	/*申请一个空的结点*/
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Coef = c;
	P->Expon = e;
	P->Link = NULL;
	/*把该结点P放在Rear最后*/
	(*PRear)->Link = P;
	/*修改尾结点*/
	(*PRear) = P;	
}


Polynomial ReadPoly()
{	
	int length;
	int Coef;
	int Expon;

	Polynomial P, Rear, t;
	scanf("%d", &length);	

	/*链表头空结点*/
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Link = NULL;
	Rear = P;

	
	while(length--)
	{	
		scanf("%d %d", &Coef, &Expon);
		/*输入注意如果出现系数为0的话去掉！！*/
		if(Coef != 0)
			Attach(Coef,Expon,&Rear);
	}
	/*把链表头部的临时的空结点删除掉*/
	t = P;
	P = P->Link;
	free(t);
	return P;
}

void PrintPoly(Polynomial L)
{
	int flag = 0;
	//L = L->Link;
	
	if(!L)
	{
		printf("0 0\n");
		return;
	}
	/*非零项不需要输出*/
	while(L)
	{
		if(!flag)
		{
			flag = 1;
		}
		else
		{
			printf(" ");
		}

		printf("%d ",L->Coef);
		printf("%d",L->Expon);	

		L = L->Link;
	}
	printf("\n");
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial P, t1, t2, Rear;
	t1 = P1;
	t2 = P2;
	/*申请一个空的头结点*/
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->Link = NULL;
	Rear = P;

	while(t1&&t2)
	{
		if(t1->Expon == t2->Expon)
		{
			/*系数为0项目要去掉*/
			if((t1->Coef + t2->Coef)!=0)
			{
				Attach((t1->Coef + t2->Coef),t1->Expon,&Rear);
			}			
			t1 = t1->Link;
			t2 = t2->Link;
		}
		else if(t1->Expon > t2->Expon)
		{
			Attach(t1->Coef,t1->Expon,&Rear);
			t1 = t1->Link;

		}
		else
		{
			Attach(t2->Coef,t2->Expon,&Rear);
			t2 = t2->Link;
		}
	}
	while(t1)
	{
		Attach(t1->Coef,t1->Expon,&Rear);
		t1 = t1->Link;
	}
	while(t2)
	{
		Attach(t2->Coef,t2->Expon,&Rear);
		t2 = t2->Link;
	}

	t2 = P;
	P = P->Link;
	free(t2);
	return P;

}


Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial t1, t2, P, Rear,t;
	ElementType c,e;

	if(!P1 || !P2) /*判断P1， P2是否为空结点*/
	{
		return NULL;
	}
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	Rear = P;

	while(t2)/*用P1的第一项先乘以P2的每一项,得到P*/
	{
		Attach(t1->Coef*t2->Coef, t1->Expon+t2->Expon,&Rear);
		t2 = t2->Link;
	}
	t1 = t1->Link;
	while(t1)
	{
		t2 = P2;
		Rear = P;
		while(t2)
		{	
			c = t1->Coef * t2->Coef;
			e = t1->Expon + t2->Expon;

			while(Rear->Link && Rear->Link->Expon > e)
			{
				Rear = Rear->Link;
			}
			if(Rear->Link && Rear->Link->Expon == e)
			{
				if(Rear->Link->Coef +c)
				{
					Rear->Link->Coef += c;
				}
				else
				{
					t = Rear->Link;
					Rear->Link = t->Link;
					free(t);
				}
			}
			else
			{
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->Coef = c;
				t->Expon = e;
				t->Link = Rear->Link;
				Rear->Link = t;
				Rear = Rear->Link;
			}

			t2 = t2->Link;

		}
		t1 = t1->Link;
	}
	/*表头的空结点去掉*/
	t2 = P;
	P = P->Link;
	free(t2);

	return P;
}