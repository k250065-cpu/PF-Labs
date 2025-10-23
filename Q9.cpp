#include <stdio.h>

int main() {
    char str[200];
    int i = 0, count = 0, length = 0, start = 0, max = 0;

    printf("Enter a Sentence: ");
    gets(str);

    while(1) {
        if(str[i] == ' ' || str[i] == '\0') {
            if(count > length) {
                length = count;
                max = start;
            }
            count = 0;
            start = i + 1;
        } else {
            count++;
        }

        if(str[i] == '\0')
            break;

        i++;
    }

    printf("Longest Word: ");
    for(i = max; i < max + length; i++)
        printf("%c", str[i]);
    printf("\nLength = %d\n", length);

    return 0;
}
