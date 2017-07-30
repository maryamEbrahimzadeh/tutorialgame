#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern int A,C,B,xx,yy;//global moteghayyer
extern int height,width;
extern struct cell{int energy;char type;};
extern struct cell maparray[10][10];//dar vaghe in naghshe e ma ast
extern FILE* map;extern FILE* map3;extern FILE* map4;extern FILE *fp;extern FILE* amibmaptxt;extern FILE* amibmaptxt2;//fp eshare gar be file ast ke etelaate bazi da on ast
extern struct gamercell {int energy;int makanxx;int makanyy;};
extern char filename[30];extern char filename2[30];
extern struct gamercell current2,current;//dar check2
extern struct cell_position
        {
        int x;
        int y;
        };
      extern  enum move_direction {
	NORTH = 1,
	SOUTH,
	NORTHEAST,
	NORTHWEST,
	SOUTHEAST,
	SOUTHWEST,
};
//-------------------------------------------------------------------------------------------------

void read_map_original (void)
{
    map=fopen("map.bin","rb");
    if(map==NULL){printf("can not open map.bin\n");}
    fread(&width,sizeof(int),1,map);
    fread(&height,sizeof(int),1,map);
    int i=0,j;
    while(i<width)
    {
        for(j=height-1;j>=0;j--)
        {
            fread(&maparray[i][j].energy,sizeof(int),1,map);
            fread(&maparray[i][j].type,sizeof(char),1,map);

        }
        i++;
    }
    fclose(map);

}
/*_____________________________________________________________________________________*/
int check4 (int makanx,int makany)//baraye checj kardane in k khnae manbaa ast ya na
{
    if(maparray[makanx][makany].type=='1')
    {
        return(0);
    }
    //agar khneh manba nabashad  1 midahad
    return(1);

}
/*_____________________________________________________________________________________*/
int check3 (int makanx,int makany)//baraye checj kardane in k khnae taghsim ast ya na
{
    if(maparray[makanx][makany].type=='2')
    {
        return(1);
    }
    //agar khneh taghsim  bashad  1 midahad
    return(0);

}
/*___________________________________________________________________________________*/
int check5 (int makanx,int makany)
{
    if(makanx>width-1 || makanx<0 || makany>height-1 || makany<0){return 0;}//agar kharej bashad 0 midahad
    else return 1;
}
/*___________________________________________________________________________________*/

int check (int makanx,int makany)
{
    if(maparray[makanx][makany].type=='3')
    {
        return(0);
    }
    //agar khaneh gheyr ghabelr obur bashad 0 midahad
    return(1);

}
/*___________________________________________________________________________________*/


int check2 (int makanxx,int makanyy)//baraye in ke bebinim yek khaneh khali ast ya na
{
 int i=1;
 rewind(fp);
 while(1)
 {fread(&current2,sizeof(current2),1,fp);
 if(feof(fp)){break;}
     if(makanxx==current2.makanxx)
               {
                   if(makanyy==current2.makanyy)
                   {
                       i=0; return i;
                   }
               }
 }
               return i;//agar  khali nbashad 0 midahad

}

