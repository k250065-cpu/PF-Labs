#include <stdio.h>

int main() {
	
    int choice, course;

    printf("Select Department\n");
    printf("1. Computer Science (CS)\n");
    printf("2. Electrical Engineering (EE)\n");
    printf("3. Business Administration (BBA)\n");
    printf("Enter your choice (1-3) : ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("CS Courses\n");
            printf("1. Data Sciences\n 2. Artificial Intelligence\n 3. Cyber Security\n");
            printf("Select a course : ");
            scanf("%d", &course);
            switch(course) {
                case 1: printf("Your Selected Course : Data Sciences\n"); break;
                case 2: printf("Your Selected Course : Artificial Intelligence\n"); break;
                case 3: printf("Your Selected Course: Cyber Security\n"); break;
                default: printf("Invalid Course\n");
            }
            break;
        case 2:
            printf("EE Courses\n");
            printf("1. Electrical Circuits\n 2. Electronics\n 3. Digital Electronics\n");
            printf("Select a course : ");
            scanf("%d", &course);
            switch(course) {
                case 1: printf("Your Selected Course : Electrical Circuits\n"); break;
                case 2: printf("Your Selected Course : Electronics\n"); break;
                case 3: printf("Your Selected Course : Digital Electronics\n"); break;
                default: printf("Invalid Course\n");
            }
            break;
        case 3:
            printf("BBA Courses\n");
            printf("1. Marketing\n 2. Finance\n 3. HR Management\n");
            printf("Select a course : ");
            scanf("%d", &course);
            switch(course) {
                case 1: printf("Your Selected Course : Marketing\n"); break;
                case 2: printf("Your Selected Course : Finance\n"); break;
                case 3: printf("Your Selected Course : HR Management\n"); break;
                default: printf("Invalid Course\n");
            }
            break;
        default:
            printf("Invalid Department\n");
    }

    return 0;
}

