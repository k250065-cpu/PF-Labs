#include <stdio.h>

#define SECTIONS 2
#define SHELVES 3
#define ITEMS 4

int main() {
    int inventory[SECTIONS][SHELVES][ITEMS];
    int section[SECTIONS] = {0};
    int shelf[SECTIONS][SHELVES] = {0};
    int i, j, k;

    printf("Enter Quantities for Each Section, Shelf, and Item:\n");
    for (i = 0; i < SECTIONS; i++) {
        printf("\nSection %d:\n", i + 1);
        for (j = 0; j < SHELVES; j++) {
            printf("  Shelf %d:\n", j + 1);
            for (k = 0; k < ITEMS; k++) {
                printf("    Item %d Quantity: ", k + 1);
                scanf("%d", &inventory[i][j][k]);
            }
        }
    }

    for (i = 0; i < SECTIONS; i++) {
        for (j = 0; j < SHELVES; j++) {
            for (k = 0; k < ITEMS; k++) {
                section[i] += inventory[i][j][k];
                shelf[i][j] += inventory[i][j][k];
            }
        }
    }

    printf("\nTotal Items Per Section:\n");
    for (i = 0; i < SECTIONS; i++) {
        printf("Section %d Total: %d\n", i + 1, section[i]);
    }

    int shelfTotal = 0;
    int maxSection = 0, maxShelf = 0;
    for (i = 0; i < SECTIONS; i++) {
        for (j = 0; j < SHELVES; j++) {
            if (shelf[i][j] > shelfTotal) {
                shelfTotal = shelf[i][j];
                maxSection = i;
                maxShelf = j;
            }
        }
    }

    printf("\nShelf With The Highest Total Quantity:\n");
    printf("Section %d, Shelf %d with %d Items\n",
           maxSection + 1, maxShelf + 1, shelfTotal);

    return 0;
}
