#include <stdio.h>

int main() {
	
    int age, movie;

    printf("Enter Your Age : ");
    scanf("%d", &age);
    
    if (age < 12) {
        printf("Child Ticket");
    } else if (age <= 60) {
        printf("Adult Ticket");
    } else {
        printf("Senior Citizen Ticket");
    }

    printf("\n Select Movie :\n");
    printf("1. Action\n 2. Comedy\n 3. Horror\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &movie);

    switch(movie) {
        case 1:
            printf("Action Movie Booked\n");
            break;
        case 2:
            printf("Comedy Movie Booked\n");
            break;
        case 3:
            printf("Horror Movie Booked\n");
            break;
        default:
            printf("Invalid Selection\n");
    }

    return 0;
}

