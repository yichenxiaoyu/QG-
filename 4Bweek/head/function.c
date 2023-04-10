#include"Function.h"

ptree creatTree(void)  //�����ڵ�
{
	ptree T = (treeNode*)malloc(sizeof(treeNode));
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}

int JudgeNum(char* data)  //�ж������Ƿ����Ҫ��
{
	if ('0' <= *data && *data <= '9' && *(data + 1) == '\n')
		return 1;
	else if (*data == '#' && *(data + 1) == '\n')
		return 2;
	else
		return 0;
}

void visit(ptree T)  //չ��
{
	if (T == NULL)
	{
		printf("û�и�ֵ��\n");
		return 0;	
	}
	printf("%c  ", T->message);
}

void InsertT(ptree* T)  //�������
{
	char ch[10];
	printf("������롮#�����ʾ�˽ڵ㲻�������\n");
	printf("������Ҫ��ŵ����ݣ���Χ��0~~9��\n");
	while (1)
	{
		fgets(ch, 10, stdin);
		if (*ch == '\n') continue;
		if (JudgeNum(ch) == 2)  //����'#'����˽ڵ㲻�������
			break;
		else if (JudgeNum(ch))
		{
			InsertTree(T, ch);  //�������
			break;
		}
		else
			printf("����������������һ�Σ�\n");
	}
}

void InsertTree(ptree* root, char* data)  //�������ڵ�
{
	if (!(*root))  // ���û�иýڵ�Ϊ��
	{
		*root = creatTree();
		(*root)->message = *data;
		return;
	}
	if (*data < (*root)->message)  //�������С�ڸýڵ�
		InsertTree(&((*root)->lchild), data);
	else  
		InsertTree(&((*root)->rchild), data);   //��֮��Ȼ
}

//��ʼ����
ptree InitTree(void)  
{
	printf("������롮#�����ʾ�˽ڵ㲻�������\n");
	ptree T = NULL;
	while(1)
	{
		char ch[10];
		printf("������Ҫ��ŵ����ݣ���Χ��0~~9��\n");
		fgets(ch, 10, stdin);
		if (JudgeNum(ch) == 2)  //����'#'����˽ڵ㲻�������
			break;
		else if ('0' <= *ch && *ch <= '9')
			InsertTree(&T, ch);  //�������
		else
			printf("����������������һ�Σ�\n");
	}
	return T;
}

ptree searchNode(ptree T, char c)
{
	if (!T)  //���Ϊ��
	{
		return NULL;
	}
	ptree temp = NULL; 
	if (T->message == c)
	{
		return T;
	}
	if (T->message > c)  //���С�ڣ���������
		temp = searchNode(T->lchild, c);
	else
		temp = searchNode(T->rchild, c);
	return temp;
}

void SearchTree(ptree T)  //����
{
	printf("������롮#����ֹͣ����\n");
	printf("��������Ҫ���ҵ�ֵ��0~~9��>>\n");
	char ch[10];
	while (1)
	{
		fgets(ch, 10, stdin);
		if (*ch == '\n') continue;
		if (JudgeNum(ch) == 2)  //����'#'����˽ڵ㲻�������
		{
			printf("�������ˡ�#�����˳���");
			break;
		}
		else if (JudgeNum(ch))
		{
			printf("��ֵΪ>>");
			visit(searchNode(T, *ch));
			return 0;
		}
		else
		{
			printf("����������������һ�Σ�\n");
			system("cls");
		}
	}
}

void DeleteTree(ptree T)
{ 
	char ch[10];
	printf("������롮#����ֹͣ����\n");
	printf("��������Ҫɾ����ֵ��0~~9��>>\n");
	while (1)
	{
		fgets(ch, 10, stdin);
		if (*ch == '\n') continue;
		if (JudgeNum(ch) == 2)  //����'#'����˽ڵ㲻�������
		{
			printf("�������ˡ�#�����˳���");
			break;
		}
		else if (JudgeNum(ch))
		{
			DeleteT(searchNode(T, *ch));
			return 0;
		}
		else
		{
			printf("����������������һ�Σ�\n");
			system("cls");
		}
	}
}

void DeleteT(ptree Node)
{
	ptree temp,p;
	//����ýڵ�ΪҶ�ӽڵ�
	if (!Node->lchild && !Node->rchild)
	{
		Node = NULL;
	}
	else if (!Node->lchild)  //���ֻ���ҽڵ�
	{
		temp = Node;
		Node = Node->rchild;
		free(temp);
	}
	else if (!Node->rchild)  //ֻ����ڵ�
	{
		temp = Node;
		Node = Node->lchild;
		free(temp);
	}
	//���ҽڵ㶼��Ϊ��
	else
	{
		p = Node;
		temp = Node->rchild;  //�ҽڵ�
		while (temp->lchild != NULL)  //һֱ�������
		{
			p = temp;
			temp = temp->lchild;
		}
		Node->message = temp->message;

		if (p != Node)  //����н���whileѭ�����оʹ�������ڵ㣩
			p->lchild = temp->rchild;  //���������ұߵ�����
		else
			Node->rchild = temp->rchild;  //���û����ڵ㣬ֱ�����������ҽڵ�
		free(temp);
	}
}