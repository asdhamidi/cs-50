#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    //Getting a positive number for change using do-while loop
    do
    {
        change = get_float("Change owed : ");
    }
    while (change < 0);
    //Converting the dollars in cents
    int cents = round(change * 100);
    //Creating separate variables for each type of coin i.e. 25, 10 ,5, and 1.
    int totalcoins = 0, coins25 = 0, coins10 = 0, coins5 = 0, coins1 = 0;
    //Using a nested if-else to get the amount of different types of coins needed.
    if (cents % 25 == 0)
    {
        coins25 = cents / 25;
    }
    else
    {
        coins25 = cents / 25;
        cents = cents - (coins25 * 25);
        if (cents % 10 == 0)
        {
            coins10 = coins10 + (cents / 10);
        }
        else
        {
            coins10 = cents / 10;
            cents = cents - (coins10 * 10);
            if (cents % 5 == 0)
            {
                coins5 = coins5 + (cents / 5);
            }
            else
            {
                coins5 = cents / 5;
                cents = cents - (coins5 * 5);
                coins1 = cents;
            }
                
        }
    }
    totalcoins = coins25 + coins10 + coins5 + coins1;
    //Displaying the total number of coins.
    printf("%i\n", totalcoins);
}