#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct date
{
	int num;
	struct date* pri, * next;
}Dnode,*Dlist;

Dlist InitDlist(void)
{
	Dnode* head = (Dlist)malloc(sizeof(Dnode));
	head->next = head->pri = NULL;
	return head;
}

void Insert(Dlist head)  //��������
{
	int op = 1;
	printf("������һ����ֵ\n");
	scanf_s("%d", &op);
	Dnode* temp = (Dlist)malloc(sizeof(Dnode));
	temp->num = op;
	if (head->next == NULL)
	{
		head->next = temp;
		temp->pri = head;
		temp->next = NULL;
	}
	else
	{
		temp->next = head->next;
		head->next->pri = temp;
		temp->pri = head;
		head->next = temp;
	}
	printf("\n");
}

void show(Dlist head)  //չ������
{
	while (head != NULL)
	{
		printf("%d ", head->num);
		if (head->next != NULL)
			printf("~ ");
		head = head->next;
	}
	printf("\n\n");
}

//void change(Dnode* head) //�������
//{
//	int cnt = 0;
//	Dnode* p1, * p2, * temp;
//	temp = head;
//  if(head==NULL)
//		return;
//	while (temp->next != NULL && temp->next->next != NULL)
//	{
//		if (cnt % 2 == 0) //���������������ڵ���
//		{
//			p1 = temp->next;
//			p2 = p1->next;
//			p1->next = p2->next;
//			p2->next->pri = p1;
//			p2->next = p1;
//			p1->pri = p2;
//			temp->next = p2;
//			p2->pri = temp;
//		}
//		temp = temp->next;
//		cnt++;
//	}
//}

void fin_mid(Dlist p) //Ѱ���м�ڵ㣬���ÿ���ָ��
{
	Dlist fast, slow;
	fast = slow = p;
	while (1)
	{
		if (fast == NULL)
		{
			printf("���������ݣ��м�Ϊ %d\n", slow->num);
			return 0;
		}
		else if (fast->next == NULL)
		{
			printf("ż�������ݣ��м�Ϊ %d ��\n", slow->num);
			slow = slow->next;
			printf("%d\n", slow->num);
			return 0;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
}

void isLoopList(Dlist head)  //�ж��Ƿ���ѭ������
{
	Dlist fast, slow;  //����ָ��
	fast = slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) //�����ָ��������ָ�룬��˵����ѭ��
		{
			printf("����ѭ������");
			return 1;
		}
	}
	printf("������ѭ������");
}

void ReverseList(Dlist head) //�ǵݹ鷴ת
{
	Dlist p1, p2, temp;  //�ֱ��¼Ҫ�����������ڵ�ͺ���һ���Ľڵ�
	if (head == NULL && head->next == NULL) 
	{
		printf("��Ϊ��");
		return 0;
	}
	p1 = head->next;
	p2 = p1->next;
	p1->next = NULL;
	while (p2)
	{
		temp = p2->next;  //�ı�p1��p2֮���ָ�볯��
		p2->next = p1;
		p1->pri = p2;
		p1 = p2;  //p1��p2����ƶ���
		p2 = temp;
	}
	head->next = p1;
	p1->pri = head;
	return head; //����ԭ�ȵ�βָ�룬�����µ�ͷָ��
}

int menu(void)
{
	while (1)
	{
		printf("1.��ʾ����\n");
		//printf("2.��ż�ڵ�Ե�\n");
		printf("2.Ѱ���м�ڵ��ֵ\n");
		printf("3.�ж��Ƿ���ѭ������\n");
		printf("4.�ǵݹ鷴ת����\n");
		printf("5.��������\n");
		printf("0,�˳�\n");
		printf("������ 0 ~ 5 ������> ");
		int op;
		scanf_s("%d", &op);
		printf("\n\n");
		if (0 <= op && op <= 5)
		{
			return op;
		}
		else
		{
			printf("�������������������룡\n");
		}
	}
}

int main()
{
	Dnode* head = InitDlist();
	int i = 4;
	int op = 1;

	while (op)
	{
		op = menu();
		switch (op)
		{
		case 0:
			return 0;
		case 1:
			show(head->next);
			break;
		/*case 2:
			change(head);
			break;*/
		case 2:
			fin_mid(head);
			break;
		case 3:
			isLoopList(head);
			break;
		case 4:
			ReverseList(head);
			break;
		case 5:
			Insert(head); 
			break;
		}
	}

	return 0;
}