// Exercise 5.44: ex05_44.c
// After you determine what the program of Exercise 5.43 does,
// modify the program to function properly after removing the
// restriction of the second argument’s being nonnegative.

#include <stdio.h>

int mystery(int a, int b);

int main(void)
{
    printf("%s", "Enter two positive integers: ");
    int x, y;
    scanf("%d%d", &x, &y);

    printf("\nThe result is %d\n", mystery(x, y));
}

// Paramater b must be a positive integer
// to prevent infinite recursion
int mystery(int a, int b)
{
    if (1 == b) { // Base case when b is positive
        return a;
    } 

    else if (-1 == b) { // Base case when b is negative
        return -a;
    }

    else if (0 == b) { // Base case when b is zero
        return 0;
    }
    
    else if (b > 0) { // Recursive step
        return a + mystery(a, b - 1);
    }

    else if (b < 0) { // Recursive step 
        return -a + mystery(a, b + 1);
    }
}