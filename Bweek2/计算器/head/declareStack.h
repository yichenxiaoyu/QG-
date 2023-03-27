#pragma once

typedef struct StackNode
{
	char date;  //存放运算符
	struct StackNode* next;
}StackNode, * LinkStackPtr;


typedef struct LinkStack //运算符栈
{
	LinkStackPtr top;  //栈顶指针
}LinkStack;


typedef struct sumStack  //操作数栈
{
	long long date;  //存放数据
	int num;
	struct sumStack* next;
}sumStack;
