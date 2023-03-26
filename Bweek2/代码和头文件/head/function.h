#pragma once
#include"declareStack.h"

void push_math(sumStack** all, char ch);
long long push_stack(StackNode** top, char* clist, sumStack** all);
int Priority(char ch);
void Calculate(StackNode** top, sumStack** all);
long long getFigura(char** list);
void InitLinkStack(LinkStack* links);  //初始化链栈
long long getFigura(char** list);  //将字符串中的数字转换成long long型
void Calculate(StackNode** top, sumStack** all);