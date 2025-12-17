#include <stdio.h>

int main(){

    // 3.16 (Gas Mileage) //


    // float gallons;
    // float miles;

    // printf("Enter the gallons used (-1 to end): ");
    // scanf("%f", &gallons);

    // printf("Enter the miles driven: ");
    // scanf("%f", &miles);

    // float miles_Per_gallon = miles / gallons;

    // printf("The miles/gallon for this tank was %f", miles_Per_gallon);

    // return 0;

    
    //3.17 (Credit-Limit Calculator)//



// int accountNumber;
// int beginningBalance;
// int totalCharges;
// int totalCredits;
// int creditlimit;

// printf("Enter account number: ");
// scanf("%d",&accountNumber);

// printf("Enter beginning balance: ");
// scanf("%d", &beginningBalance);

// printf("Enter total charges: ");
// scanf("%d", &totalCharges);

// printf("Enter total credits: ");
// scanf("%d", &totalCredits);

// printf("Enter credit limit: ");
// scanf("%d", &creditlimit);

// int balance = totalCredits + beginningBalance;

// printf("Account number:    %d\n", accountNumber);
// printf("Account number:    %d\n", accountNumber);
// printf("Credit limit:      %d\n", creditlimit);
// printf("Balance:           %d\n", balance);

// if(creditlimit < balance){
//     printf("Credit limit exceeded!\n");
// }

// return 0;

int sales;

printf("Enter sales in dollars: ");
scanf("%d", &sales);

int percentage = 0.09 * sales;
int salary = 200 + percentage;

printf("Salary is:  %d", salary);

}