cmake_minimum_required(VERSION 3.12)
project(Base)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_MODULE_PATH})
message("CMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}")

set(Boost_USE_MULTITHREADED ON)

find_package(
    Boost 1.68.0 COMPONENTS 
    filesystem
    #chrono
    log
    system
    process
    thread
    #atomic
    #REQUIRED
)

message("Boost compiler ${Boost_COMPILER}")
message("Boost_LIBRARY_DIRS : <${Boost_LIBRARY_DIRS}>")
if(Boost_FOUND)
    message("Boost_INCLUDE_DIRS: <${Boost_INCLUDE_DIRS}>")
    message("Boost_LIBRARY_DIRS : <${Boost_LIBRARY_DIRS}>")
    message("Boost_LIBRARIES: <${Boost_LIBRARIES}>")
    message("Boost_FILESYSTEM_LIBRARY: <${Boost_FILESYSTEM_LIBRARY_RELEASE}>")
else()
    #message(FATAL_ERROR "Boost not Found!! Please spacify var BOOST_ROOT.")
endif()
set(Boost_LIBRARIES
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_THREAD_LIBRARY}
    ${Boost_LOG_LIBRARY}
    ${Boost_LOG_SETUP_LIBRARY}
    ${Boost_PROCESS_LIBRARY}
    #${Boost_REGEX_LIBRARY}
    )
message("Boost_LIBRARIES: <${Boost_LIBRARIES}>")

set(include_files_dir include/Base)
file(GLOB include_files ${include_files_dir}/*.h ${include_files_dir}/*.hpp)

set(BASE_INCLUDE_DIRS "${Boost_INCLUDE_DIRS}" "${CMAKE_CURRENT_SOURCE_DIR}/include" PARENT_SCOPE)
set(BASE_LIB_DIRS "${Boost_LIBRARY_DIRS}" PARENT_SCOPE)

if(UNIX)
    set(BASE_LIBS "${Boost_LIBRARIES}" pthread PARENT_SCOPE)
else()
    set(BASE_LIBS "${Boost_LIBRARIES}" PARENT_SCOPE)
endif()

include_directories(${Boost_INCLUDE_DIRS})

add_library(Base ${include_files}
                 "src/empty.cpp")

target_link_libraries(Base)
