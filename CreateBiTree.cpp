// huawei.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"
#include "assert.h"

#define OK 0
#define ERROR 1
#define MAX 100

typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBiTree( )
{
	BiTree T;
	TElemType ch = NULL;
	scanf("%c",&ch);
	getchar();
	if(ch == ' ')
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		assert(T != NULL);
		T->data = ch;
		T->lchild = CreateBiTree();
		T->rchild = CreateBiTree();
	}
	return T;
}

int main()
{
	BiTree tree = NULL;
	tree = CreateBiTree( );
	system("PAUSE");
}
