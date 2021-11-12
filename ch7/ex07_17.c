/* Filename: ex07_17.c
 * Author: Rix Mape
 *
 * Title: The Tortoise and The Hare Simulation
 * Description: A program that simulates the classic race
 * of the tortoise and the hare using random number generation.
 * The first contender to reach or pass 70-square mark wins. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRACK 70 // Length of the racing track

int main(void)
{
    // Initialize variables representing the contenders
    int tortoise = 1;
    int hare = 1;

    // Initialize the allowed moves for each animal
    int tor_moves[10] = {3, 3, 3, 3, 3, -6, -6, 1, 1, 1};
    int har_moves[10] = {0, 0, 9, 9, -12, 1, 1, 1, -2, -2};

    srand(time(NULL)); // Seed random-number generator
    unsigned int turn = 1;

    puts("BANG!!!!!\nAND THEY'RE OFF!!!!!\n");

    // Continue race until a contender wins
    while (tortoise <= 70 && hare <= 70) {
        printf("Turn %3lu: ", turn);

        // If tortoise slip before square 1, move back to square 1
        if ((tortoise += tor_moves[rand() % 10]) < 0) {
            tortoise = 1;
        }

        if ((hare += har_moves[rand() % 10]) < 0) {
            hare = 1;
        }
        
        for (size_t i = 0; i <= TRACK; ++i) {

            if (i == tortoise && i == hare) {
                printf("%s", "B");
            }
            else if (i == tortoise) {
                printf("%s", "T");
            }
            else if (i == hare) {
                printf("%s", "H");
            } else {
                printf("%s", "-");
            }
        }

        printf("  TOR = %2d | HAR = %2d\n", tortoise, hare);
        ++turn;
    }

    if (tortoise > hare) {
        puts("\nTORTOISE WINS!!! YAY!!!");
    } else {
        puts("\nHARE wins. Yuch.");
    }
}