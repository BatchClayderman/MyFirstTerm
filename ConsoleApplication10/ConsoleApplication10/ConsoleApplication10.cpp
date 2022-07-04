#include "stdio.h"
#include "stdlib.h"
#define N 397

int main()
{
	int i, lower = 0, upper = 0, space = 0;
	char str[N] = "Encryption has long been used by militaries and governments to facilitate secret communication. It is now commonly used in protecting information within many kinds of civilian systems. For example, the Computer Security Institute reported that in 2007, 71% of companies surveyed utilized encryption for some of their data in transit, and 53% utilized encryption for some of their data in storage.";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			upper++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			lower++;
		else if (str[i] == ' ')
			space++;
	}
	printf("经统计，含有大写字母%d个，小写字母%d个，单词%d个。\n统计完成，请按任意键退出程序。\n\n", upper, lower, space + 1);
	system("pause>nul");
	return 0;
}