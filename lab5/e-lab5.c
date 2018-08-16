//Dylan Barrett
//pawprint dcbk34
//TA is Ryan
//lab 5

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int checkError(int);
int calculateRandomDiscount(void);
void drinkMenu(void);
void displayMenu(void);
void displayReceipt(void);
float calculateTax(float);
int main(void){
    double subtotal;
    double total;
    int drink;
    int food;
    float drinkcost;
    float foodcost;
    double tax;
    double taxrate;
    srand(time(NULL));
    drinkMenu();
    printf("Enter an option: ");
    scanf("%d", &drink);
    while(checkError(drink)<1 || checkError(drink)>4){
        printf("Error! Enter a number 1-4: \n");
        scanf("%d", &drink);
    }
    switch(drink){
        case 1:
            drinkcost =0;
            break;
        case 2:
            drinkcost =1.00;
            break;
        case 3:
            drinkcost =1.50;
            break;
        case 4:
            drinkcost = 1.75;
            break;
    }

    displayMenu();
    printf("Enter an option: ");
    scanf("%d", &food);
    while(checkError(food)<1 || checkError(food)>4){
        printf("Error! Enter a number 1-4: \n");
        scanf("%d", &food);
    }
    switch(food){
        case 1:
            foodcost = 4.50;
            break;
        case 2:
            foodcost = 3.00;
            break;
        case 3:
            foodcost = 5.00;
            break;
        case 4:
            foodcost = 7.20;
            break;
    }
    printf("Thank you for your order! it will be made shortly!\n");
    subtotal =(foodcost + drinkcost);
    printf("subtotal: $\n",subtotal);

    printf("Taxes: $\n", tax);
    calculateRandomDiscount();
    total = (subtotal + tax);
    printf("Total: $\n", &total);
    displayReceipt();
}

int checkError(int num){
    if(num <1 || num>4){
        return 0;
    }
    else
        return 1;
}
//float calculateTax(float){
//  float subtotal = 0;
//    float flatrate = .50;
//  float rate =0;
// if(subtotal > 4){rate = 25% subtotal + flatrate};
//  else(subtotal <= 4){rate = subtotal *10% + flatrate};
//}

int calculateRandomDiscount(void){
    int discount =rand()%10;
    float discountRate = (float)discount/ 100;
    printf("you get a discount of %f\n", discountRate);
}
void drinkMenu(void){
    int drink;
    printf("What would you like to drink?\n");
    printf("1. Water: free\n2. Coke: $1.00\n3. Lemonade: $1.50\n4. Chocolate Milk: $1.75\n\n");
}
void displayMenu(void){
    int food_cost;
    printf("What would you like to eat?\n");
    printf("1. Cheeseburger: $4.50\n2. Hotdog:$3.00\n3. Chicken Strips: $5.00\n4.Fries and Burger Combo: $7.20\n\n");
}
void displayReceipt(void){
    int x=0;
    x= x*8 + rand()%8;
    printf("Your receipt number is: #%d\n", &x);
}
