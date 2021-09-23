// Fig. 6.4: fig06_04.c
// Initializing the elements of an array with an initializer list.

#include <stdio.h>

// function main begins program execution
int main(void)
{
    // use initializer list to initialize array n
    int n[5] = {32, 27, 64, 18, 95};

    printf("%s%13s\n", "Element", "Value");

    // Output contents of array n in tabular format
    for (size_t i = 0; i < 5; ++i) {
        printf("%7u%13d\n", i, n[i]);
    }
}