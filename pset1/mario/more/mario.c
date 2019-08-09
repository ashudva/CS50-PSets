#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int h;
    //prompt user for height of pyramid from 0 to 23
    do
    {
        h = get_int("Height: ");
    }
    while (h < 0 || h  > 23);
// main loop for height of pyramid
    for (int i = 0; i < h; i++)
    {
        //1st loop for spaces before #
        for (int j = h - i; j > 1; j--)
        {
            printf(" ");
        }
        //2nd nested loop for 1st pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        //use printf instead of loop to print spaces between pyramids
        printf("  ");
        //4th loop fro second pyramid
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }
        //puts new line after every loop
        printf("\n");
    }


}