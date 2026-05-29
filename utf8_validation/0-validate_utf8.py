#!/usr/bin/python3
"""Module for UTF-8 validation"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding

    Args:
        data (list): List of integers representing bytes

    Returns:
        bool: True if valid UTF-8 encoding, False otherwise
    """
    continuation = 0

    for byte in data:
        byte = byte & 0xFF

        if continuation > 0:
            if byte >> 6 != 0b10:
                return False
            continuation -= 1
        elif byte >> 7 == 0:
            continuation = 0
        elif byte >> 5 == 0b110:
            continuation = 1
        elif byte >> 4 == 0b1110:
            continuation = 2
        elif byte >> 3 == 0b11110:
            continuation = 3
        else:
            return False

    return continuation == 0
