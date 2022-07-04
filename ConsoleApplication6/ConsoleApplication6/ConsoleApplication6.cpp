#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	system("chcp 936&title 二分法求101的八次根&color e&cls");
	int t;
	double k = 101, i = 0, j = 0, h;
	for (j = 1; j <= 101; j++)
		if (pow(j, 8) > k)
		{
			i = j - 1;
			break;
		}
	for (t = 1; t <= 8; t++)
	{
		h = (i + j) / 2;
		if (pow(h, 8) <= k)
			i = h;
		else
			j = h;
	}
	printf("经近似计算，101的八次根约为%.8f。\n计算完毕，请按任意键退出程序。\n\n", h);
	system("pause>nul");
	return 0;
}
//1.77734375