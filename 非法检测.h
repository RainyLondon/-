#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include <windows.h>
#pragma warning(disable:4996)

/*********************************非法输入检测函数声明**********************************************/


int Test1(char* a, int b, int c); //输入1位检测函数

int Test2(char* a, int b, int c);//输入1位检测函数

int Test8(char* a);                //输入8位检测函数

int Testx(char* a);             //输入姓名检测函数

int Testdate(char* a);          //输入入职时间检测函数


int Testnum1(char* a);          //输入工资信息检测函数
/*********************************检测函数**********************************************/

//输入1位检测函数
int Test1(char* a, int b, int c)
{
	int chose;
	char choose[100];
	chose = atoi(a);
	while (chose<b || chose>c || strlen(a) > 1)
	{
		printf("\n");
		printf("\n\t\t\t\t\t输入错误 请输入对应数字:");
		scanf("%s", choose);
		a = choose;
		chose = atoi(choose);
	}
	return chose;
}

//输入2位检测函数
int Test2(char* a, int b, int c)
{
	int chose;
	char choose[100];
	chose = atoi(a);
	while (chose<b || chose>c || strlen(a) > 2)
	{
		printf("\n");
		printf("\n\t\t\t\t\t\t\t输入错误 请输入对应数字:");
		scanf("%s", choose);
		a = choose;
		chose = atoi(choose);
	}
	return chose;
}

//输入8位检测函数
int Test8(char* a)
{
	int chose;
	chose = atoi(a);
	if (chose > 100000000 || chose < 1 || strlen(a) != 8)
	{
		return 1;
	}
	return 0;
}

//输入姓名检测函数
int Testx(char* a)
{
	int  i;
	int x = strlen(a);
	int f = 0;
	for (i = 0; i < x; i++)
	{
		if (*a >= '0' && *a <= '9')
		{
			f = 1;
		}
		else
		{
			f = 0;
		}
		a++;
	}
	return f;

}


//输入入职时间检测函数
int Testdate(char* a)
{
	int  i;
	int f = 0;
	for (i = 0; a[i]; i++)
	{
		if ((a[i] >= '0' && a[i] <= '9') || a[i] == '\\')
		{
			f = 0;
			break;
		}
		else
		{
			f = 1;
			break;
		}
	}
	return f;
}
//输入工资信息检测函数
int Testnum1(char* a)
{
	int  i;
	int x = strlen(a);
	int f = 0;
	for (i = 0; i < x; i++)
	{
		if (*a >= '0' && *a <= '9')
		{
			f = 0;
		}
		if (*a >= 'a' && *a <= 'z')
		{
			f = 1;
			break;
		}
		if (*a >= 'A' && *a <= 'Z')
		{
			f = 1;
			break;
		}
		a++;
	}
	return f;
}



