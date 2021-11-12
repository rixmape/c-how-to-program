/*
 * Filename: ex07_13.c
 * Author: Rix Mape
 * 
 * Title: Card shuffling and dealing
 * Description: A program that deals two five-card poker hand,
 * evaluates each, and determines which is the better hand. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUIT 4
#define FACE 13
#define CARD_IN_DECK 52
#define CARD_IN_HAND 5
#define CARD_VAL 2 // Properties of a card (i.e. face and suit)
#define HAND_IN_DECK 10
#define HAND_TYPE 3

void shuffle(unsigned int w_deck[][FACE]);
void deal_hand(const unsigned int w_deck[][FACE], unsigned int w_hand[],
    unsigned int w_cards[][CARD_VAL], size_t hand_num);
void disp_hand(const int pair, const int kind, const int straight);

int main(void)
{
    // Initialize array for the card deck
    unsigned int deck[SUIT][FACE] = {0};

    srand(time(NULL)); // Seed random-number generator
    shuffle(deck); // Shuffle the deck

    // Initialize array for hands to be dealt
    unsigned int hands[HAND_IN_DECK][HAND_TYPE];

    // Initialize array for cards of each hand
    unsigned int hand_cards[HAND_IN_DECK][CARD_IN_HAND][CARD_VAL];

    // Deal two hands from the deck
    for (size_t i = 0; i < 2; ++i) {
        deal_hand(deck, hands[i], hand_cards[i], i + 1);
    }

    // Initialize array for types of suits
    const char *suits[SUIT] = {
        "Hearts", "Diamonds", "Clubs", "Spades"};

    // Initialize array for types of faces
    const char *faces[FACE] = {
        "A", "Deuce", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    // Loop through each hand that was dealt
    for (size_t i = 0; i < 2; ++i) {

        // Display type of hand
        printf("HAND %2lu: ", i + 1);
        disp_hand(hands[i][0], hands[i][1], hands[i][2]);
        
        // Display each card in hand
        for (size_t j = 0; j < CARD_IN_HAND; ++j) {
            size_t x = hand_cards[i][j][0];
            size_t y = hand_cards[i][j][1];
            printf("  CARD %lu: %s of %s\n", j + 1, suits[x], faces[y]);
        }

        puts("");
    }

    printf("%s", "Winning card: "); // Display winning card

    // Loop through each property of hand (i.e. pair, kind, straight)
    for (size_t i = 2; i >= 0; --i) {
        // Compare each hand
        if (hands[0][i] > hands[1][i]) {
            printf("%s", "Hand 1"); // Hand 1 is better
            break;
        }
        else if (hands[0][i] < hands[1][i]) {
            printf("%s", "Hand 2"); // Hand 2 is better
            break;
        }
        else {
            if (i == 0) { // If last property is reached
                printf("%s", "Draw!"); // Both hands are equal
                break;
            }
        }
    }

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

void deal_hand(const unsigned int w_deck[][FACE], unsigned int w_hand[],
    unsigned int w_cards[][CARD_VAL], size_t hand_num)
{
    unsigned int get_pair(const unsigned int w_hand[][CARD_VAL]);
    unsigned int get_kind(const unsigned int w_hand[][CARD_VAL]);
    unsigned int is_straight(const unsigned int w_hand[][CARD_VAL]);

    size_t card_dealt = 0;

    // Deal each of the cards
    for (size_t card = hand_num * 5 - 4; card <= hand_num * 5; ++card) {

        // If five cards are dealt so far, evaluate current hand
        if (card_dealt == CARD_IN_HAND - 1) {

            // Evaluate current hand
            w_hand[0] = get_pair(w_cards);
            w_hand[1] = get_kind(w_cards);
            w_hand[2] = is_straight(w_cards);
        }

        // Loop through rows of w_deck
        for (size_t row = 0; row < SUIT; ++row) {

            // Loop through columns of w_deck for current row
            for (size_t column = 0; column < FACE; ++column) {

                // If slot contains current card, add card to hand
                if (w_deck[row][column] == card) {
                    
                    // Insert current card to array hand
                    w_cards[card_dealt][0] = row;
                    w_cards[card_dealt][1] = column;

                    ++card_dealt; // Increment card dealt for current hand
                }
            }
        }
    }
}

// Return number of pairs in hand
unsigned int get_pair(const unsigned int w_hand[][CARD_VAL])
{
    unsigned int count_pair = 0; // Counter for number of pairs

    // Loop through each card of current hand
    for (size_t i = 0; i < (CARD_IN_HAND - 1); ++i) {

        // Compare current card to other cards
        for (size_t j = (i + 1); j < CARD_IN_HAND; ++j) {

            // If current card is the same as other card,
            // increment frequency of pairs
            if (w_hand[i][1] == w_hand[j][1]) {
                ++count_pair;
            }
        }
    }

    return count_pair;
}

// Return number of kinds in hand
unsigned int get_kind(const unsigned int w_hand[][CARD_VAL])
{
    // Initialize array for the suits and frequency of each suit in hand
    int kinds[CARD_IN_HAND][2] = {0};

    // Loop through each card in hand
    for (size_t i = 0; i < CARD_IN_HAND; ++i) {

        // Loop through each slot in kinds
        for (size_t j = 0; j < CARD_IN_HAND; ++j) {

            int suit = w_hand[i][0] + 1; // Suit of current card

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
    
    unsigned int max_freq = 0; // Maximum suit frequency

    // Loop through each suit in kinds
    for (size_t i = 0; i < CARD_IN_HAND; ++i) {
        if (max_freq < kinds[i][1]) {
            max_freq = kinds[i][1];
        }
    }

    return max_freq;
}

// Return 1 if hand is straight
unsigned int is_straight(const unsigned int w_hand[][CARD_VAL])
{
    // Get minimum face value
    int min = w_hand[0][1]; // Initialize min to face value of first card
    for (int i = 1; i < CARD_IN_HAND; ++i) { // Loop from second card
        if (min > w_hand[i][1]) {
            min = w_hand[i][1];
        }
    }

    unsigned int straight = 0; // Flag variable

    // Loop through each expected face values 
    for (int i = 0; i < CARD_IN_HAND; ++i) {

        // Loop through each card in hand
        for (int j = 0; j < CARD_IN_HAND; ++j) {

            // Compare current card to expected card
            if (w_hand[j][1] == min + i) {
                straight = 1; // Current card is expected card
                break; // Stop searching
            }
            else {
                straight = 0; // Current card is not expected card
            }
        }

        // If consecutive card is not in hand, break loop;
        // hand is not straight
        if (straight == 0) {
            break;
        }
    }

    return straight;
}

// Display type of hand
void disp_hand(int num_pair, int num_kind, int is_straight)
{
    if (num_pair) {
        printf(" [%d pair%c]", num_pair, num_pair == 2 ? 's' : '\0');
    }

    if (num_kind == 5) {
        printf("%s", " [flush]");
    }
    else if (num_kind == 4 || num_kind == 3) {
        printf(" [%d of a kind]", num_kind);
    }

    if (is_straight) {
        printf(" [straight]");
    }

    puts("");
}