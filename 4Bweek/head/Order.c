#include"Function.h"

void LevelOrder(ptree T)  //��α��� 
{
	linkQueue* Q = (linkQueue*)malloc(sizeof(linkQueue));
	Initqueue(Q);
	ptree temp = NULL;
	EnQueue(Q, T);  //���
	while (!isEmpty(Q))  //�ж϶����Ƿ�Ϊ��
	{
		DeQueue(Q,&temp);  //����
		printf("\n��α����Ľ��Ϊ>>");
		visit(temp);  //����
		if (temp->lchild != NULL)
		{
			EnQueue(Q, temp->lchild);  //��ڵ����
		}
		if (temp->rchild != NULL)
		{
			EnQueue(Q, temp->rchild);  //�ҽڵ����
		}
	}
}

//�������
void PreOrder(ptree T)
{
	if (T != NULL)
	{
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//�������
void MidOrder(ptree T)
{
	if (T != NULL)
	{
		PreOrder(T->lchild);
		visit(T);
		PreOrder(T->rchild);
	}
}

//�������
void PostOrder(ptree T)
{
	if (T != NULL)
	{
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		visit(T);
	}
}

//����������ǵݹ�棩
void PreOrder2(ptree T)
{
	if (!T) return 0;
	ptree p = T;
	pStack head = InitStack();
	EnStack(&head, T);  //��ջ
	while (!empty(head))  //�ж�ջ��Ϊ��
	{
		p = DeStack(&head);  //��ջ
		visit(p);  //����
		// ����������ջ
		if (p->rchild != NULL)
		{
			EnStack(head, p->rchild);
		}
		if (p->lchild != NULL)
		{
			EnStack(head, p->lchild);
		}
	}
}

//����������ǵݹ�棩
void MidOrder2(ptree T)
{
	pStack head = NULL;
	InitStack(head);
	ptree p = T;
	while (p || !empty(head))
	{
		if (p)
		{
			EnStack(head, p);   //��ջ
			p = p->lchild;  //������
		}
		else
		{
			p = DeStack(head);  //��ջ
			visit(p);  //����
			p = p->rchild;  //������
		}
	}
}

//�������
void PostOrder2(ptree T)
{
	ptree p = T, r = NULL;  //��ŷ��ʹ��Ľڵ�
	pStack head = NULL;
	InitStack(head);
	while (p || !empty(head))
	{
		if (p)  //һֱ������
		{
			EnStack(head, p);
			p = p->lchild;
		}
		else
		{
			p = head->data;
			if (p->rchild && p->rchild != r)  //ȷ���ҽڵ������δ������
			{
				p = p->rchild;
			}
			else
			{
				p = DeStack(head);
				visit(p);
				r = p;  //��¼���ʹ�������
				p = NULL;  //�ÿ�
			}
		}
	}
}
