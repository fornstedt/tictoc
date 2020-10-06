#ifndef _TIMEMEASUREMENT_H
#define _TIMEMEASUREMENT_H

// #define DISABLE_MEASUREMENT

#ifdef DISABLE_MEASUREMENT

#define tic()
#define tic_msg(message)
#define toc()
#define toc_msg(message)

#else

#define tic() _tic(__FILE__, __LINE__, __func__)
#define tic_msg(message) _tic_msg(__FILE__, __LINE__, __func__, message)
#define toc() _toc(__FILE__, __LINE__, __func__)
#define toc_msg(message) _toc_msg(__FILE__, __LINE__, __func__, message)

void _tic(char const *fileName, int lineNumber, char const *callerName);
void _toc(char const *fileName, int lineNumber, char const *callerName);
void _toc_msg(char const *fileName, int lineNumber, char const *callerName, const char *msg);
void _tic_msg(char const *fileName, int lineNumber, char const *callerName, const char *msg);

#endif

#endif /* _TIMEMEASUREMENT_H */
