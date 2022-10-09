#include "names.h"
#include "positions.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SEED 2021
// array that stores the possible points from positions.h
int points[7] = { 0, 0, 10, 10, 15, 5, 5 };

// array that stores players points
int totalPointsArr[10];

// declaring functions
int roll(int i);
int checkMaxScore();

bool rungame = true;
// main function
int main(void) {
    // empty var for input value from user
    int totalPlayers = 0;

    //asking for user input
    printf("How many players? ");
    scanf("%d", &totalPlayers);

    // checks if user inputted valid amount or else it uses 2
    if (totalPlayers > 10 || totalPlayers < 2) {
        printf("Invalid number of players. Using 2 instead.\n");
        totalPlayers = 2;
    }

    // empty var for user input
    int seed = 0;

    // asking for seed from user
    printf("Random seed: ");
    scanf("%d", &seed);
    if (seed < 0) {
        printf("Invalid random seed. Using 2021 instead.\n");
        seed = SEED;
    }
    srandom(seed);

    int score = 0;
    int name = 0;
    while (rungame) {
        // iterates through names.h for the amount declared by the user
        for (int i = 0; i < totalPlayers; i++) {
            printf("%s rolls the pig...", names[i]);
            score = roll(i);
            name = i;
            if (score >= 100) {
                rungame = false;
                break;
            }
        }
    }
    printf("\n%s wins with %d points!\n", names[name], score);
    return 0;
}

// functions that takes rolls and makes points
int roll(int i) {
    bool turn = true;
    while (turn) {
        Position num = pig[random() % 7];
        if (num == RAZORBACK) {
            printf(" pig lands on back");

            int addp = totalPointsArr[i];
            addp += 10;
            totalPointsArr[i] = addp;
        } else if (num == TROTTER) {
            printf(" pig lands upright");

            int addp = totalPointsArr[i];
            addp += 10;
            totalPointsArr[i] = addp;
        } else if (num == SNOUTER) {
            printf(" pig lands on snout");

            int addp = totalPointsArr[i];
            addp += 15;
            totalPointsArr[i] = addp;
        } else if (num == JOWLER) {
            printf(" pig lands on ear");

            int addp = totalPointsArr[i];
            addp += 5;
            totalPointsArr[i] = addp;
        } else if (num == SIDE) {
            printf(" pig lands on side\n");
            turn = false;
            break;
        }
        if (totalPointsArr[i] >= 100) {
            rungame = false;
            turn = false;
            break;
        }
    }
    int score = totalPointsArr[i];
    return score;
}

int checkMaxScore() {
    int pts = totalPointsArr[0];

    for (int n = 1; 1 < n; n++) {
        if (totalPointsArr[n] > pts) {
            pts = totalPointsArr[n];
        }
    }
    return pts;
}
