#include <stdio.h>

int main() {
	
    char username[10], password[10];

    printf("Enter username : ");
    scanf("%s", &username);
    printf("Enter password : ");
    scanf("%s", &password);

    if (username[0] == 'a' && username[1] == 'd' && username[2] == 'm' && username[3] == 'i' && username[4] == 'n') {
        if (password[0] == '1' && password[1] == '2' && password[2] == '3' && password[3] == '4') {
            printf("Login Successful\n");
        } else {
            printf("Incorrect password\n");
        }
    } else {
        printf("Invalid username\n");
    }

    return 0;
}

