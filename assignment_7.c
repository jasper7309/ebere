#include <stdio.h>
int main(){
    
int userInput;
int number = 2;
int multiplier = 1;
int product = 0;


while(scanf("%d", &userInput) != 1 || userInput <= 1){
    printf("please enter a positive integer greater than 1: ");
    while (getchar() != '\n');
    
}

while(number <= userInput){
    printf("\n multiplication table of %d\n", number);
    while(multiplier <= 12){
        product = number * multiplier;
        printf(
            "%d * %d = %d\n", number, multiplier, product
            );
            ++multiplier;
    }
    
    number++;
    multiplier = 1;
    printf("\n");

}
}