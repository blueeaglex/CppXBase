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
}

typedef std::string String;

#endif //__CPP_BASE_OS_H__
