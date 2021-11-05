// Figure 7.24 version 2: fig07_24v2.c
// Card shuffling and dealing

// Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUIT 4 // Represents the number of suits
#define FACE 13 // Represents the number of faces
#define CARDS 52 // Represents the number of playing cards

void shuffle(unsigned int par_deck[SUIT][FACE]);

void deal(unsigned int par_deck[SUIT][FACE],
    const char *par_suits[SUIT],
    const char *par_faces[FACE]);

int main(void)
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize suit array
    const char *suits[SUIT] = {
        "Hearts", "Spades", "Clubs", "Diamonds"};

    // Initialize face array
    const char *faces[FACE] = {
        "A", "Deuce", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    // Initialize deck array
    unsigned int deck[SUIT][FACE] = {0};

    shuffle(deck); // Shuffle the deck
    
    // Print the shuffled deck
    puts("Shuffled deck:");
    for (size_t row = 0; row < SUIT; ++row) {
        for (size_t col = 0; col < FACE; ++col) {
            printf("%-4d", deck[row][col]);
        }
        puts("");
    }

    puts("\nDealt cards: ");
    deal(deck, suits, faces); // Deal 52 cards
}

// Select a slot of deck randomly and insert the order
// for which the slot will be dealt later on
void shuffle(unsigned int par_deck[SUIT][FACE])
{
    // Access the 52 slots of the deck
    for (unsigned int order = 1; order <= CARDS; ++order) {

        // Column and row numbers
        int row, col;

        // Choose new random location until unoccupied slot found
        do {
            row = 0 + rand() % SUIT;
            col = 0 + rand() % FACE;
        } while (par_deck[row][col] != 0);

        // Insert card number in the slot
        par_deck[row][col] = order;
    }
}

// Deal 52 playing cards in order
void deal(unsigned int par_deck[SUIT][FACE],
    const char *par_suits[SUIT],
    const char *par_faces[FACE])
{
    unsigned int search = 0; // Initialize number of searches
    unsigned int card_num = 1; // Initialize the number of cards dealt so far
    unsigned int card_found = 0; // Indicates if card is already found

    // Access the 52 slots of the deck
    for (unsigned int order = 1; order <= CARDS; ++order) {

        // Loop through each suit
        for (size_t row = 0; row < SUIT; ++row) {

            // Loop through each face
            for (size_t col = 0; col < FACE; ++col) {
                
                ++search; // Increment number of searches made

                // If slot contains desired card number
                if (par_deck[row][col] == order) {

                    // Print the face and suit of card
                    printf("Card %d: %9s of %-5s\n", card_num,
                        par_suits[row], par_faces[col]);

                    ++card_num; // Increment number of cards dealt
                    card_found = 1; // Desired card number is found
                    break; // Break searching through each face
                }
            }

            // Break searching through each suit
            if (card_found) {
                card_found = 0;
                break;
            }
        }
    }

    printf("\nNumber of searches: %u\n\n", search);
}