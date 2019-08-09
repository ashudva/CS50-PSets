# import cs50 functionality
from cs50 import get_float

# prompt user for positive real number
while True:
    cash = get_float("Change owed: ")
    if cash > 0:
        break

# changes and rounds the float value to integer value
n = int((cash * 100) + 0.5)

# loop for counting no. of coins
counter = 0
while n >= 25:
    n -= 25
    counter += 1
while n >= 10:
    n -= 10
    counter += 1
while n >= 5:
    n -= 5
    counter += 1
while n >= 1:
    n -= 1
    counter += 1

# print no of coins
print(counter)