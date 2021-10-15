#include <stdio.h>

#define ALLOCSIZE 10000

enum operator 
{
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/'
};

static char allocbuf[ALLOCSIZE];
static char * allocp = allocbuf;

char * alloc(int);

int main()
{
    return 0;
}

char * alloc(int n)
{
    if (allocp + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return NULL;
}
