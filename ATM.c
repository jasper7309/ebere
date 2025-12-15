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

        value = atoi(buffer);
        if (value < 0) {
            printf("Negative numbers are not allowed.\n");
            continue;
        }

        return value;
    }
}

void getStringInput(char *prompt, char *output, int maxLen) {
    while (1) {
        printf("%s", prompt);
        if (!fgets(output, maxLen, stdin)) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Remove newline
        output[strcspn(output, "\n")] = '\0';

        if (strlen(output) == 0) {
            printf("Input cannot be empty.\n");
            continue;
        }

        return;
    }
}

// -------------------- FILE OPERATIONS --------------------

void saveUser(const char *username, const char *password, int balance) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Error writing to file.\n");
        exit(1);
    }
    fprintf(fp, "%s\n%s\n%d\n", username, password, balance);
    fclose(fp);
}

void loadUser(char *username, char *password, int *balance) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("User file not found. Please register first.\n");
        exit(1);
    }
    fgets(username, 50, fp);
    fgets(password, 50, fp);
    fscanf(fp, "%d", balance);

    // remove newline chars
    username[strcspn(username, "\n")] = '\0';
    password[strcspn(password, "\n")] = '\0';

    fclose(fp);
}

// -------------------- MAIN PROGRAM --------------------

int main() {
    char username[50], password[50];
    char storedUser[50], storedPass[50];
    int balance;

    printf("===== ATM SYSTEM (WITH FILE STORAGE) =====\n");

    // -------------------- SIGN UP --------------------
    getStringInput("Create username: ", username, sizeof(username));
    getStringInput("Create password: ", password, sizeof(password));

    balance = 1000; // initial balance

    saveUser(username, password, balance);

    printf("Account created successfully!\n\n");

    // -------------------- LOGIN PHASE --------------------

    while (1) {
        char loginUser[50], loginPass[50];

        getStringInput("Enter username: ", loginUser, sizeof(loginUser));
        getStringInput("Enter password: ", loginPass, sizeof(loginPass));

        loadUser(storedUser, storedPass, &balance);

        if (strcmp(loginUser, storedUser) == 0 &&
            strcmp(loginPass, storedPass) == 0) {
            printf("Login successful!\n\n");
            break;
        } else {
            printf("Incorrect username or password. Try again.\n\n");
        }
    }

    // -------------------- MENU LOOP --------------------
    while (1) {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Money\n");
        printf("3. Deposit Money\n");
        printf("4. Exit\n");

        int choice = getIntInput();

        if (choice < 1 || choice > 4) {
            printf("Invalid menu option.\n");
            continue;
        }

        loadUser(storedUser, storedPass, &balance);

        if (choice == 1) {
            printf("Your balance is: %d\n", balance);
        }

        else if (choice == 2) {
            printf("Enter amount to withdraw: ");
            int amount = getIntInput();

            if (amount <= 0) {
                printf("Amount must be positive.\n");
            } else if (amount > balance) {
                printf("Insufficient balance.\n");
            } else {
                balance -= amount;
                saveUser(storedUser, storedPass, balance);
                printf("Withdrawal successful! New balance: %d\n", balance);
            }
        }

        else if (choice == 3) {
            printf("Enter deposit amount: ");
            int amount = getIntInput();

            if (amount <= 0) {
                printf("Amount must be positive.\n");
            } else {
                balance += amount;
                saveUser(storedUser, storedPass, balance);
                printf("Deposit successful! New balance: %d\n", balance);
            }
        }

        else if (choice == 4) {
            printf("Thank you for using the ATM.\n");
            break;
        }
    }

    return 0;
}
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main(){
    
// }