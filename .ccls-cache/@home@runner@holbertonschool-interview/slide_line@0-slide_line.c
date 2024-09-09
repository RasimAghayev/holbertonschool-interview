#include "slide_line.h"

static void slide_and_merge_left(int *line, size_t size) {
  size_t write = 0, read = 0;
  while (read < size) {
    if (line[read] == 0) {
      read++;
      continue;
    }
    if (write > 0 && line[write - 1] == line[read]) {
      line[write - 1] *= 2;
      read++;
    } else {
      line[write++] = line[read++];
    }
  }
  while (write < size) {
    line[write++] = 0;
  }
}

static void slide_and_merge_right(int *line, size_t size) {
  size_t write = size;
  size_t read = size;
  while (read > 0) {
    read--;
    if (line[read] == 0) {
      continue;
    }
    write--;
    if (write < size - 1 && line[write + 1] == line[read]) {
      line[write + 1] *= 2;
    } else {
      line[write] = line[read];
    }
  }
  while (write > 0) {
    write--;
    line[write] = 0;
  }
}

int slide_line(int *line, size_t size, int direction) {
  if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)) {
    return 0;
  }

  if (direction == SLIDE_LEFT) {
    slide_and_merge_left(line, size);
  } else {
    slide_and_merge_right(line, size);
  }

  return 1;
}