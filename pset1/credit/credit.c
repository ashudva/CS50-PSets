/*Variables
  ccLth = Credit Card Lenght
  ccNum = Credit Card Number
  ccDig = No of Credit Card Digits
*/
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
//funtion to calculate the length of the Credit Card
int ccLth(long long b)
{
    return (int)log10(b) + 1;
}
int main(void)
{
    //prompt user for CC Number
    long long ccNum = get_long_long("Number: ");
    int ccDig = ccLth(ccNum);
    long long i = ccNum;
    //validation of CC Number
    //if not a valid card print it immediatly
    if (ccDig != 13 && ccDig != 15 && ccDig != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    //saving ccNum in an array
    int array[ccDig];
    int sum = 0;
    int temp1,temp2;
    int k = ccDig - 1;
    while (i > 0)
    {
        temp1 = i % 10;
        array[k] = temp1;
        i -= temp1;
        i /= 10;
        if(i < 0)
        {
            break;
        }
        temp2 = i % 10;
        array[k - 1] = temp2;
        i -= temp2;
        i /= 10;
        temp2 *= 2;
        if (temp2 > 9)
        {
            temp2 = (temp2 % 10) + (temp2 / 10);
        }
        sum = sum + temp1 +temp2;
        k -= 2;
    }
    if ((sum % 10) != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // check the owner company of the credit card
    int digits = (array[0] * 10) + array[1];
    if (ccDig == 15)
    {
        if (digits == 34 || digits == 37)
        {
            printf("AMEX\n");
        }
    }
    else if (ccDig == 16)
    {
        if (digits == 51 || digits ==52 || digits == 53 || digits == 54 || digits ==55)
        {
            printf("MASTERCARD\n");
        }
        else if (array[0] == 4)
        {
            printf("VISA\n");
        }
    }
    else if (ccDig == 13 && array[0] == 4)
    {
        printf("VISA\n");
    }
}