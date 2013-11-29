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


typedef struct LNode
{
	char data;
	struct LNode* next;
}LNode,*LinkList;


LinkList CreateList(LinkList a,int length)
{
	int i = 0;
	LinkList p;
	a = (LinkList)malloc(sizeof(LNode));
	assert(a != NULL);
	a->next = NULL;
	for(i = length;i>0;--i)
	{
		p = (LinkList)malloc(sizeof(LNode));
		assert(p != NULL);
		scanf("%c",&(p->data));
		getchar();
		p->next = a ->next;
		a->next = p;
	}
	return a;
}

char GetElem(LinkList a,int position)
{
	LinkList p = a->next;
	int j = 1;
	char e;
	while(p && j < position)
	{
		p = p->next;
		j++;
	}
	if(!p || j > position)
		return ERROR;
	e = p->data;
	return e;
}

int ListInsert(LinkList L,int position,char data)
{
	LinkList p = L;
	int i = 0;
	while(p&&i<position-1)
	{
		p = p->next;
		++i;
	}
	if(!p||i>position - 1)
		return ERROR;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = data;
	s->next = p->next;
	p->next = s;
	return OK;
}

int ListDelete(LinkList L,int position)
{
	LinkList p = L,q = NULL;
	int i = 0;
	while(p->next&&i<position - 1)
	{
		p = p->next;
		i++;
	}
	if(!(p->next)||i>position-1)
		return ERROR;
	q = p->next;
	p->next = p->next->next;
	free(q);
	return OK;
}

void PrintList(LinkList b)
{
	b = b->next;
	while( b->next != NULL)
	{
		printf("%c  ->  ",b->data);
		b = b->next;
	}
	printf("%c",b->data);
	printf("\n");
}

LinkList MergeList(LinkList a,LinkList b,LinkList c)
{
	LinkList pa = a->next;
	LinkList pb = b->next;
	LinkList pc = a;
	c = pc;
	while(pa&&pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa?pa:pb;
	free(b);
	return c;
}

LinkList ListIntersection(LinkList a,LinkList b)
{
	LinkList pa = a->next;
	LinkList pb = b->next;
	LinkList pc = a;
	LinkList Lc = a;
	while(pa&&pb)
	{
		if(pa->data == pb->data)
		{
			pc = pa;
			pa = pa->next;
		}
		else if(pa->data < pb->data)
		{
			pc->next = pa->next;
			free(pa);
			pa = pc->next;
		}
		else
			pb = pb->next;
	}
	pc->next = NULL;
	while(pa)
	{
		pc = pa;
		pa = pa->next;
		free(pc);
	}
	pb = b;
	while(pb)
	{
		pc = pb;
		pb = pb->next;
		free(pc);
	}
	return Lc;
}

LinkList ListSub(LinkList a,LinkList b)
{
	LinkList pa = NULL,pb = NULL,pc = NULL;
	pa = a->next;
	pb = b->next;
	pc = a;
	while(pa&&pb)
	{
		if(pa->data == pb->data)
		{
			pc->next = pa->next;
			free(pa);
			pa = pc->next;
		}
		else if(pa->data < pb->data)
		{
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pb = pb->next;
		}
	}
	pb = b;
	while(pb)
	{
		pc =pb;
		pb = pb->next;
		free(pc);
	}
	return a;
}

int main()
{
	LinkList pa = NULL,paa = NULL,pbb = NULL;
	LinkList pc = NULL;
	int length = 5;
	char data;
#if 0
	pa = CreateList(pa,length);
	PrintList(pa);
	data = GetElem(pa,2);
	ListInsert(pa,3,'x');
	PrintList(pa);
	ListDelete(pa,3);
	PrintList(pa);
	LinkList pb = NULL,pc = NULL;
	printf("input list b\n");
	pb = CreateList(pb,length);
	PrintList(pb);
    pc = MergeList(pa,pb,pc);
	PrintList(pc);
#endif

#if 0	
	printf("list intersection\n");
	paa = CreateList(paa,length);
	PrintList(paa);
	pbb = CreateList(pbb,length);
	PrintList(pbb);
	pc = ListIntersection(paa ,pbb);
	PrintList(pc);
#endif
	printf("list sub\n");
	paa = CreateList(paa,length);
	PrintList(paa);
	pbb = CreateList(pbb,length);
	PrintList(pbb);
	pc = ListSub(paa ,pbb);
	PrintList(pc);
	system("pause");
}
