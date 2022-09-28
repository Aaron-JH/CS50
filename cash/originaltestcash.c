#include <stdio.h>
#include <cs50.h>

int main(void)
{
//creating integer variables that are 0 with float
    float amount;
    int quarters = 0;
    int dimes = 0;
    int nickles = 0;
    int pennies = 0;

    do
    {
    //request input from user
        amount = get_float("Amount of cash owed: $");
        printf("\n");
    }
    //while loop
    while(amount < 0);
//while loop for if amount is > 0
    while (amount > 0)
    {
    //if condition of amount is >= .25 then it should add a 1 to the quarters variable
        if (amount >= 0.25)
        {
            amount = amount-0.25;
            quarters += 1;
        }
            //else if condition of amount is >= .10 then it should add a 1 to the dimes variable
        else if (amount >= 0.10)
        {
            amount = amount-0.10;
            dimes += 1;
        }
        //else if condition of amount is >= .05 then it should add a 1 to the nickels variable
        else if (amount >= 0.05)
        {
            amount = amount-0.05;
            nickles += 1;
        }
        //else condition of amount is >= .01 then it should add a 1 to the pennies variable
        else //if (amount >= 0.01)
        {
            amount = amount-0.01;
            pennies += 1;
        }
    }

//calculates total of coins owed in an int value
    int total_coins = quarters + dimes + nickles + pennies;

    //prints total of coins owed and prints variable values
    printf("Total number of coins: %i\n", total_coins);
    printf("Total number of quarters: %i\n", quarters);
    printf("Total number of dimes: %i\n", dimes);
    printf("Total number of nickles: %i\n", nickles);
    printf("Total number of pennies: %i\n", pennies);

}