#include<stdio.h>
#include<math.h>
#define MAX_ROWS 25
#define MAX_COLS60
char screenBuffer[MAX_ROWS][MAX_COLS];
Void reserScreen()
{
   int rowIdx,colIdx;
   for(rowIdx=0; rowIdx < MAX_ROWS; rowIdx++)
   {
      for(colIdx=0; colIdx <MAX-COLS; colIdx++)
      {
         screenBuffer[rowIdx][colIdx]='_';
      }
   }
}
void renderScreen()
{
   int r,c;
   for(r=0;r< MAX_ROWS; r++)
   {
     for(c=0;c < MAX_COLS; c++)
     {
        printf("%c", screenBuffer[r][c]);
     }
     printf("\n");
   }

