#include <stdio.h>
#include <windows.h>   // WinApi header
void gotoxy(int x,int y)
{
    COORD pos;
    HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );
    if (INVALID_HANDLE_VALUE != hConsole)
    {
        pos.X = x;
        pos.Y = y;
        SetConsoleCursorPosition( hConsole, pos );
    }
}
int main()
{
    //system("color 10");
  HANDLE  hConsole;
    int k;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  // you can loop k higher to see more color choices
  int x=0,y=0;
  for(k = 1; k < 255; k++)
  {
    SetConsoleTextAttribute(hConsole, k);
    //gotoxy(x,y);
    //printf("                          \n");
    printf("%3d  %s\n", k, "in blu we trust");
        //printf("                          \n");
          //  printf("                          \n");
  }

  getchar();  // wait
  return 0;
}
