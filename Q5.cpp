#include <stdio.h>

int main() {
    int num1, num2, i, j;
    printf("Enter Size of First Array: ");
    scanf("%d", &num1);
    int arr1[num1];
    printf("Enter %d Readings for First Array:\n", num1);
    for(i = 0; i < num1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter Size of Second Array: ");
    scanf("%d", &num2);
    int arr2[num2];
    printf("Enter %d Readings for Second Array:\n", num2);
    for(i = 0; i < num2; i++)
        scanf("%d", &arr2[i]);

    int arrMerged[num1 + num2];
    for(i = 0; i < num1; i++)
        arrMerged[i] = arr1[i];
    for(j = 0; j < num2; j++)
        arrMerged[num1 + j] = arr2[j];

    printf("Merged Array:\n");
    for(i = 0; i < num1 + num2; i++)
        printf("%d ", arrMerged[i]);
    printf("\n");
    return 0;
}
