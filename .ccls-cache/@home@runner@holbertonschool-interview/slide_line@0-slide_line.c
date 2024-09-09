#include "slide_line.h"

static void merge_left(int *line, size_t size) {
  size_t write = 0, read = 0;
  while (read < size) {
    if (line[read] == 0) {
      read++;
      continue;
    }
    if (write > 0 && line[write - 1] == line[read]) {
      line[write - 1] *= 2;
      line[read] = 0;
    } else if (write != read) {
      line[write] = line[read];
      line[read] = 0;
    }
    write++;
    read++;
  }
}

static void merge_right(int *line, size_t size) {
  size_t write = size - 1, read = size - 1;
  while (read < size) { // This condition works because size_t is unsigned
    if (line[read] == 0) {
      if (read == 0)
        break; // Prevent underflow
      read--;
      continue;
    }
    if (write < size - 1 && line[write + 1] == line[read]) {
      line[write + 1] *= 2;
      line[read] = 0;
    } else if (write != read) {
      line[write] = line[read];
      line[read] = 0;
    }
    if (write == 0)
      break; // Prevent underflow
    write--;
    if (read == 0)
      break; // Prevent underflow
    read--;
  }
}

int slide_line(int *line, size_t size, int direction) {
  if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)) {
    return 0;
  }

  if (direction == SLIDE_LEFT) {
    merge_left(line, size);
  } else {
    merge_right(line, size);
  }

  return 1;
}