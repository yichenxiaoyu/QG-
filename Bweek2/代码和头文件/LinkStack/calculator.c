#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"declareStack.h"
#include"function.h"


void InitLinkStack(LinkStack*links)  //��ʼ����ջ
{
	(*links).top = NULL;
}


long long getFigura(char** list)  //���ַ����е�����ת����long long��
{
	long long sum = 0, temp;

	while ('0' <= *(*list) && *(*list) <= '9')
	{
		sum *= 10;
		temp = (long long)(*(*list) - '0');
		sum += temp;
		(*list)++;
	}
	return sum;
}

void Calculate(StackNode** top, sumStack** all)  //����ʽ��
{                                                //��ջ
	sumStack* temp = (*all);
	StackNode* tep = (*top);
	if ((*top)->date == '(')
	{

		(*top) = (*top)->next;
		free(tep);
		return;
	}
	long long right = 0;
	char ch = (*top)->date;
	right = (*all)->date;  //��ֵ
	(*all) = (*all)->next;
	
	if (ch == '+')
	{
		(*all)->date += right;
	}
	else if (ch == '-')
	{
		(*all)->date -= right;
	}
	else if (ch == '*')
	{
		(*all)->date *= right;
	}
	else if (ch == '-')
	{
		(*all)->date /= right;
	}
	(*top) = (*top)->next;
	free(temp);
	free(tep);
}


int Priority(char ch) //���㼶�ж�
{
	switch(ch)
	{
	case '(':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}