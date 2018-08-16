#include<stdio.h>
#include<stdlib.h>
void shuffle(int card[])
{
    int i;
    srand(time(NULL));
    for(i=0;i<13;i++)
    {
        int cardNo = rand()%(13-i);
        int temp = card[cardNo];
        card[cardNo] = card[13-i-1];
        card[13-i-1]=temp;
    }


}
int main(void)
{
    int deck[13], i;
    for(i=0;i<13;i++)
        deck[i]= i+1;
    shuffle(deck);

    return 0;
}

