// Fig. 6.8: fig06_08.c
// Displaying a histogram

#include <stdio.h>
#define SIZE 5

// Function main begins program execution
int main(void)
{
    // Use initializer list to initialize array n
    int n[SIZE] = {19, 3, 15, 7, 11};

    printf("%s%13s%17s\n", "Element", "Value", "Histogram");

    // For each element of array n, output a bar of the histogram
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%7u%13d        ", i, n[i]);

        for (int j = 1; j <= n[i]; ++j) { // Print one bar
            printf("%c", '*');
        }

        puts(""); // End a histogram with a newline
    }
}