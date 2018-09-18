#ifndef __OS_H__
#define __OS_H__
#include "boost/filesystem.hpp"
#include "boost/chrono.hpp"
#include "boost/interprocess/file_mapping.hpp"
#include "boost/interprocess/mapped_region.hpp"
#include <string>
#define _CRT_SECURE_NO_WARNINGS
namespace os
{
	namespace filesystem = boost::filesystem;
	namespace chrono = boost::chrono;
	namespace interprocess = boost::interprocess;
	static const size_t MaxPath = 260u;
	static const char* WRITE = "wb";
	static const char* READ = "rb";
}

typedef std::string String;

#endif //__OS_H__