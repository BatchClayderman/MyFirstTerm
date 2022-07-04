#include "stdio.h"
#include "stdlib.h"
#define MAX 1000

void error()
{
	system("cls");
	printf("\a错误：输入的字符串含有非ASCII字符，请按任意键重新输入。");
	system("pause>nul&cls");
}

int main()
{
	system("chcp 936&title A-B&color e&cls");
	char A[MAX] = { 0 }, B[MAX] = { 0 }, C[MAX] = { 0 }, D = 'N';
	int k = 0, n = 0;
a:
	system("cls");
	printf("请输入字符串 A（仅支持 ASCII 字符且最大长度为 %d）：", MAX - 1);
	fgets(A, sizeof(MAX), stdin);
	for (int i = 0; i < sizeof(A); i++)
		if (A[i] < 0 || A[i]>127)
		{
			error();
			goto a;
		}
	rewind(stdin);
b:
	system("cls");
	rewind(stdin);
	printf("请输入字符串 B（仅支持 ASCII 字符且最大长度为 %d）：", MAX - 1);
	fgets(B, 10000, stdin);
	for (int j = 0; j < sizeof(B); j++)
		if (B[j] < 0 || B[j]>127)
		{
			error();
			goto b;
		}
	rewind(stdin);
	system("cls");
	printf("正在执行计算，请稍候。\n");
	for (int i = 0; i < sizeof(A); i++)
	{
		n = 0;
		for (int j = 0; j < sizeof(B); j++)
			if (A[i] == B[j])
				n += 1;
		if (n == 0)
		{
			C[k] = A[i];
			k += 1;
		}
	}
	system("cls");
	printf("计算完成，(A-B)的值为“%s”。\n\n", C);
	printf("是否运行新的计算？输入“Y”或“y”回车运行新的计算，输入其它回车退出程序。\n");
	if (scanf_s("%c", &D, sizeof(D)) == 1)
		if (D == 'Y' || D == 'y')
		{
			k = 0;
			rewind(stdin);
			goto a;
		}
	system("cls");
	return 0;
}