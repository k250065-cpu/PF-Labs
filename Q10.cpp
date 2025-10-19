#include <stdio.h>

int main() {

    int num;

    printf("Enter the number of rows : ");
    scanf("%d", &num);

    for(int i = 1; i <= num; i += 2) {
        for(int j = 1; j <= (num - i) / 2; j++) {
            printf(" ");
        }
        for(int j = 1; j <= i; j++) {
            if(j == 1 || j == i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for(int i = num - 2; i >= 1; i -= 2) {
        for(int j = 1; j <= (num - i) / 2; j++) {
            printf(" ");
        }
        for(int j = 1; j <= i; j++) {
            if(j == 1 || j == i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

