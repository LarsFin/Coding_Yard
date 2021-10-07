#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   // max number of lines to be sorted
#define MAXLEN 1000 // max length of any input line
#define ALLOCSIZE 10000 // size of available space

char *lineptr[MAXLINES]; // pointers to text lines

static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf;     // next free position

int readlines(char *[], int);
void writelines(char *[], int);
int readline(char *, int);
char *alloc(int);
void qsort(char *[], int, int);
void swap(char *[], int, int);

// sort input lines
int main()
{
    int nlines; // number of lines read from input

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

// read input lines
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    
    while ((len = readline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0';   // delete newline character
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

// write output lines
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

// get line from input
int readline(char * s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

// return pointer to n characters
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

// sort elements into increasing order
void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }

    swap(v, left, last);

    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

// interchanges two elements in an array
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

