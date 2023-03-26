#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"function.h"





void push_math(sumStack** all, long long t)  //��������������ջ
{                                            //��ջ
	sumStack* temp = (sumStack*)malloc(sizeof(sumStack));
	if ((*all) == NULL)
	{
		temp->date = t;
		temp->next = (*all);
		(*all) = temp;
		return;
	}
	//ͷ��
	temp->date = t;
	temp->next = (*all);
	(*all) = temp;
}


void push_opt(StackNode** top, char ch)  //�������������ջ
{                                        //��ջ
	LinkStackPtr temp = (StackNode*)malloc(sizeof(StackNode));
	temp->date = ch;
	temp->next = (*top);
	(*top) = temp;
}

long long push_stack(StackNode** top, char* clist, sumStack** all)
{

	char oprator = '\0';
	long long temp = 0;  //
	int right = 0;
	while ((*clist) != '\0')
	{
		if ('0' <= *clist && *clist <= '9')
		{
			temp = getFigura(&clist);
			push_math(all, temp);
		}
		else if (
			*clist == '(' ||
			*clist == ')' ||
			*clist == '*' ||
			*clist == '/' ||
			*clist == '+' ||
			*clist == '-')
		{
			if ((*top) == NULL)
			{
				push_opt(top, *clist);
				clist++;
			}
			else if (Priority((*top)->date) >= Priority(*clist) && (*top)->date != '(')
			{
				Calculate(top, all);
				if (*clist == ')')
				{
					clist++;
					while ((*top)->date != '(')
					{
						Calculate(top, all);
					}
				}
			}
			else
			{
				push_opt(top, *clist);
				clist++;
			}
		}
		else
		{
			(*top) = malloc(sizeof(StackNode));
			return 1;
		}
	}
	while ((*top) != NULL)
	{
		Calculate(top, all);
	}
	return (*all)->date;
}