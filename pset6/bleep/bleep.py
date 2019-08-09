from cs50 import get_string
from sys import argv


def main():
    words = set()

    # Ensure correct usage
    if len(argv) is not 2:
        print("Usage: python bleep.py dictionary")
        exit(1)

    # Read file into a list
    with open(argv[1], "r") as file:
        for line in file:
            words.add(line.strip("\n"))

    # Prompt user for string to censor
    s = input("What message would you like to censor?\n")
    msg_words = list(s.split())
    msg_censored = ""

    # censor banned words
    for word in msg_words:
        if word.lower() in words:
            msg_censored += ("*" * len(word)) + " "
        else:
            msg_censored += word + " "

    # Print censored msg
    print(msg_censored)


if __name__ == "__main__":
    main()
