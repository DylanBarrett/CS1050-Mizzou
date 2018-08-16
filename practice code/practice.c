#include <stdio.h>
int main(void)
{
    int integer1, integer2;

    printf("Enter your first integer.\n");
    scanf("%d", &integer1 );

    if(integer1 < 0){
        printf("please choose a non-negative number\n");
    }

    printf("Enter your second integer.\n");
    scanf("%d", &integer2 );

    if(integer2 < 0){
        printf("please choose a non-negative number\n");
    }
    int Product;
    Product = integer1 * integer2;
    printf("Product is %d\n", Product);
    return 0;

}
