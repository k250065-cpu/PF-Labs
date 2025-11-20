#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 10
#define MAX_TITLE_LEN 100

void loadSongs(char songs[][MAX_TITLE_LEN], int *count) {
    FILE *fp = fopen("playlist.txt", "r");
    *count = 0;

    if (!fp) return;

    while (*count < MAX_SONGS && fgets(songs[*count], MAX_TITLE_LEN, fp)) {
        songs[*count][strcspn(songs[*count], "\n")] = '\0';
        (*count)++;
    }
    fclose(fp);
}

void saveSongs(char songs[][MAX_TITLE_LEN], int count) {
    FILE *fp = fopen("playlist.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", songs[i]);
    }
    fclose(fp);
}

void sortSongs(char songs[][MAX_TITLE_LEN], int count) {
    char temp[MAX_TITLE_LEN];
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(songs[i], songs[j]) > 0) {
                strcpy(temp, songs[i]);
                strcpy(songs[i], songs[j]);
                strcpy(songs[j], temp);
            }
        }
    }
}

int searchSong(char songs[][MAX_TITLE_LEN], int count, char *title) {
    for (int i = 0; i < count; i++)
        if (strcmp(songs[i], title) == 0)
            return i;
    return -1;
}

int main() {
    char songs[MAX_SONGS][MAX_TITLE_LEN];
    int count = 0;
    char input[MAX_TITLE_LEN];
    int choice;

    loadSongs(songs, &count);

    while (1) {
        printf("\nPlaylist Menu:\n");
        printf("1. Add Song\n2. Delete Song\n3. Update Song\n4. Search Song\n-1. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == -1) break;

        switch (choice) {
            case 1:
                if (count >= MAX_SONGS) {
                    printf("Playlist full!\n");
                    break;
                }
                printf("Enter Song Title: ");
                fgets(input, MAX_TITLE_LEN, stdin);
                input[strcspn(input, "\n")] = '\0';
                strcpy(songs[count++], input);
                break;

            case 2:
                printf("Enter Song To Delete: ");
                fgets(input, MAX_TITLE_LEN, stdin);
                input[strcspn(input, "\n")] = '\0';
                {
                    int index = searchSong(songs, count, input);
                    if (index == -1)
                        printf("Song Not Found.\n");
                    else {
                        for (int i = index; i < count - 1; i++)
                            strcpy(songs[i], songs[i + 1]);
                        count--;
                    }
                }
                break;

            case 3:
                printf("Enter Song To Update: ");
                fgets(input, MAX_TITLE_LEN, stdin);
                input[strcspn(input, "\n")] = '\0';
                {
                    int index = searchSong(songs, count, input);
                    if (index == -1) {
                        printf("Song Not Found.\n");
                    } else {
                        printf("Enter New Title: ");
                        fgets(songs[index], MAX_TITLE_LEN, stdin);
                        songs[index][strcspn(songs[index], "\n")] = '\0';
                    }
                }
                break;

            case 4:
                printf("Enter Song To Search: ");
                fgets(input, MAX_TITLE_LEN, stdin);
                input[strcspn(input, "\n")] = '\0';
                if (searchSong(songs, count, input) != -1)
                    printf("Song Exists In The Playlist.\n");
                else
                    printf("Song Not Found.\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }
    }

    sortSongs(songs, count);
    saveSongs(songs, count);

    printf("\nFinal Playlist (Alphabetical):\n");
    for (int i = 0; i < count; i++)
        printf("%s\n", songs[i]);

    return 0;
}
