#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "user.txt"

// -------------------- INPUT VALIDATION FUNCTIONS --------------------

int getIntInput() {
    char buffer[100];
    int value;

    while (1) {
        printf("Enter number: ");
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Check empty or newline only
        if (buffer[0] == '\n') {
            printf("Input cannot be empty.\n");
            continue;
        }

        // Validate that all characters are digits
        int valid = 1;
        for (int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++) {
            if (!isdigit(buffer[i])) {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Invalid input. Only positive numbers allowed.\n");
            continue;
        }