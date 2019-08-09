#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    float cash;           //change owed
    int n;                //integer value of cash
    int counter = 0;          //no. of coins

    //prompt user for a positive real number
    do
    {
        cash = get_float("Change owed: ");
    }
    while (cash < 0);
    //changes and rounds the float value to integer value
    n = (cash * 100) + 0.5;

    //loops for counting no. of coins
    while (n >= 25)
    {
        n = n - 25;
        counter++;
    }

    while (n >= 10)
    {
        n = n - 10;
        counter++;
    }

    while (n >= 5)
    {
        n = n - 5;
        counter++;
    }

    while (n >= 1)
    {
        n = n - 1;
        counter++;
    }

    printf("%i\n", counter);

}
