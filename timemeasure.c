#include <time.h>
#include <stdio.h>
#include "timemeasure.h"

#ifndef DISABLE_MEASUREMENT
#define MAX_NESTED 32
#define CPU_LIMIT  0.000
#define REAL_LIMIT 0.000

static unsigned int _nestedLevel = 0;
static struct timespec _cpuStart[MAX_NESTED];
static struct timespec _realStart[MAX_NESTED];

void _tic(char const *fileName, int lineNumber, char const *callerName)
{
    _tic_msg(fileName, lineNumber, callerName, NULL);
}

void _tic_msg(char const *fileName, int lineNumber, char const *callerName, const char *msg)
{
    if (_nestedLevel < MAX_NESTED)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &_cpuStart[_nestedLevel]);
        clock_gettime(CLOCK_REALTIME, &_realStart[_nestedLevel]);
    }
    else
    {
        printf("tic: Maximum nested depth reached.\n");
    }

    _nestedLevel++;

    if (msg != NULL)
    {
        printf("%s:%s:%d, level %d, start - %s\n", fileName, callerName, lineNumber, _nestedLevel, msg);
    }
}

void _toc(char const *fileName, int lineNumber, char const *callerName)
{
    _toc_msg(fileName, lineNumber, callerName, NULL);
}

void _toc_msg(char const *fileName, int lineNumber, char const *callerName, const char *msg)
{
    if (_nestedLevel < MAX_NESTED +1 && _nestedLevel > 0)
    {
        struct timespec cpuStop;
        struct timespec realStop;
        double elapsedCpu;
        double elapsedReal;

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpuStop);
        clock_gettime(CLOCK_REALTIME, &realStop);
        elapsedCpu  = (cpuStop.tv_sec   - _cpuStart[_nestedLevel-1].tv_sec) +
                      (cpuStop.tv_nsec  - _cpuStart[_nestedLevel-1].tv_nsec) / 1e9;
        elapsedReal = (realStop.tv_sec  - _realStart[_nestedLevel-1].tv_sec) +
                      (realStop.tv_nsec - _realStart[_nestedLevel-1].tv_nsec) / 1e9;

        if (elapsedCpu > CPU_LIMIT || elapsedReal > REAL_LIMIT)
        {
            if (msg != NULL)
            {
                printf("%s:%s:%d, level %d, %.3f ms (real), %.3f ms (cpu) - %s\n",
                       fileName, callerName, lineNumber, _nestedLevel, elapsedReal, elapsedCpu, msg);
            }
            else
            {
                printf("%s:%s:%d, level %d, %.3f ms (real), %.3f ms (cpu)\n",
                       fileName, callerName, lineNumber, _nestedLevel, elapsedReal, elapsedCpu);
            }
        }
    }
    else
    {
        printf("toc: Outside max nested depth.\n");
    }

    if (_nestedLevel > 0)
    {
        _nestedLevel--;
    }
}
#endif
