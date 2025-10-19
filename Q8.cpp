#include <stdio.h>

int factorial(int num) {
    int fact = 1;
    for(int i = 1; i <= num; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
	
    int num;

    printf("Enter the value of n: ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        int catalanNumber = factorial(2 * i) / (factorial(i + 1) * factorial(i));
        printf("Catalan number %d: %d\n", i + 1, catalanNumber);
    }

    return 0;
}

