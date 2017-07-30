
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
//#include <head1.h>
extern int A,C,B,xx,yy;//global moteghayyer
extern int height,width;
extern struct cell{int energy;char type;};
extern struct cell maparray[10][10];//dar vaghe in naghshe e ma ast
extern FILE* map;extern FILE* map3;extern FILE* map4;extern FILE *fp;extern FILE* amibmaptxt;extern FILE* amibmaptxt2;//fp eshare gar be file ast ke etelaate bazi da on ast
extern struct gamercell {int energy;int makanxx;int makanyy;};
extern char filename[30];extern char filename2[30];
extern struct gamercell current2;//dar check2
extern struct cell_position
        {
        int x;
        int y;
        };
/*___________________________________________________________________________________*/
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

/*___________________________________________________________________________________*/
void showpage(void)
{
      HANDLE  hConsole;
      hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int x=0;int y=0;int t=0;    int i,j;
    t=height;
    while(t>0)
    {
        gotoxy(0,(height-t)*5+2);
        printf("%d",t-1);
        t--;
    }
    t=0;
    while(t<width)
    {
        gotoxy(t*18+8,5*height+4);
        printf("%d",t);
        t++;
    }
    t=0;
    for(i=0;i<width;i++)
    {
        for(j=height-1;j>=0;j--){ //fread(&cells,sizeof(cells),1,fp);t++;
        char B=maparray[i][j].type;t++;
        int d=t/height;int f=t%height;
        if(f==0){d=(t-1)/height;}
        if(d%2==0)//zoj
        {
            if(f==0){f=height;}
            gotoxy(d*18+1,(f-1)*5);
            x=d*18+1;y=(f-1)*5;
        }
        if(d%2!=0)//fard
        {
            if(f==0){f=height;}
            gotoxy(d*18+1,(f-1)*5+2);
            x=d*18+1;y=(f-1)*5+2;
        }

     if(B=='1')
      {
          SetConsoleTextAttribute(hConsole, 160);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          if(maparray[i][j].energy>9){
          y++;gotoxy(x,y);
          printf("E.C=%d          |\n",maparray[i][j].energy);}
          else{ y++;gotoxy(x,y);
          printf("E.C=%d           |\n",maparray[i][j].energy);}
          y++;gotoxy(x,y);
           printf("----------------|\n");

      }
      if(B=='2')
      {
          SetConsoleTextAttribute(hConsole, 176);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
           printf("----------------|\n");


      }
      if(B=='3')
      {
          SetConsoleTextAttribute(hConsole, 192);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
           printf("----------------|\n");


      }
      if(B=='4')
      {
          SetConsoleTextAttribute(hConsole, 240);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("                |\n");
          y++;gotoxy(x,y);
          printf("----------------|\n");


      }
     }
  }
  //neshan dadane sellul ha ham bayad ezafeh  shavad
  SetConsoleTextAttribute(hConsole, 15);
  int T=0;
  for(i=0;i<width;i++)
  {
      for(j=height-1;j>=0;j--)
      {
          T++;
          if(check2(i,j)==0)//agar sellul dasht
          {                                                            // gotoxy(0,0);printf("teeeeest");
              //boro b on khune
                 int d=T/height;int f=T%height;
                     if(f==0){d=(T-1)/height;}
                if(d%2==0)//zoj
                {
                    if(f==0){f=height;}
                    gotoxy(20*d+5,5*(f-1)+2);
                }
                if(d%2!=0)//fard
                {
                    if(f==0){f=height;}
                    gotoxy(20*d+5,5*(f-1)+4);
                }
              printf("%c->E=%d",2,current2.energy);

          }
      }
  }

}

/*___________________________________________________________________________________*/

void score (void)
{
    struct gamercell gamer_cell;int score=0;rewind(fp);
    while(1)
    {

        fread(&gamer_cell,sizeof(gamer_cell),1,fp);
        if(feof(fp)){break;}
        score+=gamer_cell.energy;
    }

    printf("YOUR SCORE IS %d\n\n",score);
}
/*___________________________________________________________________________________*/

void show1 (void)
{
    printf("[1] Load\n");
    printf("[2] New single player game\n");
    printf("[3] New Multi player game\n");
    printf("[4] Exit\n");
    scanf("%d",&A);
}
/*___________________________________________________________________________________*/

int  show2 (void)
{
    printf("green block is boost energy cell\n");
    printf("red blocks are blocked\n");
    printf("white block are normal\n");
    printf("blue blocks are split blocks\n");
    printf("[1]move\n[2]split cell\n[3]boost energy\n[4]save\n[5]exit\n");
    scanf("%d",&B);
    return B;

}
/*___________________________________________________________________________________*/
void new_single_game(void)
{
    printf("if you want to have your map press 1 else press 2 \n");
    int d;
    scanf("%d",&d);
    if(d==1)
    {
       printf("please enter your map name forexample mymap.bin\n");
       char name[30];
       scanf("%s",name);
       FILE* mymap=fopen(name,"a+b");
       printf("first enter the width of your map then the height of that\n");
       scanf("%d %d",&width,&height);
       int i=0,j;
        while(i<width)
        {
            for(j=height-1;j>=0;j--)
            {
                 printf("enter the energy of block[%d][%d]",i,j);
                 scanf("%d",&maparray[i][j].energy);
                 printf("enter the type of block[%d][%d]",i,j);
                 scanf(" %c",&maparray[i][j].type);
            }
            i++;
        }
        //hala on ra dar file mirizim
            while(i<width)
            {
                for(j=height-1;j>=0;j--)
                {
                    fwrite(&maparray[i][j].energy,sizeof(int),1,mymap);
                    fwrite(&maparray[i][j].type,sizeof(char),1,mymap);

                }
                i++;
            }
            fclose(mymap);


    }
    else read_map_original();

    printf("enter your file name\\bin\n");//dar in file etetlaate har sellul save mishavad.
    scanf("%s",filename);
    FILE* gamermap=fopen(filename,"a+b");

    time_t
    t=time(NULL);
    srand(t);
    printf("please enter number of cell\n");
    int number;
    scanf("%d",&number);
    printf("-----wait------\n");
    int i,j=0,k=0,m;
    int array_makan_random[1000][2];//az in komak gereftam k random hay tekrari ra hazf konam
    int makanx,makany;
    while(j<number)
       {
                makanx=(rand()%width);
                makany=(rand()%height);
                i=check(makanx,makany);
                if(i==1)//ghey ghabele obur nabud
                {
                    for(m=0;m<k;m++)// khali bude
                    {
                        if(makanx==array_makan_random[m][0] && makany==array_makan_random[m][1])
                        {
                                i=0;break;
                        }
                        else{i=1;}

                    }
                }

             //agar i 1 bashad yani ghabele ghabul ast


           if(i==1)
           {
               array_makan_random[k][0]=makanx;
               array_makan_random[k][1]=makany;
               k++;
               j++;//yeki az number ha gharar gereft
               struct gamercell gamer_cell;
               gamer_cell.energy=0;
               gamer_cell.makanxx=makanx;
               gamer_cell.makanyy=makany;
               fwrite(&gamer_cell,sizeof(gamer_cell),1,gamermap);fflush(stdin);
           }
           //agar i 0 bashad dobare varede while mishavad chon j ziad nmishavad

       }
        fclose(gamermap);//ta inja  jaye selul ha  moshakhkhas shode
        fflush(stdin);
        fp=fopen(filename,"r+b");
        if(fp==NULL){printf("can not open %s",filename); }
                                                                                             system("CLS");
                                                                                             showpage();
                                                                                             gotoxy(40,40);
                                                                                             score();

   do
   {
        HANDLE  hConsole;
        SetConsoleTextAttribute(hConsole, 15);
        int B=show2();
        if(B==5)
        {
            exit(0);fclose(map3),fclose(map4),fclose(fp);fclose(amibmaptxt);fclose(amibmaptxt2);
        }
        else
        {
       do_her_aim(B);
                                                                                             system("CLS");
                                                                                             showpage();
                                                                                             gotoxy(40,40);
                                                                                             score();

        }
   }while(1);

}



/*___________________________________________________________________________________*/

void  load (void)
{
    char mapname[30];
    printf("please enter your map name\n");
    scanf("%s",mapname);
    FILE * map2=fopen(mapname,"rb");
    if(map2==NULL){printf("can not open map\n");}
    fread(&width,sizeof(int),1,map2);
    fread(&height,sizeof(int),1,map2);
    int i=0,j;
    while(i<width)
    {
        for(j=height-1;j>=0;j--)
        {fread(&maparray[i][j].energy,sizeof(int),1,map2);
        fread(&maparray[i][j].type,sizeof(char),1,map2);
        }
        i++;
    }
    fclose(map2);//ta in ja map ra khund va on ra dar maparray zakhire kard
    //hala payad map e amib ha ra bekhanim.
    char amibmap[30];
    printf("please enter your map of amibs  name\n");
    scanf("%s",amibmap);printf("-----wait------\n");
    fp=fopen(amibmap,"r+b");if(map2==NULL){printf("can not open amibs map\n");}
    fflush(stdin);
    printf("-----wait------\n");
                                                                                             system("CLS");
                                                                                             showpage();
                                                                                             gotoxy(40,40);
                                                                                             score();


    do
   {
       HANDLE  hConsole;
        SetConsoleTextAttribute(hConsole, 15);
        int B=show2();
        if(B==5)
        {
            fclose(map3);fclose(fp);fclose(map4);fclose(amibmaptxt);fclose(amibmaptxt2);
            exit(1);
        }
        else
        {
       do_her_aim(B);
                                                                                             system("CLS");
                                                                                             showpage();
                                                                                             gotoxy(40,40);
                                                                                             score();
        }
   }while(1);



}
/*____________________________________________________________________________________________________________________*/
int main(void)
{

   show1();
   if(A==1){load();};
   if(A==2){new_single_game();}
   //if(A==3){new_multi_game();};
   if(A==4){exit(1);};
gotoxy(60,60);
    return 0;
}

