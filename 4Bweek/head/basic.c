#include"Function.h"
//����
void Initqueue(linkQueue* Q)  //��ʼ������
{
	Q->tail = Q->head = (linkNode*)malloc(sizeof(linkNode));
	Q->head->data = NULL;
	Q->head->next = NULL;
}

//���
void EnQueue(linkQueue* Q, ptree T)
{
	if (Q->head == NULL)
		Q->tail = Q->head = (linkNode*)malloc(sizeof(linkNode));
	linkNode* h = Q->head;  //�ֱ�õ�ͷβָ��
	linkNode* t = Q->tail;
	if (h == t)  //�������Ϊ��
		h->data = T;
	else  //�ڶ�β���
	{
		linkNode* temp = (linkNode*)malloc(sizeof(linkNode));
		temp->data = T;
		t->next = temp;
		t = temp;
	}
}

//����
void DeQueue(linkQueue* Q, ptree* temp)
{
	linkNode* q = Q->head;  //ͷָ��
	*temp = q->data;
	if (Q->head == Q->tail)
	{
		Q->tail = NULL;
	}
	Q->head = q->next;  //�����
	free(q);
}

//�ж��Ƿ�Ϊ��
int isEmpty(linkQueue* Q)
{
	if (Q->head->data == NULL)
		return 1;
	else
		return 0;
}

//ջ
//��ʼ��
pStack InitStack(void)  //��ʼ��
{
	pStack head = (pStack)malloc(sizeof(StackNode));
	head->data = head->next = NULL;
	return head;
}

//��ջ
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

//��ջ
ptree DeStack(pStack* head)
{
	pStack temp = *head;
	ptree p = (*head)->data;  //��ʱ�������
	(*head) = (*head)->next;
	free(temp);
	return p;
}

//�п�
int empty(pStack head)
{
	if (head == NULL)
		return 1;
	else
		return 0;
}