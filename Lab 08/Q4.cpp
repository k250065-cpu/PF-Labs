#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    printf("Enter Number of Rows and Columns: ");
    scanf("%d %d", &rows, &cols);

    int hall[rows][cols];
    int i, j;
    srand(time(0));

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            hall[i][j] = rand() % 2;
        }
    }

    int total = 0;
    int max = 0, row = 0;

    for (i = 0; i < rows; i++) {
        int empty = 0;
        for (j = 0; j < cols; j++) {
            printf("%d ", hall[i][j]);
            if (hall[i][j] == 0) empty++;
        }
        printf("\n");

        total += empty;
        if (empty > max) {
            max = empty;
            row = i + 1;
        }
    }

    printf("\nTotal Available Seats: %d\n", total);
    printf("Row with Most Empty Seats: Row %d (%d empty seats)\n", row, max);

    return 0;
}
