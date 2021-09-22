// Exercise 5.20: ex05_20.c
// Display a solid rectangle made of custom

#include <stdio.h>

void draw_rectangle(int side1, int side2, char fill_character);

int main(void)
{
    int x, y;
    // Obtain the measurement of the two sides
    printf("%s", "Enter values of two sides: ");
    scanf("%d%d", &x, &y);

    char symbol;
    // Get the fill character
    printf("%s", "Enter the fill character: ");
    scanf(" %c", &symbol);

    // Draw the rectangle
    draw_rectangle(x, y, symbol);
}

void draw_rectangle(int side1, int side2, char fill_character)
{
    // Print collumns
    for (int row = 1; row <= side1; ++row) {
        // Print rows
        for (int col = 1; col <= side2; ++col) {
            // Print the rectangle using the fill character
            printf("%c", fill_character);
        }
        puts("");
    }
}