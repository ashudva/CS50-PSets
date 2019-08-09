from sys import argv
from cs50 import get_string

# check no of args
if len(argv) is not 2:
    print("usage: python vigenere.py <key>")
    exit(1)

# check if all are alpha in key
for i in range(len(argv[1])):
    if not argv[1][i].isalpha():
        print("usage: python vigenere.py <alpha key>")
        exit(1)

# prompt for plain text
p = get_string("plaintext: ")
# list to hold cyphertext
ct = []
counter = 0
m = len(argv[1])
for i in range(len(p)):
    if p[i].isalpha():
        # to keep track of char in key
        j = counter % m
        # add key to plain text
        key = ord(argv[1][j].lower()) - ord('a')
        # j not > len(key) & j will not increase if j is greater than that
        if j is (m - 1):
            counter = 0
        else:
            counter += 1
        if p[i].isupper():
            a = ord(p[i])
            a -= 65
            temp = (a + key) % 26 + 65
            ct.append(chr(temp))
        elif p[i].islower():
            b = ord(p[i])
            b -= 97
            tmp = (b + key) % 26 + 97
            ct.append(chr(tmp))
    else:
        ct.append(p[i])
print("ciphertext: ", ''.join(ct))