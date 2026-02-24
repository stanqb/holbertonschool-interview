#!/usr/bin/python3
"""Log parsing script that reads stdin and computes metrics."""
import sys


def print_stats(file_size, status_dict):
    """Print current statistics."""
    print("File size: {:d}".format(file_size))
    for key in sorted(status_dict.keys()):
        if status_dict[key] != 0:
            print("{}: {:d}".format(key, status_dict[key]))


if __name__ == "__main__":
    i = 0
    status_dict = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
    }
    file_size = 0
    try:
        for line in sys.stdin:
            keywords = line.split()
            if len(keywords) >= 2:
                if keywords[-2] in status_dict.keys():
                    status_dict[keywords[-2]] += 1
                file_size += int(keywords[-1])
                i += 1
                if not i % 10:
                    print_stats(file_size, status_dict)
        print_stats(file_size, status_dict)
    except KeyboardInterrupt:
        print_stats(file_size, status_dict)
        raise
