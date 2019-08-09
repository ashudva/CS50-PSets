from sys import argv
from cs50 import get_string
import crypt

# Ensuring correct usage
if len(argv) != 2:
    print("Usage: python crack.py <hash>")
    exit(1)

# Compute the length of the string
# 26 LC + 26 UC = 52
lc = 52
lt = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
has = argv[1]
salt = has[0:2]
key = ""

for i in range(lc):
    key = key + lt[i]
    for j in range(lc):
        key = key + lt[j]
        for k in range(lc):
            key = key + lt[k]
            for l in range(lc):
                key = key + lt[l]
                for m in range(1, slc):
                    key = key + lt[m]
                    if crypt.crypt(key, salt) is has:
                        print(key)
                        exit(0)

# If password is not craked
print("Password not cracked")
exit(2)