#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LEN 200
#define MAX_WORDS 7

int countWords(char *s) {
    int count = 0;
    char temp[MAX_LEN];
    strcpy(temp, s);

    char *token = strtok(temp, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int loadAffirmations(char affirm[][MAX_LEN]) {
    FILE *fp = fopen("affirm.txt", "r");
    if (!fp) return 0;

    int n = 0;
    while (fgets(affirm[n], MAX_LEN, fp)) {
        affirm[n][strcspn(affirm[n], "\n")] = '\0';
        n++;
    }
    fclose(fp);
    return n;
}

void saveAffirmations(char affirm[][MAX_LEN], int count) {
    FILE *fp = fopen("affirm.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(fp, "%s\n", affirm[i]);
    fclose(fp);
}

int main() {
    char affirm[MAX_LINES][MAX_LEN];
    int count = loadAffirmations(affirm);
    int choice;

    do {
        printf("\n1.Add  2.Delete  3.Update  4.Search  5.Show All  0.Exit\n");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter New Affirmation: ");
            fgets(affirm[count], MAX_LEN, stdin);
            affirm[count][strcspn(affirm[count], "\n")] = '\0';

            if (countWords(affirm[count]) > MAX_WORDS)
                printf("Too Many Words! Max %d Allowed.\n", MAX_WORDS);
            else
                count++;

        } else if (choice == 2) {
            int index;
            printf("Delete Index : ");
            scanf("%d", &index);

            if (index >= 0 && index < count) {
                for (int i = index; i < count - 1; i++)
                    strcpy(affirm[i], affirm[i + 1]);
                count--;
            }
        } else if (choice == 3) {
            int index;
            printf("Update Index : ");
            scanf("%d", &index);
            getchar();

            if (index >= 0 && index < count) {
                printf("New Text : ");
                fgets(affirm[index], MAX_LEN, stdin);
                affirm[index][strcspn(affirm[index], "\n")] = '\0';
            }
        } else if (choice == 4) {
            char phrase[MAX_LEN];
            printf("Search Phrase : ");
            fgets(phrase, MAX_LEN, stdin);
            phrase[strcspn(phrase, "\n")] = '\0';

            for (int i = 0; i < count; i++)
                if (strstr(affirm[i], phrase))
                    printf("Found : %s\n", affirm[i]);
        } else if (choice == 5) {
            for (int i = 0; i < count; i++)
                printf("%d: %s\n", i, affirm[i]);
        }

    } while (choice != 0);

    saveAffirmations(affirm, count);
    return 0;
}
