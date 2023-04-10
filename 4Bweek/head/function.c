#include"Function.h"

ptree creatTree(void)  //创建节点
{
	ptree T = (treeNode*)malloc(sizeof(treeNode));
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}

int JudgeNum(char* data)  //判断数据是否符合要求
{
	if ('0' <= *data && *data <= '9' && *(data + 1) == '\n')
		return 1;
	else if (*data == '#' && *(data + 1) == '\n')
		return 2;
	else
		return 0;
}

void visit(ptree T)  //展现
{
	if (T == NULL)
	{
		printf("没有该值！\n");
		return 0;	
	}
	printf("%c  ", T->message);
}

void InsertT(ptree* T)  //插入操作
{
	char ch[10];
	printf("如果输入‘#’则表示此节点不存放数据\n");
	printf("请输入要存放的数据（范围在0~~9）\n");
	while (1)
	{
		fgets(ch, 10, stdin);
		if (*ch == '\n') continue;
		if (JudgeNum(ch) == 2)  //输入'#'代表此节点不存放数据
			break;
		else if (JudgeNum(ch))
		{
			InsertTree(T, ch);  //添加数据
			break;
		}
		else
			printf("输入有误，请再输入一次！\n");
	}
}

void InsertTree(ptree* root, char* data)  //插入树节点
{
	if (!(*root))  // 如果没有该节点为空
	{
		*root = creatTree();
		(*root)->message = *data;
		return;
	}
	if (*data < (*root)->message)  //如果数据小于该节点
		InsertTree(&((*root)->lchild), data);
	else  
		InsertTree(&((*root)->rchild), data);   //反之亦然
}

//初始化树
ptree InitTree(void)  
{
	printf("如果输入‘#’则表示此节点不存放数据\n");
	ptree T = NULL;
	while(1)
	{
		char ch[10];
		printf("请输入要存放的数据（范围在0~~9）\n");
		fgets(ch, 10, stdin);
		if (JudgeNum(ch) == 2)  //输入'#'代表此节点不存放数据
			break;
		else if ('0' <= *ch && *ch <= '9')
			InsertTree(&T, ch);  //添加数据
		else
			printf("输入有误，请再输入一次！\n");
	}
	return T;
}

ptree searchNode(ptree T, char c)
{
	if (!T)  //如果为空
	{
		return NULL;
	}
	ptree temp = NULL; 
	if (T->message == c)
	{
		return T;
	}
	if (T->message > c)  //如果小于，就往左移
		temp = searchNode(T->lchild, c);
	else
		temp = searchNode(T->rchild, c);
	return temp;
}

void SearchTree(ptree T)  //搜索
{
	printf("如果输入‘#’则停止搜索\n");
	printf("请输入需要查找的值（0~~9）>>\n");
	char ch[10];
	while (1)
	{
		fgets(ch, 10, stdin);
		if (*ch == '\n') continue;
		if (JudgeNum(ch) == 2)  //输入'#'代表此节点不存放数据
		{
			printf("您输入了‘#’将退出！");
			break;
		}
		else if (JudgeNum(ch))
		{
			printf("该值为>>");
			visit(searchNode(T, *ch));
			return 0;
		}
		else
		{
			printf("输入有误，请再输入一次！\n");
			system("cls");
		}
	}
}

void DeleteTree(ptree T)
{ 
	char ch[10];
	printf("如果输入‘#’则停止搜索\n");
	printf("请输入需要删除的值（0~~9）>>\n");
	while (1)
	{
		fgets(ch, 10, stdin);
		if (*ch == '\n') continue;
		if (JudgeNum(ch) == 2)  //输入'#'代表此节点不存放数据
		{
			printf("您输入了‘#’将退出！");
			break;
		}
		else if (JudgeNum(ch))
		{
			DeleteT(searchNode(T, *ch));
			return 0;
		}
		else
		{
			printf("输入有误，请再输入一次！\n");
			system("cls");
		}
	}
}

void DeleteT(ptree Node)
{
	ptree temp,p;
	//如果该节点为叶子节点
	if (!Node->lchild && !Node->rchild)
	{
		Node = NULL;
	}
	else if (!Node->lchild)  //如果只有右节点
	{
		temp = Node;
		Node = Node->rchild;
		free(temp);
	}
	else if (!Node->rchild)  //只有左节点
	{
		temp = Node;
		Node = Node->lchild;
		free(temp);
	}
	//左右节点都不为空
	else
	{
		p = Node;
		temp = Node->rchild;  //右节点
		while (temp->lchild != NULL)  //一直到最左边
		{
			p = temp;
			temp = temp->lchild;
		}
		Node->message = temp->message;

		if (p != Node)  //如果有进行while循环（有就代表有左节点）
			p->lchild = temp->rchild;  //重新连接右边的子树
		else
			Node->rchild = temp->rchild;  //如果没有左节点，直接向下连接右节点
		free(temp);
	}
}