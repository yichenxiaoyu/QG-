#pragma once
#include"Declare.h"
char* menu(void);

char* menu1(void);  //队列存亡菜单
int run1(linkQ** qlink, int* i);    //执行

char* menu2(void);  //队列元素更改菜单
int run2(linkQ** qlink, int i);    //执行

char* menu3(void);  //队列元素更改菜单
int run3(linkQ** qlink, int i);   //执行
int runing(linkQ** qlink, int* judge);