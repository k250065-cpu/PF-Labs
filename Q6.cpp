#include <stdio.h>
#include <math.h>

int main() {
	
    int shape, choice;
    float area, perimeter;

    printf("Geometry Calculator\n");
    printf("Select a Shape :\n 1. Circle\n 2. Rectangle\n 3. Triangle\n");
    scanf("%d", &shape);

    switch (shape) {
        case 1:  
            printf("You selected Circle \n");
            float radius;
            printf("Enter the Radius : ");
            scanf("%f", &radius);
            printf("1. Area\n 2. Perimeter\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice) {
            	case 1:
					area = 3.14 * radius * radius;
					printf("The Area of the Circle is : %.2f\n", area);
            		break;
				case 2:
					perimeter = 2 * 3.14 * radius;  
					printf("The Perimeter of the Circle is : %.2f\n", perimeter);
					break;
			}
            break;
        case 2:  
            printf("You selected Rectangle.\n");
            float length, width;
            printf("Enter length and width: ");
            scanf("%f %f", &length, &width);
            printf("1. Area\n 2. Perimeter\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice) {
            	case 1:
					area = length * width;
					printf("The Area of the Rectangle is : %.2f\n", area);
            		break;
				case 2:
					perimeter = 2 * (length + width);  
					printf("The Perimeter of the Rectangle is : %.2f\n", perimeter);
					break;
			}
            break;
        case 3: 
            printf("You selected Triangle.\n");
            float base, height;
            printf("Enter base and height: ");
            scanf("%f %f", &base, &height);
            printf("1. Area\n 2. Perimeter\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice) {
            	case 1:
					area = 0.5 * base * height;
					printf("The Area of the Triangle is : %.2f\n", area);
            		break;
				case 2:
					perimeter = base * height * sqrt((base * base) + (height * height));  
					printf("The Perimeter of the Triangle is : %.2f\n", perimeter);
					break;
			}
            break;
        default:
            printf("Invalid Input\n");
    }

    return 0;
}

