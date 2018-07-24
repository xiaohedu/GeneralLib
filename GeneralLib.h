//
// Created by zxkj on 18-7-24.
//

#ifndef GENERALLIB_GENERALLIB_H
#define GENERALLIB_GENERALLIB_H

#include <string>

using namespace std;

//================日志记录类 start==================//
//Name:Clog
//Note:日志记录类.基于log4cplus的日志记录工具
//Author:liheng
//CreateTime:2018.07.24
//Version:V1.0
class CLog
{
public:
    //默认构造函数.意味着采用的配置文件名称为:log4cplus.properties;配置文件路径和可执行文件路径一致
    CLog();

    //自定义配置文件名称和路径
    CLog(string strConfigPath);

    virtual ~CLog();

public:

    //定义日志级别,和log4cplus中的日志级别保持一致
    //•TRACE •DEBUG •INFO •WARN •ERROR •FATAL
    typedef enum _LogLevel
    {
        TRACE = 0,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL
    }LogLevel;

private:
    string m_strConfigPath;//log4cplus.properties配置文件的路径.完整路径

public:
    //返回配置文件路径
    string getConfigPath();

    void writeLog(LogLevel,string& strInfo);

    void writeErrorLog(string strError);
};
//================日志记录类 end==================//
#endif //GENERALLIB_GENERALLIB_H
