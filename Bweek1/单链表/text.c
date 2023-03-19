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

void change(node* head) //交换结点
{
	int cnt = 0;
	node* p1,*p2, *temp;
	
	temp = head;
	while (temp->next!=NULL && temp->next->next!= NULL)
	{
		if (cnt % 2 == 0) //让其往下面两个节点走
		{
			p1 = temp->next;  //交换两个节点的地址
			p2 = p1->next;
			p1->next = p2->next;
			p2->next = p1;
			temp->next = p2;
		}
		temp = temp->next;
		cnt++;
	}
}

node* Initllist(node** head) //初始化链表
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

void fin_mid(list p) //寻找中间节点，运用快慢指针
{
	list fast, slow;
	fast = slow = p;
	while (1)
	{
		if (fast == NULL)
		{
			printf("奇数个数据，中间为 %d\n", slow->n);
			return 0;
		}
		else if (fast->next == NULL)
		{
			printf("偶数个数据，中间为 %d 和\n", slow->n);
			slow = slow->next;
			printf("%d\n", slow->n);
			return 0;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
}

void isLoopList(list head)  //判断是否是循环链表
{
	list fast, slow;  //快慢指针
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

list ReverseListone(list head) //非递归反转
{
	list p1, p2, temp; //p1和p2是用来改变前面两个节点的方向的，temp是在p2后记录链表
	p1 = head->next;
	p2 = p1->next;
	p1->next = NULL; //让最开始的节点指空
	while (p2) //最后p2到尾部时结束
	{
		temp = p2->next; 
		p2->next = p1;
		p1 = p2;
		p2 = temp;
	}
	return p1; //返回原先的尾指针，就是新的头指针
}

list ReverseListtwo(list temp) //递归反转
{

	if (temp->next == NULL || temp == NULL) //遇到最后的节点时, 或是空指针
	{	
		return temp;
	}
	list new_head = ReverseListtwo(temp->next); 
	temp->next->next = temp;
	temp->next = NULL; //链表尾部置空
	return new_head;  //返回头指针
}

int menu(void)
{
	while (1)
	{
		printf("1.显示链表\n");
		printf("2.奇偶节点对调\n");
		printf("3.寻找中间节点的值\n");
		printf("4.判断是否是循环链表\n");
		printf("5.非递归反转链表\n");
		printf("6.递归反转链表\n");
		printf("0,退出\n");
		printf("请输入 0 ~ 6 的数字> ");
		int op = 9;
		scanf_s("%d", &op);
		printf("\n\n");
		if (0 <= op && op <= 6)
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