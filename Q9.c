#include <stdio.h>

int main() {
	
    int num, even = 0, odd = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while(num > 0) {
        int a = num % 10; 
        if(a % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        num /= 10; 
    }

    printf("Even digits: %d\n", even);
    printf("Odd digits: %d\n", odd);

    return 0;
}

