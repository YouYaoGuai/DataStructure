// huawei.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"
#include "assert.h"

#define STACK_TYPE int
#define STACK_SIZE 100


#define OK 0
#define ERROR 1

static STACK_TYPE stack[STACK_SIZE];
static int top_element = -1;

int is_full(void)
{
	return top_element == STACK_SIZE - 1;
}
int is_empty(void)
{
	return top_element == -1;
}

void push(STACK_TYPE value)
{
	assert(!is_full());
	top_element += 1;
	stack[top_element] = value;
}

STACK_TYPE pop(void)
{
	assert(!is_empty());
	return stack[top_element--];
}

STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack[top_element];
}

