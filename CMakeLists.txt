cmake_minimum_required(VERSION 3.10)
project(GeneralLib)

set(CMAKE_CXX_STANDARD 11)


#============加载log4cplus动态链接库--start============================//
find_library(LOG4CPLUS_LIB liblog4cplus.so ./cmake-build-debug)
IF (NOT LOG4CPLUS_LIB)
    MESSAGE(FATAL_ERROR "log4cplus not found")
ENDIF(NOT LOG4CPLUS_LIB)
#============加载log4cplus动态链接库--end============================//


aux_source_directory(./ CODEPATH)
add_executable(${PROJECT_NAME} ${CODEPATH})



##================================#
##include_directories("./log4cplus")
#
#LINK_DIRECTORIES("./cmake-build-debug")
##LINK_LIBRARIES(osg osgDB osgViewer)
#LINK_LIBRARIES(liblog4cplus)
##================================#





TARGET_LINK_LIBRARIES(${PROJECT_NAME} log4cplus)