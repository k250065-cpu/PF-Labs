#include <stdio.h>

void findRoadsWithTarget(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Road %d and Road %d have a Combined Traffic of %d (Target %d)\n", i + 1, j + 1, arr[i] + arr[j], target);
                return;
            }
        }
    }
    printf("No Such Roads Found.\n");
}

int main() {
    int n, target;

    printf("Enter the Number of Roads: ");
    scanf("%d", &n);
    
    int vehicles[n];
    
    printf("Enter the Vehicle Counts for the Roads:\n");
    for (int i = 0; i < n; i++) {
        printf("Road %d: ", i + 1);
        scanf("%d", &vehicles[i]);
    }
    
    printf("Enter the Target Vehicle Count: ");
    scanf("%d", &target);
    
    findRoadsWithTarget(vehicles, n, target);
    
    return 0;
}
