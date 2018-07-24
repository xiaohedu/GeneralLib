#include <iostream>
#include <cstdlib>

#include "log4cplus/logger.h"
#include "log4cplus/configurator.h"
#include "log4cplus/helpers/loglog.h"
#include "log4cplus/helpers/stringhelper.h"
#include "log4cplus/loggingmacros.h"

//#include <log4cplus/logger.h>
//#include <log4cplus/configurator.h>
//#include <log4cplus/helpers/loglog.h>
//#include <log4cplus/helpers/stringhelper.h>
//#include <log4cplus/loggingmacros.h>


#include <iomanip>//std::setprecision
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <zconf.h>
#include <sstream>

#include "GeneralLib.h"

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

int main()
{
    CLog m_log;
    m_log.writeErrorLog("123");


    return 0;
}

CLog::CLog()
        :m_strConfigPath("")
{
    //获取配置文件路径
    char dir[PATH_MAX] = {0};
    char syspath[PATH_MAX] = {0};
    int n = readlink("/proc/self/exe", dir, PATH_MAX);

    const char *ptr;
    ptr = strrchr(dir, '/');

    int length = strlen(dir) - strlen(ptr);
    string s1(dir);
    string s2;
    s2 = s1.substr(0, length);
    memcpy(syspath, (char*)s2.data(), PATH_MAX);

    m_strConfigPath = syspath;
    m_strConfigPath += "/log4cplus.properties";



    log4cplus::initialize();
    //log4cplus.rootLogger//
    PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(m_strConfigPath));

}

CLog::CLog(string strConfigPath)
        :m_strConfigPath(strConfigPath)
{
    log4cplus::initialize();
    //log4cplus.rootLogger//
    PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(m_strConfigPath));
}


//析构函数.退出时进行shutdown()操作
CLog::~CLog()
{
    log4cplus::Logger::shutdown();
}

string CLog::getConfigPath()
{
    return m_strConfigPath;
}

void CLog::writeErrorLog(string strError)
{
    Logger logger = Logger::getRoot();
    // error
    LOG4CPLUS_ERROR(logger, strError);

}

void CLog::writeLog(LogLevel logLevel,string& strInfo)
{
    Logger logger = Logger::getRoot();

    switch(logLevel)
    {
        case TRACE:LOG4CPLUS_TRACE(logger, strInfo);break;
        case DEBUG:LOG4CPLUS_DEBUG(logger, strInfo);break;
        case INFO:LOG4CPLUS_INFO(logger, strInfo);break;
        case WARN:LOG4CPLUS_WARN(logger, strInfo);break;
        case ERROR:LOG4CPLUS_ERROR(logger, strInfo);break;
        case FATAL:LOG4CPLUS_FATAL(logger, strInfo);break;
        default:break;
    }

}
