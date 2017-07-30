#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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

void print_square (int x, int y)
{
    gotoxy(x, y);
    printf("%c%c%c%c%c", 220, 220, 220, 220, 220);
    gotoxy(x, y+1);
    printf("%c%c%c%c%c", 220, 220, 220, 220, 220);
    gotoxy(x, y+2);
    printf("%c%c%c%c%c", 220, 220, 220, 220, 220);
}

void print_screen (int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int i, j, k= 3;
    for (i=0; i<x; i++)
    {
        for (j=0; j<y; j++)
            if (i%2 == 0)
            {
                if ((j+k)%3 == 0)
                    SetConsoleTextAttribute(hConsole, 10);
                else if ((j+k)%3 == 1)
                    SetConsoleTextAttribute(hConsole, 9);
                else
                    SetConsoleTextAttribute(hConsole, 11);
                print_square(i*5, j*3);
            }
            else
            {
                if ((j+k)%3 == 0)
                    SetConsoleTextAttribute(hConsole, 14);
                else if ((j+k)%3 == 2)
                    SetConsoleTextAttribute(hConsole, 12);
                else
                    SetConsoleTextAttribute(hConsole, 13);
                print_square(i*5, j*3 + 1);
            }
        k--;
        if (k==0)
            k=3;
    }
}
int main ()
{
  //  print_screen(8, 8);
  print_square(5,5);


    return 0;
}
