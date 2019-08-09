from sys import argv
from cs50 import get_string
key = -1

if len(argv) is 2:
    key = int(argv[1])

if len(argv) is not 2 or key < 0:
    print("usage : python caesar.py <non negative key>")
    exit(1)
else:
    # prompt user for plaintext
    pt = []
    ptext = get_string("plaintext: ")
    for i in range(len(ptext)):
        pt.append(ptext[i])
    l = len(pt)
    ct = []
    # loop over every element of plaintext
    for i in range(l):
        # encipher only alphabetic chars
        if pt[i].isalpha():
            # preserve case of the char
            if pt[i].isupper():
                # convert ascii index to alpha index
                a = ord(pt[i])
                a -= 65
                temp = (a + key) % 26 + 65
                ct.append(chr(temp))
            elif pt[i].islower():
                b = ord(pt[i])
                b -= 97
                tmp = (b + key) % 26 + 97
                ct.append(chr(tmp))
        # for non alpha char
        else:
            ct.append(pt[i])
    ctext = ''.join(ct)
    print(f"ciphertext: {ctext}")