/*LAB 7
  2 -D ARRAYS
  MATRIX MANIPULATION
  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW_SIZE 10
#define COL_SIZE 10

void load2DArray(int [][COL_SIZE], int );
void print2DArray(int [][COL_SIZE], int);
void print1DArray(int [], int);
void loadDiagonal(int [][COL_SIZE], int, int []);
void printTranspose(int [][COL_SIZE], int);
int findEvenOdd(int [][COL_SIZE], int);
int findZeros(int [][COL_SIZE], int);
int checkError(int);
void findMaxNumber(int [][COL_SIZE], int);

int main(void){

    srand(time(NULL));

    int matrix1[ROW_SIZE][COL_SIZE] = {};

    int diagonalArray[ROW_SIZE] = {};
    int size=0;

    printf("Enter the size of the 2-D array: "); // It will be a square matrix for all purposes this lab
    scanf("%d",&size);

    while(checkError(size)==0){
        printf("Please enter a value between 1-10 only: ");
        scanf("%d",&size);
    }

    load2DArray(matrix1, size);


    printf("THE FIRST 2-D ARRAY is: \n");
    print2DArray(matrix1, size);


    int numberOfZeros = findZeros(matrix1,size);
    printf("The number of zeros in 2-D Array: %d \n",numberOfZeros);

    int numberOfEvens = findEvenOdd(matrix1,size);
    printf("The number of Even numbers: %d\nThe number of Odd numbers: %d\n", numberOfEvens, (size*size)-numberOfEvens);

    printf("The primary diagonal elements in the 2-D array, loaded into a 1-D array are: ");
    loadDiagonal(matrix1,size,diagonalArray);
    print1DArray(diagonalArray,size);

    printf("\nThe transpose of the 2-D Array is \n");
    printTranspose(matrix1,size);

    printf("\n************ BONUS ***********\n");

    findMaxNumber(matrix1,size);

    return 0;
}
void printTranspose(int matrix[ROW_SIZE][COL_SIZE], int size){

    int i=0;
    int j=0;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%d ",matrix[j][i]);
        }
        printf("\n");
    }
}
void print2DArray(int matrix[][COL_SIZE], int size){

    int i=0;
    int j=0;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void load2DArray(int matrix[][COL_SIZE], int size){

    int i=0;
    int j=0;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            matrix[i][j] = rand()%10;
        }
    }
}
void print1DArray(int array[], int size){

    int i=0;
    for(i=0;i<size;i++){
        printf("%d ",array[i]);
    }
}
int checkError(int val){
    if(val <=0 || val >20){
        return 0;
    }
    return 1;
}
void loadDiagonal(int matrix[][COL_SIZE], int size, int diagonalArray[]){

    int i=0;
    int j=0;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(i == j){
                diagonalArray[i] = matrix[j][i];
            }
        }
    }
}
int findZeros(int matrix[][COL_SIZE], int size){

    int i=0;
    int j=0;
    int count =0;

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(matrix[i][j]==0){
                count++;
            }
        }
    }
    return count;
}
int findEvenOdd(int matrix[][COL_SIZE], int size){

    int i=0;
    int j=0;
    int evenCount=0;

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(matrix[i][j]%2 ==0){
                evenCount++;
            }
        }
    }
    return evenCount;
}
void findMaxNumber(int matrix[][COL_SIZE], int size){

    int i=0;
    int j=0;
    for(i=0;i<size;i++){
        printf("ROW %d\n", i);
        int frequency[10]={0};
        for(j=0;j<size;j++){
            frequency[matrix[j][i]]++;
        }
        int k =0;
        int maxOccurence=0;
        int maxIndex =-1;
        for(k=0;k<size;k++){
            printf("%d --------------> %d\n",k,frequency[k] );
            if(frequency[k]>maxOccurence){
                maxOccurence = frequency[k];
                maxIndex = k;
            }
        }
        printf(" %d occurs %d times\n",maxIndex,maxOccurence);
    }
}
