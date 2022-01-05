#!/usr/bin/python3
"""
This module contains functions for min ops problem
"""


def minOperations(n):
    """calculates the fewest number of operations needed"""
    if type(n) is not int:
        return 0
    if n <= 1:
        return 0
    k = 2
    while k * k <= n:
        if n % k == 0:
            res = minOperations(k) + minOperations(n//k)
            return res
        k += 1
    return n
