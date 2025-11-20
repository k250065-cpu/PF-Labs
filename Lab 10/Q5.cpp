#include <stdio.h>
#include <string.h>

#define MAX_TAGS 200
#define MAX_LEN 100

int loadTags(char tags[][MAX_LEN]) {
    FILE *fp = fopen("tags.txt", "r");
    if (!fp) return 0;

    int n = 0;
    while (fgets(tags[n], MAX_LEN, fp)) {
        tags[n][strcspn(tags[n], "\n")] = '\0';
        n++;
    }
    fclose(fp);
    return n;
}

void saveTags(char tags[][MAX_LEN], int count) {
    FILE *fp = fopen("tags.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s\n", tags[i]);
    fclose(fp);
}

void addTag(char tags[][MAX_LEN], int *count, char *newTag) {
    strcpy(tags[*count], newTag);
    (*count)++;
}

void deleteTag(char tags[][MAX_LEN], int *count, int index) {
    for (int i = index; i < (*count) - 1; i++)
        strcpy(tags[i], tags[i + 1]);
    (*count)--;
}

void updateTag(char tags[][MAX_LEN], int index, char *newTag) {
    strcpy(tags[index], newTag);
}

void searchTags(char tags[][MAX_LEN], int count, char *phrase) {
    for (int i = 0; i < count; i++)
        if (strstr(tags[i], phrase))
            printf("Found: %s\n", tags[i]);
}

int main() {
    char tags[MAX_TAGS][MAX_LEN];
    int count = loadTags(tags);
    int choice;

    do {
        printf("\n1.Add  2.Delete  3.Update  4.Search  5.Show All  0.Exit\n");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            char temp[MAX_LEN];
            printf("Enter New Tag : ");
            fgets(temp, MAX_LEN, stdin);
            temp[strcspn(temp, "\n")] = '\0';
            addTag(tags, &count, temp);

        } else if (choice == 2) {
            int index;
            printf("Delete Tag Index : ");
            scanf("%d", &index);
            deleteTag(tags, &count, index);

        } else if (choice == 3) {
            int index;
            char temp[MAX_LEN];
            printf("Update Index : ");
            scanf("%d", &index);
            getchar();
            printf("New Tag : ");
            fgets(temp, MAX_LEN, stdin);
            temp[strcspn(temp, "\n")] = '\0';
            updateTag(tags, index, temp);

        } else if (choice == 4) {
            char phrase[MAX_LEN];
            printf("Search Phrase : ");
            fgets(phrase, MAX_LEN, stdin);
            phrase[strcspn(phrase, "\n")] = '\0';
            searchTags(tags, count, phrase);

        } else if (choice == 5) {
            for (int i = 0; i < count; i++)
                printf("%d: %s\n", i, tags[i]);
        }

    } while (choice != 0);

    saveTags(tags, count);
    return 0;
}
