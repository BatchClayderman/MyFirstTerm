#include <iostream>
#include <time.h>
#include <string.h>
#include <conio.h>
#ifndef M
#define M 1000 //货品信息的上限
#endif
int T = 0;  //记录现有的总货物数
int times = 1;  //记录操作节点编号
void menu();

typedef struct
{
	int num;                //货品编号
	char name[30];              //货品名称
	int stock;                //现有库存
	int in;                       //入库数目
	int out;                //出库数目
	char time[2];               //记录操作节点编号
}goods;
goods s[M];                //用于存放货品信息
goods tr[2 * M];             //用于存放操作信息

void Stock_state()    //创建库存文件：添加或删除商品
{
	FILE* fp;
	int i;
	int k1, k2, k3, k4, index = NULL; // k为指令标码，index为货物对应编号
	char tem[30] = { NULL };

	printf("\n\n");   //打印对应菜单
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*      1.添加货品         2.删除货品        *\n");
	printf("*                                           *\n");
	printf("*               0.返回菜单                  *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n请输入查询选项:");
	scanf_s("%d", &k1);
	fopen_s(&fp, "stockstate.txt", "a+");
	if (fp != NULL) {
		if (k1 == 1) {   // 添加货品
			printf("\n请输入所要添加货品的名称:\n");
			scanf_s("%s", tem, sizeof(tem));
			printf("\n请问是否添加'%s'货品？是请输入1，否请输入0\n", tem);
			scanf_s("%d", &k2);

			if (k2 == 1) {    //确认添加货品
				T++;
				strcpy_s(s[T].name, tem);
				s[T].num = T;
				s[T].stock = 0;
				fscanf_s(fp, "%10d%10s%10d", &s[T].num, s[T].name, sizeof(s[T].name), &s[T].stock);

			}
			else if (k2 == 0) {    // 否认添加货品
				printf("\n输入任意键返回上一级\n");
				system("pause>nul");
			}
		}
		else if (k1 == 2 && T != 0) {  // 删除货品

			printf("\n\n请输入删除方式:1.通过货品编号删除   2.通过货品名称删除  :");
			scanf_s("%d", &k3);

			if (k3 == 1) {  //通过货品编号删除  输入对应index
				printf("\n请输入对应货品编号：");
				scanf_s("%d", &index);
			}
			else if (k3 == 2) {  //通过货品名称删除
				printf("\n请输入对应货品名称：");
				scanf_s("%s", &tem, sizeof(tem));

				for (i = 1; i <= T; i++) {    // 寻找是否存在该货品  存在则存储对应index
					if (strcmp(tem, s[i].name) == 0) {
						index = i;
					}
					else {
						if (i == T) {
							printf("\n警告！货品列表中无上述货品！\n");
							printf("\n输入任意键返回上一级\n");
							system("pause>nul");
						}
					}
				}
			}

			printf("\n请问是否删除'%s'货品？是请输入1，否请输入0\n", s[index].name);
			scanf_s("%d", &k4);

			if (k4 == 1) {    //确认删除货品
				for (i = index; i <= T; i++) {
					s[i].num = s[i + 1].num;
					strcpy_s(s[i].name, s[i + 1].name);
					s[i].stock = s[i + 1].stock;
				}
				T--;

				for (i = index; i <= T; i++) {
					fscanf_s(fp, "%d%s", &s[T].num, s[T].name, sizeof(s[T].name));
				}
			}
			else if (k4 == 0) {    // 否认删除货品
				printf("\n输入任意键返回上一级\n");
				system("pause>nul");
			}
		}
		else if (k1 == 2 && T == 0) {
			printf("\n当前库存无货品\n");
			printf("\n输入任意键返回上一级\n");
			system("pause>nul");
		}
		else if (k1 == 0) {
			menu();
		}
	}
	if (fp)
		fclose(fp);
}

void Stock_trans()        //创建与写入出入库操作日志文件以及具体操作 1为增加库存，2为减少库存
{
	FILE* fp;
	int i;
	int k, index = NULL;
	char tem[30] = { NULL };
	fopen_s(&fp, "stocktrans.txt", "a+");
	if (fp != NULL) {
		if (T == 0) {
			printf("\n\n当前仓库无货品，请按任意键返回菜单添加货品\n");
			printf("\n输入任意键返回上一级\n");
			system("pause>nul");
			menu();
		}

		printf("\n请输入目标货品的名称\n");
		scanf_s("%s", &tem, sizeof(tem));

		for (i = 1; i <= T; i++) {    // 寻找是否存在该货品  存在则存储对应index
			if (strcmp(tem, s[i].name) == 0) {
				index = i;
			}
			else if (strcmp(tem, s[i].name) != 0) {
				if (i == T) {
					printf("\n警告！货品列表中无上述货品！\n");
					printf("\n输入任意键返回上一级\n");
					system("pause>nul");
					menu();
				}
			}
		}

		strcpy_s(tr[times].name, s[index].name);
		tr[times].num = s[index].num;

		printf("\n\n");   //打印对应菜单
		printf("*********************************************\n");
		printf("*                                           *\n");
		printf("*      1.添加货品         2.删除货品        *\n");
		printf("*                                           *\n");
		printf("*               0.返回菜单                  *\n");
		printf("*                                           *\n");
		printf("*********************************************\n");
		printf("\n\n请输入选项:");
		scanf_s("%d", &k);

		if (k == 1) {  //增加对应库存
			printf("\n\n请输入所需增加库存数目:");
			scanf_s("%d", &tr[times].in);
			s[index].stock += tr[times].in;
		}
		else if (k == 2) {  //减少对应库存
			printf("\n\n请输入所需减少库存数目:");
			scanf_s("%d", &tr[times].out);

			if (tr[times].out > s[index].stock) {
				printf("\n\n警告！库存不足！\n");
				printf("\n输入任意键返回上一级\n");
				system("pause>nul");
				menu();
			}
			else s[index].stock -= tr[times].out;
		}

		tr[times].stock = s[index].stock;

		if (tr[times].stock == 0) {
			printf("\n该货品已调用完全\n");

			for (i = index; i <= T; i++) {  //删除对应货品
				s[i].num = s[i + 1].num;
				strcpy_s(s[i].name, s[i + 1].name);
				s[i].stock = s[i + 1].stock;
			}

			T--;
		}
		else  printf("\n\n'%s'货品现有库存为%d\n\n", tr[times].name, tr[times].stock); //显示操作后的货品库存

		times++;

		printf("\n输入任意键返回上一级\n");
		system("pause>nul");
		menu();

	}
	if (fp)
		fclose(fp);

}

void Display()        //显示库存情况
{
	int i, j;
	system("cls");
	printf("货品编号       货品名称       现有库存\n");
	for (i = 1, j = 1; i <= T; i++, j++)
	{
		printf("%-14d  %-15s%-15d\n", s[i].num, s[i].name, s[i].stock);

		if (j % 20 == 0 && j < T) { // 对显示的数据进行类似翻页的处理，每20项重新提示对应数据类型
			system("pause");
			puts("\n");
			printf("货品编号       货品名称       现有库存\n");
		}
	}

}

void Query()  // 查询货品
{
	int i;
	int k, index = NULL;//初始化 index = NULL
	char tem[30] = { NULL };
	system("cls");

	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*                 查询方式                  *\n");
	printf("*                                           *\n");
	printf("*      1.货品编号         2.货品名称        *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n请输入查询方式选项:");
	scanf_s("%d", &k);

	if (k == 1) {
		printf("请输入货品编号:");
		scanf_s("%d", &index);

		if (index > T) {
			printf("\n警告！货品编号已超出上限%d！", T);
			printf("\n输入任意键返回上一级\n");
			system("pause>nul");
		}
	}
	else if (k == 2) {
		printf("请输入货品名称:");
		scanf_s("%s", &tem, sizeof(tem));

		for (i = 1; i <= T; i++) {
			if (strcmp(tem, s[i].name) == 0)
				index = i;
			else {
				if (i == T) {
					printf("\n警告！货品列表中无上述货品！");
					printf("\n输入任意键返回上一级\n");
					system("pause>nul");
				}
			}
		}
	}

	printf("货品编号  货品名称  现有库存\n");
	printf("%-9d  %-10s%-10d\n", s[index].num, s[index].name, s[index].stock);

	printf("\n输入任意键返回上一级\n");
	system("pause>nul");

}

void Modify()   // 修改货品信息
{
	int i;
	int k1, k2, k3, index = NULL; //k为指令标码，index为货品对应编号，h为库存改变量
	char tem[30] = { NULL };
	system("cls");

	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*      1.货品编号         2.货品名称        *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n请输入修改目标的编号或名称:");

	scanf_s("%d", &k1);

	if (k1 == 1) {
		printf("请输入修改目标货品编号:");
		scanf_s("%d", &index);
	}
	else if (k1 == 2) {
		printf("请输入修改目标货品名称:");
		scanf_s("%s", tem, sizeof(tem));
		for (i = 1; i <= T; i++) {
			if (strcmp(tem, s[i].name) == 0)
				index = i;
			else {
				if (i == T)
					index = T + 1;
			}
		}
	}

	if (index > T) {    //判断所得编号是否合法
		printf("\n警告！货品列表中无上述货品！");
		printf("\n输入任意键返回上一级\n");
		system("pause>nul");
	}
	else {      //正式修改编号对应信息
		printf("\n\n");
		printf("*********************************************\n");
		printf("*                                           *\n");
		printf("*       1.货品名称          2.现有库存      *\n");
		printf("*                                           *\n");
		printf("*********************************************\n");
		printf("请选择修改选项:");
		scanf_s("%d", &k2);

		if (k2 == 1) {
			printf("\n该货品现名称为'%s'，请输入修改后的货品名称：", s[index].name);
			scanf_s("%s", &tem, sizeof(tem));
			strcpy_s(s[index].name, tem);
			strcpy_s(tr[times].name, tem);
		}
		else if (k2 == 2) {
			printf("\n\n");
			printf("*********************************************\n");
			printf("*                                           *\n");
			printf("             %s   现有库存为%d             \n", s[index].name, s[index].stock);
			printf("*       1.增加库存          2.减少库存      *\n");
			printf("*                                           *\n");
			printf("*********************************************\n");
			printf("请选择修改选项:");
			scanf_s("%d", &k3);

			if (k3 == 1) {
				printf("\n\n请输入所需增加的库存数目:");
				scanf_s("%d", &tr[times].in);
				s[index].stock += tr[times].in;
			}
			else if (k3 == 2) {
				printf("\n\n请输入所需减少的库存数目:");
				scanf_s("%d", &tr[times].out);

				if (tr[times].out > s[index].stock) {
					printf("\n\n警告！库存不足！\n");
					printf("\n输入任意键返回上一级\n");
					system("pause>nul");
				}
				else  s[index].stock -= tr[times].out;
			}
		}

		strcpy_s(tr[times].name, s[index].name);
		tr[times].stock = s[index].stock;
		tr[times].num = s[index].num;
		times++;

		printf("\n请确认核对货品信息:\n");
		printf("货品编号       货品名称       现有库存\n");
		printf("%-14d  %-15s%-15d\n", s[index].num, s[index].name, s[index].stock);
		printf("\n输入任意键返回上一级\n");
		system("pause>nul");
	}

}

void menu()  //打印菜单
{
	int sele = 1;
	while (sele)
	{
		system("cls");
		printf("\n\n");
		printf("*********************************************\n");
		printf("*               仓库管理系统                *\n");
		printf("*********************************************\n");
		printf("*                                           *\n");
		printf("*       1.货品管理          2.库存管理      *\n");
		printf("*                                           *\n");
		printf("*       3.查询              4.修改          *\n");
		printf("*                                           *\n");
		printf("*       5.统计              6.退出          *\n");
		printf("*                                           *\n");
		printf("*********************************************\n");
		printf("请选择功能序号:");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:Stock_state(); break;
		case 2:Stock_trans(); break;
		case 3:Query(); break;
		case 4:Modify(); break;
		case 5:Display(); break;
		case 6: {
			printf("\n感谢你的使用\n");
			exit(0); sele = 0; break;
		}


		}
		printf("\n\n");
		system("pause");
	}
}

int main()
{
	menu(); //打印菜单
	return 0;
}