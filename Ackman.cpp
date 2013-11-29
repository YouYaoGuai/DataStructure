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

int Ackman(int m,int n)
{
	int temp;
	if(m == 0)
		return n+1;
	else if(n == 0)
		return Ackman(m-1,1);
	else
	{
		temp = Ackman(m,n-1);
		return Ackman(m-1,temp);
	}
}

int main()
{
	int m,n;
	m = 2;
	n = 3;
	printf("%d",Ackman(m,n));
	system("Pause");
}




