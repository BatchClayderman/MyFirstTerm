#include "stdio.h"
#include "stdlib.h"

int main()
{
	main:
	int i, j, a[4][3] = { 88, 85, 92, 98, 80, 72, 68, 90, 92, 95, 73, 84 };
	double stu[] = { 0,0,0,0 }, sub[] = { 0,0,0 }, k;
	char c;
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= 2; j++)
			stu[i] = stu[i] + a[i][j];
		stu[i] = stu[i] / 3;
	}
	for (j = 0; j <= 2; j++)
	{
		for (i = 0; i <= 3; i++)
			sub[j] = sub[j] + a[i][j];
		sub[j] = sub[j] / 4;
	}
	printf("已录入四位学生的三科信息，以下为您提供四个选择：\n  A：输出学生各门课的成绩；\n  B：计算并输出每个学生的平均成绩；\n  C：计算并输出各学科的平均成绩；\n  D：对全舍学生的平均成绩由高到低排序并输出；\n  E：退出程序。\n请选择一项并回车：");
	fflush(stdin); 
	scanf_s(" %c", &c, 1);
	system("cls");
	if ((c - 'A') < 0 || ('E' - c) < 0)
	{
		printf("无效选项，请按任意键返回菜单重新输入。\n");
		system("pause>nul&cls");
		goto main;
	}
	switch (c)
	{
	case 'A':printf("输出如下表所示：\n      语文  数学  英语\n张三   %d    %d    %d\n李四   %d    %d    %d\n王五   %d    %d    %d\n赵六   %d    %d    %d\n", a[0][0], a[0][1], a[0][2],a[1][0],a[1][1],a[1][2],a[2][0],a[2][1],a[2][2],a[3][0],a[3][1],a[3][2]); break;
	case 'B':printf("经计算，张三的平均成绩为%f，李四的平均成绩为%f，王五的平均成绩为%f，赵六的平均成绩为%f。\n", stu[0], stu[1], stu[2], stu[3]); break;
	case 'C':printf("经计算，全舍语文平均成绩为%f，全舍数学平均成绩为%f，全舍英语平均成绩为%f。\n", sub[0], sub[1], sub[2]); break;
	case 'E':
	{
		return 0;
		system("exit"); 
	}; break;
	case 'D':
	{
		if (stu[0] < stu[1])
		{
			k = stu[0];
			stu[0] = stu[1];
			stu[1] = k;
		}
		if (stu[1] < stu[2])
		{
			k = stu[1];
			stu[1] = stu[2];
			stu[2] = k;
		}
		if (stu[2] < stu[3])
		{
			k = stu[2];
			stu[2] = stu[3];
			stu[3] = k;
		}
		if (stu[0] < stu[1])
		{
			k = stu[0];
			stu[0] = stu[1];
			stu[1] = k;
		}
		if (stu[1] < stu[2])
		{
			k = stu[1];
			stu[1] = stu[2];
			stu[2] = k;
		}
		if (stu[0] < stu[1])
		{
			k = stu[0];
			stu[0] = stu[1];
			stu[1] = k;
		}
		printf("四名学生的平均成绩由高到低排序为：%f≥%f≥%f≥%f。\n", stu[0], stu[1], stu[2], stu[3]);
	}; break;
	}
	printf("是否重新载入菜单（Y/N）：");
	fflush(stdin); 
	scanf_s(" %c", &c, 1);
	if (c == 'Y')
	{
		system("cls");
		goto main;
	}
	else
	{
		printf("\n");
		return 0;
		system("exit");
	}
}