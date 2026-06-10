#include<stdio.h>
#include<math.h>
#define MAX_ROWS 25
#define MAX_COLS 60
char screenBuffer[MAX_ROWS][MAX_COLS];
void resetScreen()
{
   int rowIdx,colIdx;
   for(rowIdx=0; rowIdx < MAX_ROWS; rowIdx++)
   {
      for(colIdx=0; colIdx <MAX_COLS; colIdx++)
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
      screenBuffer[i][startCol+ w-1]=drawChar;
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
{
  case 1:
  {
    int r,c,h,w;
    printf("Enter Row,Col,Height,Width:");
    scanf("%d%d%d%d",&r,&c,&h,&w);
    placeRectangle(r,c,h,w,'*');
    break;
  }
  case 2:
  {
   int r,cStart,cEnd;
   printf("Enter Row,start Column,End Column:");
   scanf("%d%d%d",&r,&cStart,&cEnd);
   placeHorizontalLine(r,cStart,cEnd,'*');
   break;
  }
  case 3:
  {
   int r,c,h;
   printf("Enter Top Row,Center Column,Height:");
   scanf("%d%d%d",&r,&c,&h);
   placeTriangle(r,c,h,'*');
   break;
  }
  case 4:
 {
  int x,y,rad;
  printf("Enter Center Row,Center Column,Radius:");
  scanf("%d%d%d",&x,&y,&rad);
  placeCircle(x,y,rad,'*');
  break;
 }
case 5:
{
   int r,c,h,w;
   printf("Enter Row,Col,Height,Width to Erase:");
   scanf("%d%d%d%d",&r,&c,&h,&w);
   placeRectangle(r,c,h,w,'_');
   break;
}
case 6:
{
  int r,cStart,cEnd;
  printf("Enter Row,Start Column,End Column to Erase:");
  scanf("%d%d%d",&r,&cStart,&cEnd);
  placeHorizontalLine(r,cStart,cEnd,'_');
  break;
}
case 7:
   renderScreen();
   break;
case 8:
   resetScreen();
   printf("Screen has been completely wiped!\n");
   break;
case 9:
   printf("Shutting down...Goodbye.\n");
   break;
default:
   printf("Error:Invalid Option Chosen!\n");
}
  }while(userSelection!=9);
  return 0;
}

