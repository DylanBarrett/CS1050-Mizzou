//Dylan Barrett
//Lab 9
//TA is Ryan
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define SIZE 50
//prototypes
void initializeArray(int *, int);
void printArray(int *, int);
int checkSize(int);
void sort(int*, int);
float standardDeviation(int*, int);
float median(int*, int);
float mean(int *, int);
int findMaxNumber(int *, int);
int main(void) 
{
    srand(time(NULL));
    //int* allocatedArray = (int*)malloc(sizeof(int) * SIZE);
    int array[SIZE];
    int *p= array;
    int size=0;
    printf("enter the size of the input: ");//asking user how big they want array to be.
    scanf("%d", &size);
    while(checkSize(size)==0)
    {
        printf("Invalid input. Enter the size of the array again: ");// error checking to see if it falls within limits
        scanf("%d", &size);
    }
    initializeArray(p, size);//calling function to initialize random array
    printf("\nInput Array\n");
    printArray(p, size);//calling function to print random array that was just initialized
    sort(p, size);//sorting the first array
    printf("\nSorted Array\n");
    printArray(p, size);//printing the sorted array
    printf("Median of the array is %.2f\n", median(p, size));
    printf("Standard deviation is %.2lf\n", standardDeviation(p, size));
    //mean(p, size);//calling the mean function to find and display the average of numbers in array
    //printf("Average is: %lf\n", mean);
    //findMaxNumber(p, size);
    return 0;
}
void initializeArray(int *p, int size)
{
    srand(time(NULL));
    int counter=0;
    for(counter=0; counter<size;counter++)
    {
        *(p + counter )=rand()%5 + 1;//random numbers between 1 and 5.
    }
}
void printArray(int *p, int size)
{
    int counter=0;
    for(counter=0; counter<size;counter++)
    {
        printf("%d ", *(p + counter));
    }
    printf("\n");
}
int checkSize(int size)
{
    if(size<1 || size>50)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
/*float mean(int *p, int size)
  {
  int i=0;
  float mean=0;
  for(i=0; i<size; i++)
  {
  mean += *(p + i);
  }
  mean /= size;
  return mean;
  }
  */
float median(int *p, int size)
{
    float medianVal =0;
    //sorting array
    sort(p, size);
    if(size%2==0)
    {
        medianVal += *(p+(size/2));//add value to right of middle element
        medianVal += *(p+((size/2)-1)); //add value to left of middle element
        medianVal /= 2; //takes average of two 
    }
    else
    {
        medianVal = *(p+(size-1)/2);//assigns the value to the middle of the sorted array
    }
    return  medianVal;
}
float standardDeviation(int*p , int size)
{  
    float mean =0;
    int i=0;
    for(i=0; i<size; i++)
    {
        mean += *(p+i);
    }
    mean /= size;
    float std_sum=0;
    for(i=0; i<size;i++)
    {   
        float temp = (*(p+i) - mean);
        std_sum += pow(temp, 2);
    }
    std_sum /= (size-1);
    float standardDeviation = sqrt(std_sum);
    return standardDeviation;
}
void sort(int *p, int size)
{
    int hold=0;
    int pass =0;
    for(pass=1; pass<size; pass++)
    {
        int i=0;
        for(i=0; i<(size-1); i++)
        {
            if(*(p+i)> *(p+i+1))
            {
                hold = *(p+i);
                *(p+i) = *(p+i+1);
                *(p+i+1) = hold;
            }
        }
    }
}
/*int findMaxNumber(int *p, int size)
  int k=0;
  int maxOccur=0;
  int maxIndex=0;
  for(k=0;k<size;k++)
  {
  if(frequency*(p)>maxOccur){
  maxOccur = frequency*(p);
  maxIndex=k;
  }
  }
  printf("the number which occurs more than (%d/2) times in the input array is %d", size, maxIndex);
  }
  }*/
