#include <stdio.h>

int main() {
	
    int pin, temp, sum = 0;

    printf("Enter 4-digit PIN: ");
    scanf("%d", &pin);

    temp = pin;
    
    while (temp > 0) {
        sum = sum + (temp % 10);
        temp = temp / 10;
    }

    if (sum > 10)
        printf("Strong PIN (Sum = %d)\n", sum);
    else
        printf("Weak PIN (Sum = %d)\n", sum);

    return 0;
}

