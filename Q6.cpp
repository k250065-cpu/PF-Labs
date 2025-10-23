#include <stdio.h>

int main() {
    int num, i, temp;
    printf("Enter Number of Readings: ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter %d Readings:\n", num);
    for(i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    temp = arr[num - 1];
    for(i = num - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = temp;

    printf("Array after Rotating :\n");
    for(i = 0; i < num; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
