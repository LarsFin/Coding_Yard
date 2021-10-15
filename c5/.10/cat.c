#include <stdio.h>

// challenge: write a program that takes a file path as an argument and prints its contents to the console.
// Your program should report to the user on a non existing file.

#define FILEBUFSIZE 10000

static char buf[FILEBUFSIZE];

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("Please provide a file path to read from.");
        return 0;
    }

    FILE * fp = fopen(argv[1], "r");

    while (fgets(buf, FILEBUFSIZE, fp) != NULL)
        printf("%s", buf);

    fclose(fp);

    return 0;
}
