#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, n;
	float a[1000] = {0}, l;
	printf("请输入排序数字的个数（最多支持1000个数）：");
	scanf_s("%d", &n);
	if (n > 1000)
	{
		n = 100;
		printf("\a注意：本程序最多支持1000个数，已更改为100。");
		system("pause");
	}
	for (i = 0; i <= n - 1; i++)
	{
		system("cls");
		printf("请输入第%d个数：", i + 1);
		scanf_s("%f", &a[i]);
	}
	system("cls");
	for (i = n - 1; i >= 0; i--)
		for (j = 0; j <= i; j++)
		{
			if (a[j] < a[i])
			{
				l = a[i];
				a[i] = a[j];
				a[j] = l;
			}
		}
	printf("%d个数从大到小排序如下：\n", n);
	for (i = 0; i <= n - 1; i++)
		printf("%f≥", a[i]);
	printf("\b \n\n排序完成，请按任意键退出本程序。\n");
	system("pause>nul");
	return 0;
}