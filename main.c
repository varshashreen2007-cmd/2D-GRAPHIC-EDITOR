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
}
void placeRectangle(int startRow,int startCol,int h,int w,char drawChar)
{
   int i;
   for(i=startCol;i< startCol + w; i++)
   {
      screenBuffer[startRow][i]=drawChar;
      screenBuffer[startRow + h-1][i]= drawChar;
   }
   for(i=startRow; i < startRow + h; i++)
   {
      screenBuffer[i][startCol]=drawChar;
      screenBuffer[i][sttartCol+ w-1]=drawChar;
   }
}
void placeHorizontalLine(int TargetRow, int leftCol, int rightCol,char drawChar)
{
   int idx;
   for(idx = leftCol; idx <= rightCol; idx++)
   {
      screenBuffer[TargetRow][idx] = drawChar;
   }


