#include <iostream>
#include <string>

void help()
{
	std::cout << "这个程序将帮助你干掉烦人的管理员窗口\n\n";
	std::cout << "输入0干掉管理员窗口,输入1恢复管理员窗口弹出,输入2重启电脑\n\n";
	std::cout << "如果执行失败请以管理员身份运行此程序\n\n";
	std::cout << "注意:操作将在重启后生效\n\n";
	std::cout << "如果一次不成功请以管理员身份运行此程序并且多试几次就成功了\n\n";
	std::cout << "这个程序将修改注册表中的EnableLUA值为0,从而禁用用户账户控制(UAC),使得所有程序都以管理员身份运行,且不会再弹出管理员窗口\n\n\
请注意,禁用UAC可能降低系统的安全性,并且不建议在常规使用的情况下关闭UAC\n\n在执行此操作之前,请确保你理解风险并仔细考虑\n\n";

}

int main()
{
	help();
	std::string user_input;
	while (user_input != "exit")
	{
		std::getline(std::cin, user_input);
		if (user_input == "0")
		{
			system("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v EnableLUA /t REG_DWORD /d 0 /f");
			std::cout << "操作成功\n";
			std::cout << "注意:操作将在重启后生效\n";

		}
		else if (user_input == "1")
		{
			system("reg add HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v EnableLUA /t REG_DWORD /d 1 /f");
			std::cout << "操作成功\n";
			std::cout << "注意:操作将在重启后生效\n";

		}
		else if (user_input == "2")
		{
			system("shutdown /r /t 0");
			std::cout << "开始重启\n";
		}
		else
		{
			std::cout << "错误\n";;
		}
		
	}
}

