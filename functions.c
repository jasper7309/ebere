#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "functions.h"
    
int count_vowels(char input[]) {
    int length = strlen(input);
    int counter = 0;

    for (int i = 0; i < length; i++) {
        char ch = input[i];

        // Check for vowels (lowercase and uppercase)
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') 
        {
            counter++;
        }
    }

    return counter;
}

void reverse_string(char input[], char output[]) {
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        output[i] = input[length - 1 - i];
    }

    output[length] = '\0';  
}


