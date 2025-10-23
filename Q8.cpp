#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i = 0, check = 0;

    printf("Enter First String: ");
    scanf("%s", str1);
    printf("Enter Second String: ");
    scanf("%s", str2);

    while(str1[i] != '\0' && str2[i] != '\0') {
        if(str1[i] != str2[i]) {
            check = 1;
            break;
        }
        i++;
    }

    if(check == 0 && str1[i] == '\0' && str2[i] == '\0')
        printf("Strings are Equal.\n");
    else
        printf("Strings are Not Equal.\n");

    return 0;
}
