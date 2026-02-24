#!/usr/bin/python3
"""Log parsing script that reads stdin and computes metrics."""
import sys


def print_stats(total_size, status_counts):
    """Print current statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


def parse_line(line):
    """Parse a log line and return (status_code, file_size) or None."""
    try:
        parts = line.split()
        if len(parts) < 9:
            return None
        # Check basic structure: parts[1] == '-', parts[-3] ends with '"'
        if parts[1] != '-':
            return None
        if not parts[2].startswith('['):
            return None
        if parts[5] != '"GET':
            return None
        if parts[6] != '/projects/260':
            return None
        if parts[7] != 'HTTP/1.1"':
            return None
        status_code = int(parts[8])
        file_size = int(parts[9])
        return (status_code, file_size)
    except (ValueError, IndexError):
        return None


def main():
    """Main function to parse logs from stdin."""
    total_size = 0
    line_count = 0
    valid_codes = {200, 301, 400, 401, 403, 404, 405, 500}
    status_counts = {code: 0 for code in valid_codes}

    try:
        for line in sys.stdin:
            line = line.strip()
            result = parse_line(line)
            if result is None:
                continue
            status_code, file_size = result
            total_size += file_size
            if status_code in valid_codes:
                status_counts[status_code] += 1
            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise
    finally:
        if line_count == 0 or line_count % 10 != 0:
            print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
