#include <stdio.h>
#include <math.h>

int main() {
	
    float a, b, c, answer, root1, root2;

    printf("Enter the values of a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    answer = (b * b) - (4 * a * c);

    if (answer > 0) {
        root1 = (-b + sqrt(answer)) / (2 * a);
        root2 = (-b - sqrt(answer)) / (2 * a);
        printf("Roots are real and distinct: %.2f, %.2f \n", root1, root2);
    }
    else if (answer == 0) {
        root1 = -b / (2 * a);
        printf("Roots are real and equal: %.2f \n", root1);
    }
    else {
        float realPart = -b / (2 * a);
        float imaginaryPart = sqrt(-answer) / (2 * a);
        printf("Roots are imaginary: %.2f + %.2fi, %.2f - %.2fi \n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}

