#include "menger.h"
#include <math.h>
#include <stdio.h>

/**
 * is_empty - Determines if a specific cell in the sponge should be empty
 * @x: x coordinate
 * @y: y coordinate
 *
 * Return: 1 if the cell should be empty, 0 otherwise
 */
int is_empty(int x, int y)
{
while (x > 0 || y > 0)
{
if (x % 3 == 1 && y % 3 == 1)
 return (1);
x /= 3;
y /= 3;
}
return (0);
}

/**
 * menger - Draws a 2D Menger sponge
 * @level: The level of the Menger sponge
 */
void menger(int level)
{
int size, x, y;

if (level < 0)
 return;

size = pow(3, level);

for (y = 0; y < size; y++)
{
for (x = 0; x < size; x++)
{
if (is_empty(x, y))
 printf(" ");
else
 printf("#");
}
printf("\n");
}
}
