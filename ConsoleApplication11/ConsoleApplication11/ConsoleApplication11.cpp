#include <stdio.h>
#include <stdlib.h>
#ifndef MAX
#define MAX 1000
#endif

int main()
{
	system("chcp 936&title 第十例 排序&color e&cls");
	int i, j, n, min, index;
	float a[MAX] = { 0 }, b[MAX] = { 0 }, c[MAX] = { 0 }, d[MAX] = { 0 }, temp;
set:
	system("cls");
	printf("请输入待排序数的个数（最多支持999个数）：");
	if (scanf_s("%d", &n) != 1)
	{
		printf("\a");
		rewind(stdin);
		goto set;
	}
	if (n >= 1000 || n <= 0)
	{
		rewind(stdin);
		goto set;
	}
	for (i = 0; i < n; i++)
	{
	put:
		system("cls");
		printf("请输入第%d个数：", i + 1);
		while (scanf_s("%f", &a[i]) != 1)
		{
			printf("\a");
			rewind(stdin);
			goto put;
		}
	}
	//复制数组
	for (i = 0; i < n; i++)
	{
		b[i] = a[i];
		c[i] = a[i];
		d[i] = a[i];
	}
	//冒泡排序
	for (i = 0; i < n; i++)
		for (j = 1; j < n - i; j++)
			if (b[j - 1] > b[j])
			{
				temp = b[j - 1];
				b[j - 1] = b[j];
				b[j] = temp;
			}
	//选择排序
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (c[j] < c[min])
			{
				temp = c[min];
				c[min] = c[j];
				c[j] = temp;
			}
	}
	//插入排序
	for (i = 1; i < n; i++)
	{
		if (d[i] < d[i - 1])
		{
			temp = d[i];
			index = i;
			for (j = i - 1; j >= 0; j--)
			{
				if (d[j] > temp)
				{
					d[j + 1] = d[j];
					index = j;
				}
				else
					break;
			}
			d[index] = temp;
		}
	}
	//输出
	system("cls");
	printf("原顺序输入：\n");
	for (i = 0; i < n; i++)
		printf("第%d个数：%f\n", i + 1, a[i]);
	printf("\n冒泡排序输出：\n");
	for (i = 0; i < n; i++)
		printf("第%d个数：%f\n", i + 1, b[i]);
	printf("\n选择排序输出：\n");
	for (i = 0; i < n; i++)
		printf("第%d个数：%f\n", i + 1, c[i]);
	printf("\n插入排序输出：\n");
	for (i = 0; i < n; i++)
		printf("第%d个数：%f\n", i + 1, b[i]);
	printf("\n\n操作成功结束，请按任意键退出本程序。\n");
	system("pause>nul&cls");
	return 0;
}