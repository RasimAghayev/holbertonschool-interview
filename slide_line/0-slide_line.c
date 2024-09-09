#include "slide_line.h"

static void merge_left(int *line, size_t size) {
  size_t i, j;
  for (i = 0; i < size && line[i]; i++) {
    for (j = i + 1; j < size; j++) {
      if (line[j] == 0)
        continue;
      if (line[i] == line[j]) {
        line[i] *= 2;
        line[j] = 0;
      }
      break;
    }
  }
}

static void merge_right(int *line, size_t size) {
  size_t i, j;
  for (i = size - 1; i < size && line[i]; i--) {
    for (j = i - 1; j < size; j--) {
      if (line[j] == 0)
        continue;
      if (line[i] == line[j]) {
        line[i] *= 2;
        line[j] = 0;
      }
      break;
    }
  }
}

static void slide_left(int *line, size_t size) {
  size_t i, j = 0;
  for (i = 0; i < size; i++) {
    if (line[i] != 0) {
      line[j++] = line[i];
    }
  }
  for (; j < size; j++) {
    line[j] = 0;
  }
}

static void slide_right(int *line, size_t size) {
  int i, j = size - 1;
  for (i = size - 1; i >= 0; i--) {
    if (line[i] != 0) {
      line[j--] = line[i];
    }
  }
  for (; j >= 0; j--) {
    line[j] = 0;
  }
}

int slide_line(int *line, size_t size, int direction) {
  if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)) {
    return 0;
  }

  if (direction == SLIDE_LEFT) {
    merge_left(line, size);
    slide_left(line, size);
  } else {
    merge_right(line, size);
    slide_right(line, size);
  }

  return 1;
}