// Exercise 5.19: ex05_19.c
// Display a solid rectangle of asterisks given the values of its sides

#include <stdio.h>

void draw_rectangle(int side1, int side2);

int main(void)
{
    int x, y;
    // Obtain the measurement of the two sides
    printf("%s", "Enter values of two sides: ");
    scanf("%d%d", &x, &y);

    // Draw the rectangle
    draw_rectangle(x, y);
}

void draw_rectangle(int side1, int side2)
{
    for (int row = 1; row <= side1; ++row) {
        for (int col = 1; col <= side2; ++col) {
            printf("%s", "*");
        }
        puts("");
    }
}