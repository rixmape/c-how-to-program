// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(unsigned int w_deck[][FACES]); // Shuffling modifies w_deck
void deal(unsigned int w_deck[][FACES], const char *w_face[],
    const char *w_suit[]); // Dealing doesn't modify the arrays

int main(void)
{
    // Initialize deck array
    unsigned int deck[SUITS][FACES] = {0};

    srand(time(NULL)); // Seed random-number generator
    shuffle(deck); // Shuffle the deck

    // Initialize suit array
    const char *suit[SUITS] = {
        "Hearts", "Diamonds", "Clubs", "Spades"};

    // Initialize face array
    const char *face[FACES] = {
        "A", "Deuce", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    deal(deck, face, suit); // Deal the deck
}

// Shuffle cards in deck
void shuffle(unsigned int w_deck[][FACES])
{
    // For each of the cards, choose slot of deck randomly
    for (size_t card = 1; card <= CARDS; ++card) {
        size_t row;
        size_t column;

        // Choose new random location until unoccupied slot found
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (w_deck[row][column] != 0);

        // Place card number in chosen slot of deck
        w_deck[row][column] = card;
    }
}

// Deal cards in deck
void deal(unsigned int w_deck[][FACES], const char *w_face[],
    const char *w_suit[])
{
    // Deal each of the cards
    for (size_t card = 1; card <= CARDS; ++card) {
        // Loop through rows of w_deck
        for (size_t row = 0; row < SUITS; ++row) {
            // Loop through columns of w_deck for current row
            for (size_t column = 0; column < FACES; ++column) {
                // If slot contains current card, display card
                if (w_deck[row][column] == card) {
                    printf("%5s of %-8s%c", w_face[column], w_suit[row],
                        card % 2 == 0 ? '\n' : '\t'); // 2-column format
                }
            }
        }
    }
}