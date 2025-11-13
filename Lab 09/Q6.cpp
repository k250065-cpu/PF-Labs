#include <stdio.h>
#include <string.h>

char* formatName(char *first, char *last) {
    static char fullName[100];
    strcpy(fullName, first);
    strcat(fullName, " ");
    strcat(fullName, last);
    return fullName;
}

int main() {
    char first[50], last[50];
    
    printf("Enter first name: ");
    scanf("%s", first);
    printf("Enter last name: ");
    scanf("%s", last);

    printf("Full Name: %s\n", formatName(first, last));
    
    return 0;
}
