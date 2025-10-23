#include <stdio.h>

int main() {
    int i, arr[7];
    printf("Enter 7 Readings:\n");
    for(i = 0; i < 7; i++)
        scanf("%d", &arr[i]);

    int max = arr[0], min = arr[0];
    for(i = 1; i < 7; i++) {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }

    printf("Maximum Reading: %d\n", max);
    printf("Minimum Reading: %d\n", min);
    return 0;
}
