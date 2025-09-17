#include <stdio.h>

int main() {
	
	float basicSalary, grossSalary, HRA, DA ;
	
	printf("Enter Employee's Basic Salary : ");
	scanf("%f", &basicSalary);
	
	HRA = basicSalary * 0.10 ;
	DA = basicSalary * 0.05 ;
		
	grossSalary = basicSalary + HRA + DA ;
	
	printf("Gross Salary = %.2f", grossSalary);
	
	return 0;
}
