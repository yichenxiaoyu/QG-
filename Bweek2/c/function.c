#define _CRT_SECURE_NO_WARNINGS 1
#include"Declare.h"

linkQ* InitQueue(void)  //初始化队列
{
	linkQ* qlink = (linkQ*)malloc(sizeof(linkQ));
	qlink->head = NULL;
	qlink->tail = NULL;
	qlink->cnt = 0;
	printf("初始化成功！\n\n");
	return qlink;
}

void Destroy(linkQ* qlink, int* i)  //销毁队列
{
	qNode* temp;
	while (qlink->head != NULL)
	{
		temp = qlink->head;
		qlink->head = qlink->head->next;
		free(temp);
	}
	qlink->tail = NULL;
	printf("销毁成功！\n\n");
	*i = 1;
}


void enQueue(linkQ** qlink)  //入队
{
	qNode* temp = (qNode*)malloc(sizeof(qNode));
	if (temp ==NULL )
	{
		printf("fail!\n");
		return;
	}
	//将元素排在队尾，tail向后移
	printf("请输入需要的数据\n");
	scanf("%s", temp->date);
	if ((*qlink)->cnt == 0)  //判断队列是否为空
	{
		temp->next = (*qlink)->tail;
		(*qlink)->tail = (*qlink)->head = temp;
	}
	else
	{
		temp->next = ((*qlink)->tail)->next;
		((*qlink)->tail)->next = temp;
		((*qlink)->tail) = temp;
	}
	(*qlink)->cnt++;  //元素个数++
	printf("入队成功\n\n");
}


void deQueue(linkQ** qlink)  //出队
{
	if (IsEmptyQueue((*qlink)->head))
	{
		return;
	}
	(*qlink)->cnt--;
	qNode* temp = (*qlink)->head;
	(*qlink)->head = (*qlink)->head->next;
	free(temp);
	printf("出队成功\n\n");
}

void showQueue(qNode* head)  //显示队列成员
{
	while (head != NULL)
	{
		printf("%s\t", head->date);
		head = head->next;
	}
	printf("\n");
}


void GetHeadQueue(qNode* head)  //查看队头元素
{
	if (IsEmptyQueue(head))
	{
		return;
	}
	printf("队头元素：%s\n", head->date);
}


int IsEmptyQueue(qNode* head)  //判断是否队列为空
{
	if (head == NULL)
	{
		printf("队列元素为空，请加入新的成员。\n\n");
		return 1;
	}
	return 0;
}

void LengthQueue(linkQ* qlink)  //判断队列长度
{
	printf("队列元素个数为 %d\n\n", qlink->cnt);
}


void ClearQueue(linkQ* qlink)  //清空队列
{
	qlink->cnt = 0;
	qNode* temp;
	while (qlink->head != NULL)
	{
		temp = qlink->head;
		qlink->head = qlink->head->next;
		free(temp);
	}
	qlink->tail = NULL;
	printf("清空成功！\n");
}


