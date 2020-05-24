#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include <windows.h>
#pragma warning(disable:4996)
/**********************************文件数据函数声明*********************************************/


void file_recovers();   //文件恢复

void file_backups();    //文件备份

void file_backups()
{
	FILE* op, * inp;
	if ((op = fopen("职工账号.txt", "rb")) == NULL)
	{
		printf("\n\t\t文件打开失败！\n");
	}
	if ((inp = fopen("职工账号备份.txt", "wb")) == NULL)
	{
		printf("\n\t\t文件打开失败！\n");
	}
	char c;
	while (!feof(op))
	{
		fread(&c, sizeof(char), 1, op);
		fwrite(&c, sizeof(char), 1, inp);
	}
	fclose(inp);
	fclose(op);
	printf("\n\t\t\t\t\t恭喜！文件数据备份完成！\n");
	printf("\n\t\t\t\t\t");
	system("pause");
	printf("\n\t\t\t\t\t\t\t\n");
	system("cls");
	return;
}

void file_recovers()
{
	FILE* op, * inp;
	if ((op = fopen("职工账号备份.txt", "rb")) == NULL)
	{
		printf("\n\t\t\t\t\t文件打开失败！\n");
	}
	if ((inp = fopen("职工账号.txt", "wb")) == NULL)
	{
		printf("\n\t\t\t\t\t文件打开失败！\n");
	}
	char c;
	while (!feof(op))
	{
		fread(&c, sizeof(char), 1, op);
		fwrite(&c, sizeof(char), 1, inp);
	}
	fclose(inp);
	fclose(op);
	printf("\n\t\t\t\t\t恭喜！文件数据恢复完成！\n");
	printf("\n\t\t\t\t\t");
	system("pause");
	printf("\n\t\t\t\t\t\t\t\n");
	system("cls");
	return;
}



