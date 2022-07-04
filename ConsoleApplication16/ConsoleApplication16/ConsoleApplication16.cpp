#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
	system("chcp 936&title 第十二例 判断8位密码是否符合规则&color e&cls");
	int i;
	char psd[9] = { 0 }, pwd[9] = { 0 };
	printf("请输入一个8位密码：");
psd0:
	scanf_s("%s", &psd, 9);
	rewind(stdin);
	system("cls");
	if (strlen(psd) != 8)
	{
		putchar('\a');
		printf("您输入的密码不是8位密码，请重新输入：");
		goto psd0;
	}
	for (i = 0; i<=7; i++)
	{
		if (psd[i] >= '0'&&psd[i] <= '9')
			goto psd1;
	}
	putchar('\a'); 
	printf("您输入的密码未含有数字，请重新输入：");
	goto psd0;
psd1:
	for (i = 0; i<=7; i++)
	{
		if (psd[i] >= 'A'&&psd[i] <= 'Z')
			goto psd2;
	}
	putchar('\a'); 
	printf("您输入的密码未含有大写字母，请重新输入：");
	goto psd0;
psd2:
	for (i = 0; i<=7; i++)
	{
		if (psd[i] >= 'a'&&psd[i] <= 'z')
			goto psd3;
	}
	putchar('\a'); 
	printf("您输入的密码未含有小写字母，请重新输入：");
	goto psd0;
psd3:
	for (i = 0; i<=7; i++)
	{
		if (psd[i] < '0'||(psd[i] > '9'&&psd[i]<'A')||(psd[i]>'Z'&&psd[i]<'a')||psd[i]>'z')
			goto psd4;
	}
	putchar('\a'); 
	printf("您输入的密码未含有非数字非字母字符，请重新输入：");
	goto psd0;
psd4:
	printf("所输入的密码符合要求，请再次输入您的密码：");
	scanf_s("%s", &pwd, 9);
	rewind(stdin);
	for (i = 0; i < 8; i++)
	{
		if (psd[i] != pwd[i])
			break;
		else
			goto psd5;
	}
	system("cls");
	printf("\a%s\t%s两次输入密码不相同，请重新设定密码：", psd, pwd);
	goto psd0;
psd5:
	system("cls");
	printf("密码设置成功！请按任意键退出程序。\n");
	system("pause>nul&cls");
	return 0;
}