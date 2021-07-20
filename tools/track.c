#include <stdio.h>
#include <time.h>

#define TIME(relays, process) {\
    clock_t start, end;\
    double elapsed;\
    start = clock();\
    for (int i = 0; i < relays; i++)\
        process;\
    end = clock();\
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;\
    printf(#process ":\t%f\n", elapsed);\
}
