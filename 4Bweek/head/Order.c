#include"Function.h"

void LevelOrder(ptree T)  //层次遍历 
{
	linkQueue* Q = (linkQueue*)malloc(sizeof(linkQueue));
	Initqueue(Q);
	ptree temp = NULL;
	EnQueue(Q, T);  //入队
	while (!isEmpty(Q))  //判断队列是否为空
	{
		DeQueue(Q,&temp);  //出队
		printf("\n层次遍历的结果为>>");
		visit(temp);  //访问
		if (temp->lchild != NULL)
		{
			EnQueue(Q, temp->lchild);  //左节点入队
		}
		if (temp->rchild != NULL)
		{
			EnQueue(Q, temp->rchild);  //右节点入队
		}
	}
}

//先序遍历
void PreOrder(ptree T)
{
	if (T != NULL)
	{
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//中序遍历
void MidOrder(ptree T)
{
	if (T != NULL)
	{
		PreOrder(T->lchild);
		visit(T);
		PreOrder(T->rchild);
	}
}

//后序遍历
void PostOrder(ptree T)
{
	if (T != NULL)
	{
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		visit(T);
	}
}

//先序遍历（非递归版）
void PreOrder2(ptree T)
{
	if (!T) return 0;
	ptree p = T;
	pStack head = InitStack();
	EnStack(&head, T);  //入栈
	while (!empty(head))  //判断栈不为空
	{
		p = DeStack(&head);  //出栈
		visit(p);  //访问
		// 先右再左入栈
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

//中序遍历（非递归版）
void MidOrder2(ptree T)
{
	pStack head = NULL;
	InitStack(head);
	ptree p = T;
	while (p || !empty(head))
	{
		if (p)
		{
			EnStack(head, p);   //入栈
			p = p->lchild;  //往左移
		}
		else
		{
			p = DeStack(head);  //出栈
			visit(p);  //访问
			p = p->rchild;  //往右移
		}
	}
}

//后序遍历
void PostOrder2(ptree T)
{
	ptree p = T, r = NULL;  //存放访问过的节点
	pStack head = NULL;
	InitStack(head);
	while (p || !empty(head))
	{
		if (p)  //一直向左移
		{
			EnStack(head, p);
			p = p->lchild;
		}
		else
		{
			p = head->data;
			if (p->rchild && p->rchild != r)  //确保右节点存在且未被访问
			{
				p = p->rchild;
			}
			else
			{
				p = DeStack(head);
				visit(p);
				r = p;  //记录访问过的数据
				p = NULL;  //置空
			}
		}
	}
}
