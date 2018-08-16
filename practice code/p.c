#include <stdio.h>

int main(void)
{
    printf("Enter two integers seperated by a comma and i will you\n the relationship they satisfy.\n");

    int num1, num2;
    scanf("%d,%d", &num1, &num2 );

    if (num1 == num2){
        printf("%d is equal to %d\n", num1, num2 );
    }
    if(num1 != num2){
        printf("%d is NOT equal to %d\n", num1, num2 );
    }
    if(num1 < num2){
        printf("%d is strictly less than %d\n", num1, num2 );
    }
    if(num1 <= num2){
        printf("%d is less than or equal to %d\n", num1, num2 );
    }
    if(num1 > num2){
        printf("%d is strictly greater than %d\n", num1, num2 );
    }
    if(num1 >= num2){
        printf("%d is greater than or equal to %d\n", num1, num2 );
    }
    return 0;
}
