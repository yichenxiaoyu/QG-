#define _CRT_SECURE_NO_WARNINGS 1
#include"Declare.h"

char* menu(void)
{
	char op[10];
	printf("请选择>\n");
	printf("1.队列存亡菜单（初始化在这里）\n");
	printf("2.元素更改菜单\n");
	printf("3.队列信息获取菜单\n");
	printf("0.退出\n>>");
	scanf("%s", op);
	system("cls");
	return op;
}

char* menu1(void)  //队列存亡菜单
{
	char op[10];
	printf("请选择>>\n");
	printf("1.初始化队列\n");
	printf("2.销毁队列\n");
	printf("0.退出至主菜单\n");
	scanf("%s", op);
	system("cls");
	return op;
}


char* menu2(void)  //队列元素更改菜单
{
	char op[10];
	printf("请选择>>\n");
	printf("1.入队\n");
	printf("2.出队\n");
	printf("3.清空\n");
	printf("0.退出至主菜单\n");
	scanf("%s", op);
	system("cls");
	return op;
}



char* menu3(void)  //队列元素更改菜单
{
	char op[10];
	printf("请选择>>\n");
	printf("1.查看队头\n");
	printf("2.判断是否为空\n");
	printf("3.查看队列长度\n");
	printf("4.查看队列元素\n");
	printf("0.退出至主菜单\n");
	scanf("%s", op);
	system("cls");
	return op;
}


int main()
{
	linkQ* qlink;
	int judge = 1;  //判断是否有初始化
	while (runing(&qlink, &judge));
}