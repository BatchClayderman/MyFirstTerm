#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;
int main()
{
	int v4 = 9, i, v6 = 46;
	char v7[104];
	char a1[46] = { 0x60,0x6A,0x6B,0x75,0x7B,0x4C,0x69,0x74,0x69,0x5f,0x6b,0x74,0x69,0x5f,0x79,0x71,0x5f,0x46,0x71,0x5f,0x62,0x69,0x5f,0x67,0x76,0x66,0x69,0x74,0x69,0x6f,0x66,0x69,0x6e,0x5f,0x6b,0x76,0x6e,0x5f,0x69,0x64,0x77,0x67,0x66,0x69,0x6e,0x7d };
	for (i = 0; i < v6; ++i)
	{
		if (a1[i] != 123 && a1[i] != 125 && a1[i] != 95)
		{
			a1[i] ^= 1;
			if (a1[i] <= 64 || a1[i] > 90)
			{
				v7[i] = ((a1[i] - 97 - v4) * 11) % 26 + 97;
				if ((11 * (a1[i] - 97 - v4) & 2147483648) != 0)
					v7[i] += 26;
			}
			else
			{
				v7[i] = ((a1[i] - 65 - v4) * 11) % 26 + 65;
				if ((11 * (a1[i] - 65 - v4) & 0x80000000) != 0)
					v7[i] += 26;
			}
		}
		else
			v7[i] = a1[i];
	}
	cout << v7;
	printf("\n\n计算完毕，请手动从上述字符串中提取出flag，请按任意键退出程序。\n\n");
	system("pause>nul");
	return 0;
}