#define _CRT_SECURE_NO_WARNINGS 1
#include"RunAndMenu.h"
#include"Declare.h"

int run1(linkQ** qlink, int* i)  //ִ�ж��д���
{
	char* op;
	op = menu1();
	switch (*op)
	{
	case '1':
		if (*i)
		{
			(*qlink) = InitQueue();
			*i = 0;
		}
		else
			printf("��ô���£��벻Ҫ�ظ���ʼ����\n");
		return 1;
	case '2':
		if (*i)
		{
			printf("�����~~�����ȳ�ʼ����!\n\n");
			return 1;
		}
		Destroy(*qlink, i);
		return 1;
	case '0':
		if (*(op + 1) == '\0')
			return 0;
	default:
		printf("�����������������\n\n");
		return 1;
	}
}

int run2(linkQ** qlink, int i)  //
{
	if (i)
	{
		printf("�����~~�����ȳ�ʼ����!\n\n");
		return 0;
	}
	char* op;
	op = menu2();
	switch (*op)
	{
	case '1':
		enQueue(qlink);
		return 1;
	case '2':
		deQueue(qlink);
		return 1;
	case '3':
		ClearQueue(*qlink);
	case '0':
		if (*(op + 1) == '\0')
			return 0;
	default:
		printf("�����������������\n\n");
		return 1;
	}
}

int run3(linkQ** qlink, int i)  //
{
	if (i)
	{
		printf("�����~~�����ȳ�ʼ����!\n");
		return 0;
	}
	char* op;
	op = menu3();
	switch (*op)
	{
	case '1':
		GetHeadQueue((*qlink)->head);
		return 1;
	case '2':
		if (!IsEmptyQueue((*qlink)->head))
		{
			printf("���в�Ϊ�ա�\n\n");
		}
		return 1;
	case '3':
		LengthQueue(*qlink);
		return 1;
	case '4':
		showQueue((*qlink)->head);
		return 1;
	case '0':
		if (*(op + 1) == '\0')
			return 0;
	default:
		printf("�����������������\n\n");
		return 1;
	}
}

int runing(linkQ** qlink, int* judge)
{
	char* op;
	op = menu();
	switch (*op)
	{
	case '1':
		while (run1(qlink, judge));
		return 1;
	case '2':
		while (run2(qlink, *judge));
		return 1;
	case '3':
		while (run3(qlink, *judge));
		return 1;
	case '0':
		if (*(op + 1) == '\0')
			return 0;
	default:
		printf("�����������������\n\n");
	}
}