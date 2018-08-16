//sorting numbers
//
#include<stdio.h>
int main(void){
    int array[100],n,c,d,pos,swap;
    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);

    for(c=0; c< n; c++)
        scanf("%d", &array[c]);

    for(c=0; c <(n-1); c++){
        pos = c;

        for(d =c +1; d < n; d++){
            if(array[pos] > array[d])
                pos = d;
        }
        if(pos != c){
            swap = array[c];
            array[c] = array[pos];
            array[pos] = swap;
        }
    }
    printf("Sorted list in ascending order: \n");
    for(c=0; c < n; c++)
        printf("%d\n", array[c]);
    return 0;
}

