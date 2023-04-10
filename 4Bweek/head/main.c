#include"Function.h"
char* menu(void)
{
	char op[15];
	printf("1.查找\n");
	printf("2.删除\n");
	printf("3.插入\n");
	printf("4.层次遍历\n");
	printf("5.先序遍历\n");
	printf("6.中序遍历\n");
	printf("7.后序遍历\n");
	printf("8.先序遍历（非递归）\n");
	printf("9.中序遍历（非递归）\n");
	printf("10.后序遍历（非递归）\n");
	printf("0.退出\n");
	printf("请输入需要的选择>>\n");
	scanf("%s",op);
	return op;
}

int main()
{
	printf("进入初始化ing\n");
	ptree T = InitTree();  //初始化
	char *op;
	do
	{
		op = menu();
		switch (*op)
		{
		case '1':
			SearchTree(T);
 			break;
		case '2':
			DeleteTree(T);
			break;
		case '3':
			InsertT(&T);
			break;
		case '4':
			LevelOrder(T);
			break;
		case '5':
			PreOrder(T);
			break;
		case '6':
			MidOrder(T);
			break;
		case '7':
			PostOrder(T);
			break;
		case '8':
			PreOrder2(T);
			break;
		case '9':
			MidOrder2(T);
			break;
		case '10':
			PostOrder2(T);
			break;
		case '0':
			break;
		default:
			printf("输入错误！");
			*op = '1';
		}
	} while (op[0] - '0');
	return 0;
}