// Fig 5.14: fig05_14.c
// Simulating the game of craps.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time

// enumeration constants represent game status
enum Status {CONTINUE, WON, LOST};

int roll_dice(void); // function prototype

int main(void)
{
    // randomize random number generator using current time
    srand(time(NULL));

    int my_point; // player must take this point to win
    enum Status game_status; // can contain CONTINUE, WON or LOST
    int sum = roll_dice(); // first roll of the dice

    // determine game status based on sum of dice
    switch(sum) {

        // win on first roll
        case 7:
        case 11:
            game_status = WON;
            break;

        // lose on first roll
        case 2:
        case 3:
        case 12:
            game_status = LOST;
            break;

        // remember point
        default:
            game_status = CONTINUE; // player should keep rolling
            my_point = sum; // remember the point
            printf("Point is %d\n", my_point);
            break;
    }

    // while game not complete
    while (CONTINUE == game_status) { // player should keep rolling
        sum = roll_dice(); // roll dice again

        // determine game status
        if (sum == my_point) { // won by making point
            game_status = WON;
        }
        else {
            if (7 == sum) { // lose by rolling 7
                game_status = LOST;
            }
        }
    }

    // display won or lost message
    if (WON == game_status) { // did player win?
        puts("Player wins");
    }
    else { // player lost
        puts("Player loses");
    }
}

// roll dice, calculate sum and display results
int roll_dice(void)
{
    int die1 = 1 + (rand() % 6); // pick random die1 value
    int die2 = 1 + (rand() % 6); // pick random die2 value

    // display results of this roll
    printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
    return die1 + die2; // return sum of dice
}