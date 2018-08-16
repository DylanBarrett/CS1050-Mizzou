//Dylan Barrett
//Ta is Ryan
//function calling and returning values
#include<stdio.h>
#include<stdlib.h>

int checkError(int);
int checkEven(int);
int checkPrime(int);
void printMizzou(int);
int addDigits(int);
int smallestLargestSum(int);
int count;
int main(void)
{
    int num, sum;
    printf("enter a positive number: ");
    scanf("%d", &num);
    while(checkError(num) == 0){
        printf("Error! enter a postitve number only\n");
        scanf("%d", &num);   
    }

    if(checkEven(num)==1){
        printf("\n%d is an even number", num);
    }
    else{
        printf("\n%d is an odd number", num);
    }
    if(checkPrime(num) == 1){
        printf("\n%d is a prime number", num);
    }
    else{
        printf("\n%d is not a prime number\n", num);
    }

    sum = addDigits(num);
    printf("\nThe sum of digits in %d is %d\n\n", num, sum);

    printf("Enter the second positive number: ");
    scanf("%d" ,&count);
    while(checkError(count)== 0){
        printf("Error! enter a postive number only\n");
        scanf("%d", &count);
    }

    printMizzou(count);

    printf("\n\n*****BONUS*****\nThe sum of the smallest and largest digit in %d is %d\n", num, addDigits(num));

    return 0;
}//End of main
int checkError(int num){
    if(num > 0){
        return 1;
    }
    else
        return 0;
}
int checkEven(int num){
    if(num%2 ==0){
        return 1;
    }
    else
        return 0;
}
int checkPrime(int num){
    int x;
    for(x=2; x <= num -1; x++){
        if(num % x == 0)
            return 0;
    }
    if(x == num)
        return 1;
}
int addDigits(int num){
    int s=0, a, r;
    a = num;
    while(a)
    {
        r = a % 10;
        s = s + r;
        a = a/10;
    }
    return s;
}
int smallestLargestSum(int num){
    int small= 10;
    int large= -1;
    int check = 0;
    while(num > 0){
        check = num%10;
        if(check > large)
            large = check;
        if(check == 0 || check < small)
            small = check;
        num /=10;
    }
    return small + large;
}
void printMizzou(int num2){
    int count=1;
    for(count=1; count <= num2; ++count){

        if(count % 3 == 0){
            printf("MIZ ");}
        if(count % 5 == 0){
            printf("ZOU ");}
        if(count%3!=0 && count%5!=0){
            printf(" %d ", count);
        }
    }
}
