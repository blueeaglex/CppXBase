#ifndef __LOG_H__
#define __LOG_H__


#ifdef OS_WINDOWS
#  include "boost/log/trivial.hpp"
#  define DEBUG_LOG BOOST_LOG_TRIVIAL(debug) << __FUNCTION__ << ":" << __LINE__
#  define INFO_LOG  BOOST_LOG_TRIVIAL(info) << __FUNCTION__ << ":" << __LINE__
#  define WARNING_LOG BOOST_LOG_TRIVIAL(warning) << __FUNCTION__ << ":" << __LINE__
#  define ERROR_LOG BOOST_LOG_TRIVIAL(error) << __FUNCTION__ << ":" << __LINE__
#  define FATAL_LOG BOOST_LOG_TRIVIAL(fatal) << __FUNCTION__ << ":" << __LINE__
#else
#  include <iostream>
#  define DEBUG_LOG   std::cout << "[DEBUG]" << __FUNCTION__ << ":" << __LINE__ << " "
#  define INFO_LOG    std::cout << "[INFO]" << __FUNCTION__ << ":" << __LINE__ << " "
#  define WARNING_LOG std::cout << "[WARNING]" << __FUNCTION__ << ":" << __LINE__ << " "
#  define ERROR_LOG   std::cout << "[ERROR]" << __FUNCTION__ << ":" << __LINE__ << " "
#  define FATAL_LOG   std::cout << "[FATAL]" << __FUNCTION__ << ":" << __LINE__ << " "
#endif

#endif
