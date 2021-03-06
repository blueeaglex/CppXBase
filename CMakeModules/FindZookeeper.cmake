# Find zookeeper
find_path(ZOOKEEPER_ROOT "include/zookeeper/zookeeper.h" "/usr/local/zookeeper")

set(ZOOKEEPER_LIB_DIR ZOOKEEPER_LIB_DIR-NOTFOUND)
set(ZOOKEEPER_INCLUDE_DIR ZOOKEEPER_INCLUDE_DIR-NOTFOUND)
set(ZOOKEEPER_LIBS ZOOKEEPER_LIBS-NOTFOUND)
if(${ZOOKEEPER_ROOT} STREQUAL ZOOKEEPER_ROOT-NOTFOUND)
    message(FATAL_ERROR "ZOOKEEPER_ROOT not found")
else()
    set(ZOOKEEPER_LIB_DIR ${ZOOKEEPER_ROOT}/lib)
    set(ZOOKEEPER_INCLUDE_DIR ${ZOOKEEPER_ROOT}/include/zookeeper)
    set(ZOOKEEPER_LIBS zookeeper_mt)
endif()
