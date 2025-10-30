#include <stdio.h>
#include <ctype.h>

int main() {
    char words[3][10];
    int i, j, count = 0;

    printf("Enter 3 Words (each up to 9 letters):\n");
    for (i = 0; i < 3; i++) {
        scanf("%s", words[i]);
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; words[i][j] != '\0'; j++) {
            char ch = toupper(words[i][j]);
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                count++;
            }
        }
    }

    printf("\nTotal Number of Vowels: %d\n", count);
    return 0;
}
