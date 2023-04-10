#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct treeNode  // 二叉树
{
	char message;
	struct treeNode* lchild, * rchild;
}treeNode, * ptree;

//栈
typedef struct StackNode  // 栈
{
	struct treeNode* data;  // 存放数据
	struct StackNode* next;
}StackNode, * pStack;

//队列
typedef struct linkNode  // 队列
{
	struct treeNode* data;
	struct linkNode* next;
}linkNode, * plink;

typedef struct
{
	linkNode* head, * tail;  //存放队头和队尾指针
}linkQueue;


ptree InitTree(void);
void SearchTree(ptree T);  //查找
void DeleteTree(ptree T);  //删除
void DeleteT(ptree Node);
void InsertTree(ptree* root, char* data);  //增加
void InsertT(ptree* T);  //添加操作
int JudgeNum(char* data);  //判断数据是否符合要求

void LevelOrder(ptree T);  //层次遍历

void PreOrder(ptree T);  //先序遍历
void MidOrder(ptree T);  //中序遍历
void PostOrder(ptree T);  //后序遍历
void visit(ptree T);  //访问

//非递归
void PreOrder2(ptree T);  
void MidOrder2(ptree T);
void PostOrder2(ptree T);

//队列
void Initqueue(linkQueue* Q);  //初始化
void EnQueue(linkQueue* Q, ptree T);  //入队
void DeQueue(linkQueue* Q, ptree* temp);  //出队
int isEmpty(linkQueue* Q);  //判断是否为空

//栈
//初始化
pStack InitStack(void);  
//入栈
void EnStack(pStack* head, ptree T);
//出栈
ptree DeStack(pStack* head);
//判空
int empty(pStack head);