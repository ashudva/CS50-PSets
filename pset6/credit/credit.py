# Variables :-
# 1. ccLth = Credit Card Lenght
# 2. ccNum = Credit Card Number
# 3. ccDig = No of Credit Card Digits
# import log & other fuctions
from math import log
from cs50 import get_int

# function to find length of credit card


def ccLth(b):
    return int(log(b, 10)) + 1


# prompt user for CC number
ccNum = get_int("Number: ")
ccDig = ccLth(ccNum)

# validation of CC number, if not print invalid
if ccDig != 13 and ccDig != 15 and ccDig != 16:
    print("INVALID")

# save ccNum in a list
CC = [int(x) for x in str(ccNum)]

# check company of CC
digits = (CC[0] * 10) + CC[1]
if ccDig == 15:
    if digits == 34 or digits == 37:
        print("AMEX")

elif ccDig == 16:
    if digits == 51 or digits == 52 or digits == 53 or digits == 54 or digits == 55:
        print("MASTERCARD")
    elif CC[0] == 4:
        print("VISA")

elif ccDig == 13 and CC[0] == 4:
    print("VISA")