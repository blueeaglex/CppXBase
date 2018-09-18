project(Base)

find_package(
			BOOST REQUIRED COMPONENTS 
			filesystem
			chrono
			log
			atomic
			)
if(Boost_FOUND)
	message("boost include directories: <${Boost_INCLUDE_DIRS}>")
	message("boost lib directories : <${Boost_LIBRARY_DIRS}>")
else()
	message(FATAL_ERROR "Boost not Found!! Please spacify var BOOST_ROOT.")
endif()

set(BASE_INCLUDE_DIRS "${Boost_INCLUDE_DIRS}" PARENT_SCOPE)
set(BASE_LIB_DIRS "${Boost_LIBRARY_DIRS}" PARENT_SCOPE)
set(BASE_LIBS "${Boost_LIBRARIES}" PARENT_SCOPE)

file(GLOB include_files ./*.h ./*.hpp)

include_directories(${Boost_INCLUDE_DIRS})

add_library(Base ${include_files}
                 "src/empty.cpp")

target_link_libraries(Base)