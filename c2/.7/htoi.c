#include <stdio.h>

// challenge: write a function 'htoi(s)' which converts a string of hexadecimal digits into its equivalent integer value
// e.g; "2EF" becomes 751

#define HEX_MAX_LEN 7 // not including sign

int htoi(char[]);
int power(int, int);

int main()
{
    printf("'%s' as HEX as DEC is %d\n", "2EF", htoi("2EF"));     // should be 751
    printf("'%s' as HEX as DEC is %d\n", "-B7", htoi("-B7"));   // should be -183
    printf("'%s' as HEX as DEC is %d\n", "12X", htoi("12X"));     // should be 0
}

// returns zero if hex string cannot be converted to integer
int htoi(char hex[])
{
    unsigned short hcd[HEX_MAX_LEN]; // hexadecimal character values as decimal
    int isneg, dec, i, h, j;

    dec = i = j = 0;

    if (isneg = hex[0] == '-')
        i++;

    while (i < HEX_MAX_LEN && (h = hex[i]) != '\0')
    {
        if (h >= '0' && h <= '9')
            hcd[j] = h - 48;
        else if (h >= 'A' && h <= 'F')
            hcd[j] = h - 55;
        else
            return 0;

        i++; j++;
    }

    int k = j - 1;

    while (--j >= 0)
        dec += hcd[j] * power(16, k - j);

    if (isneg)
        dec *= -1;

    return dec;
}

int power(int x, int y)
{
    int n = 1;

    for (int i = 0; i < y; i++)
        n *= x;

    return n;
}
