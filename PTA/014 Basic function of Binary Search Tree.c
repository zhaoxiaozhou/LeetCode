#include <stdio.h>
#include <stdlib.h>
/*下面是错误的代码*/
                /*只有两种情况，忽略了左右子树都为空的情况*/
                // if(BST->Left != NULL)
                // {
                //     BST = BST->Left;
                // }
                // else if(BST->Right != NULL)
                // {
                //     BST = BST->Right;
                // }
/*这个题目很值得好好看一看*/

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }

    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    printf("Minp is :%d\n", MinP->Data);

    MaxP = FindMax(BST);
    printf("MaxP is :%d\n", MaxP->Data);

    scanf("%d", &N);

    /*Find Operation*/
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }

    /*Delete Operation*/
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}


BinTree Insert( BinTree BST, ElementType X )
{
    if(BST == NULL)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else
    {
        if(X > BST->Data)
        {
            BST->Right = Insert(BST->Right, X);
        }
        else if(X < BST->Data)
        {
            BST->Left = Insert(BST->Left, X);
        }        
    }
    return BST;
}


BinTree Delete( BinTree BST, ElementType X )
{
    BinTree Temp;

    if(BST == NULL)
    {
        printf("Not Found\n");
        return NULL;
    }
    else
    {
        if(X < BST->Data)
        {
            BST->Left = Delete(BST->Left, X);
        }
        else if(X > BST->Data)
        {
            BST->Right = Delete(BST->Right, X);
        }
        else
        {
            /*删除的结点有左右子结点*/
            if((BST->Left != NULL) && (BST->Right != NULL))
            {
                Temp = FindMin(BST->Right);
                BST->Data = Temp->Data;
                BST->Right = Delete(BST->Right, Temp->Data);
            }
            /*被删除的结点最多只有一个结点*/
            else
            {
                //Temp = BST;

                if(!BST->Left)
                {
                    BST = BST->Right;
                }
                else if(!BST->Right)
                {
                    BST = BST->Left;
                }
                /*下面是错误的代码*/
                /*只有两种情况，忽略了左右子树都为空的情况*/
                // if(BST->Left != NULL)
                // {
                //     BST = BST->Left;
                // }
                // else if(BST->Right != NULL)
                // {
                //     BST = BST->Right;
                // }
                /*这里free掉不太理解*/
               //free(Temp);
            }   

        }
    }

    return BST;
    //return NULL;
}

BinTree Delete1( BinTree BST, ElementType X )
{

    BinTree Temp, Temp1;
    Temp1 = BST;

    if(!BST)
    {
        printf("Not Found\n");
        return Temp1;
    }
    else
    {
        if(X < BST->Data)
        {
            BST->Left = Delete(BST->Left, X);
        }
        else if(X > BST->Data)
        {
            BST->Right = Delete(BST->Right, X);
        }
        else
        {
            if(BST->Left && BST->Right)
            {
                Temp = FindMin(BST->Right);
                BST->Data = Temp->Data;
                BST->Right = Delete(BST->Right, Temp->Data);
            }
            else
            {
                Temp = BST;

                if(!BST->Left)
                {
                    BST = BST->Right;
                }
                else if(!BST->Right)
                {
                    BST = BST->Left;
                }

                free(Temp);
            }
        
        }

    }
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    while(BST)
    {
        if(X < BST->Data)
        {
            BST = BST->Left;
        }
        else if(X > BST->Data)
        {
            BST = BST->Right;
        }
        else
        {
            return BST;
        }
    }
    return NULL;
}


Position FindMin( BinTree BST )
{
    if(BST != NULL)
    {
        while(BST->Left != NULL)
        {
            BST = BST->Left;
        }
    }
    return BST;
}

Position FindMax( BinTree BST )
{
    if(BST != NULL)
    {
        while(BST->Right != NULL)
        {
            BST = BST->Right;
        }
    }
    return BST;
}

void PreorderTraversal( BinTree BT )/* 先序遍历，由裁判实现，细节不表 */
{
    if(BT != NULL)
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void InorderTraversal( BinTree BT )  /* 中序遍历，由裁判实现，细节不表 */
{
    if(BT != NULL)
    {
        InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right);
    }
}