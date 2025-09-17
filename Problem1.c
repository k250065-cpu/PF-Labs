#include <stdio.h>

int main(){
	int marks1, marks2,marks3;
	int total;
	float percentage;
	
	printf("Enter Marks for Subject 1 : ");
	scanf("%d", &marks1);
	printf("Enter Marks for Subject 2 : ");
	scanf("%d", &marks2);
	printf("Enter Marks for Subject 3 : ");
	scanf("%d", &marks3);	
	
	total = marks1 + marks2 + marks3;
	percentage = (float)total/3;
	
	printf("Total Marks : %d \n" ,total);
	printf("Percentage : %.2f" , percentage);
	
	return 0;
}
