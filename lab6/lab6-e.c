//Dylan Barrett
//TA is Ryan
//Lab 6 


#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 50

int checkError(int);
void initializeArray(int[], int);
void printArray(int[], int);
int max(int[],int);
float average(int[],int);
int count_numbers(int[],int,int);
int common_numbers(int[],int[],int);
void sort(int[],int);
int main(void)
{
    srand(time(NULL));
    int a[SIZE];
    int b[SIZE];
    int choice;
    int count;
    printf("enter the size of the input:");
    scanf("%d", &choice);
    while(checkError(choice) ==0){
        printf("Invalid input! enter the size of the input again: \n");
        scanf("%d", &choice);
    }
    initializeArray(a, choice);//initializing first array
    printf("\nInput array 1\n");
    printArray(a, choice);//printing first array random values
    printf("\nThe maximum number is present at the index location %d in the array\n", max(a,choice));
    printf("Average of numbers in the first array is %.2f\n", average(a,choice));

    initializeArray(b, choice);//initializing second array
    printf("\nInput array 2\n");
    printArray(b, choice);//printing second array random values
    printf("\n");
    printf("\nThe maximum number is present at the index location %d in the array\n", max(b,choice));
    printf("Average of numbers in the second array is %.2f\n\n", average(b, choice));

    printf("Enter a number: ");
    scanf("%d", &count);
    printf("the count of number %d in the first array is %d\n", count, count_numbers(a, choice, count));
    printf("the count of number %d in the second array is %d\n", count, count_numbers(b, choice, count));

    //BONUS/////
    printf("\n***Bonus part***\n");
    printf("\nthe number of common numbers in the two arrays: %d\n", common_numbers(a, b, choice));
    //cant get the numbers in common to work and cant get the sorting to work either.
    //
    //
    //
    printf("\nArrays befor sorting\n");
    printArray(a, choice);
    printf("\n");
    printArray(b, choice);
    printf("\nArrays after sorting\n");
    printArray(a, choice);
    printf("\n");
    printArray(b, choice);
    return 0;
}//end main

int checkError(int num) 
{
    if(num < 1 || num > 50)
        return 0;
    else
        return 1;
}
void initializeArray(int a[], int choice)
{
    int x;
    for(x=0;x< choice; x++)
    {
        a[x] = rand()%10;
    }
}
void printArray(int a[], int choice)
{
    int x;
    for(x=0; x < choice; x++){
        printf("%d ", a[x]);
    }
}
int max(int a[],int choice){
    int x;
    int max = -1;
    int maxindex = 0;
    for(x=0;x < choice; x++){
        if(a[x] > max){
            max = a[x];
            maxindex = x;
        }
    }
    return maxindex;
}
float average(int a[], int choice){
    int x;
    int sum = 0;
    float average;
    for(x = 0; x < choice; x++){
        sum += a[x];
    }
    average = (float)sum / (float)choice;
    return average;
}
int count_numbers(int a[], int choice, int count){
    int x; 
    int counter = 0;
    for(x = 0; x < choice; x++){
        if(a[x] == count){
            counter++;
        }
    }
    return counter;
}
int common_numbers(int a[], int b[], int choice){
    int x;
    int counter = 0;
    for(x = 0; x < choice; x++){
        if(a[x] == b[x]){
            counter++;
        }
    }
    return counter;
}
void sort(int a[], int choice)
{
    int x;
    int pass;
    int hold;
    for(pass = 1; pass < choice; pass++){
        for(x = 0; x < choice; x++){
            if(a[x] > a[x+1]){
                hold = a[x];
                a[x] = a[x+1];
                a[x+1] = hold;
            }
        }
    }
}
