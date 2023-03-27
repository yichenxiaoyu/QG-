#define _CRT_SECURE_NO_WARNINGS 1
#include"Declare.h"

linkQ* InitQueue(void)  //��ʼ������
{
	linkQ* qlink = (linkQ*)malloc(sizeof(linkQ));
	qlink->head = NULL;
	qlink->tail = NULL;
	qlink->cnt = 0;
	printf("��ʼ���ɹ���\n\n");
	return qlink;
}

void Destroy(linkQ* qlink, int* i)  //���ٶ���
{
	qNode* temp;
	while (qlink->head != NULL)
	{
		temp = qlink->head;
		qlink->head = qlink->head->next;
		free(temp);
	}
	qlink->tail = NULL;
	printf("���ٳɹ���\n\n");
	*i = 1;
}


void enQueue(linkQ** qlink)  //���
{
	qNode* temp = (qNode*)malloc(sizeof(qNode));
	if (temp ==NULL )
	{
		printf("fail!\n");
		return;
	}
	//��Ԫ�����ڶ�β��tail�����
	printf("��������Ҫ������\n");
	scanf("%s", temp->date);
	if ((*qlink)->cnt == 0)  //�ж϶����Ƿ�Ϊ��
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
	(*qlink)->cnt++;  //Ԫ�ظ���++
	printf("��ӳɹ�\n\n");
}


void deQueue(linkQ** qlink)  //����
{
	if (IsEmptyQueue((*qlink)->head))
	{
		return;
	}
	(*qlink)->cnt--;
	qNode* temp = (*qlink)->head;
	(*qlink)->head = (*qlink)->head->next;
	free(temp);
	printf("���ӳɹ�\n\n");
}

void showQueue(qNode* head)  //��ʾ���г�Ա
{
	while (head != NULL)
	{
		printf("%s\t", head->date);
		head = head->next;
	}
	printf("\n");
}


void GetHeadQueue(qNode* head)  //�鿴��ͷԪ��
{
	if (IsEmptyQueue(head))
	{
		return;
	}
	printf("��ͷԪ�أ�%s\n", head->date);
}


int IsEmptyQueue(qNode* head)  //�ж��Ƿ����Ϊ��
{
	if (head == NULL)
	{
		printf("����Ԫ��Ϊ�գ�������µĳ�Ա��\n\n");
		return 1;
	}
	return 0;
}

void LengthQueue(linkQ* qlink)  //�ж϶��г���
{
	printf("����Ԫ�ظ���Ϊ %d\n\n", qlink->cnt);
}


void ClearQueue(linkQ* qlink)  //��ն���
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
	printf("��ճɹ���\n");
}


