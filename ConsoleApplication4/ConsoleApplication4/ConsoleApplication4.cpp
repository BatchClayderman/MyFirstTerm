#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 936&title 文件读写&color e&cls");
	FILE* in, * out;
	char ch, infile[1000] = { 0 }, outfile[1000] = { 0 };
	printf("请输入读入文件路径：");
	scanf_s("%s", &infile, sizeof(infile));
	printf("请输入输出文件的路径：");
	scanf_s("%s", &outfile, sizeof(outfile));
	if ((in = fopen (infile,"r")) == NULL)
	{
		printf("\a无法打开读入文件。\n");
		exit(0);
	}
	if ((out = fopen (outfile, "w")) == NULL)
	{
		printf("\a无法打开输出文件。\n");
		exit(0);
	}
	ch = fgetc(in);
	while (!feof(in))
	{
		fputc(ch, out);
		putchar(ch);
		ch = fgetc(in);
	}
	putchar(10);
	fclose(in);
	fclose(out);
	return 0;
}