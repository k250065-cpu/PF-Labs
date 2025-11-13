#include <stdio.h>

float calculateBonus(float salary) {
    if (salary < 30000) {
        return salary * 0.20;
    } else {
        return salary * 0.10;
    }
}

int main() {
    float salaries[5] = {25000, 35000, 28000, 45000, 60000};
    float totalPayout = 0;
    
    for (int i = 0; i < 5; i++) {
        float bonus = calculateBonus(salaries[i]);
        float total = salaries[i] + bonus;
        totalPayout += total;
        
        printf("Employee %d Bonus: %.2f\n", i + 1, bonus);
        printf("Employee %d Total Payout: %.2f\n", i + 1, total);
    }
    
    printf("Total Payout: %.2f\n", totalPayout);
    
    return 0;
}
