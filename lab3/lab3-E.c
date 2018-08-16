//Dylan barrett
//lab 3
//calculate intrest lab
//ryan is ta
//we couldnt get the right numbers in class
//had problems with the compound interest and interest earned statement
//my cmpd interest after so many is wrong and so is the interest earned
//we tried multiple things in class and still couldnt get it to work.
#include<stdio.h>
#include<math.h>
int main(void)
{ 
    int account = 0;
    double year = 0;
    double amount = 0;
    double cmpdinterest = 0;
    double interestearned = 0;
    double rate = 0;
    printf("Bank account type\n (1) Checking\n (2) Saving\n (3) Fixed Deposit\n");
    printf("Please choose an account type: ");//asking user input
    scanf("%d", &account);

    while(account < 1 || account > 3){
        printf("Please enter a number 1-3. \n");//checking for error if input amount doesn't fall withing range
        scanf("%d", &account);
    }
    printf("Enter a year: ");
    scanf("%lf", &year);

    while(year < 1 || year > 10){
        printf("Incorrect input, year should be between 1-10.\n");
        scanf("%lf", &year);
    }
    printf("Enter the amount: ");
    scanf("%lf", &amount);
    while(amount <= 0){
        printf("Incorrect input, enter a positive amount\n");
        scanf("%lf", &amount);
    }
    switch(account){
        case 1://intrest rate for checking account
            rate = .05;
            break;
        case 2://intrest rate for savings account
            rate = .10;
            break;
        case 3://intrest rate for fixed deposit
            rate = .15;
            break;
        default: 
            printf("Error! you didnt enter a correct value\n");
            printf("Please choose a number 1-3\n");
    }
    cmpdinterest = amount * (pow(rate,year));//problem i think is here gives me wrong values//
    printf("Total amount after %.2lf years is %.2lf\n",year,cmpdinterest);
    interestearned = (cmpdinterest - amount);
    printf("Total interest earned on the amount %.2lf with the rate %.2lf%% is %.2lf.\n", amount,rate,interestearned);

    return 0;
}   
