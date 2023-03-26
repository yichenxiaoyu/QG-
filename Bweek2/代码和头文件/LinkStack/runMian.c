#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<string.h>
#include"function.h"

char* menu(void)
{
	char op[10];
	printf("请选择退出     > 0\n");
	printf("请选择继续使用 > 1\n");
	scanf("%s", op);
	return op;
}

char run(void)
{
	char clist[50];
	LinkStack links;
	printf("请输入一个合理的计算式！\n>>");
	scanf("%s", clist); //获取计算式子
	InitLinkStack(&links);  //初始化链栈

	sumStack* all = NULL;

	long long sum = push_stack(&(links.top), clist, &all);
	if (sum && links.top != NULL)  //表达式不正确
	{
		printf("大哥，表达式有问题！\n");
		return '3';
	}
	printf("结果为 %lld \n\n", sum);
	free(all);
	free(links.top);
	return '1';
}

int main()
{
	printf("这是一个非常简单的计算器，请手下留情\n");

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
			printf("输入错误！请重新输入\n\n");
		}
	} while (*op - '0');
	printf("已退出，感谢使用！\n");
}