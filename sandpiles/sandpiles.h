#ifndef SANDPILES_H
#define SANDPILES_H

/* INCLUDED LIBRARIES */
#include <stdlib.h>
#include <stdio.h>

/* FUNCTION PROTOTYPES */

/* function to print individual grid */
static void print_grid(int grid[3][3]);

/* function to sum two sandpiles */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
/* subfunction to check stability of grid1 and set flags grid */
int grid1_unstable(int grid1[3][3], int flags[3][3]);
/* subfunction to topple individual cell to help stabilize sandpile */
void topple(int grid1[3][3], int i, int j);

#endif /* SANDPILES_H */
