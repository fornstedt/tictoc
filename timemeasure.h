
// #define DISABLE_MEASUREMENT

#ifdef DISABLE_MEASUREMENT
  #define tic()
  #define toc()
#else
  #define toc() _toc(__FILE__, __func__)
#endif

#ifndef DISABLE_MEASUREMENT
void tic();
void _toc(char const *fileName, char const *callerName);
#endif
