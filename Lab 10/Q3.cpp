#include <stdio.h>
#include <string.h>

#define MAX_RECIPES 40
#define MAX_LENGTH 50

void loadRecipes(char recipes[][MAX_LENGTH], int *count) {
    FILE *fp = fopen("recipes.txt", "r");
    if (!fp) {
        printf("File Does not Exist. Starting With An Empty List.\n");
        return;
    }

    while (fgets(recipes[*count], MAX_LENGTH, fp) != NULL && *count < MAX_RECIPES) {
        recipes[*count][strcspn(recipes[*count], "\n")] = '\0';
        (*count)++;
    }
    fclose(fp);
}

void saveRecipes(char recipes[][MAX_LENGTH], int count) {
    FILE *fp = fopen("recipes.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", recipes[i]);
    }
    fclose(fp);
}

void addRecipe(char recipes[][MAX_LENGTH], int *count) {
    if (*count >= MAX_RECIPES) {
        printf("List Is Full.\n");
        return;
    }
    printf("Enter New Recipe Name: ");
    scanf(" %[^\n]", recipes[*count]);
    (*count)++;
}

void modifyRecipe(char recipes[][MAX_LENGTH], int count) {
    int index;
    printf("Enter Recipe Index To Modify (0–%d): ", count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= count) {
        printf("Invalid Index.\n");
        return;
    }

    printf("Enter New Recipe Name: ");
    scanf(" %[^\n]", recipes[index]);
}

void removeRecipe(char recipes[][MAX_LENGTH], int *count) {
    int index;
    printf("Enter Recipe Index To Remove (0–%d): ", *count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= *count) {
        printf("Invalid Index.\n");
        return;
    }

    for (int i = index; i < (*count) - 1; i++) {
        strcpy(recipes[i], recipes[i + 1]);
    }
    (*count)--;
}

void searchRecipe(char recipes[][MAX_LENGTH], int count) {
    char key[MAX_LENGTH];
    printf("Enter Search Text: ");
    scanf(" %[^\n]", key);

    printf("\nSearch Results:\n");
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(recipes[i], key)) {
            printf("%d: %s\n", i, recipes[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No Matching Recipes Found.\n");
    }
}

void sortRecipes(char recipes[][MAX_LENGTH], int count) {
    char temp[MAX_LENGTH];

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(recipes[j], recipes[j + 1]) > 0) {
                strcpy(temp, recipes[j]);
                strcpy(recipes[j], recipes[j + 1]);
                strcpy(recipes[j + 1], temp);
            }
        }
    }
}

int main() {
    char recipes[MAX_RECIPES][MAX_LENGTH];
    int count = 0;
    int choice;

    loadRecipes(recipes, &count);

    while (1) {
        printf("\n===== Recipe Manager =====\n");
        printf("1. Add Recipe\n");
        printf("2. Modify Recipe\n");
        printf("3. Remove Recipe\n");
        printf("4. Search Recipes\n");
        printf("5. Display All Recipes\n");
        printf("-1. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == -1) break;

        switch (choice) {
            case 1: addRecipe(recipes, &count); break;
            case 2: modifyRecipe(recipes, count); break;
            case 3: removeRecipe(recipes, &count); break;
            case 4: searchRecipe(recipes, count); break;
            case 5:
                printf("\nAll Recipes:\n");
                for (int i = 0; i < count; i++)
                    printf("%d: %s\n", i, recipes[i]);
                break;
            default:
                printf("Invalid Choice.\n");
        }
    }

    sortRecipes(recipes, count);
    saveRecipes(recipes, count);

    printf("Recipes Saved Alphabetically.\n");
    return 0;
}
