// Exercise 5.35: ex05_35.c
// Solving nth Fibonacci number using iteration

#include <stdio.h>

unsigned long long int fibonacci(unsigned int n);

int main(void)
{
    unsigned int index;

    // Obtain the position of the Fibonnaci number
    printf("%s", "Enter the index position: ");
    scanf("%u", &index);

    // Call fibonacci with the index returning fib_number
    unsigned long long int fib_number = fibonacci(index);

    // Display the number at nth position
    printf("Fibonacci number at %uth position: %llu", index, fib_number);
}

unsigned long long int fibonacci(unsigned int n)
{
    unsigned long long int previous_num = 0;
    unsigned long long int current_num = 1;
    unsigned long long int fibonacci_num = 0;

    if (0 == n) {
        return 0;  // Return first base fibonacci number
    } else if (1 == n) {
        return 1;  // Return second base fibonacci number
    }

    for (int i = 2; i <= n; ++i) {
        fibonacci_num = previous_num + current_num;
        previous_num = current_num;
        current_num = fibonacci_num;
    }

    return fibonacci_num;
}