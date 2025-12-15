#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arithemetic(int number1, int number2){
    int sum = number1 + number2;
    int product = number1 * number2;
    int difference = number1 - number2;
    int quotient = number1 / number2;
    int remainder = number1 % number2;

    printf("The sum of %d and %d is %d\n", number1, number2, sum);
    printf("The product of %d and %d is %d\n",number1, number2, product);
    printf("The difference between %d and %d is %d\n", number1, number2, difference);
    printf("The quotient of %d and %d is %d\n", number1, number2, quotient);
    printf("The remainder when %d is divided by %d is %d\n", number1, number2, remainder);

    
}

void compare(int num1, int num2){
    if(num1 > num2){
        printf("%d is larger\n", num1);
    }else if(num2 > num1){
        printf("%d is larger\n", num2);
    }else{
        printf("These numbers are equal.\n");
    }

}

void solve(int number1, int number2, int number3){
    int sum = number1 + number2 + number3;
    int average = sum/3;
    int product = number1 * number2 * number3;
    int smallest;
    
    if(number1 < number2 && number1 < number3){
        smallest = number1;
    }else if(number2 < number1 && number2 < number3){
        smallest = number2;
    }else{
        smallest = number3;
    }

    int largest;

    if(number1 > number2 && number1 > number3){
        largest = number1;
    }else if(number2 > number1 && number2 > number3){
        largest = number2;
    }else{
        largest = number3;
    }


    printf("The sum of %d, %d and %d is %d\n", number1, number2, number3, sum);
    printf("The avaerage of %d, %d and %d is %d\n", number1, number2, number3, average);
    printf("The product of %d, %d and %d is %d\n", number1, number2, number3, product);
    printf("The smallest is %d\n", smallest);
    printf("The largest is %d\n", largest);

   

}

void Circle(int radius){
    int diameter = radius * 2;
    int circumference = 2 * 3.142 * radius;
    int area = 3.142 * radius * radius;

    printf("The diameter of a circle with radius %d is %d\n", radius, diameter);
    printf("The circumference of a circle with radius %d is %d\n", radius, circumference);
    printf("The area of a circle with radius %d is %d\n", radius, area);

}


void odd_or_even(int number){
        if(number % 2 == 0){
            printf("%d is even",number);
        }else{
             printf("%d is odd",number);
        }
    }


void multiple(int number1, int number2){
    if(number2 % number1 == 0){
        printf("%d is a multiple of %d", number1, number2);
    }else{
        printf("%d is not a multiple of %d", number1, number2);
    }
}

int main(){
    int number1;
    int number2;
    int number3;
    // printf("Enter two integers: ");
    // scanf("%d", &number1);
    // scanf("%d", &number2);

    // arithemetic(number1, number2);

    // printf("\n\n\n");

    // printf("Enter two integers: ");
    // scanf("%d", &number1);
    // scanf("%d", &number2);

    // compare(number1, number2);

    // printf("\n\n\n");


    // printf("Enter three integers: ");
    // scanf("%d", &number1);
    // scanf("%d", &number2);
    // scanf("%d", &number3);

    // solve(number1, number2, number3);

    //  printf("\n\n\n");

    // printf("Enter a Circle's radius: ");
    // scanf("%d", &number1);

    // // Circle(number1);

    // printf("\n\n\n");


    // printf("Enter an integer: ");
    // scanf("%d", &number1);

    // odd_or_even(number1);

    // printf("\n\n\n");

    printf("Enter two integers: ");
    scanf("%d", &number1);
    scanf("%d", &number2);

    multiple(number1, number2);

    return 0;

}
