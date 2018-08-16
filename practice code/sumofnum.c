#include <stdio.h>

int main(void)
{
    int x=0;
    int bonusnum;
    int sumeven=0;
    int sumodd=0;
    int sum=0;

    printf("***Bonus***\n");
    printf("Enter a number and I will tell you its sums: ");
    scanf("%d", &bonusnum);
    printf("the numbers are: ");

    for(x=0; bonusnum >= x; x++){
        printf("%d", x);
        sum +=x;
        if(x%2 == 0){
            sumeven += x;
        }
        else
            sumodd += x;
    }
    printf("\nThe sum of all numbers from 0 to %d is %d\n", bonusnum, sum);
    printf("Sum of even numbers = %d\n", sumeven);
    printf("sum of odd numbers = %d\n" , sumodd);
    return 0;
}

