#include <stdio.h>

int main() {
    int num, i, temp;
    printf("Enter Number of Readings: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter %d Readings:\n", num);
    for(i = 0; i < num; i++)
        scanf("%d", &arr[i]);

    int start = 0, end = num - 1;
    while(start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    printf("Array after Reversal:\n");
    for(i = 0; i < num; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
