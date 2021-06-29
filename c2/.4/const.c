// indicates the function does not mutate the array
int strSize(const char[]);

int main()
{
    const int i = 50;

    // compile error with below
    // i++;
    // output: error: increment of read-only variable ‘i’
}
