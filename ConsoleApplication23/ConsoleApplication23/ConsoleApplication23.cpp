#include <stdio.h>
#include <stdlib.h>
#define N 1001
#define n 10

//计算字符串长度
int lenstring(char* str)
{
	if (*str == '\0')
		return 0;
	else
		return lenstring(++str) + 1;
}

//将字符串反转
void fliplr(char* string)
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
}

//比较字符串大小
int Strcmp(char* p1, char* p2)
{
	for (int i = 0; i < N; ++i)
	{
		if (p1[i] != p2[i]) 
			return p1[i] - p2[i];
		else if (p1[i] == '\0' && p2[i] == '\0')
			return 0;
	}
	return 0;
}

//将字符串进行排序
void order(char **p)
{
	char* temp;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (Strcmp(*(p + i), *(p + j)) > 0)
			{ 
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
}

//主程序
int main()
{
	system("chcp 936&title 将10个字符串按ASCII表以从后往前的顺序进行排序&color e&cls");
	char str1[N] = { '\0' }, str2[N] = { '\0' }, str3[N] = { '\0' }, str4[N] = { '\0' }, str5[N] = { '\0' }, str6[N] = { '\0' }, str7[N] = { '\0' }, str8[N] = { '\0' }, str9[N] = { '\0' }, str10[N] = { '\0' };
	//定义指针数组str, 由10个指向char型数据的指针元素组成, 这10个指针元素分别是指向10个字符数组的指针。
	char* str[10] = { str1,str2,str3,str4,str5,str6,str7,str8,str9,str10 };
	char** p = str;
	system("cls");
	for (int i = 0; i < n; ++i)
	{
		printf("请输入第%d个非中文字符串（超过1000个字符的部分会被忽略）：\n", i + 1);
		fgets(*(p + i), N, stdin);
		rewind(stdin);//清空键盘输入缓冲区。
		system("cls");
	}
	system("cls");
	//删除用fgets函数接受字符串后字符串末尾的换行符'\n'。
	for (int i = 0; i < n; ++i)
		for (char* q = *(p + i); *q; ++q)
			if (*q == '\n')
			{
				*q = '\0';
				break;
			}
	printf("排序前:\n\n");
	for (int i = 0; i < n; ++i)
	{
		printf("原字符串%d：\n%s\n\n", i + 1, *(p + i));
		fliplr(p[i]);
	}
	order(p);
	for (int i = 0; i < n; ++i)
		fliplr(p[i]);
	printf("\n\n末字符从小到大排序后:\n\n");
	for (int i = 0; i < n; ++i)
		printf("排序字符串%d：\n%s\n\n", i + 1, *(p + i));
	printf("\n\n\n\n字符串排序成功结束，请按任意键退出本程序。\n");
	system("pause>nul&cls");
	return 0;
}