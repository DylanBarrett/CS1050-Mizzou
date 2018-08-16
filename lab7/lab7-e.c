//Dylan Barrett
//Ta is Ryan
//lab 7
//2d arrays

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 20

int errorCheck(int);
void initialize2DArray(int[][MAX], int);
void print2DArray(int[][MAX], int);
int findZeros(int [][MAX], int);
int findEvenOdd(int [][MAX], int);
int findOdd(int[][MAX], int);
void loadDiagonal(int[][MAX],int, int[MAX]);
void print1DArray(int [],int);
void printTranspose(int[][MAX], int);
int main(void)
{
    srand(time(NULL));
    int array[MAX][MAX];
    int size;

    printf("Enter the size of the 2-D array: ");
    scanf("%d", &size);
    while(errorCheck(size) == 0){
        printf("Please Enter the size of the array between 1-20 only: ");
        scanf("%d", &size);
    }
    initialize2DArray(array, size);
    printf("The first 2-D array is:\n");
    print2DArray(array, size);

    printf("The numbers of zeros in 2-D Array: %d\n",findZeros(array, size));
    printf("The number of even numbers is: %d\n",findEvenOdd(array, size));
    printf("The number of odd numbers is: %d\n", findOdd(array, size));
    printf("the transpose of the 2-D array is \n");
    printTranspose(array, size);
    //printf("the primary diagonal elements in the 2-D array, loaded into a 1-D array are: %d ", print1DArray); 
    printf("\n");
    return 0;
}//end main

int errorCheck(int size)
{
    if(size < 1 || size > 20){
        return 0;
    }
    else
        return 1;
}
void initialize2DArray(int array[][MAX], int size)
{
    int row;
    int column;
    for(row =0; row < size; row++){
        for(column = 0; column < size; column++){
            array[row][column] = rand()%10;
        }
    }
}
void print2DArray(int array[][MAX], int size)
{
    int row;
    int column;
    for(row =0; row < size; row++){
        for(column = 0; column < size; column++){
            printf("%3d ", array[row][column]);
        }
        printf("\n");
    }
}
int findZeros(int array[][MAX], int size)
{
    int zerocounter =0;
    int row =0;
    int column =0;
    for(row =0; row < size; row++){
        for(column =0; column < size; column++){
            if(array[row][column] ==0){
                zerocounter++;
            }
        }
    }
    return zerocounter;
}
int findEvenOdd(int array[][MAX],int size)
{
    int row;
    int even =0;
    int column =0;
    for(row =0; row < size; row++){
        for(column =0; column < size; column++){
            if(array[row][column]%2 == 0){
                even++;
            }
        }
    }
    return even;
}
int findOdd(int array[][MAX], int size)
{    
    int row;
    int odd =0;
    int column =0;
    for(row =0; row < size; row++){
        for(column =0; column < size; column++){
            if(array[row][column]%2 != 0){
                odd++;
            }
        }
    }
    return odd;
}
//void loadDiagonal(int array[][MAX],int size, int a[MAX])
//{
//  int i,j;
//for(i=0; i < size; i++){
//  for(j=0 ; j < size; j++)
//{
//  if(i==j)
//{
//  printf("%d", array[i]);
//      }
//    }
//  }
//}
void print1DArray(int a[],int size)
{
    int x;
    for(x=0; x< size; x++)
    {
        printf("%d", a[x]);
    }
}
void printTranspose(int array[][MAX], int size)
{
    int row;
    int column;
    for(row=0; row< size; ++row){
        for(column = 0; column< size; ++column){
            printf("%3d ", array[column][row]);
        }
        printf("\n");
    }
}
