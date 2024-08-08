#!/usr/bin/python3
"""
This script reads lines from standard input and computes metrics.
Metrics include the total file size and the count of different HTTP status codes.

After every 10 lines, or when the script is interrupted with a keyboard signal (CTRL + C),
it prints the total file size and the number of occurrences of each status code.
"""

import sys


def printsts(dic, size):
    """ Prints information """
    print("File size: {:d}".format(size))
    for i in sorted(dic.keys()):
        if dic[i] != 0:
            print("{}: {:d}".format(i, dic[i]))


sts = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
       "404": 0, "405": 0, "500": 0}

count = 0
size = 0

try:
    for line in sys.stdin:
        if count != 0 and count % 10 == 0:
            printsts(sts, size)

        stlist = line.split()
        count += 1

        try:
            size += int(stlist[-1])
        except:
            pass

        try:
            if stlist[-2] in sts:
                sts[stlist[-2]] += 1
        except:
            pass
    printsts(sts, size)


except KeyboardInterrupt:
    printsts(sts, size)
    raise
