#pragma once

typedef struct StackNode
{
	char date;  //��������
	struct StackNode* next;
}StackNode, * LinkStackPtr;


typedef struct LinkStack //�����ջ
{
	LinkStackPtr top;  //ջ��ָ��
}LinkStack;


typedef struct sumStack  //������ջ
{
	long long date;  //�������
	int num;
	struct sumStack* next;
}sumStack;
