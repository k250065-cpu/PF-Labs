#include <stdio.h>

int main() {
	
	int num;
	
	printf("Enter a Integer (between 65 and 90) : ");
	scanf("%d" , &num);
	
	if ( num >= 65 && num <= 90 ) {
		
		printf("Input = %d     Output = %c " , num , (char)num);
		
	}
	return 0;
}
