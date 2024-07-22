#include "sandpiles.h"

/**
 * sandpiles_sum - sums two sandpiles and topples until sum is stable
 * @grid1: first 3x3 grid of integers to sum, assumed to be stable
 * @grid2: second 3x3 grid of integers to sum, assumed to be stable
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
  int row = 0, col = 0;
  int unstable_flags[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  /* sum grid1 and grid2 into grid1 */
  for (row = 0; row < 3; row++)
  {
    for (col = 0; col < 3; col++)
    {
      grid1[row][col] += grid2[row][col];
    }
  }

  while (grid1_unstable(grid1, unstable_flags))
  {
    /* for every indicated flag, topple the cell */
    for (row = 0; row < 3; row++)
    {
      for (col = 0; col < 3; col++)
      {
        if (unstable_flags[row][col])
        {
          topple(grid1, row, col);
        }
      }
    }
  }
}

/**
 * grid1_unstable - checks stability of grid1 and sets flags where unstable
 * grid1 is unstable if any of its cells contain more than 3 grains
 * @grid1: 3x3 grid of integers to check stability of
 * @flags: 3x3 grid indicating where unstable cells are prior to toppling
 * @return: 1 if unstable, 0 otherwise
 */
int grid1_unstable(int grid1[3][3], int flags[3][3])
{
  int is_grid1_unstable = 0;
  int row, column;

  for (row = 0; row < 3; row++)
  {
    for (column = 0; column < 3; column++)
    {
      if (grid1[row][column] > 3)
      {
        is_grid1_unstable = 1;
        flags[row][column] = 1;
      }
      else
      {
        flags[row][column] = 0;
      }
    }
  }
  return is_grid1_unstable;
}

/**
 * toppleCell - topples individual cell to help make sandpile stable
 * @grid: 3x3 grid which holds cell to topple
 * @rowIndex: row coordinate of cell to topple
 * @columnIndex: column coordinate of cell to topple
 *
 * Return: void
 */
void toppleCell(int grid[3][3], int rowIndex, int columnIndex)
{
  grid[rowIndex][columnIndex] -= 4;
  if (rowIndex > 0)
  {
    grid[rowIndex - 1][columnIndex]++;
  }
  if (rowIndex < 2)
  {
    grid[rowIndex + 1][columnIndex]++;
  }
  if (columnIndex > 0)
  {
    grid[rowIndex][columnIndex - 1]++;
  }
  if (columnIndex < 2)
  {
    grid[rowIndex][columnIndex + 1]++;
  }
}

/**
 * printGrid - prints individual grid
 * @grid: 3x3 grid of integers to print
 *
 * Return: void
 */
static void printGrid(int grid[3][3])
{
  for (int row = 0; row < 3; row++)
  {
    for (int column = 0; column < 3; column++)
    {
      if (column != 0)
      {
        printf(" ");
      }
      printf("%d", grid[row][column]);
    }
    printf("\n");
  }
}
