#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//#include<math.h>
#include<stdlib.h>

typedef struct date
{
	int n;
	struct date* next;
}node, * list;

void show(list head)
{
	while (head != NULL)
	{
		printf("%d ", head->n);
		if (head->next != NULL)
			printf("~ ");
		head = head->next;
	}
	printf("\n\n");
}

void change(node* head) //�������
{
	int cnt = 0;
	node* p1,*p2, *temp;
	
	temp = head;
	while (temp->next!=NULL && temp->next->next!= NULL)
	{
		if (cnt % 2 == 0) //���������������ڵ���
		{
			p1 = temp->next;  //���������ڵ�ĵ�ַ
			p2 = p1->next;
			p1->next = p2->next;
			p2->next = p1;
			temp->next = p2;
		}
		temp = temp->next;
		cnt++;
	}
}

node* Initllist(node** head) //��ʼ������
{
	int i = 4;
	list temp;
	*head = (node*)malloc(sizeof(node));
	(*head)->next = NULL;
	while (i--)
	{
		temp = (node*)malloc(sizeof(node));
		temp->n = i;
		temp->next = (*head)->next;
		(*head)->next = temp;
	}

}

void fin_mid(list p) //Ѱ���м�ڵ㣬���ÿ���ָ��
{
	list fast, slow;
	fast = slow = p;
	while (1)
	{
		if (fast == NULL)
		{
			printf("���������ݣ��м�Ϊ %d\n", slow->n);
			return 0;
		}
		else if (fast->next == NULL)
		{
			printf("ż�������ݣ��м�Ϊ %d ��\n", slow->n);
			slow = slow->next;
			printf("%d\n", slow->n);
			return 0;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
}

void isLoopList(list head)  //�ж��Ƿ���ѭ������
{
	list fast, slow;  //����ָ��
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

list ReverseListone(list head) //�ǵݹ鷴ת
{
	list p1, p2, temp; //p1��p2�������ı�ǰ�������ڵ�ķ���ģ�temp����p2���¼����
	p1 = head->next;
	p2 = p1->next;
	p1->next = NULL; //���ʼ�Ľڵ�ָ��
	while (p2) //���p2��β��ʱ����
	{
		temp = p2->next; 
		p2->next = p1;
		p1 = p2;
		p2 = temp;
	}
	return p1; //����ԭ�ȵ�βָ�룬�����µ�ͷָ��
}

list ReverseListtwo(list temp) //�ݹ鷴ת
{

	if (temp->next == NULL || temp == NULL) //�������Ľڵ�ʱ, ���ǿ�ָ��
	{	
		return temp;
	}
	list new_head = ReverseListtwo(temp->next); 
	temp->next->next = temp;
	temp->next = NULL; //����β���ÿ�
	return new_head;  //����ͷָ��
}

int menu(void)
{
	while (1)
	{
		printf("1.��ʾ����\n");
		printf("2.��ż�ڵ�Ե�\n");
		printf("3.Ѱ���м�ڵ��ֵ\n");
		printf("4.�ж��Ƿ���ѭ������\n");
		printf("5.�ǵݹ鷴ת����\n");
		printf("6.�ݹ鷴ת����\n");
		printf("0,�˳�\n");
		printf("������ 0 ~ 6 ������> ");
		int op = 9;
		scanf_s("%d", &op);
		printf("\n\n");
		if (0 <= op && op <= 6)
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
	node* head;
	list relist;
	Initllist(&head);
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
		case 2:
			change(head);
			break;
		case 3:
			fin_mid(head);
			break;
		case 4:
			isLoopList(head);
			break;
		case 5:
			head->next = ReverseListone(head);
			break;
		case 6:
			head->next = ReverseListtwo(head->next);
			break;
		}
	}
	return 0;
}