#pragma once
#include"declareStack.h"

void push_math(sumStack** all, char ch);
long long push_stack(StackNode** top, char* clist, sumStack** all);
int Priority(char ch);
void Calculate(StackNode** top, sumStack** all);
long long getFigura(char** list);
void InitLinkStack(LinkStack* links);  //��ʼ����ջ
long long getFigura(char** list);  //���ַ����е�����ת����long long��
void Calculate(StackNode** top, sumStack** all);