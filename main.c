#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void define(int number) {
    if(number % 2 == 0){
        printf("%d is an even number.\n",number);
    }else{
        printf("%d is an odd number\n",number);
    }
}


int main(){
    // int count = 1;
    // while(count <= 0){
    //     if(count % 2 != 0) printf("%d\n",count);
        
    //     count += 1;

//     char userName[10];
//     int password;
    
//     while (strcmp(userName, "admin") != 0 || password != 1234){

//     printf("please enter username: ");
//     scanf("%9s", userName);

//     printf("please enter password: ");
//     scanf("%d", &password);
//   }

// int evenNumbers = 2;
// int total = 0;

// while(evenNumbers < 50){
// if (evenNumbers % 2 == 0){

//     total = total + evenNumbers;
// }
//    evenNumbers++;
    
// }
// printf("the sum off all even numbers btw 1 and 50 is %d\n", total);

// int largest = 0;
// int count = 1;

// int number;
// printf("enter number: ");
// scanf("%d", &number);

// largest = number;

// while (count < 10){

//     printf("enter number: ");
//     scanf("%d", number);

//     if(number > largest){

//         largest = number;

//     } 

//     count++;

// }
// printf("the largest number is %d", largest);


// }


// int pin = 0;
//     int accountBalance = 1000;

//     while (pin != 1234) {
//         printf("Enter PIN: ");
//         scanf("%d", &pin);
//     }

//     int userInput = 0;

//     while (userInput != 4) {

//         printf(
//             "\nWelcome to Jasper's Bank\n"
//             "1. Check Balance\n"
//             "2. Withdraw Money\n"
//             "3. Deposit Money\n"
//             "4. Exit\n"
//             "Your choice: "
//         );

//         while (scanf("%d", &userInput) != 1) {
//             printf("Wrong input. Choose from options 1-4: ");
//             while (getchar() != '\n');  // clear buffer
//         }

//         switch (userInput) {

//             case 1:
//                 printf("Your current balance is $%d\n", accountBalance);
//                 break;

//             case 2: {
//                 int withdraw;
//                 printf("Enter amount to withdraw: ");

//                 while (scanf("%d", &withdraw) != 1) {
//                     printf("Enter a valid amount: ");
//                     while (getchar() != '\n');
//                 }

//                 if (withdraw <= accountBalance) {
//                     accountBalance -= withdraw;
//                     printf("Successfully withdrawn $%d. Current balance: $%d\n",
//                            withdraw, accountBalance);
//                 } else {
//                     printf("Insufficient balance.\n");
//                 }
//                 break;
//             }

//             case 3: {
//                 int depositAmount;
//                 printf("Enter amount to deposit: ");

//                 while (scanf("%d", &depositAmount) != 1) {
//                     printf("Enter a valid amount: ");
//                     while (getchar() != '\n');
//                 }

//                 accountBalance += depositAmount;
//                 printf("Successfully deposited. Updated balance: $%d\n", accountBalance);
//                 break;
//             }

//             case 4:
//                 printf("Exiting program...\n");
//                 break;

//             default:
//                 printf("Wrong input.\n");
//                 break;
//         }
//     }

//     return 0;


// }

// int userInput;
// int number = 2;
// int multiplier = 1;
// int product = 0;


// while(scanf("%d", &userInput) != 1 || userInput <= 1){
//     printf("please enter a positive integer greater than 1: ");
//     while (getchar() != '\n');
    
// }

// while(number <= userInput){
//     printf("\n multiplication table of %d\n", number);
//     while(multiplier <= 12){
//         product = number * multiplier;
//         printf(
//             "%d * %d = %d\n", number, multiplier, product
//             );
//             ++multiplier;
//     }
    
//     number++;
//     multiplier = 1;
//     printf("\n");
    

// }


// int userInput, original_number, digit;
// int sum = 0;

// printf("enter a positive integer i.e 1234: ");
// if (scanf("%d", &userInput) != 1 || userInput <= 0){
//     printf("wrong input please enter a valid positive integer/n");
// }else{

// original_number = userInput;

// while (userInput > 0){
//     digit = userInput % 10;
//     sum = sum + digit;
//     userInput = userInput / 10;
// }

// printf("The sum of the digits of %d is: %d\n", original_number, sum);
// }
// return 0;


// int userInput;

// printf("enter a positive integer: ");
// if(scanf("%d", &userInput) != 1|| userInput <= 0){
//     printf("wrong input enter a positive integer\n");
// }else{
// int factorial
// for(factorial > 0, --factorial){
//     su
// }

// int numbers[5];
// int sum = 0;

// printf("enter five numbers: ");
// for(int i = 0; i < 5; i++){
//     scanf("%d", &numbers[i]);
//     if(numbers[i] % 2 == 0){
//         sum = sum + numbers[i];
//     }
// }

//     printf("the sum of the even numbers in %d, %d, %d, %d, %d is %d", numbers[0],numbers[1],numbers[2],numbers[3],numbers[4], sum);

// int numbers[5];

// printf("enter five numbers: ");

// for(int i = 0; i < 5; i++){
//     scanf("%d", &numbers[i]);
// }

// int n = sizeof(numbers) / sizeof(numbers[0]);

// qsort(numbers, n, sizeof(int), compare_ascending );
// printf("sorted ascending: ");

// for(int i = 0; i < 5; i++){
//     printf("%d", numbers[i]);
// }


// int numbers[6];

// printf("enter six numbers: ");

// for(int i = 0; i < 6; i++){
//     scanf("%d", &numbers[i]);
// }

// int n = sizeof(numbers) / sizeof(numbers[0]);

// qsort(numbers, n, sizeof(int), compare_descending);
//   printf("sorted descending: ");


// for(int i = 0; i < 6; i++){
//     printf("%d", numbers[i]);
// }



// int numbers[5];

// printf("enter five numbers: ");

// for(int i = 0; i < 5; i++){
//     scanf("%d", &numbers[i]);
// }

// int n = sizeof(numbers) / sizeof(numbers[0]);

// int temp;

// for(int i = 0; i < n - 1; i++){
//     for(int j = 0; j < n - i - 1; j++){
        
//         if(numbers[j] > numbers[j + 1]){
//             temp = numbers[j];
//             numbers[j] = numbers[j + 1];
//             numbers[j + 1] = temp; 
            
          
//         }
//     }
// }

// printf("array sorted in ascending order: ");
// for(int i = 0; i < 5; i++){
//     printf("%d", numbers[i]);
// }

// int numbers[6];

// printf("enter six numbers: ");

// for(int i = 0; i < 6; i++){
//     scanf("%d", &numbers[i]);
// }


// int n = sizeof(numbers) / sizeof(numbers[0]);

// int temp;

// for(int i = 0; i < n -1; i++){
//     for(int j = 0; j < n - i - 1; j++){
        
//         if(numbers[j] < numbers[j + 1]){
//             temp = numbers[j];
//             numbers[j] = numbers [j+ 1];
//             numbers[j + 1] = temp;
//         }
//     }
// }

// printf("array sorted in descending order: ");

// for(int i = 0; i < 6; i++){
//     printf("%d", numbers[i]);
// }



// int numbers[5];
// printf("enter five numbers: ");

// for(int i = 0; i < 5; i++){
//     scanf("%d", &numbers[i]);
// }

// printf("Before: ");

// for(int i = 0; i < 5; i++){
//     printf("%d ", numbers[i]);
// }

// int temp;

// temp = numbers[0];
// numbers[0] = numbers[4];
// numbers[4] = temp;

// printf("\nAfter: ");
// for(int i = 0; i < 5; i++){
//     printf("%d ", numbers[i]);


// }


// int values [2][3] = {
//     {2, 4, 5},
//     {3, 6, 9}
// };

// for(int i = 0; i < 2; i++){
//     for(int j = 0; j < 3; j++){
//         printf("%d, ", values[i][j]);
//     }
//      printf("\n");
// }


// char userInput [3][3];

// printf("Welcome to X and O game ");

// for(int i = 0; i < 3; i++){

//     for(int j = 0; j < 3; j++){

//         printf("\nEnter X or O: ");
//         scanf("%c",&userInput [i][j] );

//         while(userInput[i][j] != 'x'  && userInput[i][j] != 'o'){

//             printf("Error: invalid input.... please enter 'x' or o: " );
//              scanf(" %c", &userInput [i][j]);
           

//         }
        
//     }

// }

// printf("Your final output: ");
// for(int i = 0; i < 3; i++){
//     for(int j = 0; j < 3; j++){
//         printf("%d, ",userInput [i][j]);
        
//     }
//     printf("\n");
// }
// }

// char userInput;
// int row;
// int col;
// char board[3][3] = {
//       {'1', '2', '3'},
//       {'4', '5', '6'},
//       {'7', '8', '9'}
// };

// printf("Welcome to Jasper's X and O game!!\n");




// for(int i = 1; i < 10; i++){

//      for(int a = 0; a < 3; a++){
//         for(int b = 0; b < 3; b++) {
//             printf(" %c ", board[i][j]);
//         }
//         printf("\n");

//     }

//     for(int i = 0; i < 9; i++){

//         printf("Round %d: player x choose an index (1--9): ", i);
//         scanf("%c", userInput);

//     while(userInput < 1 || userInput > 9){
//         printf("wrong input.... enter an index from 1--9: ");
//         scanf("%d", userInput);
//     }

//     row = (choice -1)/3;
//     col = (choice -1)%3;

//     board[row][col] = userInput;

//     printf("\n");
// }


    






//         printf("\n");
    
       

        


//         }
        



        


//     }










    // printf("player x: pick an index from (1-9)");

    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {

    //         printf("\nEnter X or O: ");
    //         scanf(" %c", &userInput[i][j]);   

    //         while(userInput[i][j] != 'x' && userInput[i][j] != 'o') {
    //             printf("Error: invalid input... please enter 'x' or 'o': ");
    //             scanf(" %c", &userInput[i][j]);
    //         }
    //     }
    // }

    // printf("\n\nYour final output:\n");
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         printf("%c ", userInput[i][j]);
    //     }
    //     printf("\n");
    // }


    int userInput;

    printf("enter a number: ");
    scanf("%d", &userInput);
    define(userInput);

    return 0;
}


