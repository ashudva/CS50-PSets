#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
//main should accept cmd line argument
int main(int argc, string argv[])
{
    //check if no. of args are 2
    if (argc != 2)
    {
        //print error if args are not equal to 2
        printf("error: please input a valid key in single argument after ./vigenere(alphabatic)\n");
        return 1;
    }
    //iterate the loop upto the length of the string argument 1 i.e, key and check if its all alphabatical
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (! isalpha(argv[1][i]))
        {
            printf("error: input an alphabatic key\n");
            return 1;
        }
    }
    //get the plaintext input from user
    string p = get_string("plaintext: ");
    //declare a variable to store ciphertext of data type string with same no. of characters as in plaintext
    int n = strlen(p);
    int m = strlen(argv[1]);
    char c[n];
    int j;
    int counter = 0;
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        if (isalpha(p[i]))
        {
            //to keep track of characters in key use j
            j = counter % m;
            //to encipher we neeed to add key to the plaintext character
            int key = tolower(argv[1][j]) - 'a';
            /*-- j should not be graeater than no of elements in key
                 and j should not increase if j is greater than that --*/
            j == (m - 1) ? counter = 0 : counter++;
            if (isupper(p[i]))
            {
                p[i] -= 65;
                c[i] = (p[i] + key) % 26;
                c[i] += 65;
                printf("%c", c[i]);
            }
            else if (islower(p[i]))
            {
                p[i] -= 97;
                c[i] = (p[i] + key) % 26;
                c[i] += 97;
                printf("%c", c[i]);
            }

        }
        else
        {
            c[i] = p[i];
            printf("%c", c[i]);
        }
    }
    printf("\n");
    return 0;
}