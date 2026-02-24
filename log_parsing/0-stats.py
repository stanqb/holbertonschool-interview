#!/usr/bin/python3
"""Log parsing script that reads stdin and computes metrics."""
import sys
import re


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
    pattern = re.compile(
        r'^\S+ - \[.*\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'
    )

    try:
        for line in sys.stdin:
            line = line.strip()
            match = pattern.match(line)
            if not match:
                continue
            try:
                status_code = int(match.group(1))
                file_size = int(match.group(2))
                total_size += file_size
                if status_code in valid_codes:
                    status_counts[status_code] += 1
                line_count += 1
                if line_count % 10 == 0:
                    print_stats(total_size, status_counts)
            except ValueError:
                continue
    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise
    finally:
        if line_count == 0 or line_count % 10 != 0:
            print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
