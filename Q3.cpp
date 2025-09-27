#include <stdio.h>

int main() {
	
    int choice1, choice2;

    printf("Library Management System\n");
    printf("1. Manage Books\n 2. Manage Magazines\n");
    printf("Enter your choice : ");
    scanf("%d", &choice1);

    switch (choice1) {
        case 1:
            printf("Manage Books\n");
            printf("1. Issue Book\n 2. Return Book\n");
            printf("Enter your choice : ");
            scanf("%d", &choice2);
            switch (choice2) {
                case 1:
                    printf("Book Issued\n");
                    break;
                case 2:
                    printf("Book Returned\n");
                    break;
                default:
                    printf("Invalid Choice\n");
            }
            break;
        case 2:
            printf("Manage Magazines\n");
            printf("1. Issue Magazine\n 2. Return Magazine\n");
            printf("Enter your choice : ");
            scanf("%d", &choice2);
            switch (choice2) {
                case 1:
                    printf("Magazine Issued\n");
                    break;
                case 2:
                    printf("Magazine Returned\n");
                    break;
                default:
                    printf("Invalid Choice\n");
            }
            break;
        default:
            printf("Invalid Choice\n");
    }

    return 0;
}

