#include "os.h"

namespace console
{
	
inline void checkOutputDir(String &directory, bool no_abort = false)
{
	if (os::filesystem::exists(directory))
	{
		if (no_abort)
		{
			std::cout << "已覆盖文件夹 <" << directory << ">" << std::endl;
		}
		else
		{
			std::cout << "文件夹 <" << directory << "> 已经存在,继续可能覆盖原数据,是否继续？[y/n]" << std::endl;
			String user_confirm;
		reconfirm:
			std::cin >> user_confirm;
			if ("n" == user_confirm)
				exit(0);
			else if ("y" != user_confirm)
				goto reconfirm;
		}
	}
	else os::filesystem::create_directories(directory);
}

}