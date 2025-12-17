#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "users.dat"

typedef struct {
    char username[30];
    int passwordHash;
    int pinHash;       // -1 = not created
    char phone[15];
    char account[15];
    int balance;
} User;

// ================= HASH =================
int hash(const char *s) {
    int h = 0;
    while (*s) h = h * 31 + *s++;
    return h;
}

// ================= INPUT =================
void getString(const char *msg, char *out, int size) {
    while (1) {
        printf("%s", msg);
        fgets(out, size, stdin);
        out[strcspn(out, "\n")] = 0;
        if (strlen(out)) return;
        printf("Input cannot be empty.\n");
    }
}

int getInt() {
    char buf[50];
    while (1) {
        fgets(buf, 50, stdin);
        buf[strcspn(buf, "\n")] = 0;

        if (!strlen(buf)) {
            printf("Empty input. Try again: ");
            continue;
        }

        for (int i = 0; buf[i]; i++) {
            if (!isdigit(buf[i])) {
                printf("Numbers only. Try again: ");
                goto retry;
            }
        }
        return atoi(buf);
    retry:;
    }
}

// ================= ACCOUNT =================
void generateAccount(const char *phone, char *account) {
    if (phone[0] == '0')
        strcpy(account, phone + 1);
    else
        strcpy(account, phone);
}

// ================= FILE HELPERS =================
int userCount() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;
    fseek(fp, 0, SEEK_END);
    int count = ftell(fp) / sizeof(User);
    fclose(fp);
    return count;
}

User readUser(int index) {
    FILE *fp = fopen(FILE_NAME, "rb");
    User u;
    fseek(fp, index * sizeof(User), SEEK_SET);
    fread(&u, sizeof(User), 1, fp);
    fclose(fp);
    return u;
}

void writeUser(int index, User u) {
    FILE *fp = fopen(FILE_NAME, "rb+");
    fseek(fp, index * sizeof(User), SEEK_SET);
    fwrite(&u, sizeof(User), 1, fp);
    fclose(fp);
}

void appendUser(User u) {
    FILE *fp = fopen(FILE_NAME, "ab");
    fwrite(&u, sizeof(User), 1, fp);
    fclose(fp);
}

// ================= REGISTER =================
void registerUser() {
    User u;
    char pass[30];

    getString("Username: ", u.username, 30);
    getString("Password: ", pass, 30);

    while (1) {
        getString("Phone number: ", u.phone, 15);
        if (u.phone[0] == '0' && strlen(u.phone) >= 10) break;
        printf("Invalid phone number.\n");
    }

    generateAccount(u.phone, u.account);

    u.passwordHash = hash(pass);
    u.pinHash = -1;
    u.balance = 1000;

    appendUser(u);

    printf("Account created successfully.\n");
    printf("Your account number: %s\n", u.account);
}

// ================= LOGIN =================
int login(User *loggedUser, int *index) {
    char user[30], pass[30];
    int count = userCount();

    while (1) {
        getString("Username: ", user, 30);
        getString("Password: ", pass, 30);

        for (int i = 0; i < count; i++) {
            User u = readUser(i);
            if (!strcmp(u.username, user) &&
                u.passwordHash == hash(pass)) {
                *loggedUser = u;
                *index = i;
                printf("\nWelcome %s!\n", u.username);
                return 1;
            }
        }
        printf("Invalid login.\n");
    }
}

// ================= PIN =================
int validPin(const char *p) {
    if (strlen(p) != 4) return 0;
    for (int i = 0; i < 4; i++)
        if (!isdigit(p[i])) return 0;
    return 1;
}

void createPin(User *u, int index) {
    char pin[10];

    while (1) {
        printf("Create 4-digit ATM PIN: ");
        fgets(pin, 10, stdin);
        pin[strcspn(pin, "\n")] = 0;

        if (!validPin(pin)) {
            printf("PIN must be 4 digits.\n");
            continue;
        }

        u->pinHash = hash(pin);
        writeUser(index, *u);
        printf("ATM PIN created successfully.\n");
        break;
    }
}

int verifyPin(User *u) {
    char pin[10];
    printf("Enter ATM PIN: ");
    fgets(pin, 10, stdin);
    pin[strcspn(pin, "\n")] = 0;
    return validPin(pin) && hash(pin) == u->pinHash;
}

// ================= TRANSFER =================
int findAccount(const char *acc) {
    int count = userCount();
    for (int i = 0; i < count; i++) {
        User u = readUser(i);
        if (!strcmp(u.account, acc)) return i;
    }
    return -1;
}

// ================= MAIN =================
int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf(" Welcome to Jasper's Banking Services\n");
        printf("====================================\n");
        printf("1. Register\n2. Login\n3. Exit\nChoice: ");

        choice = getInt();

        if (choice == 1) {
            registerUser();
        }

        else if (choice == 2) {
            User current;
            int index;

            if (!userCount()) {
                printf("No users registered.\n");
                continue;
            }

            login(&current, &index);

            if (current.pinHash == -1)
                createPin(&current, index);

            while (1) {
                current = readUser(index);

                printf("\n1. Balance\n2. Deposit\n3. Withdraw\n4. Transfer\n5. Logout\nChoice: ");
                choice = getInt();

                if (choice == 1) {
                    printf("Balance: %d\n", current.balance);
                }

                else if (choice == 2) {
                    printf("Amount: ");
                    int amt = getInt();
                    current.balance += amt;
                    writeUser(index, current);
                    printf("Deposit successful.\n");
                }

                else if (choice == 3) {
                    if (!verifyPin(&current)) {
                        printf("Wrong PIN.\n");
                        continue;
                    }
                    printf("Amount: ");
                    int amt = getInt();
                    if (amt <= current.balance) {
                        current.balance -= amt;
                        writeUser(index, current);
                        printf("Withdrawal successful.\n");
                    } else {
                        printf("Insufficient balance.\n");
                    }
                }

                else if (choice == 4) {
                    if (!verifyPin(&current)) {
                        printf("Wrong PIN.\n");
                        continue;
                    }

                    char acc[15];
                    getString("Recipient account: ", acc, 15);
                    int rIndex = findAccount(acc);

                    if (rIndex == -1) {
                        printf("Account not found.\n");
                        continue;
                    }

                    printf("Amount: ");
                    int amt = getInt();

                    if (amt <= current.balance) {
                        User receiver = readUser(rIndex);
                        current.balance -= amt;
                        receiver.balance += amt;
                        writeUser(index, current);
                        writeUser(rIndex, receiver);
                        printf("Transfer successful.\n");
                    } else {
                        printf("Insufficient balance.\n");
                    }
                }

                else if (choice == 5) {
                    break;
                }
            }
        }

        else if (choice == 3) {
            printf("Thank you for using Jasper's Banking Services.\n");
            break;
        }
    }

    return 0;
}

