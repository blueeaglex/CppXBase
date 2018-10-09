#ifndef __CPP_BASE_OS_H__
#define __CPP_BASE_OS_H__

#include <boost/filesystem.hpp>
#include "boost/chrono.hpp"
#include "boost/interprocess/file_mapping.hpp"
#include "boost/interprocess/mapped_region.hpp"
#include "boost/process.hpp"
#include <string>
#define _CRT_SECURE_NO_WARNINGS
namespace os
{
	namespace filesystem = boost::filesystem;
    namespace chrono = boost::chrono;
    namespace interprocess = boost::interprocess;
    namespace process = boost::process;
	static const size_t MaxPath = 260u;

    inline bool process_exist(const char* pidName)
    {
        bool ret = false;

        DIR *dir; //进程目录
        struct dirent * next;

        FILE *status;
        char buffer[1024];
        char name[1024];

        dir = opendir("/proc"); ///proc中包括当前的进程信息,读取该目录
        if (!dir) //目录不存在结束
        {
            printf("Cannot open /proc\n");
            return 0;
        }

        //遍历 读取进程信息
        while ((next = readdir(dir)) != NULL)
        {
            //跳过"."和".."两个文件名
            if ((strcmp(next->d_name, "..") == 0) || (strcmp(next->d_name, ".") == 0)) continue;

            //如果文件名不是数字则跳过
            if (!isdigit(*next->d_name)) continue;

            //判断是否能打开状态文件
            sprintf(buffer,"/proc/%s/status",next->d_name);
            if (!(status = fopen(buffer,"r"))) continue;

            //读取状态文件
            if (fgets(buffer,1024,status) == NULL)
            {
                fclose(status);
                continue;
            }
            fclose(status);

            sscanf(buffer,"%*s %s",name); //读取PID对应的程序名，格式为Name:  程序名

    //        if (strcmp(name,pidName) == 0) //判断程序名是否符合预期
            if(strstr(name,pidName))
                ret = true;
        }
        closedir(dir);
        return ret;
    }
}

typedef std::string String;

#endif //__CPP_BASE_OS_H__
