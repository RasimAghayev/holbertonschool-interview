#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics:
- Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status
                code> <file size>
- After every 10 lines and/or a keyboard interruption (CTRL + C), print these
  statistics from the beginning:
Example:
    File size: 5213
    200: 2
    401: 1
    403: 2
    404: 1
    405: 1
    500: 3
"""

import sys

status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
total_size = 0


def print_stats():
    """
    Function to print the statistics about the logs.
    """
    global total_size

    print('File size: {}'.format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print('{}: {}'.format(code, status_codes[code]))


if __name__ == "__main__":
    line_count = 0
    try:
        for line in sys.stdin:
            try:
                parts = line.split()
                if len(parts) > 2:
                    status_code = parts[-2]
                    file_size = int(parts[-1])

                    if status_code in status_codes:
                        status_codes[status_code] += 1
                    total_size += file_size

            except (IndexError, ValueError):
                continue

            line_count += 1
            if line_count == 10:
                print_stats()
                line_count = 0
    except KeyboardInterrupt:
        print_stats()
        raise
    else:
        print_stats()
