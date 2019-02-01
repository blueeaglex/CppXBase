#ifndef __CPP_BASE_OS_H__
#define __CPP_BASE_OS_H__
#include "boost/filesystem.hpp"
#include "boost/chrono.hpp"
#include "boost/interprocess/file_mapping.hpp"
#include "boost/interprocess/mapped_region.hpp"
#include "boost/process.hpp"
#include "boost/program_options.hpp"
#include <string>
#define _CRT_SECURE_NO_WARNINGS
namespace os
{
	using boost::system::error_code;
	namespace filesystem = boost::filesystem;
	namespace chrono = boost::chrono;
	namespace interprocess = boost::interprocess;
    namespace process = boost::process;
	namespace program_options = boost::program_options;
	static const size_t MaxPath = 260u;
	static const char* WRITE = "wb";
	static const char* READ = "rb";

    inline bool process_exist(const char* pidName)
    {
        bool ret = false;

        DIR *dir; //����Ŀ¼
        struct dirent * next;

        FILE *status;
        char buffer[1024];
        char name[1024];

        dir = opendir("/proc"); ///proc�а�����ǰ�Ľ�����Ϣ,��ȡ��Ŀ¼
        if (!dir) //Ŀ¼�����ڽ���
        {
            printf("Cannot open /proc\n");
            return 0;
        }

        //���� ��ȡ������Ϣ
        while ((next = readdir(dir)) != NULL)
        {
            //����"."��".."�����ļ���
            if ((strcmp(next->d_name, "..") == 0) || (strcmp(next->d_name, ".") == 0)) continue;

            //����ļ�����������������
            if (!isdigit(*next->d_name)) continue;

            //�ж��Ƿ��ܴ�״̬�ļ�
            sprintf(buffer,"/proc/%s/status",next->d_name);
            if (!(status = fopen(buffer,"r"))) continue;

            //��ȡ״̬�ļ�
            if (fgets(buffer,1024,status) == NULL)
            {
                fclose(status);
                continue;
            }
            fclose(status);

            sscanf(buffer,"%*s %s",name); //��ȡPID��Ӧ�ĳ���������ʽΪName:  ������

    //        if (strcmp(name,pidName) == 0) //�жϳ������Ƿ����Ԥ��
            if(strstr(name,pidName))
                ret = true;
        }
        closedir(dir);
        return ret;
    }
}

typedef std::string String;

#endif //__CPP_BASE_OS_H__
