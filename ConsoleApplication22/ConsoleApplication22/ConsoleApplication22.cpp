#include "iostream"
#include "string"
#include "cstdio"

using namespace std;

void swap(char* x, char* y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void Arrange(char* a, int i, int n)
{
	int j;
	if (i == n)
		printf("%s\t", a);
	else
	{
		for (j = i; j <= n; j++)
		{
			if (a[i] == a[j] && j != i)
				continue;
			swap((a + i), (a + j));
			Arrange(a, i + 1, n);
			swap((a + i), (a + j));
		}
	}
}

int main()
{
	system("chcp 936&title 全排列&color e&cls");
	char a[10001];
	a[10000] = '\0';
	printf("请输入字符串以完成全排列（最多支持9999个单字节字符）：\n");
	scanf_s("%s", &a, sizeof(a));
	printf("\n全排列输出如下：\n");
	Arrange(a, 0, strlen(a) - 1);
	printf("\n\n全排列输出完毕，请按任意键退出程序。\n\n");
	system("pause>nul");
	return 0;
}