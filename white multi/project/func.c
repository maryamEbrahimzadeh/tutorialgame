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
//----------------------------------------------------------------------------------------------------------------
void move (void)
{
    //kodam celul?
    //koja?
    //struct gamercell current;
    int up,right;
    printf("select the cell that you want to move\nI am in [0][0](left_down)\nI am not in block\ngive me adress og block  first x then y \n");
    scanf("%d",&right);scanf("%d",&up);
    if(up>height-1 || right>width-1)
    {
        printf("It is wrong\n");return;
        move();
    }
    else{printf("ok\n");}
    printf("________________________________");
    printf("now select one of these\n");
    printf("[1] North\n[2] South\n[3] Northeast\n[4] Northwest\n[5] Southeast\n[6] Southwest\n");
    scanf("%d",&C);
    if(C==1)//north
    {
        if(check2(right,up+1)==0){return ;}if(check(right,up+1)==0){return;} if(up+1>height-1||right>width-1||right<0||up+1<0){return;}
        rewind(fp);
        fread(&current,sizeof(current),1,fp);
        while(1)
        {
            if(feof(fp)){break;}
            if(current.makanxx==right && current.makanyy==up  && check2(current.makanxx,current.makanyy+1)!=0  &&   check(current.makanxx,current.makanyy+1)!=0)
            {//in if e bala ham check mikonad ke khane maghsad kali bashad va ghabele obur bashad.

                rewind(fp);
                while(1)
                {
                   fread(&current,sizeof(current),1,fp);
                   if(current.makanxx==right && current.makanyy==up)
                        break;
                }
                current.makanyy++;
                fseek(fp,-1*sizeof(current),SEEK_CUR);
                fwrite(&current,sizeof(current),1,fp);
                fflush(stdin);


                break;
            }
            else{fread(&current,sizeof(current),1,fp);}
        }


    }
        if(C==2)//south
        {
            if(check2(right,up-1)==0){return;}if(check(right,up-1)==0){return;}if(up-1>height-1||right>width-1||right<0||up-1<0){return;}

            rewind(fp);
            fread(&current,sizeof(current),1,fp);
            while(1)
            {
                if(feof(fp)){break;}
                if(current.makanxx==right && current.makanyy==up && check2(current.makanxx,current.makanyy-1)!=0  &&   check(current.makanxx,current.makanyy-1)!=0)
                {
                    rewind(fp);
                    while(1)
                    {
                        fread(&current,sizeof(current),1,fp);
                        if(current.makanxx==right && current.makanyy==up)
                            break;
                    }
                    current.makanyy--;
                    fseek(fp,-1*sizeof(current),SEEK_CUR);
                    fwrite(&current,sizeof(current),1,fp);fflush(stdin);


                    break;
                }
                else{fread(&current,sizeof(current),1,fp);}
            }


        }
        if(C==3)//Northeast
        {
            if(right%2!=0)//fard
            {
                if(check2(right+1,up)==0){return;}if(check(right+1,up)==0){return;}if(up>height-1||right+1>width-1||right+1<0||up<0){return;}
                rewind(fp);
                fread(&current,sizeof(current),1,fp);
                while(1)
                    {
                        if(feof(fp)){break;}
                        if(current.makanxx==right && current.makanyy==up && check2(current.makanxx+1,current.makanyy)!=0  &&   check(current.makanxx+1,current.makanyy)!=0)
                        {
                            rewind(fp);
                            while(1)
                            {
                                fread(&current,sizeof(current),1,fp);
                                if(current.makanxx==right && current.makanyy==up)
                                    break;
                            }
                            current.makanxx++;
                            fseek(fp,-1*sizeof(current),SEEK_CUR);
                            fwrite(&current,sizeof(current),1,fp);


                            break;
                        }
                        else{fread(&current,sizeof(current),1,fp);}
                    }
            }


        else
        {
                if(check2(right+1,up+1)==0){return;}if(check(right+1,up+1)==0){return;}if(up+1>height-1||right+1>width-1||right+1<0||up+1<0){return;}
                rewind(fp);
                fread(&current,sizeof(current),1,fp);
                while(1)
                    {
                        if(feof(fp)){break;}
                        if(current.makanxx==right && current.makanyy==up && check2(current.makanxx+1,current.makanyy+1)!=0  &&   check(current.makanxx+1,current.makanyy+1)!=0)
                        {
                             rewind(fp);
                            while(1)
                            {
                                fread(&current,sizeof(current),1,fp);
                                if(current.makanxx==right && current.makanyy==up)
                                    break;
                            }
                            current.makanxx++;
                            current.makanyy++;
                            fseek(fp,-1*sizeof(current),SEEK_CUR);
                            fwrite(&current,sizeof(current),1,fp);


                            break;
                        }
                        else{fread(&current,sizeof(current),1,fp);}
                    }
        }
        }
        if(C==4)//Northwest
        {
            if(right%2!=0)//fard
            {
            if(check2(right-1,up)==0){return;}if(check(right-1,up)==0){return;}if(up>height-1||right-1>width-1||right-1<0||up<0){return;}
            rewind(fp);
            fread(&current,sizeof(current),1,fp);
            while(1)
            {
                if(feof(fp)){break;}
                    if(current.makanxx==right && current.makanyy==up&& check2(current.makanxx-1,current.makanyy)!=0  &&   check(current.makanxx-1,current.makanyy)!=0)
                    {
                         rewind(fp);
                            while(1)
                            {
                                fread(&current,sizeof(current),1,fp);
                                if(current.makanxx==right && current.makanyy==up)
                                    break;
                            }
                            current.makanxx--;
                            fseek(fp,-1*sizeof(current),SEEK_CUR);
                            fwrite(&current,sizeof(current),1,fp);


                        break;
                    }
                    else{fread(&current,sizeof(current),1,fp);}
            }

        }
        else
        {
            if(check2(right-1,up+1)==0){return;}if(check(right-1,up+1)==0){return;}if(up+1>height-1||right-1>width-1||right-1<0||up+1<0){return;}
            rewind(fp);
            fread(&current,sizeof(current),1,fp);
            while(1)
            {
                if(feof(fp)){break;}
                    if(current.makanxx==right && current.makanyy==up&& check2(current.makanxx-1,current.makanyy+1)!=0  &&   check(current.makanxx-1,current.makanyy+1)!=0)
                    {
                         rewind(fp);
                            while(1)
                            {
                                fread(&current,sizeof(current),1,fp);
                                if(current.makanxx==right && current.makanyy==up)
                                    break;
                            }
                        current.makanxx--;
                        current.makanyy++;
                        fseek(fp,-1*sizeof(current),SEEK_CUR);
                        fwrite(&current,sizeof(current),1,fp);


                        break;
                    }
                    else{fread(&current,sizeof(current),1,fp);}
            }
        }
        }
        if(C==5)//Southeast
        {
            if(right%2!=0){
            if(check2(right+1,up-1)==0){return;}if(check(right+1,up-1)==0){return;}if(up-1>height-1||right+1>width-1||right+1<0||up-1<0){return;}
            rewind(fp);
            fread(&current,sizeof(current),1,fp);
            while(1)
            {
                if(feof(fp)){break;}
                    if(current.makanxx==right && current.makanyy==up && check2(current.makanxx+1,current.makanyy-1)!=0  &&   check(current.makanxx+1,current.makanyy-1)!=0)
                    {
                         rewind(fp);
                            while(1)
                            {
                                fread(&current,sizeof(current),1,fp);
                                if(current.makanxx==right && current.makanyy==up)
                                    break;
                            }
                        current.makanxx++;
                        current.makanyy--;
                        fseek(fp,-1*sizeof(current),SEEK_CUR);
                        fwrite(&current,sizeof(current),1,fp);


                        break;
                    }
                    else{fread(&current,sizeof(current),1,fp);}
            }

        }
        else
        {
            if(check2(right+1,up)==0){return;}if(check(right+1,up)==0){return;}if(up>height-1||right+1>width-1||right+1<0||up<0){return;}
            rewind(fp);
            fread(&current,sizeof(current),1,fp);
            while(1)
            {
                if(feof(fp)){break;}
                    if(current.makanxx==right && current.makanyy==up && check2(current.makanxx+1,current.makanyy)!=0  &&   check(current.makanxx+1,current.makanyy)!=0)
                    {
                         rewind(fp);
                            while(1)
                            {
                                fread(&current,sizeof(current),1,fp);
                                if(current.makanxx==right && current.makanyy==up)
                                    break;
                            }
                        current.makanxx++;
                        fseek(fp,-1*sizeof(current),SEEK_CUR);
                        fwrite(&current,sizeof(current),1,fp);


                        break;
                    }
                    else{fread(&current,sizeof(current),1,fp);}
            }
        }
        }
        if(C==6)//Southwest
        {
        if(right%2!=0){
                if(check2(right-1,up-1)==0){return;}if(check(right-1,up-1)==0){return;}if(up-1>height-1||right-1>width-1||right-1<0||up-1<0){return;}
            rewind(fp);
            fread(&current,sizeof(current),1,fp);
            while(1)
            {
                if(feof(fp)){break;}
                    if(current.makanxx==right && current.makanyy==up&& check2(current.makanxx-1,current.makanyy-1)!=0  &&   check(current.makanxx-1,current.makanyy-1)!=0)
                    {
                         rewind(fp);
                            while(1)
                            {
                                fread(&current,sizeof(current),1,fp);
                                if(current.makanxx==right && current.makanyy==up)
                                    break;
                            }
                        current.makanxx--;
                        current.makanyy--;
                        fseek(fp,-1*sizeof(current),SEEK_CUR);
                        fwrite(&current,sizeof(current),1,fp);

                        break;
                    }
                    else{fread(&current,sizeof(current),1,fp);}
            }

        }
        else
            {
                if(check2(right-1,up)==0){return;}if(check(right-1,up)==0){return;}if(up>height-1||right-1>width-1||right-1<0||up<0){return;}
                rewind(fp);
            fread(&current,sizeof(current),1,fp);
            while(1)
            {
                if(feof(fp)){break;}
                    if(current.makanxx==right && current.makanyy==up&& check2(current.makanxx-1,current.makanyy)!=0  &&   check(current.makanxx-1,current.makanyy)!=0)
                    {
                         rewind(fp);
                            while(1)
                            {
                                fread(&current,sizeof(current),1,fp);
                                if(current.makanxx==right && current.makanyy==up)
                                    break;
                            }
                        current.makanxx--;
                        fseek(fp,-1*sizeof(current),SEEK_CUR);
                        fwrite(&current,sizeof(current),1,fp);


                        break;
                    }
                    else{fread(&current,sizeof(current),1,fp);}
            }
        }
        fflush(stdin);
     }
}
//________________________________________________________________________________________________________________________________//
int split (void)
{
    //kodam selul?
    //be koja?
    //taghsim energy!
    struct gamercell current;
    int up,right;
    printf("select the cell that you want to split\nI am in [0][0]\ngive me the address first x then y \n");
    scanf("%d",&right);scanf("%d",&up);
    if(up>height-1 || right>width-1)
    {
        printf("it is wrong\n");
        split();
    }
    else{printf("ok\n");}


        rewind(fp);   //printf("----wait----\n");

        while(1)
        {

            fread(&current,sizeof(current),1,fp);if(feof(fp)){break;}
            if(current.makanxx==right && current.makanyy==up )
            {
                        if(current.energy>=80)
                        {
                                time_t
                                t=time(NULL);
                                srand(t);
                                if(check3(right,up)==1)//agaar taghsim bashad
                                {
                                    if(right%2!=0)//fard
                                    {//mikham khuneh haye atraf ro check konam
                                        if(check(right,up+1)==0 ||check5(right,up+1)==0||check2(right,up+1)==0)
                                        {
                                            if(check(right+1,up)==0||check5(right+1,up)==0||check2(right+1,up)==0)
                                            {
                                                if(check(right+1,up-1)==0||check5(right+1,up-1)==0||check2(right+1,up-1)==0)
                                                {
                                                    if(check(right-1,up-1)==0||check5(right-1,up-1)==0||check2(right-1,up-1)==0)
                                                    {
                                                        if(check(right,up-1)==0||check5(right,up-1)==0||check2(right,up-1)==0)
                                                        {
                                                            if(check(right-1,up)==0||check5(right-1,up)==0||check2(right-1,up)==0)
                                                            {
                                                                return 0;
                                                            }
                                                        }
                                                    }

                                                }

                                            }
                                        }
                                        while(1)
                                    {

//printf("----wait----\n");
                                        int x=rand()%width;
                                        if(x==right || x==right-1 || x==right+1)
                                        {
                                            int y;
                                            do
                                                {y=rand()%height;}while(y!=up &&y!=up-1&&y!=up+1);

                                            if(x==right-1 && y==up+1){continue;}
                                            else if(x==right && y==up){continue;}
                                            else if(x==right+1 && y==up+1){continue;}
                                            else if(x>width-1 || y>height-1 ||x<0 ||y<0){continue;}
                                            else if(check(x,y)!=0 && check2(x,y)!=0)
                                            { xx=x;
                                             yy=y;
                                            break;
                                            }



                                        }
                                    }
                                    }

                                    else//zoj
                                    {
                                        if(check(right,up+1)==0||check5(right,up+1)==0||check2(right,up+1)==0 )
                                        {
                                            if(check(right+1,up+1)==0||check5(right+1,up+1)==0||check2(right+1,up+1)==0 )
                                            {
                                                if(check(right+1,up)==0||check5(right+1,up)==0||check2(right+1,up)==0 )
                                                {
                                                    if(check(right,up-1)==0||check5(right,up-1)==0||check2(right,up-1)==0)
                                                    {
                                                        if(check(right-1,up)==0||check5(right-1,up)==0||check2(right-1,up)==0 )
                                                        {
                                                            if(check(right-1,up+1)==0||check5(right-1,up+1)==0||check2(right-1,up+1)==0)
                                                            {
                                                                return 0;
                                                            }
                                                        }
                                                    }

                                                }

                                            }

                                        }
                                         while(1)
                                    {

    //printf("----wait----\n");
                                        int x=rand()%width;
                                        if(x==right || x==right-1 || x==right+1)
                                        {

                                            int y;
                                            do
                                                {y=rand()%height;}while(y!=up &&y!=up-1&&y!=up+1);

                                            if(x==right-1 && y==up-1){continue;}
                                            else if(x==right && y==up){continue;}
                                            else if(x==right+1 && y==up-1){continue;}
                                            else if(x>width-1 || y>height-1 || x<0 ||y<0){continue;}
                                            else if(check(x,y)!=0 && check2(x,y)!=0)
                                            { xx=x;
                                             yy=y;
                                            break;
                                            }



                                        }
                                    }
                                    }

                            rewind(fp);
                            while(1)
                            {
                                fread(&current,sizeof(current),1,fp);
                                if(current.makanxx==right && current.makanyy==up)
                                    break;
                            }
                            current.energy=40;
                            fseek(fp,-1*sizeof(current),SEEK_CUR);
                            fwrite(&current,sizeof(current),1,fp);
                            struct gamercell gamer_cell;
                            gamer_cell.energy=40;
                            gamer_cell.makanxx=xx;
                            gamer_cell.makanyy=yy;
                            fseek(fp,0,SEEK_END);
                            fwrite(&gamer_cell,sizeof(gamer_cell),1,fp);break;

                          }//agar check3
                        }
                        else
                            {
                                printf("energy is too low\n");return 0;
                            }
                    }
                }

                fflush(stdin);return(0);

    }
/*______________________________________________________________________________________________________________________________*/
struct cell_position move2 (int x,int y,enum move_direction move_directions)
{
    if(move_directions==NORTH)
    {
        y++;
    }
    if(move_directions==SOUTH)
    {
        y--;
    }
    if(move_directions==NORTHEAST)
    {
        if(x%2!=0){x++;}else{x++;y++;}
    }
    if(move_directions==NORTHWEST)
    {
        if(x%2!=0){x--;}else{x--;y++;}
    }
    if(move_directions==SOUTHEAST)
    {
        if(x%2!=0){x++;y--;}else{x++;}
    }
    if(move_directions==SOUTHWEST)
    {
        if(x%2!=0){x--;y--;}else{x--;}
    }
   struct cell_position res;
   res.x=x;
   res.y=y;
   return res;




}
/*______________________________________________________________________________________________________________________________*/
void boost (void)
{
   // struct gamercell current;
    int up,right;
    printf("select the cell that you want to boost\nI am in [0][0]\ngive me the adrass of block first x then y \n");
    scanf("%d",&right);scanf("%d",&up);
    if(up>height-1 || right>width-1)
    {
        printf("it is wrong\n");
        boost();
    }
    else{printf("ok\n");}
    if(check4(right,up))
    {
        printf(" but this is not ok for boosting\n");
    }
    else
    {

        if(maparray[right][up].energy>=15)
           {

                rewind(fp);

                while(1)
                {
                    fread(&current,sizeof(current),1,fp);
                    if(feof(fp)){break;}
                    if(current.makanxx==right && current.makanyy==up)
                    {
                        if(current.energy<100){
                        maparray[right][up].energy-=15;
                        current.energy+=15;
                        fseek(fp,-1*sizeof(current),SEEK_CUR);
                        fwrite(&current,sizeof(current),1,fp);
                        fflush(stdin);
                        break;}
                    }
                }
            }
        else
        {

                rewind(fp);
                fread(&current,sizeof(current),1,fp);
                while(1)
                {
                    fread(&current,sizeof(current),1,fp);
                    if(feof(fp)){break;}

                    if(current.makanxx==right && current.makanyy==up)

                    {
                        //if(current.energy<100){
                        current.energy+=maparray[right][up].energy;
                        maparray[right][up].energy=0;
                        fseek(fp,-1*sizeof(current),SEEK_CUR);
                        fwrite(&current,sizeof(current),1,fp);
                        fflush(stdin);
                        break;//}



                    }
                }

        }

    }

}
/*______________________________________________________________________________________________________________________________*/
void save (void)
{
    char mapname[30];char mapname2[30];char amibmap[30];
    printf("please enter your map name\\bin\n");
    scanf("%s",mapname);
     printf("please enter your map name\\text\n");
    scanf("%s",mapname2);
    if(strlen(filename)<2){printf("enter the name of your map of amibs \\bin \n");scanf("%s",filename2);}
    else{printf("the name of your map of amibs is %s\\bin \n",filename);}
    printf("please enter your map of amibs\\txt");
    scanf("%s",amibmap);
    printf("in this file first u see the energy of cell the x and y for each cell\n");
    map3=fopen(mapname,"a+b");//bin/map
    fwrite(&width,sizeof(int),1,map3);
    fwrite(&height,sizeof(int),1,map3);
    int i=0,j;char ch='-';
    while(i<width)
    {
        for(j=height-1;j>=0;j--)
        {
                fwrite(&maparray[i][j].energy,sizeof(int),1,map3);
                fwrite(&maparray[i][j].type,sizeof(char),1,map3);
        }
        i++;
    }

    map4=fopen(mapname2,"a+");//txt/map
    fprintf(map4,"%d\n",width);
    fprintf(map4,"%d\n",height);
    i=0;
    while(i<width)
    {
        for(j=height-1;j>=0;j--)
        {
            fprintf(map4,"%d\n",i);
            fprintf(map4,"%d\n",j);
            fprintf(map4,"%d\n",maparray[i][j].energy);
            fprintf(map4,"%c\n",maparray[i][j].type);
            fprintf(map4,"%c\n",ch);
        }
        i++;
    }
    if(strlen(filename2)<2)
    {amibmaptxt=fopen(filename,"r+b");}//bin/amibs
    else{amibmaptxt=fopen(filename2,"a+b");}//bin/amibs
    struct gamercell current;
    rewind(fp);
    while(1)
    {

        fread(&current,sizeof(current),1,fp);
        if(feof(fp)){break;}
        fwrite(&current,sizeof(current),1,amibmaptxt);



    }
    amibmaptxt2=fopen(amibmap,"a+");//txt/amibs
    rewind(fp);
    while(1)
    {

        fread(&current,sizeof(current),1,fp);
        if(feof(fp)){break;}
        fprintf(amibmaptxt2,"%d\n",current.energy);
        fprintf(amibmaptxt2,"%d\n",current.makanxx);
        fprintf(amibmaptxt2,"%d\n",current.makanyy);
        fprintf(amibmaptxt2,"%s\n","----");

    }
  fflush(stdin);
}
/*______________________________________________________________________________________________________________________________*/
void do_her_aim (int B)
{
    if(B==1)//move
    {
       move();//ok
    }
    if(B==2)//split
    {
        split();//ok
    }
    if(B==3)//boost
    {
       boost();//ok

    }
    if(B==4)//save
    {
        save();//ok
    }


}



