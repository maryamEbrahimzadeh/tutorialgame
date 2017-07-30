#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <head1.h>
int A,C,B,xx,yy;//global moteghayyer
int height,width;
struct cell{int energy;char type;};
struct cell maparray[10][10];//dar vaghe in naghshe e ma ast
FILE* map;FILE* map3;FILE* map4;FILE *fp;FILE* amibmaptxt;FILE* amibmaptxt2;//fp eshare gar be file ast ke etelaate bazi da on ast
struct gamercell {int energy;int makanxx;int makanyy;};
char filename[30];char filename2[30];
struct gamercell current2;//dar check2


