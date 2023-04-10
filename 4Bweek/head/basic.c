#include"Function.h"
//队列
void Initqueue(linkQueue* Q)  //初始化队列
{
	Q->tail = Q->head = (linkNode*)malloc(sizeof(linkNode));
	Q->head->data = NULL;
	Q->head->next = NULL;
}

//入队
void EnQueue(linkQueue* Q, ptree T)
{
	if (Q->head == NULL)
		Q->tail = Q->head = (linkNode*)malloc(sizeof(linkNode));
	linkNode* h = Q->head;  //分别得到头尾指针
	linkNode* t = Q->tail;
	if (h == t)  //如果队列为空
		h->data = T;
	else  //在队尾添加
	{
		linkNode* temp = (linkNode*)malloc(sizeof(linkNode));
		temp->data = T;
		t->next = temp;
		t = temp;
	}
}

//出队
void DeQueue(linkQueue* Q, ptree* temp)
{
	linkNode* q = Q->head;  //头指针
	*temp = q->data;
	if (Q->head == Q->tail)
	{
		Q->tail = NULL;
	}
	Q->head = q->next;  //向后移
	free(q);
}

//判断是否为空
int isEmpty(linkQueue* Q)
{
	if (Q->head->data == NULL)
		return 1;
	else
		return 0;
}

//栈
//初始化
pStack InitStack(void)  //初始化
{
	pStack head = (pStack)malloc(sizeof(StackNode));
	head->data = head->next = NULL;
	return head;
}

//入栈
void EnStack(pStack* head, ptree T)
{
	if (*head == NULL)
	{
		(*head)->data = T;
		return 0;
	}
	pStack temp = InitStack();
	temp->data = T;
	temp->next = (*head)->next;
	(*head) = temp;

}

//出栈
ptree DeStack(pStack* head)
{
	pStack temp = *head;
	ptree p = (*head)->data;  //暂时存放数据
	(*head) = (*head)->next;
	free(temp);
	return p;
}

//判空
int empty(pStack head)
{
	if (head == NULL)
		return 1;
	else
		return 0;
}