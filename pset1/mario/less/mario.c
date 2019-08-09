#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    int h;
    int i;
    int j;
    int k;
    //ask user for a positive integer but less than 23
    do
    {
        h = get_int("Height: ");
    }
    while (h < 0 || h > 23 );

    //loop for new lines which is equal to height of pyramid
    for (i = 0; i < h; i++)
    {
        //loop for spaces
        for (j = h - i; j > 1; j--)
        {
            printf(" ");
        }
        //loop for # or blocks
        for (k = 0; k < i + 2; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
