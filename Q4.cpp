#include <stdio.h>

int main() {
	
    int category, item;

    printf("Online Food Ordering\n");
    printf("1. Fast Food\n 2. Drinks\n");
    printf("Enter your choice : ");
    scanf("%d", &category);

    switch (category) {
        case 1:
            printf("Fast Food\n");
            printf("1. Burger\n 2. Pizza\n 3. Fries\n");
            printf("Enter your choice : ");
            scanf("%d", &item);
            switch (item) {
                case 1:
                    printf("You ordered a Burger\n");
                    break;
                case 2:
                    printf("You ordered a Pizza\n");
                    break;
                case 3:
                    printf("You ordered Fries\n");
                    break;
                default:
                    printf("Invalid choice\n");
            }
            break;
        case 2:
            printf("Drinks\n");
            printf("1. Coke\n 2. Juice\n 3. Water\n");
            printf("Enter your choice : ");
            scanf("%d", &item);
            switch (item) {
                case 1:
                    printf("You ordered a Coke\n");
                    break;
                case 2:
                    printf("You ordered Juice\n");
                    break;
                case 3:
                    printf("You ordered Water\n");
                    break;
                default:
                    printf("Invalid choice\n");
            }
            break;
        default:
            printf("Invalid category\n");
    }

    return 0;
}

