#include "GeneralLib.h"


#include <cstdlib>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/stringhelper.h>
#include <log4cplus/loggingmacros.h>
#include <iomanip> //std::setprecision
#include <iostream>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;


static Logger logger;

CLog::CLog()
{

    log4cplus::initialize();

    //log4cplus.rootLogger//
    PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log.properties"));

    logger = Logger::getRoot();

#ifndef NDEBUG
    cout<<"In CLog() constructor..."<<endl;
#endif

}

CLog::~CLog()
{
    log4cplus::Logger::shutdown();

#ifndef NDEBUG
    cout<<"In ~CLog() destructor..."<<endl;
#endif
}

void CLog::WriteLog()
{
    //Logger logger = Logger::getRoot();

    // trace
    LOG4CPLUS_TRACE(logger, "trace and get the fingerprint: " << "random integer: " << random());
    // debug
    LOG4CPLUS_DEBUG(logger, "this is debug log: " << "random integer: "<< random());
    // info
    LOG4CPLUS_INFO(logger, "the information centry...." << "[ 1 + 1 = " << 1 + 1 << "]");
    // warn
    int i = 10;
    LOG4CPLUS_WARN(logger, "Writing warning messages to log...." << i);
    // error
    LOG4CPLUS_ERROR(logger, "ooooooh, there is an error....");
    //fatal
    LOG4CPLUS_FATAL(logger, "oh, my god! the fatal error occur!!!!!!!!!");
    LOG4CPLUS_DEBUG(logger, "This is a bool: " << true);
    LOG4CPLUS_INFO(logger, "This is a char: " << 'x');
    LOG4CPLUS_WARN(logger, "This is a int: " << 1000);
    LOG4CPLUS_ERROR(logger, "This is a long(hex): " << std::hex << 100000000);
    LOG4CPLUS_FATAL(logger, "This is a double: " << std::setprecision(15) << 1.2345234234);

}
