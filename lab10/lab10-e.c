//Dylan Barrett
//Lab 10
//Ryan is TA

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
int loadNumbers(char*, int*, int);
void printNumbers(int*, int);
float findAverage(int*, int);
//void printReverse(int*, int);
int max(int*, int);
int min(int*, int);
int writeData(char *, int*, int);
int main(int argc, char** argv)
{
    if(argc != 6)//error checking to make sure it has the correct number of arguments
    {
        printf("Please check argument count.\n");
        return 0;
    }
    int *arrayPointer =malloc(sizeof(int) * 10);//allocating enough space based on size of array from file input
    int arraySize= atoi(argv[1]);//changing string of 8 to the value of 8

    loadNumbers(*(argv+2) , arrayPointer, arraySize);//loading numbers from the first input file input1.txt
    printf("the numbers retrieved from the file input1.txt are:\n");
    printNumbers(arrayPointer, arraySize);//printing the numbers from that input file
    printf("the mean of the array is %.2lf\n", findAverage(arrayPointer, arraySize));//calling function to find averge of teh input file numbers
    printf("the min number in the array is %d\n",min(arrayPointer, arraySize));//calling function to print the min number in the input file
    printf("the max number in the array is %d\n",max(arrayPointer, arraySize));//calling function to print the max number in the input file
    writeData(*(argv+4), arrayPointer, arraySize);
    printf("Output written to the output file ---> output1.txt\n");

    loadNumbers(*(argv+3), arrayPointer, arraySize);//loading numbers from the second input file input2.txt
    printf("\nthe numbers retrieved from the file input2.txt are:\n");
    printNumbers(arrayPointer, arraySize);//printing the numbers from that input file
    printf("the mean of the array is %.2lf\n", findAverage(arrayPointer, arraySize));//calling function to find average of the input file numbers
    printf("the min of all the numbers = %d\n", min(arrayPointer, arraySize));//calling function to find the min number of the input file numbers
    printf("the max of all the numbers = %d\n", max(arrayPointer, arraySize));//calling function to print the max number in the input file
    writeData(*(argv+5), arrayPointer, arraySize);
    printf("Output written to the output file ---> output2.txt\n");

    //cant get this to run correctly
    /*printf("\n****Bonus****\n");
      loadNumbers(*(argv+2), arrayPointer, arraySize);
      printf("\nthe numbers reversed from input1.txt file are: \n");
      printReverse(arrayPointer, arraySize);
      loadNumbers(*(argv+3), arrayPointer, arraySize);
      printf("the numbers reversed from input2.txt file are: \n");
      printReverse(arrayPointer, arraySize);//Cant get numbers to print out in reverse order.
      */
    free(arrayPointer);//freeing up the space that was allocated in beginning of program.
    return 0;
}
int loadNumbers(char* fileName, int* arrayPointer, int arraySize)
{
    FILE* filePointer = fopen(fileName, "r");//opeining the input files
    if (filePointer == NULL)
    {
        printf("Error opening file.");//if file doesnt exist exit program
    }
    int counter =0;
    for(counter =0; counter< arraySize; counter++)
    {
        fscanf(filePointer, "%d", (arrayPointer + counter));//scanning all the numbers in the input file
    }
    fclose(filePointer);
    return 1;
}
int writeData(char* fileName, int* arrayPointer, int arraySize)
{
    FILE* filePointer = fopen(fileName, "w");//opening the output file and writing to it.
    if(filePointer == NULL)
    {
        printf("Error opening file.");//if file doesnt exist exit program
        return 0;
    }
    fprintf(filePointer, "The numbers are:\n");
    int counter=0;
    for(counter =0; counter< arraySize; counter++)
    {
        fprintf(filePointer, "%d ", *(arrayPointer + counter));
    }
    fprintf(filePointer, "\nthe min is: %d\n", min(arrayPointer, arraySize));
    fprintf(filePointer,"the max is: %d\n", max(arrayPointer, arraySize));
    fprintf(filePointer,"the average is: %.2lf\n", findAverage(arrayPointer, arraySize));

    fclose(filePointer);
    return 1;
}
void printNumbers(int *arrayPointer, int arraySize)
{
    int counter=0;
    for(counter=0;counter<arraySize;counter++)
    {
        printf("%d ", *(arrayPointer + counter));//printing the numbers from the input files
    }
    printf("\n");
}
/*int checkSize(int size)
  {
  if(size<1 || size>10)//error checking to make sure input falls within the requirements
  {
  return 0;
  }
  else
  {
  return 1;
  }
  }
  */
float findAverage(int *arrayPointer, int arraySize)
{
    float average=0;
    int i=0;
    for(i=0;i < arraySize;i++)
    {
        average += *(arrayPointer+i);//adding up the total of all numbers in input file
    }
    average /= arraySize;//dividing the total of the input file by the amount of numbers in the input file
    return average;
}
int max(int *arrayPointer, int arraySize)
{
    int i=0;
    int maxValue = *(arrayPointer +0);
    for(i=0;i<arraySize;i++)
    {
        if(maxValue< *(arrayPointer + i))
        {
            maxValue= *(arrayPointer + i);
        }
    }
    return maxValue;
}
int min(int *arrayPointer, int arraySize)
{
    int i=0;
    int minValue = *(arrayPointer + 0);
    for(i=0;i<arraySize;i++)
    {
        if(minValue > *(arrayPointer + i))
        {
            minValue= *(arrayPointer + i);
        }
    }
    return minValue;
}
/*void printReverse(int* arrayPointer, int arraySize)
  {
  if(arraySize[0] == '\0'){
  return;
  }
  else{
  reverse(&arraySize[1]);
  putchar(arraySize[0]);
  }
  }
  */
/*void sort(int *allocatedArray, int size)
  {
  int hold=0;
  int pass=0;
  for(pass=1;pass<size;pass++)
  {
  int i=0;
  for(i=0; i<(size-1);i++)
  {
  if(*(allocatedArray+i)> *(allocatedArray+i+1))
  {
  hold=*(allocatedArray+i);
 *(allocatedArray+i)=*(allocatedArray+i+1);
 *(allocatedArray+i+1)= hold;
 }
 }
 }
 }
 */
