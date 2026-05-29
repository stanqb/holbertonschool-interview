#!/usr/bin/python3
"""Module for calculating minimum operations to reach n H characters"""


def minOperations(n):
    """Calculate the fewest number of operations to get exactly n H's

    Uses prime factorization: the minimum operations equals the sum
    of all prime factors of n.

    Args:
        n (int): Target number of H characters

    Returns:
        int: Minimum number of operations, or 0 if impossible
    """
    if n <= 1:
        return 0

    ops = 0
    factor = 2

    while factor <= n:
        while n % factor == 0:
            ops += factor
            n //= factor
        factor += 1

    return ops
