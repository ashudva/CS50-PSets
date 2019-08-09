# import get_int from cs50 library
from cs50 import get_int

# get input between 0 and 23
while True:
    h = get_int("Height: ")
    if h > 0 and h <= 23:
        break
# prints the pattern
for i in range(h):
    for j in range(1, h - i):
        print(" ", end='')
    for k in range(i + 1):
        print("#", end='')
    print()