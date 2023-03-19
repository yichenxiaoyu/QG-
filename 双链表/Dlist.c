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

void Insert(Dlist head)  //插入数据
{
	int op = 1;
	printf("请输入一个数值\n");
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

void show(Dlist head)  //展现数据
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

//void change(Dnode* head) //交换结点
//{
//	int cnt = 0;
//	Dnode* p1, * p2, * temp;
//	temp = head;
//  if(head==NULL)
//		return;
//	while (temp->next != NULL && temp->next->next != NULL)
//	{
//		if (cnt % 2 == 0) //让其往下面两个节点走
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

void fin_mid(Dlist p) //寻找中间节点，运用快慢指针
{
	Dlist fast, slow;
	fast = slow = p;
	while (1)
	{
		if (fast == NULL)
		{
			printf("奇数个数据，中间为 %d\n", slow->num);
			return 0;
		}
		else if (fast->next == NULL)
		{
			printf("偶数个数据，中间为 %d 和\n", slow->num);
			slow = slow->next;
			printf("%d\n", slow->num);
			return 0;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
}

void isLoopList(Dlist head)  //判断是否是循环链表
{
	Dlist fast, slow;  //快慢指针
	fast = slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) //如果快指针遇到慢指针，则说明有循环
		{
			printf("它是循环链表！");
			return 1;
		}
	}
	printf("它不是循环链表！");
}

void ReverseList(Dlist head) //非递归反转
{
	Dlist p1, p2, temp;  //分别记录要交换的两个节点和后面一个的节点
	if (head == NULL && head->next == NULL) 
	{
		printf("表为空");
		return 0;
	}
	p1 = head->next;
	p2 = p1->next;
	p1->next = NULL;
	while (p2)
	{
		temp = p2->next;  //改变p1和p2之间的指针朝向
		p2->next = p1;
		p1->pri = p2;
		p1 = p2;  //p1和p2向后移动。
		p2 = temp;
	}
	head->next = p1;
	p1->pri = head;
	return head; //返回原先的尾指针，就是新的头指针
}

int menu(void)
{
	while (1)
	{
		printf("1.显示链表\n");
		//printf("2.奇偶节点对调\n");
		printf("2.寻找中间节点的值\n");
		printf("3.判断是否是循环链表\n");
		printf("4.非递归反转链表\n");
		printf("5.插入数据\n");
		printf("0,退出\n");
		printf("请输入 0 ~ 5 的数字> ");
		int op;
		scanf_s("%d", &op);
		printf("\n\n");
		if (0 <= op && op <= 5)
		{
			return op;
		}
		else
		{
			printf("您输入有误，请重新输入！\n");
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