#include <stdio.h>

int main() {
	
    int a, b, c;

    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    if ((a > b && a < c) || (a > c && a < b)) {
        printf("The second largest number is %d\n", a);
    }
    else if ((b > a && b < c) || (b > c && b < a)) {
        printf("The second largest number is %d\n", b);
    }
    else if ((c > a && c < b) || (c > b && c < a)) {
        printf("The second largest number is %d\n", c);
    }

    return 0;
}



