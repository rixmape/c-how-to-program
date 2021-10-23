// Exercise 6.20: ex06_20.c
// Simulating 1000 games of craps.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GAME 1000 // Number of games

// Enumeration constants represent game status
enum Status {CONTINUE, WON, LOST};

int roll_dice(void);

int main(void)
{
    // Counts the games won on the first roll
    // up to those wins made after the twentieth roll
    int wins[22] = {0};

    // Counts the games lost on the first roll
    // up to those losses made after the twentieth roll
    int losses[22] = {0};

    // Counts the total number of rolls made out of all games
    int len_roll = 0;

    // Seed the random number generator using current time
    srand(time(NULL));

    // Play 1000 games of craps
    for (unsigned int play = 0; play < GAME; ++play) {

        int my_point; // Player must take this point to win
        enum Status game_status; // Can contain CONTINUE, WON or LOST
        int sum = roll_dice(); // First roll of the dice

        // Determine game status based on sum of dice
        switch(sum) {

            // Win on first roll
            case 7:
            case 11:
                game_status = WON;
                ++wins[1]; // Start recording wins at second element
                break;

            // Lose on first roll
            case 2:
            case 3:
            case 12:
                game_status = LOST;
                ++losses[1]; // Start recording losses at second element
                break;

            // Remember point
            default:
                game_status = CONTINUE; // Player should keep rolling
                my_point = sum; // Remember the point
                break;
        }

        int roll = 2; // Track the number of succeeding rolls

        // While game not complete
        while (CONTINUE == game_status) { // Player should keep rolling
            sum = roll_dice(); // Roll dice again
        
            // Use temporary variable to store the current number
            // of rolls made to maintain its current value
            int temp_roll = roll;

            // Limit temp_roll to the size of arrays wins and losses
            if (temp_roll > 21) {
                temp_roll = 21;
            }

            // Determine game status
            if (sum == my_point) { // Won by making point
                ++wins[temp_roll];
                game_status = WON;
                break; // Break immediately to maintain current number of roll
            }
            else {
                if (7 == sum) { // Lose by rolling 7
                    ++losses[temp_roll];
                    game_status = LOST;
                    break;
                }
            }

            ++roll; // Increment the number of rolls made for the current game
        }

        // Increment the number of rolls made from the 1st game
        len_roll += roll;
    }

    // Display the number of games won and lost at each nth roll
    printf("\n\n%7s%7s%7s\n", "ROLLS", "WON", "LOST");
    for (unsigned int roll = 1; roll < 22; ++roll) {

        // Use special format for rolls made after the twentieth roll
        if (roll == 21) {
            printf("    >20%7d%7d\n", wins[roll], losses[roll]);
        }
        
        // Print the number of roll and the wins and losses at that roll
        else {
            printf("%7d%7d%7d\n", roll, wins[roll], losses[roll]);
        }
    }

    
    // Compute the chance of winning craps
    int total_wins;
    for (unsigned int i = 0; i < 22; ++i) {
        total_wins += wins[i];
    }
    float win_chance = (float) total_wins / GAME * 100;

    // Display the chance of winning craps
    printf("\nChance of winning in playing %d games: %.2f%%\n",
        GAME, win_chance);

    // Display average length of playing craps
    printf("\nTotal number of rolls made out of %d games: %d",
        GAME, len_roll);
    printf("\nAverage length of playing craps: %d", len_roll / GAME);
}

// roll dice, calculate sum and display results
int roll_dice(void)
{
    int die1 = 1 + (rand() % 6); // pick random die1 value
    int die2 = 1 + (rand() % 6); // pick random die2 value

    return die1 + die2; // return sum of dice
}

