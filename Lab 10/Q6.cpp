#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOTES 200
#define MAX_LEN   150

int countWordInLine(char *line, char *word) {
    int count = 0;
    char *p = line;
    int wlen = strlen(word);

    while ((p = strstr(p, word)) != NULL) {
        if ((p == line || !isalnum(*(p - 1))) &&
            !isalnum(*(p + wlen))) {
            count++;
        }
        p += wlen;
    }
    return count;
}

void copyString(char *dest, char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int loadNotes(char notes[][MAX_LEN]) {
    FILE *fp = fopen("episodes.txt", "r");
    if (!fp) return 0;

    int count = 0;
    while (fgets(notes[count], MAX_LEN, fp)) {
        notes[count][strcspn(notes[count], "\n")] = '\0';
        count++;
    }
    fclose(fp);
    return count;
}

void saveNotes(char notes[][MAX_LEN], int count) {
    FILE *fp = fopen("episodes.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s\n", notes[i]);
    fclose(fp);
}

void addNote(char notes[][MAX_LEN], int *count, char *newNote) {
    copyString(notes[*count], newNote);
    (*count)++;
}

void deleteNote(char notes[][MAX_LEN], int *count, int index) {
    for (int i = index; i < *count - 1; i++)
        copyString(notes[i], notes[i + 1]);
    (*count)--;
}

void editNote(char notes[][MAX_LEN], int index, char *newText) {
    copyString(notes[index], newText);
}

void searchNotes(char notes[][MAX_LEN], int count, char *phrase) {
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < count; i++)
        if (strstr(notes[i], phrase))
            printf("%d: %s\n", i, notes[i]);
}

void countWordAll(char notes[][MAX_LEN], int count, char *word) {
    int total = 0;
    for (int i = 0; i < count; i++)
        total += countWordInLine(notes[i], word);

    printf("Word '%s' Appears %d Times Across All Notes.\n", word, total);
}

void displayNotes(char notes[][MAX_LEN], int count) {
    printf("\n--- NOTES ---\n");
    for (int i = 0; i < count; i++)
        printf("%d: %s\n", i, notes[i]);
}

int main() {
    char notes[MAX_NOTES][MAX_LEN];
    int count = loadNotes(notes);
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Add Note ");
        printf("2. Delete Note ");
        printf("3. Edit Note ");
        printf("4. Search Notes\n");
        printf("5. Count Word Across Notes ");
        printf("6. Show All Notes ");
        printf("0. Exit\n");
        printf("Enter Choice : ");

        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            char temp[MAX_LEN];
            printf("New Note : ");
            fgets(temp, MAX_LEN, stdin);
            temp[strcspn(temp, "\n")] = '\0';
            addNote(notes, &count, temp);

        } else if (choice == 2) {
            int index;
            printf("Delete Index : ");
            scanf("%d", &index);
            if (index >= 0 && index < count)
                deleteNote(notes, &count, index);

        } else if (choice == 3) {
            int index;
            char temp[MAX_LEN];
            printf("Edit Index : ");
            scanf("%d", &index);
            getchar();
            printf("New Text : ");
            fgets(temp, MAX_LEN, stdin);
            temp[strcspn(temp, "\n")] = '\0';
            editNote(notes, index, temp);

        } else if (choice == 4) {
            char phrase[MAX_LEN];
            printf("Search Phrase : ");
            fgets(phrase, MAX_LEN, stdin);
            phrase[strcspn(phrase, "\n")] = '\0';
            searchNotes(notes, count, phrase);

        } else if (choice == 5) {
            char word[50];
            printf("Word To Count : ");
            fgets(word, sizeof(word), stdin);
            word[strcspn(word, "\n")] = '\0';
            countWordAll(notes, count, word);

        } else if (choice == 6) {
            displayNotes(notes, count);
        }

    } while (choice != 0);

    saveNotes(notes, count);
    return 0;
}
