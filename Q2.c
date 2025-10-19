#include <stdio.h>

int main() {
	
    int num, result = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        result = result * 10 + (num % 10);
        num = num / 10;
    }

    printf("Reversed Number: %d\n", result);
    return 0;
}

