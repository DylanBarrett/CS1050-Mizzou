//Dylan Barrett
//TA is Ryan Section E
//Pawprint DCBk34
//HW3
//reading and writing to files
//cant get the clean function to work
//cant get the sort function to sort the cleaned data just prints the last sorted value 7007 5289.82 etc....
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
bool loadData(char*, int*, double*, char*, int);//done
void printData(int*, double*, char*, int);//done
int highAmt(double*, int);//done
int lowAmt(double*, int);//done
float averageAmt(double*, int);//done
bool writeData(char*, int*, double*, char*, int);//done
int checkPalindrome(int);//done
int cleanData(int*, double*, char*, int*, double*, char*, int);//needs work
void sortData(int*, double*, char*, int);//needs work
int main(int argc, char **argv)
{
    if(argc != 5)//error checking to make sure it has the correct number of arguments
    {
        printf("Argument count should be 5.\n");
        return 0;
    }
    int Size= atoi(*(argv+1));
    int indexHigh=0;
    int indexLow=0;
    int *id=malloc(sizeof(int)*Size);
    double *amt=malloc(sizeof(double)*Size);
    char *desig=malloc(sizeof(char)*Size);
    int *idClean=malloc(sizeof(int)*Size);
    double *amtClean=malloc(sizeof(double)*Size);
    char *desigClean=malloc(sizeof(char)*Size);

    loadData(*(argv+2),id,amt,desig,Size);//loading numbers from the input file hw3input.txt
    printData(id, amt, desig, Size);
    indexHigh=highAmt(amt, Size);
    indexLow=lowAmt(amt, Size);
    printf("\nThe TA with ID %d has the max amount of %.2lf from the original file data.\n",*(id+indexHigh), *(amt+indexHigh));
    printf("\nThe TA with ID %d has the min amount of %.2lf from the original file data.\n", *(id+indexLow), *(amt+indexLow));
    printf("\nThe average amount across all the TAs is %.2lf.\n", averageAmt(amt, Size));
    writeData(*(argv+3), id, amt, desig,Size);
    printf("\nData from hw3Input.txt is now written to hw3BadOuput.txt\n");
    printf("\n*****DATA AFTER CLEANING*****\n\n");
    loadData(*(argv+2),id,amt,desig,Size);
    cleanData(id, amt, desig, idClean, amtClean, desigClean, Size);
    sortData(id,amt,desig,Size);
    printData(id, amt, desig, Size);
    printf("\nThe TA with ID %d has the max amount of %.2lf from the updated file data.\n",*(id+indexHigh), *(amt+indexHigh));
    printf("\nThe TA with ID %d has the min amount of %.2lf from the updated file data.\n", *(id+indexLow), *(amt+indexLow));
    printf("\nThe average amount across all the TAs is %.2lf.\n", averageAmt(amt, Size));
    writeData(*(argv+4), id, amt,desig,Size);
    printf("\nUpdated output written to hw3GoodOutput.txt\n");

    //free(id);//Whenever i try to free space it runs then throws a backtrace, memory map then aborts. Not sure how to fix it.
    //free(amt);
    //free(desig);
    //free(idClean);
    //free(amtClean);
    //free(desigClean);//freeing up the space that was allocated in beginning of program
    return 0;
}//end of main*/
bool loadData(char* filename, int* id, double* amt, char* desig, int Size)
{   
    FILE *filePointer=fopen(filename,"r");
    if(filePointer==NULL)
    {
        printf("Can't open input file\n");
        return false;
    }
    int i=0;
    for(i=0; i<Size;i++)
    {
        fscanf(filePointer, "%d %lf %c", (id+i),(amt+i),(desig+i));
    }
    fclose(filePointer);
    return 1;
}
void printData(int *id, double *amt, char *desig, int Size)
{
    printf("\nAccount\tAmounts\tDesignation\n");
    int i=0;
    for(i=0;i<Size;i++)
    {
        printf("%d\t%.2lf\t\t%c\n", *(id+i), *(amt+i), *(desig+i));//printing the numbers from the input files
    }
}
int highAmt(double *amt, int Size)
{

    float high=0;
    int i=0;
    int index=0;
    high =*(amt);
    for(i=0;i<Size;i++)
    {
        if(*(amt + i)> high)
        {
            high =*(amt + i);
            index=i;
        }//end if loop
    }//end for loop
    return index;
}
int lowAmt(double *amt, int Size)
{
    int i=0;
    float low=0;
    int index=0;
    low= *(amt);
    for(i=0;i<Size;i++)
    {
        if(*(amt +i)<low)
        {
            low = *(amt+i);
            index=i;
        }//end if loop
    }//end for loop
    return index ;
}
float averageAmt(double *amt, int Size)
{
    float total=0;
    int i=0;
    for(i=0; i<Size;i++)
    {
        total += *(amt +i);;//adding up the total of all values in the input file
    }
    return total/Size;//dividing the total of the input file by the amount of numbers in the input file
}
bool writeData(char* filename, int* id, double* amt, char* desig, int Size)
{
    FILE* filePointer = fopen(filename, "w");//opening the output file and writing to it.
    int indexH;
    int indexL;
    if(filePointer == NULL)
    {
        printf("Error opening file.");//error message if file doesn't exist
        return 0;
    }
    int i=0;
    fprintf(filePointer, "Name\tAccount No.\tAmmount\n" );
    for(i=0;i<Size;i++)
    {
        fprintf(filePointer, "%d\t%.2lf\t\t%c\n", *(id+i), *(amt+i), *(desig+i));
    }
    indexH=highAmt(amt, Size);
    fprintf(filePointer,"the TA with the id %d has the highest amount %.2lf in the data file\n", *(id+indexH), *(amt+indexH));

    indexL=lowAmt(amt, Size);
    fprintf(filePointer,"the TA with the id %d has the highest amount %.2lf in the data file\n", *(id+indexL), *(amt+indexL));

    fprintf(filePointer, "the average amount is %.2lf\n", averageAmt(amt, Size));
    fclose(filePointer);
    return 1;
}
int checkPalindrome(int id)
{
    int revNum=0;
    int dig=0;
    while(id>0)
    {
        dig= id%10;
        revNum=revNum*10 +dig;
        id = id/10;
    }
    if(id==revNum){
        return 1;
    }
    else{
        return 0;
    }
}
int cleanData(int *id, double *amt, char *desig, int *idClean, double *amtClean, char *desigClean, int Size)//cant get this function to work have tried multiply ways to get it to work
{
    int *p1,*p2,i, validCount;
    double *q1,*q2;
    char *r1,*r2;

    p1= id;
    q1= amt;
    r1= desig;
    p2= idClean;
    q2= amtClean;
    r2= desigClean;
    validCount=0;
    //int j=0;
    //int i=0;
    for(i=0;i<Size;i++)
    {
        if(checkPalindrome (*p1)&&(*q1>=500 && *q1<=5000)&& *r1 !='P')
        {
            *p2=*p1;
            *q2=*q1;
            *r2=*r1;
            p2++;
            q2++;
            r2++;
            validCount++;
        }
        p1++;
        q1++;
        r1++;
    }
    return validCount;
}
void sortData(int* id, double* amt, char* desig, int Size)//sort data function kind of works, only sorts the last data set of ID 7007. not sure how to fix it.
{  
    if(Size<=13)
    {
        int i;
        int j;
        double tempAmt;
        int tempId;
        char tempDesig;
        int check=-1;
        for(i=0;i<2;i++)
        {
            for(j=0;j<Size;j++)
            {
                if(i==0)
                {
                    if(*(desig+j)=='J')
                    {
                        tempDesig= *(desig+j);
                        tempId= *(id+j);
                        tempAmt= *(amt+j);
                        check++;
                    }
                }
                if(i==1)
                { 
                    if(*(desig+j)=='S')
                    {
                        tempDesig= *(desig+j);
                        tempId= *(id+j);
                        tempAmt= *(amt+j);
                        check++;
                    }
                }
                *(desig+j)= *(desig+check);
                *(desig+check)= tempDesig;
                *(amt+j) = *(amt+check);
                *(amt+check)= tempAmt;
                *(id+j)= *(id+check);
                *(id+check)=tempId;
            }
        }
    }
    else{
        printf("Number of records cant be more than 13\n");
    }
}
