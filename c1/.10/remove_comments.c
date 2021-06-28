#include <stdio.h>

// challenge: write a program to remove all comments from a C program
// assumption 1: multi lined strings are permitted for the sake of simplicity

#define OUT                     0   // whether the reader is outside of comments and strings
#define IN_LINE_COMMENT         1   // whether the reader is inside a single line comment (//)
#define IN_MULTILINE_COMMENT    2   // whether the reader is inside a multiline comment (/* */)
#define IN_STRING               3   // whether the reader is inside a string and therefore, should ignore comments

#define WRITE_LINE          0   // determines that the read line should be written to result
#define IGNORE_LINE         1   // determines that the read line should be discarded
#define WRITE_LAST_LINE     2   // determines that the read line should be written to result but is the end of the input
#define IGNORE_LAST_LINE    3   // determines that the read line should be discarded and is the end of the input

#define RESULT_MAX_LENGTH   10000   // maximum length of result which can be output
#define LINE_MAX_LENGTH     1000    // maximum length of a line being read

int state = OUT;                    // the state which text is being read under
int rPos = 0;                       // the position which text is being written at for the result
char result[RESULT_MAX_LENGTH];     // the result which is written to
char line[LINE_MAX_LENGTH];         // the current line being constructed from tokens 

void appendLine();  // appends read line onto result
int readLine();     // reads a line from user's input

int main()
{
    int lineInstruction = WRITE_LINE;

    while (lineInstruction != WRITE_LAST_LINE && lineInstruction != IGNORE_LAST_LINE)
    {
        lineInstruction = readLine();

        if (lineInstruction != IGNORE_LINE && lineInstruction != IGNORE_LAST_LINE)
            appendLine();
    }

    printf("\n----------------------------------------------------------");
    printf("\n%s", result);
}

void appendLine()
{
    int i = 0;
    char c;

    while ((c = line[i++]) != '\0')
        result[rPos++] = c;
}

int readLine()
{
    int lPos = 0;
    int ignore = 0;
    char lc, c;
    lc = c = '\0';

    while ((c = getchar()) != EOF && c != '\n')
    {
        if (lc == '/' && c == '/')
        {
            state = IN_LINE_COMMENT;

            if (lPos == 0)
                ignore = 1;
        }

        if (state != IN_LINE_COMMENT && lc != '\0')
            line[lPos++] = lc;

        lc = c;
    }

    if (state != IN_LINE_COMMENT && lc != '\0')
    {
        line[lPos++] = lc;
        line[lPos++] = c;
    }
    else if (c == '\n')
        line[lPos++] = c;
    
    line[lPos] = '\0';

    if (c == EOF)
    {
        if (ignore == 0)
            return WRITE_LAST_LINE;
        else
            return IGNORE_LAST_LINE;
    }

    if (state == IN_LINE_COMMENT)
        state = OUT;

    if (ignore == 0)
        return WRITE_LINE;
    else
        return IGNORE_LINE;
}
