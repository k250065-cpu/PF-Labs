#include <stdio.h>

int main() {
	
    int check, count1, count2, prime;

    printf("Enter a number: ");
    scanf("%d", &check);

    prime = 1;
    if (check <= 1)
        prime = 0;
    else {
        for (count1 = 2; count1 <= check / 2; count1++) {
            if (check % count1 == 0) {
                prime = 0;
                break;
            }
        }
    }

    if (prime)
        printf("%d is a Prime Number.\n", check);
    else
        printf("%d is NOT a Prime Number.\n", check);

    printf("Prime numbers from 1 to %d:\n", check);
    for (count1 = 2; count1 <= check; count1++) {
        prime = 1;
        for (count2 = 2; count2 <= count1 / 2; count2++) {
            if (count1 % count2 == 0) {
                prime = 0;
                break;
            }
        }
        if (prime)
            printf("%d ", count1);
    }
    printf("\n");

    return 0;
}

