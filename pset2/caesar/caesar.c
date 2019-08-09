#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    int key;//Declare key in main so we can use it anywhere in our program
    //check no of cmd line arguments
    if (argc == 2)
    {
        key = atoi(argv[1]);
    }
    if (argc != 2 || key < 0)
    {
        printf("error: enter a valid key (non negative) after ./caesar and single cmd line argument\n");
        //return 1 to main if argc != 2 or key is negative
        return 1;
    }
    else
    {
        //prompt user for plaintext
        string pt = get_string("plaintext: ");
        int l = strlen(pt);
        //declare a string or a character array to store ciphertext
        char ct[l];
        //loop over every element of plaintext
        for (int i = 0; i < l; i++)
        {
            //we need to encipher only alphabatical characters otherwise leave them as it is
            if (isalpha(pt[i]))
            {
                //preserve case of the ciphertext character
                if (isupper(pt[i]))
                {
                    //convert ascii index to alphabatical index
                    pt[i] -= 65;
                    //equation to encipher
                    ct[i] = (pt[i] + key) % 26;
                    //convert alphabatical index back to ascii index
                    ct[i] += 65;
                }
                if (islower(pt[i]))
                {
                    //convert ascii index to alphabatical index
                    pt[i] -= 97;
                    //equation to encipher
                    ct[i] = (pt[i] + key) % 26;
                    //convert alphabatical index back to ascii index
                    ct[i] += 97;
                }
            }
            else
            {
                //for non alphabatical characters
                ct[i] = pt[i];
            }
        }
        //print ciphertext with a new line
        printf("ciphertext: %s\n", ct);
    }
}