#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char * alloc(int);
void afree(char *);

int main()
{
    char * chunk = alloc(29);
    printf("Amount of allocates space used: %d\n", allocp - allocbuf);
    afree(chunk);
    printf("Amount of allocates space used: %d\n", allocp - allocbuf);

    return 0;
}

char * alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return NULL;
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
