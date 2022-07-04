#include "stdio.h"
#include "stdlib.h"
#define N 14

int main()
{
	system("chcp 936&title 第九例 打印杨辉三角&color e&cls");
	int i, j, k, n = 0, a[N][N];
a:
	system("cls");
	printf("请输入要打印的行数（最多支持13行）：");
	while (scanf_s("%d", &n) != 1)
	{
		printf("\a");
		rewind(stdin);
		goto a;
	}
	if (n <= 0 || n >= 14)
	{
		printf("\a");
		rewind(stdin);
		goto a;
	}
	system("cls");
	printf("%d行杨辉三角如下：\n", n);
	for (i = 1; i <= n; i++)
		a[i][1] = a[i][i] = 1;
	for (i = 3; i <= n; i++)
		for (j = 2; j <= i - 1; j++)
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	for (i = 1; i <= n; i++) {
		for (k = 1; k <= n - i; k++)
			printf("   ");
		for (j = 1; j <= i; j++)
			printf("%6d", a[i][j]);
		printf("\n");
	}
	printf("\n\n\n操作成功结束，请按任意键退出本程序。\n");
	system("pause>nul&cls");
	return 0;
}