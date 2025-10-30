#include <stdio.h>

int main() {
    float marks[5][4];
    float avg[5], highest[4];
    int i, j;

    printf("Enter Marks of 5 Students (4 subjects each):\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        for (j = 0; j < 4; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%f", &marks[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        float sum = 0;
        for (j = 0; j < 4; j++) {
            sum += marks[i][j];
        }
        avg[i] = sum / 4.0;
    }

    for (j = 0; j < 4; j++) {
        highest[j] = marks[0][j];
        for (i = 1; i < 5; i++) {
            if (marks[i][j] > highest[j])
                highest[j] = marks[i][j];
        }
    }

    printf("\nAverage Marks of Each Student: [");
    for (i = 0; i < 5; i++) {
        printf("%.2f", avg[i]);
        if (i < 4) printf(", ");
    }
    printf("]\n");

    printf("Highest Marks in Each Subject: [");
    for (j = 0; j < 4; j++) {
        printf("%.2f", highest[j]);
        if (j < 3) printf(", ");
    }
    printf("]\n");

    return 0;
}
