#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MAX
#define MAX 1000
#endif

void error()
{
	system("cls");
	printf("\a所输入的内容不符合要求，请按任意键重新输入。\n");
	rewind(stdin);
	system("pause>nul");
}

int main()
{
	system("chcp 936&title 十进制转换&color e&cls");
	char m[MAX] = { 0 }, u[MAX] = { 0 };
	int k, n;
	for (;;)
	{
	a:
		system("cls");
		printf("请输入您想要转换的进制（范围：2-9，输入0可退出程序）：");
		rewind(stdin);
		if (scanf_s("%d", &k) == 1)
		{
			if (k == 0)
			{
				system("cls");
				exit(0);
			}
			else if (k >= 10 || k <= 1)
			{
				error();
				goto a;
			}
		}
		else
		{
			error();
			goto a;
		}
	b:
		system("cls");
		printf("请输入十进制正整数（输入非正整数可退出程序）：");
		if (scanf_s("%d", &n) == 1)
		{
			if (n <= 0)
			{
				system("cls");
				exit(0);
			}
		}
		else
		{
			error();
			goto b;
		}
		int t = n;
		_itoa_s(n % k, m, 10);
		n = (n - (n % k)) / k;
		while (n > 0)
		{
			_itoa_s(n % k, u, 10);
			strcat_s(u, m);
			strcpy_s(m, u);
			n = (n - (n % k)) / k;
		}
		system("cls");
		printf("经计算，十进制数%d用%d进制表示为%s。\n", t, k, m);
		system("pause");
	}
	printf("操作成功结束，请按任意键退出本程序。\n");
	system("pause>nul&cls");
	return 0;
}