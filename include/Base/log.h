#ifndef __LOG_H__
#define __LOG_H__

#include "boost/log/trivial.hpp"

#define DEBUG_LOG BOOST_LOG_TRIVIAL(debug) << __FUNCTION__ << ":" << __LINE__
#define INFO_LOG  BOOST_LOG_TRIVIAL(info) << __FUNCTION__ << ":" << __LINE__
#define WARNING_LOG BOOST_LOG_TRIVIAL(warning) << __FUNCTION__ << ":" << __LINE__
#define ERROR_LOG BOOST_LOG_TRIVIAL(error) << __FUNCTION__ << ":" << __LINE__
#define FATAL_LOG BOOST_LOG_TRIVIAL(fatal) << __FUNCTION__ << ":" << __LINE__

#endif