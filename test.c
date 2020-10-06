#include <unistd.h>
#include "timemeasure.h"

void func(void);
void func2(void);

int main(void)
{
    func();
    return 0;
}

void func(void)
{
    tic_msg("func");

    func2();
    func2();
    func2();

    toc();
}

void func2(void)
{
    tic();
    int x = 3;

    for (int i=0; i < 100000000; i++)
    {
        x *= 7;
    }
    sleep(1);
    toc_msg("func2");
}
