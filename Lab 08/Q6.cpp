#include <stdio.h>

int main() {
    int board[3][3];
    int i, j;

    printf("Enter Elements of The Game Board:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    printf("\nOriginal Game Board:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            int temp = board[i][j];
            board[i][j] = board[j][i];
            board[j][i] = temp;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3 / 2; j++) {
            int temp = board[i][j];
            board[i][j] = board[i][3 - 1 - j];
            board[i][3 - 1 - j] = temp;
        }
    }

    printf("\nRotated Game Board (Clockwise 90 Degrees):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
