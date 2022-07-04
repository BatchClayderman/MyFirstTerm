#include "stdio.h"
#include "stdlib.h"

int lenstring(char* str)
{
	if (*str == '\0')
		return 0;
	else
		return lenstring(++str) + 1;
}

int fliplr(char* string)
{
	int len = lenstring(string);
	if (len > 1)
	{
		int temp = string[0];
		string[0] = string[len - 1];
		string[len - 1] = '\0';
		fliplr(string + 1);
		string[len - 1] = temp;
	}
	printf("子过程返回值：%s\n", string);
	return *string;
}

int main()
{
	while (true)
	{
		char str[10000] = "example";
		system("chcp936&title 字符串反转程序&color e&cls");
		printf("本字符串处理程序最多支持9999个单字节字符，输入“#”回车可退出程序。\n请输入原字符串：");
		scanf_s("%s", &str, sizeof(str));
		if (str[0] == '#')
			break;
		system("cls");
		printf("原字符串：\n%s\n\n", str);
		printf("执行过程：\n");
		fliplr(str);
		printf("\n反转后字符串：\n%s\n\n处理完毕，请按任意键继续。\n\n", str);
		system("pause>nul");
	}
	system("cls");
	printf("欢迎再次使用，请按任意键退出程序。");
	system("pause>nul&cls");
	return 0;
}