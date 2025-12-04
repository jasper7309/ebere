#include <stdio.h>
#include "functions.h"

int main(){

    char userInput1[100];
    char reversed[100];

    printf("Enter a word: ");
    scanf("%99s", userInput1);

    reverse_string(userInput1, reversed);

    printf("Reversed string: %s\n", reversed);


 char userInput[100];
    printf("enter a word: ");
    scanf("%99s", userInput);
    count_vowels(userInput);
    printf("the number of vowels in %s is %d", userInput, count_vowels(userInput));
} 