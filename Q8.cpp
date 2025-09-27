#include <stdio.h>
#include <math.h>

int main() {
	
    float amount, interestRate, time, emi;
    int interestType;

    printf("Enter Loan Amount : ");
    scanf("%f", &amount);
    printf("Enter Time (in years) : ");
    scanf("%f", &time);
    printf("Enter Interest Type (1 for Simple interest, 2 for Compound interest): ");
    scanf("%d", &interestType);

    if (interestType == 1) {
        interestRate = 0.1;
        float total = amount * (1 + interestRate * time);
        emi = total / (time * 12);
        printf("The EMI for the Loan with Simple interest is : %.2f\n", emi);
    } else if (interestType == 2) {
        interestRate = 0.1;
        float total = amount * pow(1 + interestRate, time);
        emi = total / (time * 12);
        printf("The EMI for the Loan with Compound interest is : %.2f\n", emi);
    } else {
        printf("Invalid Input\n");
    }

    return 0;
}

