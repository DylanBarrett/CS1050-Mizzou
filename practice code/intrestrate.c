#include<stdio.h>
#include<math.h>
int main (void)
{
    int selection, year;
    double amount, amountCI, interestEarned;
    double interestRate;

    printf("Bank Account Type\n\n");
    printf("(1) Checking\n(2) Savings\n(3) Fixed Deposit\n");
    printf("please make a selection: ");
    scanf("%d", &selection);

    while(selection<1 || selection>3)
    {
        printf("incorrect choice, please make a choice again\n");
        scanf("%d", &selection);
    }
    printf("enter a year: ");
    scanf("%d", &year);

    while(year < 1 || year > 10){
        printf("incorrect value, year should be between 1-10\n");
        scanf("%d", &year);
    }
    printf("enter the amount");
    scanf("%lf", &amount);
    while(amount<=0){
        printf("incorrect value, enter the amount again: ");
        scanf("%lf", &amount);
    }
    switch(selection){
        case 1:
            interestRate = 1.05;
            break;

        case 2:
            interestRate = 1.10;
            break;

        case 3:
            interestRate = 1.15;
            break;
        default:
            printf("Error! please choose a number 1-3\n");
    }
    amountCI = amount * pow(interestRate, (double)year);
    printf("total amount earned after %d years is $%.2lf\n",year, amountCI);
    interestEarned = (amountCI - amount);
    printf("total interest earned on the amount $%.2lf is $%.2lf at a rate of %.2lf\n", amount, interestEarned,interestRate);

    return 0;
}
