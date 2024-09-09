#include "slide_line.h"

/**
 * slide_line - Slide and merge an array of integers to the left or right.
 * @line: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Return: 1 on success, 0 on failure.
 */
int slide_line(int *line, size_t size, int direction) {
  size_t i, j;
  int temp[size];

  if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
    return (0);

  /* Initialize temp array */
  for (i = 0; i < size; i++)
    temp[i] = 0;

  if (direction == SLIDE_LEFT) {
    j = 0;
    for (i = 0; i < size; i++) {
      if (line[i] != 0) {
        if (temp[j] == line[i]) {
          temp[j - 1] *= 2;
          temp[j] = 0;
          j--;
        } else {
          temp[j] = line[i];
          j++;
        }
      }
    }
  } else if (direction == SLIDE_RIGHT) {
    j = size - 1;
    for (i = size; i > 0; i--) {
      if (line[i - 1] != 0) {
        if (temp[j] == line[i - 1]) {
          temp[j + 1] *= 2;
          temp[j] = 0;
          j++;
        } else {
          temp[j] = line[i - 1];
          j--;
        }
      }
    }
  }

  /* Copy the result to the original line array */
  for (i = 0; i < size; i++)
    line[i] = temp[i];

  return (1);
}
