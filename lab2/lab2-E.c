/*dylan barrett (dcbk34)*/
/*lab2-e*/
//Ryan is my TA
/*control flow/math*/

#include <stdio.h>
int main(void)
{
    double num1 = 0;
    double num2 = 0;

    printf("Enter your first non-negative number:");
    scanf("%lf", &num1);

    if (num1 < 0)
    {
        printf("Error!\n Please enter a non-negative number:\n");
        scanf("%lf" , &num1);
    }
    printf("the value of our variable is %.2lf\n" ,num1);//rounding the input number to the 2nd decimal


    printf("Enter your second non-negative number:");
    scanf("%lf" , &num2);

    if (num2 < 0)
    {
        printf("Error! Please enter a non-negative number:\n");
        scanf("%lf" , &num2);
    }
    printf("the value of our variable is %.2f\n" , num2);// rounding the input number to the 2nd decimal place
    //Bonus from here till
    while(num1 == 0)
    {
        printf("You cannot divide by zero!\n");
        printf("Enter anohter number: \n");
        scanf("%lf", &num1);
    }
    while(num2 == 0)
    {
        printf("you cannot divide by zero!\n");
        printf("enter another number: \n");
        scanf("%lf" , &num2);
    }
    //Bonus ends here 
    if ( num1 < num2 )
    {
        printf("%lf is the bigger number\n:", num2);
    }
    if ( num1 > num2 )
    {
        printf("%lf is the bigger number\n:", num1);
    }
    double productOfNumbers = 0; //multiplying the numbers
    productOfNumbers = num1 * num2;
    double divisionOfNumbers = 0; //divison of the numbers
    divisionOfNumbers = num1 / num2;
    double sumOfNumbers = 0;// sum of the numbers
    sumOfNumbers = num1 + num2;
    double subtractionOfNumbers = 0;// difference of the numbers
    subtractionOfNumbers = num1 - num2;
    printf("the numbers Multiplied is %.2lf\n" , productOfNumbers);
    printf("the numbers divided is %.2lf\n" , divisionOfNumbers);
    printf("the numbers added is %.2lf\n" , sumOfNumbers);
    printf("the numbers subtracted is %.2lf\n" , subtractionOfNumbers);

    return 0;
}
