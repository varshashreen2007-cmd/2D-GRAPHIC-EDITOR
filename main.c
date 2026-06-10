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
}
void placeTriangle(int topR,int centerC, int height,char drawChar)
{
   int i;
   for(i=0;i< height;i++)
   {  
      screenBuffer[topR + i][centerC-i]=drawChar;
      screenBuffer[topR + i][centerC+i]=drawChar;
   }
   for(i=centerC-height+1;i<=centerC + height - 1;i++)
   {
     screenBuffer[topR +height - 1][i]=drawChar;
   }
}
void placeCircle(int centerX,int centerY,int radius,char drawChar)
{
   int deg;
   for(deg=0; deg<360; deg++)
   {
      int targetX=centerX+radius*cos(deg*3.14159/180);
      int targetY=centerY+radius*sin(deg*3.14159/180);
      if(targetX>=0 && targetX<MAX_ROWS && targetY>=0 && targetY<MAX_COLS)
      {
         screenBuffer[targetX][targetY]=drawChar;
      }
   }
}
int main()
{
   int userSelection;
   resetScreen();
   do
  {
   printf("\n=====CONSOLE GRAPHICS SYSTEM=====\n");
   printf("1.Construct Rectangle\n");
   printf("2.Construct Line\n");
   printf("3.Construct Triangle\n");
   printf("4.Construct Circle\n");
   printf("5.Erase Rectangle\n");
   printf("6.Erase Line\n");
   printf("7.Output Current Screen\n");
   printf("8.Wipe Screen Clean\n");
   printf("9.Terminate Program\n");
   printf("Provide Option:");
   scanf("%d",&userSelection);
switch(userSelection)

