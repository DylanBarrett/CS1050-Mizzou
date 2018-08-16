//Dylan Barrett
//Ta is Ryan
//Homework 2
//Casino

#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#define SIZE 13
int checkError(int);
void DisplayMenu();
void swap(int *, int *);
void shuffle(int []);
int drawCard(int[]);
int luckySeven(int);
int highCard(int, int);
double calculateWinnings(int, int,double);
int main(void)
{ 
    srand(time(NULL));
    double money=100;
    int deck[SIZE];//setting the deck size = to 13
    while(money>0)//asking user repeatedly if they want to play or exit as long as money > 0
    {
        DisplayMenu();//calling function and scanning in choice
        int choice;
        scanf("%d", &choice);
        if(choice == 3)//sentinel to break if number 3 is entered to exit the program
        {
            printf("Thanks for playing.\n");
            break;
        }
        else{
            while(checkError(choice)==0)
            {
                printf("Invalid input! Enter a valid number.\n\n\n");
                DisplayMenu();
                scanf("%d", &choice);
            }
        }
        double bet;
        while(1)
        {
            int i;
            for(i=0; i< SIZE; i++)
            {
                deck[i] = i+1;
            }
            printf("Enter the amount you want to bet: $");//asking user how much they want to bet, scanning it in, then checking to see if the bet falls within the check
            scanf("%lf", &bet);
            if(bet <= 0 || bet >money)
            {
                printf("Please enter a bet from 0 to %.2f\n",money);
            }
            else{
                break;
            }
        }
        shuffle(deck);
        int card = drawCard(deck);
        if(choice ==1)
        {
            int result = luckySeven(card);//results for lucky seven program
            if(result ==0)
            {
                printf("you drew %d you lose\n", card);
            }
            else
            {
                printf("you drew %d you won\n", card);
            }
            money= money + calculateWinnings(1,result,bet);
            printf("Money left: $%.2f\n\n", money);
        }
        else{
            shuffle(deck);
            int compCard=drawCard(deck);
            int result = highCard(card,compCard);
            if(result ==0)
            {
                printf("you drew %d you lose.\n", card); //the dealer drew %d. You lose!\n", card, compCard);//results for high card program 
            }
            else
            {
                printf("you drew %d you win.\n",card);//the dealer drew %d. You won!\n", card, compCard);
            }
            money= money + calculateWinnings(2,result,bet);//calculating and printing results for users money
            printf("Money left: $%.2f\n", money);
        }
        if(money<=0){//if statement executed when money falls below 0.
            printf("You have been thrown out of the casino.\n");
            printf("Be more careful with your money next time!\n");
        }
    }
    return 0;
}//End of main
void DisplayMenu()
{
    printf("Welcome to the Guilliams Casino!\n\n");
    printf("Which game do you want to play?\n");
    printf("1)Lucky Seven\n");
    printf("2)High Card\n");
    printf("3)Exit\n");
}
int checkError(int choice)
{
    if(choice < 1 || choice > 3)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void swap(int *i, int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
void shuffle(int arr[])
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        j=rand()%(SIZE);
        swap(&arr[i],&arr[j]);
    }
}
int drawCard(int arr[])
{
    int card;
    int i;
    for(i=0;i<SIZE;i++)
    {
        if(arr[i] != -1)
        {
            card=arr[i];
            arr[i] = -1;
        }
    }
    return card;
}
int luckySeven(int card)
{
    if(card%7==0)
    {
        return 1;
    }
    else
    { 
        return 0;
    }
}
int highCard(int a, int b)
{
    if(a >= b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
double calculateWinnings(int game, int result, double bet)
{
    if(result ==0)
    {
        return -bet;
    }
    else
    {
        if(game ==1)
        {
            return 7*bet;
        }
        else
        {
            return bet;
        }
    }
}
