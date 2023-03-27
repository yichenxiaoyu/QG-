#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct qNode  //����ڵ�
{
	char date[10];
	struct qNode* next;
}qNode;

typedef struct linkQ  //������ʽ����
{
	int cnt;          //����Ԫ�ظ���
	qNode* head;
	qNode* tail;
}linkQ;


linkQ* InitQueue(void);  //��ʼ������
void Destroy(linkQ* qlink, int* i);  //���ٶ���

void enQueue(linkQ** qlink);  //���
void deQueue(linkQ** qlink);  //����
void showQueue(qNode* head);  //��ʾ���г�Ա
void GetHeadQueue(qNode* head);  //�鿴��ͷԪ��
int IsEmptyQueue(qNode* head);  //�ж��Ƿ����Ϊ��
void LengthQueue(linkQ* qlink);  //�ж϶��г���
void ClearQueue(linkQ* qlink);  //��ն���

