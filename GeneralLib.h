#ifndef __RING_LOG_H__
#define __RING_LOG_H__

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>//getpid, gettid

class CLog
{
public:
    CLog();

    virtual ~CLog();

public:
    void WriteLog();
};

#endif