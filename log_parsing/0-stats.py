#!/usr/bin/python3
"""Log parsing script that reads stdin and computes metrics."""
import sys


def print_stats(total_size, status_counts):
    """Print current statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


def main():
    """Main function to parse logs from stdin."""
    total_size = 0
    line_count = 0
    valid_codes = {200, 301, 400, 401, 403, 404, 405, 500}
    status_counts = {code: 0 for code in valid_codes}

    try:
        for line in sys.stdin:
            parts = line.split()
            try:
                if len(parts) < 7:
                    continue
                file_size = int(parts[-1])
                status_code = int(parts[-2])
                total_size += file_size
                if status_code in valid_codes:
                    status_counts[status_code] += 1
                line_count += 1
                if line_count % 10 == 0:
                    print_stats(total_size, status_counts)
            except (ValueError, IndexError):
                continue
    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise


if __name__ == "__main__":
    main()
