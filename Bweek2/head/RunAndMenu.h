#pragma once
#include"Declare.h"
char* menu(void);

char* menu1(void);  //���д����˵�
int run1(linkQ** qlink, int* i);    //ִ��

char* menu2(void);  //����Ԫ�ظ��Ĳ˵�
int run2(linkQ** qlink, int i);    //ִ��

char* menu3(void);  //����Ԫ�ظ��Ĳ˵�
int run3(linkQ** qlink, int i);   //ִ��
int runing(linkQ** qlink, int* judge);