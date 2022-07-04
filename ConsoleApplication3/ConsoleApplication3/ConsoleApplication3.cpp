#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, k, m, n;
	float a[100][100], x[100] = { 0 }, l, t;
	printf("请输入行数（最多支持100行）：");
	scanf_s("%d", &m);
	if (m > 100)
	{
		m = 10;
		printf("\a注意：本程序最多支持100行，已更改为10。");
		system("pause");
	}
	printf("请输入每一行元素的个数（最多支持每行100个数）：");
	scanf_s("%d", &n);
	if (n > 100)
	{
		n = 10;
		printf("\a注意：本程序最多支持每行100个数，已更改为10。");
		system("pause");
	}
	for (i = 0; i <= m - 1; i++)
		for (j = 0; j <= n - 1; j++)
		{
			system("cls");
			printf("请输入第%d行第%d个数：", i + 1, j + 1);
			scanf_s("%f", &a[i][j]);
		}
	system("cls"); 
	for (i = 0; i <= m - 1; i++)
	{
		for (j = 0; j <= n - 1; j++)
			x[i] += a[i][j];
		x[i] /= n;
	}
	for (i = m-1; i >= 0; i--)
		for (k = 0; k <= i; k++)
		{
			if (x[i] < x[k])
			{
				l = x[i];
				x[i] = x[k];
				x[k] = l;
				for (j = 0; j <= n - 1; j++)
				{
					t = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = t;
				}
			}
		}
	for (i = 0; i <= m - 1; i++)
		for (j = n - 1; j >= 0; j--)
			for (k = 0; k <= j; k++)
			{
				if (a[i][k] > a[i][j])
				{
					l = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = l;
				}
			}
	printf("行与行之间平均值从小到大，行内从小到大排序如下：\n");
	for (i = 0; i <= m - 1; i++)
	{
		for (j = 0; j <= n - 1; j++)
			printf("%f\t", a[i][j]);
		printf("\n");
	}
	printf("\b \n\n排序完成，请按任意键退出本程序。\n\n");
	system("pause>nul");
	return 0;
}