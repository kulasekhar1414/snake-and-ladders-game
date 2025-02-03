#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINNING_POSITION 100

// Function to roll the dice and return a random value between 1 and 6
int rollDice() {
    return (rand() % 6) + 1;
}

// Function to update player's position based on snakes and ladders
int updatePosition(int position) {
    // Snakes and Ladders board configuration
    // Format: position -> new position
    int snakesAndLadders[] = {
        16, 6,   // Snake from 16 to 6
        47, 26,  // Snake from 47 to 26
        49, 11,  // Snake from 49 to 11
        56, 53,  // Snake from 56 to 53
        62, 19,  // Snake from 62 to 19
        64, 60,  // Snake from 64 to 60
        87, 24,  // Snake from 87 to 24
        93, 73,  // Snake from 93 to 73
        95, 75,  // Snake from 95 to 75
        98, 78,  // Snake from 98 to 78
        1, 38,   // Ladder from 1 to 38
        4, 14,   // Ladder from 4 to 14
        9, 31,   // Ladder from 9 to 31
        21, 42,  // Ladder from 21 to 42
        28, 84,  // Ladder from 28 to 84
        36, 44,  // Ladder from 36 to 44
        51, 67,  // Ladder from 51 to 67
        71, 91,  // Ladder from 71 to 91
        80, 100  // Ladder from 80 to 100
    };

    // Check if there's a snake or ladder at the current position
    for (int i = 0; i < 20; i++) {
        if (position == snakesAndLadders[2 * i]) {
            position = snakesAndLadders[2 * i + 1];
            break;
        }
    }
    return position;
}

int main() {
    int player1Pos = 0, player2Pos = 0;
    int diceRoll;
    int currentPlayer = 1;  // 1 for Player 1, 2 for Player 2

    // Initialize random number generator
    srand(time(0));

    printf("Welcome to the Snakes and Ladders Game!\n");

    // Game loop
    while (player1Pos < WINNING_POSITION && player2Pos < WINNING_POSITION) {
        if (currentPlayer == 1) {
            printf("\nPlayer 1's turn\n");
            printf("Press Enter to roll the dice...");
            getchar();

            diceRoll = rollDice();
            printf("Player 1 rolled a %d\n", diceRoll);
            player1Pos += diceRoll;

            if (player1Pos > WINNING_POSITION) {
                player1Pos = WINNING_POSITION;  // Player cannot go beyond 100
            }

            player1Pos = updatePosition(player1Pos);
            printf("Player 1 is now at position %d\n", player1Pos);
            currentPlayer = 2;
        } else {
            printf("\nPlayer 2's turn\n");
            printf("Press Enter to roll the dice...");
            getchar();

            diceRoll = rollDice();
            printf("Player 2 rolled a %d\n", diceRoll);
            player2Pos += diceRoll;

            if (player2Pos > WINNING_POSITION) {
                player2Pos = WINNING_POSITION;  // Player cannot go beyond 100
            }

            player2Pos = updatePosition(player2Pos);
            printf("Player 2 is now at position %d\n", player2Pos);
            currentPlayer = 1;
        }
    }

    // Declare winner
    if (player1Pos == WINNING_POSITION) {
        printf("\nPlayer 1 wins! Congratulations!\n");
    } else {
        printf("\nPlayer 2 wins! Congratulations!\n");
    }

    return 0;
}
