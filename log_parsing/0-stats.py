#!/usr/bin/python3
import sys

total_size = 0
status_codes = {'200': 0, '301': 0, '400': 0, '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}
line_count = 0

def print_stats():
    """Prints the current statistics."""
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")

try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()

        # Check if the line has at least 7 parts (IP, -, date, GET, URL, HTTP/version, status code, file size)
        if len(parts) >= 7:
            status_code = parts[-2]
            file_size = parts[-1]

            # Update the total file size
            try:
                total_size += int(file_size)
            except ValueError:
                pass

            # Update the status code count
            if status_code in status_codes:
                status_codes[status_code] += 1

        # Print statistics every 10 lines
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    # Print statistics on keyboard interrupt
    print_stats()
    raise

# Final print (in case there was no interrupt but the input ended)
print_stats()
