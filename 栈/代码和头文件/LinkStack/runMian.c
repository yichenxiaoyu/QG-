#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<string.h>
#include"function.h"

char* menu(void)
{
	char op[10];
	printf("��ѡ���˳�     > 0\n");
	printf("��ѡ�����ʹ�� > 1\n");
	scanf("%s", op);
	return op;
}

char run(void)
{
	char clist[50];
	LinkStack links;
	printf("������һ������ļ���ʽ��\n>>");
	scanf("%s", clist); //��ȡ����ʽ��
	InitLinkStack(&links);  //��ʼ����ջ

	sumStack* all = NULL;

	long long sum = push_stack(&(links.top), clist, &all);
	if (sum && links.top != NULL)  //���ʽ����ȷ
	{
		printf("��磬���ʽ�����⣡\n");
		return '3';
	}
	printf("���Ϊ %lld \n\n", sum);
	free(all);
	free(links.top);
	return '1';
}

int main()
{
	printf("����һ���ǳ��򵥵ļ�����������������\n");

	char* op;
	do
	{
		op = menu();
		switch (*op)
		{
		case '1':
			if(*(op+1) == '\0')
			{
				*op = run();
				break;
			}
		case '0':
			if (*(op + 1) == '\0')
				break;
		default :
			printf("�����������������\n\n");
		}
	} while (*op - '0');
	printf("���˳�����лʹ�ã�\n");
}