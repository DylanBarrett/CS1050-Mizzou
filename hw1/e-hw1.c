//Dylan Barrett 
//lab E homework 1
//Ta is Ryan
//calculate electric bill

#include <stdio.h>
int main(void)
{  
    int x =0;
    int bonusnum;
    int sum =0;
    int sumeven = 0;
    int sumodd = 0;
    int cont =1;
    int connection;
    double units,rate,energy_charge,customer_charge,total_bill;
    while(cont == 1){
        printf("*****ELECTRICITY BILL CALCULATOR******\n");
        printf("1. Residential\n2. Commercial\n3. Industrial\n.");//prompting user input on connection
        printf("Choose the type of connection type: ");
        scanf("%d", &connection);//scanning input into system

        if(connection == 0){//sentinel for exiting whenever user wants to// 
            printf("Exiting electric bill calculator\n");break;}
        else{
            while(connection <  1 || connection > 3){//continuing programing if connection doesnt equal 0 but checking if the input falls within valid range of 1-3//
                printf("Invalid input! please enter a valid choice:\n");
                scanf("%d" , &connection);
            }
            printf("Enter the number of units (in kWh): ");//number of units consumed by connection//
            scanf("%lf" , &units);
            while(units < 1 )
            {
                printf("Invalid Input! Please enter a positive value:\n ");//only accepting numbers greater than or equal to 1//
                scanf("%lf" , &units);
            }
            switch(connection){//running certain calculations based on the users input for the type of connection//
                case 1://residental cost
                    if(units > 0 && units <= 300){rate = 7.5;}
                    else if(units > 300 && units <=750){rate = 10;}
                    else if(units > 750 && units <= 1500){rate = 13.50;}
                    else if(units > 1500){rate = 15;}
                    if(connection == 1){customer_charge = 25;}
                    break;

                case 2://commercial cost
                    if(units > 0 && units <= 300){rate = 10.50;}
                    else if(units > 300 && units <= 750){rate = 14;}
                    else if(units > 750 && units <=  1500){rate = 17.50;}
                    else if(units > 1500){rate = 20;}
                    if(connection == 2){customer_charge = 90;}
                    break;

                case 3://Industrial cost
                    if(units > 0 && units <= 300){rate = 36.50;}
                    else if(units > 300 && units <= 750){rate = 40;}
                    else if(units > 750 && units <= 1500){rate = 45.50;}
                    else if(units > 1500){rate = 50;}
                    if(connection == 3){customer_charge = 850;}
                    break;
                default:
                    printf("Error! you didn't enter a correct value\n.");
                    printf("Please choose a number 1-3\n.");
            }
            energy_charge =(units * (rate/100));//calclating the energy charge based on units consumed times the rate 
            printf("Total energy charge for the customer is $%.2f\n" , energy_charge);

            total_bill =(energy_charge + customer_charge);//summing total bill from energy charge plus customer flat rate charge//
            printf("Total bill from connection is $%.2f\n\n" , total_bill);

            printf("Do you want to continue?\n");
            printf("Press 1 to continue or 0 to exit.\n\n");//asking user if they want to run program again//
        }}

    //bonus
    printf("\n***Bonus***\n");
    printf("\nEnter a number and i will tell you its sums: ");
    scanf("%d", &bonusnum);
    printf("the numbers are: ");

    for(x=0; bonusnum >= x; x++){
        printf("%d" , x);
        sum +=x;
        if (x%2 == 0){
            sumeven += x;
        }
        else
            sumodd +=x;
    }
    printf("\nThe sum of all numbers from 0 to %d is %d\n", bonusnum, sum);
    printf("Sum of even numbers = %d\n", sumeven);
    printf("Sum of odd numbers = %d\n" , sumodd);

    return 0;
}

