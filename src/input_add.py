#!/usr/bin/env python3
'''
Program to input string of numbers and display the sum.
'''


def main():
    '''
    Accept string of whitespace-delimited numbers and display the sum.

    (Separate numbers with spaces/newlines; empty line to end input.)
    '''

    print('Numbers to Add?')

    num_list = []

    user_input = None
    while user_input != '':
        user_input = input()
        num_list.extend(list(map(int, user_input.split())))

    num_sum = 0
    for num in num_list:
        num_sum += num

    print('Sum: ' + str(num_sum))


if __name__ == '__main__':
    main()
