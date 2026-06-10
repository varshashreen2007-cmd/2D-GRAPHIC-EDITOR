#include<stdio.h>
#include<math.h>
#define MAX_ROWS 25
#define MAX_COLS60
char screenBuffer[MAX_ROWS][MAX_COLS];
Void reserScreen()
{
   int rowIdx,colIdx;
   for(rowIdx=0; rowIdx < MAX_ROWS; rowIdx++)
