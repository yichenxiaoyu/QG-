#define _CRT_SECURE_NO_WARNINGS 1
#include"Declare.h"

char* menu(void)
{
	char op[10];
	printf("��ѡ��>\n");
	printf("1.���д����˵�����ʼ�������\n");
	printf("2.Ԫ�ظ��Ĳ˵�\n");
	printf("3.������Ϣ��ȡ�˵�\n");
	printf("0.�˳�\n>>");
	scanf("%s", op);
	system("cls");
	return op;
}

char* menu1(void)  //���д����˵�
{
	char op[10];
	printf("��ѡ��>>\n");
	printf("1.��ʼ������\n");
	printf("2.���ٶ���\n");
	printf("0.�˳������˵�\n");
	scanf("%s", op);
	system("cls");
	return op;
}


char* menu2(void)  //����Ԫ�ظ��Ĳ˵�
{
	char op[10];
	printf("��ѡ��>>\n");
	printf("1.���\n");
	printf("2.����\n");
	printf("3.���\n");
	printf("0.�˳������˵�\n");
	scanf("%s", op);
	system("cls");
	return op;
}



char* menu3(void)  //����Ԫ�ظ��Ĳ˵�
{
	char op[10];
	printf("��ѡ��>>\n");
	printf("1.�鿴��ͷ\n");
	printf("2.�ж��Ƿ�Ϊ��\n");
	printf("3.�鿴���г���\n");
	printf("4.�鿴����Ԫ��\n");
	printf("0.�˳������˵�\n");
	scanf("%s", op);
	system("cls");
	return op;
}


int main()
{
	linkQ* qlink;
	int judge = 1;  //�ж��Ƿ��г�ʼ��
	while (runing(&qlink, &judge));
}