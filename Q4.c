#include <stdio.h>

int main() {
	
    int marks, count = 0;
    float average, sum = 0;

    printf("Enter marks (-1 to stop):\n");

    while (1) {
        scanf("%d", &marks);
        if (marks == -1)
            break;
        sum = sum + marks;
        count++;
    }

    if (count > 0)
        printf("Average Marks = %.2f\n", sum / count);
    else
        printf("No marks entered.\n");

    return 0;
}

