#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int imageA[8][8];
    int imageB[8][8];
    int i, j;

    srand(time(0));

    printf("Original Image:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            imageA[i][j] = rand() % 256;
            printf("%3d ", imageA[i][j]);
        }
        printf("\n");
    }

    printf("\nBrightened Image:\n");
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            imageB[i][j] = imageA[i][j] + 20;
            if (imageB[i][j] > 255)
                imageB[i][j] = 255;
            printf("%3d ", imageB[i][j]);
        }
        printf("\n");
    }

    return 0;
}
