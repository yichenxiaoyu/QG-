#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct qNode  //定义节点
{
	char date[10];
	struct qNode* next;
}qNode;

typedef struct linkQ  //定义链式队列
{
	int cnt;          //队列元素个数
	qNode* head;
	qNode* tail;
}linkQ;


linkQ* InitQueue(void);  //初始化队列
void Destroy(linkQ* qlink, int* i);  //销毁队列

void enQueue(linkQ** qlink);  //入队
void deQueue(linkQ** qlink);  //出队
void showQueue(qNode* head);  //显示队列成员
void GetHeadQueue(qNode* head);  //查看队头元素
int IsEmptyQueue(qNode* head);  //判断是否队列为空
void LengthQueue(linkQ* qlink);  //判断队列长度
void ClearQueue(linkQ* qlink);  //清空队列

