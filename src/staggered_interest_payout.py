#!/usr/bin/env python
'''
Staggered Interest Payout As-On-Date

Functions to calculate the amount due for scenarios like the following:

    1 year ➢ 4% ➢ ₹10000
    2 year ➢ 4% ➢ ₹10000
    3 year ➢ 4% ➢ ₹10000
    4 year ➢ 4% ➢ ₹10000
'''

import sys
from sys import argv, stderr
from os.path import sep


def payout_today(time, rate, amount_per_year):
    '''
    Calculate payout today for fixed rate and amount per year.
    '''
    return 100.0 * sum([amount_per_year / (100.0 + t * rate)
                        for t in range(1, time + 1)])


if __name__ == '__main__':
    me = argv[0].split(sep)[-1]

    if len(argv) != 4:
        print("Usage:\n\t" + me + " <time> <rate> <amount per year>",
              file=stderr)
        sys.exit(1)

    print(payout_today(int(argv[1]), *map(float, argv[2:])))
