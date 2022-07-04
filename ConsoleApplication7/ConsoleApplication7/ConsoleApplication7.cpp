#include "stdio.h"
#include "stdlib.h"

void error()
{
	system("cls");
	printf("\a您输入的数不合法，请按任意键重新输入。");
	rewind(stdin);
	system("pause>nul&cls");
}

int main()
{
	system("chcp 936&title 数组一致性判断&color e");
	int a[100] = { 0 }, b[100] = { 0 }, c, e = 0, i;
a:
	system("cls");
	printf("请输入数组长度：");
	if (scanf_s("%d", &c) != 1)
	{
		error();
		goto a;
	}
	for (i = 0; i < c; i++)
	{
	b:
		system("cls");
		printf("请定义第1个数组的第%d个数：", i + 1);
		if (scanf_s("%d", &a[i]) != 1)
		{
			error();
			goto b;
		}
	}
	for (i = 0; i < c; i++)
	{
	c:
		system("cls");
		printf("请定义第2个数组的第%d个数：", i + 1);
		if (scanf_s("%d", &b[i]) != 1)
		{
			error();
			goto c;
		}
	}
	for (i = 0; i <c; i++)
	{
		if (a[i] != b[i])
		{
			e += 1;
			printf("两个数组中的第%d个数不一致。\n", i + 1);
		}
	}
	if (e != 0)
		printf("\n两个数组不一致，有%d个数不一致。\n", e);
	else
		printf("两个数组一致。");
	printf("\n\n\n操作成功结束，请按任意键退出本程序。\n");
	system("pause>nul&cls");
	return 0;
}