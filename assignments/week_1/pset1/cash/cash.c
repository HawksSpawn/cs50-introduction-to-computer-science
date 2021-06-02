// Print how many coins the customer receives as change

#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_change(string prompt);
int get_coins(int cents);

int main(void)
{
    float dollars = get_change("Change owed: ");
    // Dollars entered by the user are converted to cents (i.e. from a float to an int)
    // to avoid tiny errors that might otherwise add up!
    int cents = round(dollars * 100);
    int coins = get_coins(cents);

    printf("%i\n", coins);
}

// Prompt user how much change is owed
float get_change(string prompt)
{
    float change;
    do
    {
        change = get_float("%s", prompt);
    }
    while (change < 0);

    return change;
}

// Calculate the minimum number of coins with which that change can be made
int get_coins(int cents)
{
    // It is assumed that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)
    int quarters = 25, dimes = 10, nickels = 5, pennies = 1;
    int total_coins = 0;
    int coins;

    if (cents >= quarters)
    {
        // Compute how many quarters you can give
        coins = cents / quarters;
        // Keeps track of coins used
        total_coins += coins;
        // Compute the remaining change owed
        cents -= coins * quarters;
    }

    if (cents >= dimes)
    {
        coins = cents / dimes;
        total_coins += coins;
        cents -= coins * dimes;
    }

    if (cents >= nickels)
    {
        coins = cents / nickels;
        total_coins += coins;
        cents -= coins * nickels;
    }

    if (cents >= pennies)
    {
        total_coins += cents / pennies;
    }

    return total_coins;
}
