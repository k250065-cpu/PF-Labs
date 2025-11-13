#include <stdio.h>

void inputData(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter Number of Patients for Day %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

float averagePatients(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (float)sum / n;
}

int busiestDay(int arr[], int n) {
    int max = arr[0], maxDay = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxDay = i;
        }
    }
    return maxDay + 1;
}

int slowestDay(int arr[], int n) {
    int min = arr[0], minDay = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minDay = i;
        }
    }
    return minDay + 1;
}

int main() {
    int patients[7];
    inputData(patients, 7);
    
    float avg = averagePatients(patients, 7);
    printf("Average Patients per Day: %.2f\n", avg);
    
    int busyDay = busiestDay(patients, 7);
    printf("Busiest Day: Day %d (%d patients)\n", busyDay, patients[busyDay - 1]);
    
    int slowDay = slowestDay(patients, 7);
    printf("Slowest Day: Day %d (%d patients)\n", slowDay, patients[slowDay - 1]);
    
    return 0;
}
