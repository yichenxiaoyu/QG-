#include"Function.h"
char* menu(void)
{
	char op[15];
	printf("1.����\n");
	printf("2.ɾ��\n");
	printf("3.����\n");
	printf("4.��α���\n");
	printf("5.�������\n");
	printf("6.�������\n");
	printf("7.�������\n");
	printf("8.����������ǵݹ飩\n");
	printf("9.����������ǵݹ飩\n");
	printf("10.����������ǵݹ飩\n");
	printf("0.�˳�\n");
	printf("��������Ҫ��ѡ��>>\n");
	scanf("%s",op);
	return op;
}

int main()
{
	printf("�����ʼ��ing\n");
	ptree T = InitTree();  //��ʼ��
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
			printf("�������");
			*op = '1';
		}
	} while (op[0] - '0');
	return 0;
}