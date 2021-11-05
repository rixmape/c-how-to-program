/*
 * Filename: ex07_12.c
 * Author: Rix Mape
 * 
 * Title: Card shuffling and dealing
 * Description: Modified fig07_24.c program. Added card-dealing function
 * that deals a five-card poker hand. Then determine the type of hand.
 */

// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUIT 4
#define FACE 13
#define CARD_IN_DECK 52
#define CARD_IN_HAND 5
#define CARD_VAL 2 // Properties of a card (i.e. face and suit)

void shuffle(unsigned int w_deck[][FACE]); // Shuffling modifies w_deck
void deal(unsigned int w_deck[][FACE], const char * w_faces[],
    const char *w_suits[]); // Dealing doesn't modify the arrays

int main(void)
{
    // Initialize deck array
    unsigned int deck[SUIT][FACE] = {0};

    srand(time(NULL)); // Seed random-number generator
    shuffle(deck); // Shuffle the deck

    // Initialize suits array
    const char *suits[SUIT] = {
        "Hearts", "Diamonds", "Clubs", "Spades"};

    // Initialize faces array
    const char *faces[FACE] = {
        "A", "Deuce", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    deal(deck, faces, suits); // Deal the deck
}

// Shuffle cards in deck
void shuffle(unsigned int w_deck[][FACE])
{
    // For each of the cards, choose slot of deck randomly
    for (size_t card = 1; card <= CARD_IN_DECK; ++card) {
        size_t row;
        size_t column;

        // Choose new random location until unoccupied slot found
        do {
            row = rand() % SUIT;
            column = rand() % FACE;
        } while (w_deck[row][column] != 0);

        // Place card number in chosen slot of deck
        w_deck[row][column] = card;
    }
}

// Deal cards in deck
void deal(unsigned int w_deck[][FACE], const char * w_faces[],
    const char * w_suits[])
{
    // Function prototype for evaluating hand
    void eval_hand(const size_t w_hand[][CARD_VAL]);

    size_t hand[CARD_IN_HAND][CARD_VAL]; // Array for cards in current hand
    size_t card_dealt = 0; // Counter for cards dealt so far
    int hand_dealt = 1; // Counter for hands dealt so far

    // Deal each of the cards
    for (size_t card = 1; card <= CARD_IN_DECK; ++card) {

        // If there are five cards in hand, evaluate current hand
        if (card_dealt == CARD_IN_HAND) {
            
            // Evaluate current hand
            printf("HAND %d:", hand_dealt);
            eval_hand(hand);

            // Loop through each card in hand
            for (size_t i = 0; i < CARD_IN_HAND; ++i) {            
                // Print current hand
                printf("\n  CARD %lu: %s of %s", i + 1, w_suits[hand[i][0]],
                    w_faces[hand[i][1]]);
            }

            puts("\n");

            ++hand_dealt; // Increment hand dealt for current deck
            card_dealt = 0; // Reset number of cards dealt for current hand
        }

        // Loop through rows of w_deck
        for (size_t row = 0; row < SUIT; ++row) {

            // Loop through columns of w_deck for current row
            for (size_t column = 0; column < FACE; ++column) {

                // If slot contains current card, add card to hand
                if (w_deck[row][column] == card) {
                    
                    // Store the suit and face of card to array hand
                    hand[card_dealt][0] = row;
                    hand[card_dealt][1] = column;

                    ++card_dealt; // Increment card dealt for current hand
                }
            }
        }
    }
}

// Evaluate a hand
void eval_hand(const size_t w_hand[][CARD_VAL])
{
    int get_pair(const size_t hand[][CARD_VAL]);
    int get_kind(const size_t hand[][CARD_VAL]);

    // Evaluate for any pair
    int pair = get_pair(w_hand);
    if (pair) {
        printf(" [%d pair%c]", pair, pair == 2 ? 's' : '\0');
    }

    // Evaluate for same kinds
    int kind = get_kind(w_hand);
    if (kind == 5) {
        printf("%s", " [flush]");
    }
    else if (kind == 4 || kind == 3) {
        printf(" [%d of a kind]", kind);
    }

    // Check for a straight
}

// Return number of pairs in hand
int get_pair(const size_t hand[][CARD_VAL])
{
    int count_pair = 0; // Counter for number of pairs

    // Loop through each card of current hand
    for (size_t i = 0; i < (CARD_IN_HAND - 1); ++i) {

        // Compare current card to other cards
        for (size_t j = (i + 1); j < CARD_IN_HAND; ++j) {

            // If current card is the same as other card,
            // increment frequency of pairs
            if (hand[i][1] == hand[j][1]) {
                ++count_pair;
            }
        }
    }

    return count_pair;
}

// Return number of kinds in hand
int get_kind(const size_t hand[][CARD_VAL]) {
    
    // Initialize array for the suits and frequency of each suit in hand
    int kinds[CARD_IN_HAND][2] = {0};

    // Loop through each card in hand
    for (size_t i = 0; i < CARD_IN_HAND; ++i) {

        // Loop through each slot in kinds
        for (size_t j = 0; j < CARD_IN_HAND; ++j) {

            int suit = hand[i][0] + 1; // Suit of current card

            // If suit is stored already, increment its frequency
            if (suit == kinds[j][0]) {
                ++kinds[j][1];
                break; // Break loop to disregard succeeding slots
            }

            // Else if current suit is not stored yet,
            // insert the suit to the slot and increment its frequency
            else if (kinds[j][0] == 0) {
                kinds[j][0] = suit;
                ++kinds[j][1];
                break; // Break loop to disregard succeeding slots
            }
        }
    }
    
    int max_freq = 0; // Maximum suit frequency

    // Loop through each suit in kinds
    for (size_t i = 0; i < CARD_IN_HAND; ++i) {
        if (max_freq < kinds[i][1]) {
            max_freq = kinds[i][1];
        }
    }

    return max_freq;
}