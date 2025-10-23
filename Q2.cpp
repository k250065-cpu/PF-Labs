#include <stdio.h>

int main() {
    int num, i;
    printf("Enter Number of Hourly Readings: ");
    scanf("%d", &num);

    float arr[num], sum = 0.0;
    printf("Enter %d Power Readings (in watts):\n", num);
    for(i = 0; i < num; i++) {
        scanf("%f", &arr[i]);
        sum += arr[i];
    }

    float avg = sum / num;
    printf("Total Power Usage: %.2f watts\n", sum);
    printf("Average Power Usage: %.2f watts\n", avg);
    return 0;
}
