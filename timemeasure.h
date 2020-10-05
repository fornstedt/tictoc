#define toc() _toc(__FILE__, __func__)

void tic();
void _toc(char const *fileName, char const *callerName);
