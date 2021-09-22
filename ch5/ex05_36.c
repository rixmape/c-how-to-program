// Exercise 5.36: ex05_36.c
// Solve Towers of Hanoi using recursion

#include <stdio.h>

// Function prototype
int hanoi(int disks, char from, char to, char aux);

int main(void)
{
    // Set number of disks
    int n = 3;
    hanoi(n, 'A', 'C', 'B');   
}

int hanoi(int disks, char from, char to, char aux)
{
    if (disks == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return 0;
    }

    hanoi(disks - 1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", disks, from, to);
    hanoi(disks - 1, aux, to, from);
}