#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct treeNode  // ������
{
	char message;
	struct treeNode* lchild, * rchild;
}treeNode, * ptree;

//ջ
typedef struct StackNode  // ջ
{
	struct treeNode* data;  // �������
	struct StackNode* next;
}StackNode, * pStack;

//����
typedef struct linkNode  // ����
{
	struct treeNode* data;
	struct linkNode* next;
}linkNode, * plink;

typedef struct
{
	linkNode* head, * tail;  //��Ŷ�ͷ�Ͷ�βָ��
}linkQueue;


ptree InitTree(void);
void SearchTree(ptree T);  //����
void DeleteTree(ptree T);  //ɾ��
void DeleteT(ptree Node);
void InsertTree(ptree* root, char* data);  //����
void InsertT(ptree* T);  //��Ӳ���
int JudgeNum(char* data);  //�ж������Ƿ����Ҫ��

void LevelOrder(ptree T);  //��α���

void PreOrder(ptree T);  //�������
void MidOrder(ptree T);  //�������
void PostOrder(ptree T);  //�������
void visit(ptree T);  //����

//�ǵݹ�
void PreOrder2(ptree T);  
void MidOrder2(ptree T);
void PostOrder2(ptree T);

//����
void Initqueue(linkQueue* Q);  //��ʼ��
void EnQueue(linkQueue* Q, ptree T);  //���
void DeQueue(linkQueue* Q, ptree* temp);  //����
int isEmpty(linkQueue* Q);  //�ж��Ƿ�Ϊ��

//ջ
//��ʼ��
pStack InitStack(void);  
//��ջ
void EnStack(pStack* head, ptree T);
//��ջ
ptree DeStack(pStack* head);
//�п�
int empty(pStack head);