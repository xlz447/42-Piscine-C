#!/usr/bin/python
#
# example usage:

# generate 100,000 test cases:
#   ./evalexpr -n 100000 > output
# print the cases that failed:
#   grep FAIL output
# fix your program to handle the failures, then re-run the tests and see if you pass them now:
#   ./evalexpr -f output | grep FAIL
# generate 100,000 new test cases and append them to the test suite you generated previously:
#   ./evalexpr -n 100000 >> output
# run all 200,000 tests and pretty-print the output:
#   ./evalexpr -f output | grep -v NULL | column -t -s'__'

from __future__ import print_function
import subprocess
import argparse
import os

from random import random, randint, choice, seed
seed(0)


class Expression:
    pass


class Number(Expression):
    def __init__(self, num):
        self.num = num

    def __str__(self):
        return str(self.num) + " "


class BinaryExpression(Expression):
    def __init__(self, left, op, right):
        self.left = left
        self.op = op
        self.right = right

    def __str__(self):
        return str(self.left) + self.op + " " + str(self.right)


class ParenthesizedExpression(Expression):
    def __init__(self, exp):
        self.exp = exp

    def __str__(self):
        return "( " + str(self.exp) + ") "


def randomExpression(prob):
    p = random()
    if p > prob:
        return Number(randint(1, 100) * (-1 if random() < .2 else 1))
    elif randint(0, 1) == 0:
        return ParenthesizedExpression(randomExpression(prob / 1.2))
    else:
        left = randomExpression(prob / 1.2)
        op = choice(["+", "-", "*", "/", "%"])
        right = randomExpression(prob / 1.2)
        return BinaryExpression(left, op, right)


__author__ = "Huy Z"

# Based on https://stackoverflow.com/a/6881218

INT_MAX = 2147483647
INT_MIN = -2147483648
LLONG_MAX = 9223372036854775807
LLONG_MIN = -9223372036854775808


def parse_args():
    """
    Define an argument parser and return the parsed arguments
    """
    parser = argparse.ArgumentParser(
        prog='exprtest',
        description='tests your expr_eval against the built-in expr command')
    parser.add_argument("--file", "-f", help="re-run tests from test suite in a file", required=False)
    parser.add_argument("--number", "-n", help="number of tests to generate", required=False, default=1000, type=int)

    return parser.parse_args()


def check_test(expr):
    FNULL = open(os.devnull, 'w')

    expected = "division by zero"
    while (expected == "division by zero"):
        expected = subprocess.check_output(["expr"] + str(expr).strip().split(' '), stderr=FNULL).strip()

    actual = subprocess.check_output(["./eval_expr", str(expr).strip()], stderr=FNULL).strip()

    return expected, actual


def report(expr, expected, actual):
    if expected != actual:
        print('FAIL', end='')
    else:
        print('PASS', end='')
    print('__expected__{}__actual__{}__expr__{}'.format(expected, actual, str(expr)))


def main():
    args = parse_args()

    if args.file:
        with open(args.file) as testsuite:
            tests = [line.rstrip('\n').split('__') for line in testsuite]
        for test in tests:
            try:
                expr = test[6]
            except IndexError:
                continue
            expected, actual = check_test(expr)
            report(expr, expected, actual)
    else:
        for index in range(0, args.number + 1):
            expr = randomExpression(1)

            try:
                expected, actual = check_test(expr)

                if int(expected) < INT_MAX and int(expected) > INT_MIN:
                    report(expr, expected, actual)
                else:
                    print("NULL expected value outside of range: {} {} {}".format(INT_MAX, expected, INT_MIN))
                    index += 1

            except subprocess.CalledProcessError:
                pass


if __name__ == "__main__":
    main()

# vim: ft=python expandtab smarttab shiftwidth=4 softtabstop=4 :
