#include "stdio.h"
#include "stdlib.h"

int main()
{
	int a[100] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, b[100] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, n, i, j = 0;
	printf("请输入一维数组的长度（最多支持100个数）：");
	scanf_s("%d", &n);
	if (n > 100 || n <= 0)
		{
			n = 10;
			printf("您输入的数不合法，已定义为10。\n");
			system("pause");
		}
	system("cls");
	for (i = 0; i <= n - 1; i++)
	{
		printf("请定义数组的第%d个数：", i + 1);
		scanf_s("%d", &a[i]);
		system("cls");
	}
	for (i = 0; i < n; i++)
	{
		if (abs(a[i]) % 2 == 1)
		{
			b[j] = a[i];
			j++;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[j] = a[i];
			j++;
		}
	}
	for (j = 0; j < n; j++)
		printf("%d\t", b[j]);
	printf("\n\n输出完毕，请按任意键退出。\n\n");
	system("pause>nul");
	return 0;
}