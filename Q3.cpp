#include <stdio.h>

int main() {
    int num, i, value, j;
    printf("Enter Number of Readings: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter %d Readings:\n", num);
    for(i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    printf("Enter Value to Delete: ");
    scanf("%d", &value);

    for(i = 0; i < num; i++) {
        if(arr[i] == value) {
            for(j = i; j < num - 1; j++)
                arr[j] = arr[j + 1];
            num--;
            i--;
        }
    }

    printf("Array after Deletion: ");
    for(i = 0; i < num; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
