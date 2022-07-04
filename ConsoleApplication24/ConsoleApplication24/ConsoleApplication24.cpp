#include "stdio.h"
#include "stdlib.h"

int fact(int k)
{
	if (k <= 1)
		return k;
	else
		return k * fact(k - 1);
}

int main()
{
	system("chcp 936&title 第六例 递归法求阶乘&color e&cls");
	int d;
a:
	system("cls");
	printf("请输入一个小于13的自然数：");
	if (scanf_s("%d", &d) == 1)
	{
		if (d > 12 || d < 0)
		{
			printf("\a");
			goto a;
		}
	}
	else
	{
		printf("\a");
		rewind(stdin);
		goto a;
	}
	int a[16] = { 0 }, * p, i;
	for (i = 0; i < d; i++)
	{
		a[i] = fact(i + 1);
	}
	p = a;
	i = 0;
	system("cls");
	printf("输出如下：\n0的阶乘为1；");
	while (i < d)
	{
		printf("\n%d的阶乘为%d；", i + 1, *p);
		i++;
		p++;
	}
	printf("\b\b。\n\n\n操作成功结束，请按任意键退出本程序。\n");
	system("pause>nul&cls");
	return 0;
}