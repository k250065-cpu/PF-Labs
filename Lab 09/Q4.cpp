#include <stdio.h>

void updateValue(int x) {
    x = 85;
}

void updateReference(int *x) {
    *x = 85;
}

int main() {
    int num = 80;
    printf("Before Updated Value: %d\n", num);
    updateValue(num);
    printf("After Updated Value: %d (No Change)\n", num);

    printf("Before Updated Reference: %d\n", num);
    updateReference(&num);
    printf("After Updated Reference: %d (Updated Successfully)\n", num);

    return 0;
}
