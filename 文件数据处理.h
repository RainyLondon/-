#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include <windows.h>
#pragma warning(disable:4996)
/**********************************�ļ����ݺ�������*********************************************/


void file_recovers();   //�ļ��ָ�

void file_backups();    //�ļ�����

void file_backups()
{
	FILE* op, * inp;
	if ((op = fopen("ְ���˺�.txt", "rb")) == NULL)
	{
		printf("\n\t\t�ļ���ʧ�ܣ�\n");
	}
	if ((inp = fopen("ְ���˺ű���.txt", "wb")) == NULL)
	{
		printf("\n\t\t�ļ���ʧ�ܣ�\n");
	}
	char c;
	while (!feof(op))
	{
		fread(&c, sizeof(char), 1, op);
		fwrite(&c, sizeof(char), 1, inp);
	}
	fclose(inp);
	fclose(op);
	printf("\n\t\t\t\t\t��ϲ���ļ����ݱ�����ɣ�\n");
	printf("\n\t\t\t\t\t");
	system("pause");
	printf("\n\t\t\t\t\t\t\t\n");
	system("cls");
	return;
}

void file_recovers()
{
	FILE* op, * inp;
	if ((op = fopen("ְ���˺ű���.txt", "rb")) == NULL)
	{
		printf("\n\t\t\t\t\t�ļ���ʧ�ܣ�\n");
	}
	if ((inp = fopen("ְ���˺�.txt", "wb")) == NULL)
	{
		printf("\n\t\t\t\t\t�ļ���ʧ�ܣ�\n");
	}
	char c;
	while (!feof(op))
	{
		fread(&c, sizeof(char), 1, op);
		fwrite(&c, sizeof(char), 1, inp);
	}
	fclose(inp);
	fclose(op);
	printf("\n\t\t\t\t\t��ϲ���ļ����ݻָ���ɣ�\n");
	printf("\n\t\t\t\t\t");
	system("pause");
	printf("\n\t\t\t\t\t\t\t\n");
	system("cls");
	return;
}



