#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int get_rnd()
{
    struct timeval time;
    gettimeofday(&time,NULL);
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
    return rand();
}

int get_odd(int (*f)())
{
    int n = f();
    while( n%2 == 0)
    {
        n = f();  
    }
    return n;
}

int main(void)
{
    for(int i=0; i<5; ++i)
    {
        printf("%d\n", get_odd(&get_rnd));
    }	
}
