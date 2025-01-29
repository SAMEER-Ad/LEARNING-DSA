#include <stdio.h>

void printHeart() {
    int i, j;
    int n = 10; // size of the heart

    // Upper part of the heart
    for (i = n / 2; i <= n; i += 2) {
        for (j = 1; j < n - i; j += 2) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower part of the heart
    for (i = n; i >= 1; i--) {
        for (j = i; j < n; j++) {
            printf(" ");
        }
        for (j = 1; j <= (i * 2) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}
void printFish() {
    int i, j;
    int n = 10; // size of the fish

    // Upper part of the fish
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                printf(" ");
            } else if (i == 1 && j == n) {
                printf(" ");
            } else if (i == 2 && j == 1) {
                printf(" ");
            } else if (i == 2 && j == n) {
                printf(" ");
            } else if (i == 3 && j == 1) {
                printf(" ");
            } else if (i == 3 && j == n) {
                printf(" ");
            } else if (i == 4 && j == 1) {
                printf(" ");
            } else if (i == 4 && j == n) {
                printf(" ");
            } else if (i == 5 && j == 1) {
                printf(" ");
            } else if (i == 5 && j == n) {
                printf(" ");
            } else if (i == 6 && j == 1) {
                printf(" ");
            } else if (i == 6 && j == n) {
                printf(" ");
            } else if (i == 7 && j == 1) {
                printf(" ");
            } else if (i == 7 && j == n) {
                printf(" ");
            } else if (i == 8 && j == 1) {
                printf(" ");
            } else if (i == 8 && j == n) {
                printf(" ");
            } else if (i == 9 && j == 1) {
                printf(" ");
            } else if (i == 9 && j == n) {
                printf(" ");
            } else if (i == 10 && j == 1) {
                printf(" ");
            } else if (i == 10 && j == n) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}


int main() {
    printHeart();
    printFish();
    return 0;
}