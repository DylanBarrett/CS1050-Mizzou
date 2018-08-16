#include <stdio.h>

int main (void)
{
    int numberToPrint;
    printf("Hello World!\nPlease give me a number!");
    scanf("%d" , &numberToPrint);

    if(numberToPrint > 50)
    {
        printf("Wow. What a big number!!\n");
    }
    else
    {
        printf("What a small number.\n");

    }

    printf("%d is the number I typed." , numberToPrint);
    return 0;


}
