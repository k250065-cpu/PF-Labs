#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEVELS 50
#define MAX_CHAR 150

int countWords(char *str) {
    int count = 0, inWord = 0;
    while (*str) {
        if (*str != ' ' && !inWord) {
            inWord = 1;
            count++;
        } else if (*str == ' ') {
            inWord = 0;
        }
        str++;
    }
    return count;
}

void loadLevels(char levels[][MAX_CHAR], int *count) {
    FILE *fp = fopen("levels.txt", "r");
    *count = 0;

    if (!fp) return;

    while (*count < MAX_LEVELS && fgets(levels[*count], MAX_CHAR, fp)) {
        levels[*count][strcspn(levels[*count], "\n")] = '\0';
        (*count)++;
    }
    fclose(fp);
}

void saveLevels(char levels[][MAX_CHAR], int count) {
    FILE *fp = fopen("levels.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s\n", levels[i]);
    fclose(fp);
}

int searchLevel(char levels[][MAX_CHAR], int count, char *name) {
    for (int i = 0; i < count; i++)
        if (strcmp(levels[i], name) == 0)
            return i;
    return -1;
}

int main() {
    char levels[MAX_LEVELS][MAX_CHAR];
    int count = 0;
    char input[MAX_CHAR];
    int choice;

    loadLevels(levels, &count);

    while (1) {
        printf("\nLevel Menu:\n");
        printf("1. Add Level\n2. Delete Level\n3. Update Level\n4. Search Level\n-1. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == -1) break;

        switch (choice) {
            case 1:
                if (count >= MAX_LEVELS) {
                    printf("Storage Full!\n");
                    break;
                }
                printf("Enter Level Description (Max 7 Words): ");
                fgets(input, MAX_CHAR, stdin);
                input[strcspn(input, "\n")] = '\0';
                if (countWords(input) > 7) {
                    printf("Too Many Words!\n");
                } else {
                    strcpy(levels[count++], input);
                }
                break;

            case 2:
                printf("Enter Level To Delete: ");
                fgets(input, MAX_CHAR, stdin);
                input[strcspn(input, "\n")] = '\0';
                {
                    int index = searchLevel(levels, count, input);
                    if (index == -1)
                        printf("Not Found.\n");
                    else {
                        for (int i = index; i < count - 1; i++)
                            strcpy(levels[i], levels[i + 1]);
                        count--;
                    }
                }
                break;

            case 3:
                printf("Enter Level To Update: ");
                fgets(input, MAX_CHAR, stdin);
                input[strcspn(input, "\n")] = '\0';
                {
                    int index = searchLevel(levels, count, input);
                    if (index == -1) {
                        printf("Not Found.\n");
                    } else {
                        printf("Enter New Description: ");
                        fgets(levels[index], MAX_CHAR, stdin);
                        levels[index][strcspn(levels[index], "\n")] = '\0';
                        if (countWords(levels[index]) > 7) {
                            printf("Too Many Words. Update Cancelled.\n");
                        }
                    }
                }
                break;

            case 4:
                printf("Enter Level To Search: ");
                fgets(input, MAX_CHAR, stdin);
                input[strcspn(input, "\n")] = '\0';
                if (searchLevel(levels, count, input) != -1)
                    printf("Level Exists.\n");
                else
                    printf("Not Found.\n");
                break;

            default:
                printf("Invalid Option.\n");
        }
    }

    saveLevels(levels, count);
    printf("Changes Saved.\n");

    return 0;
}
