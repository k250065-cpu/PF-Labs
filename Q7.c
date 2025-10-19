#include <stdio.h>
#include <string.h>

int main() {
	
    char str[100], rStr[100];
    int len, i, a, p = 1;

    printf("Enter a string: ");
    scanf("%s", &str);

    len = strlen(str);
    
    for(i = 0, a = len - 1; a >= 0; i++, a--) {
        rStr[i] = str[a];
    }
    rStr[i] = '\0';

    for(i = 0; i < len; i++) {
        if(str[i] != rStr[i]) {
            p = 0;
            break;
        }
    }

    if(p) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

