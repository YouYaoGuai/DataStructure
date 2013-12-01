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

int CreateList(LinkList *a,int length)
{
        int i = 0;
        LinkList p;
        *a = (LinkList)malloc(sizeof(LNode));
        assert(a != NULL);
        (*a)->next = NULL;
        for(i = length;i>0;--i)
        {
                p = (LinkList)malloc(sizeof(LNode));
                assert(p != NULL);
                scanf("%c",&(p->data));
                getchar();
                p->next = (*a) ->next;
                (*a)->next = p;
        }
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

int main()
{
	    LinkList *pc;
		LinkList pa;
		pc = &pa;
        int length = 5;
        char data;

        CreateList(pc,length);
        PrintList(*pc);
		system("PAUSE");
}
