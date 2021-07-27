#include <stdio.h>
#include <stdlib.h>
#include<windows.h>


int r=0, c=0;
typedef struct
{
    int r;
    int c;
    int baarr[50][50];
    int disparr[50][50];
int time;

} game;
typedef struct
{
    char name[10];
    int best;


} user;
/*
typedef struct
{
    char name[10];
    int r;
    int c;
    int ba[50][50];
    int disp[50][50];


}*/
void players(int score)
{
    FILE * pf;
    user u[50];
    int n;
    pf=fopen("players.txt","r");
    while(!(feof(pf)))
    {
        fscanf(pf,"%d,%[^,]%*c",&u[n].best,u[n].name);
        strlwr(u[n].name);
        n++;
    }
char inserted[25];
    fclose(pf);

    int ds;
    int i;
    char temp[25];
pf=fopen("players.txt","a");
    do
    {
       printf("add to existing user ? \n (1) YES (2) I'm new to the game (3) Exit without saving ");
       scanf("%d",&ds);

    }while((ds!=1)&&(ds!=2)&&(ds!=3));
int F=0;
    if (ds==1)
    {
        printf("enter your unique name");
        scanf("%s",inserted);

        strlwr(temp);
        for(i=0;i<n;i++)
        {
            if(!strcmp(temp,u[i].name))
            {
                if(score>u[i].best)
             {
                 u[i].best=score;
                 F=1;
             }
              printf("name : %s \n best score%d",u[i].name,u[i].best);
            }

        }
        if(F==0)
        {
            printf("NOT found do you want to create new unique name\ (1)no,Thanks  (2)YES?");
            scanf("%d",&ds);
        }

    }
    if(ds==2)
    {

           printf("enter your name");
    scanf("%s",u[n].name);
    u[n].best=score;
    }
    if (ds==3)
        return;



}
void newgame();
void completegame()
{
       system("COLOR 3F");
    int k=0;
    int i=0;
    int j=0;
    FILE*fu;
    game loaded[50];

    fu=fopen("game.txt","r");
    while(!(feof(fu)))
    {
        fscanf(fu,"%d %d",&loaded[k].r,&loaded[k].c);
        for(i=0; i<loaded[k].r; i++)
        {
            for(j=0; j<loaded[k].c; j++)
                fscanf(fu,"%d",&loaded[k].baarr[i][j]);
        }
        for(i=0; i<loaded[k].r; i++)
        {
            for(j=0; j<loaded[k].c; j++)
                fscanf(fu,"%d",&loaded[k].disparr[i][j]);
        }

        k++;
    }
    k--;

    fclose(fu);
    int n;
    printf("Choose game");

    for(n=0; n<k; n++)
    {
        printf("(%d)\n\n",n+1);
        for(i=0; i<loaded[n].r; i++)
        {
            for(j=0; j<loaded[n].c; j++)
            {
                if ((loaded[n].disparr[i][j]>0)&&(loaded[n].disparr[i][j]!=88)&&(loaded[n].disparr[i][j]<10))
                    printf("%d   ",loaded[n].disparr[i][j]);
                else if((loaded[n].disparr[i][j]>0)&&(loaded[n].disparr[i][j]!=88)&&(loaded[n].disparr[i][j]>9))
                    printf("%d  ",loaded[n].disparr[i][j]);
                else if(loaded[n].disparr[i][j]==0)
                    printf("    ");
                else if (loaded[n].disparr[i][j]==-1)
                {
                    printf("*   ");
                }
                else if (loaded[n].disparr[i][j]==-2)
                    printf("f   ");

                else if (loaded[n].disparr[i][j]==-3)
                {
                    printf("?   ");
                }
                else if(loaded[n].disparr[i][j]==-10)
                    printf("    ");

                else printf("X   ");
                // if((i==(0)&&(j==(c-1))))
                //printf("\t\t%d",w);
            }
            printf("\n");
        }

        printf("\n");
    }
    int d;


    scanf("%d",&d);
    d--;
    system("cls");
    for(i=0; i<loaded[d].r; i++)
    {
        for(j=0; j<loaded[d].c; j++)
        {
            if ((loaded[d].disparr[i][j]>0)&&(loaded[d].disparr[i][j]!=88)&&(loaded[d].disparr[i][j]<10))
                printf("%d   ",loaded[d].disparr[i][j]);
            else if((loaded[d].disparr[i][j]>0)&&(loaded[d].disparr[i][j]!=88)&&(loaded[d].disparr[i][j]>9))
                printf("%d  ",loaded[d].disparr[i][j]);
            else if(loaded[d].disparr[i][j]==0)
                printf("    ");
            else if (loaded[d].disparr[i][j]==-1)
            {
                printf("*   ");
            }
            else if (loaded[d].disparr[i][j]==-2)
                printf("f   ");

            else if (loaded[d].disparr[i][j]==-3)
            {
                printf("?   ");
            }
            else if(loaded[d].disparr[i][j]==-10)
                printf("    ");

            else printf("X   ");
            // if((i==(0)&&(j==(c-1))))
            //printf("\t\t%d",w);
        }
        printf("\n");
    }

    char move;
    int T=0;
    int w=0;
    int m ;
    int mo=0;
    m=1+(((loaded[d].r-2)*(loaded[d].c-2))/10);
    int ds;
    int x,y;
    int start;
    int ended;

    start=clock();
    int diff;
    while (w<m)
    {
        ended=clock();

        printf("\nChoose whether to (o)open - (f)flag - (q)question - (u)unmark - (b) go back  \n");
        scanf("%c",&move);
        if((move=='o')||(move=='f')||(move=='u')||(move=='q'))
        {

            printf("\nplay your move\n");

            scanf("%d%d",&x,&y);

            system("cls");

            if(move=='o')
            {
                if (loaded[d].disparr[x][y]==loaded[d].baarr[x][y])
                {
                    if(loaded[d].disparr[x][y-1]==88)
                        loaded[d].disparr[x][y-1]=loaded[d].baarr[x][y-1];
                    if(loaded[d].disparr[x][y+1]==88)
                        loaded[d].disparr[x][y+1]=loaded[d].baarr[x][y+1];
                    if(loaded[d].disparr[x+1][y-1]==88)
                        loaded[d].disparr[x+1][y-1]=loaded[d].baarr[x+1][y-1];
                    if(loaded[d].disparr[x+1][y]==88)
                        loaded[d].disparr[x+1][y]=loaded[d].baarr[x+1][y];
                    if(loaded[d].disparr[x+1][y+1]==88)
                        loaded[d].disparr[x+1][y+1]=loaded[d].baarr[x+1][y+1];
                    if(loaded[d].disparr[x-1][y-1]==88)
                        loaded[d].disparr[x-1][y-1]=loaded[d].baarr[x-1][y-1];
                    if(loaded[d].disparr[x-1][y+1]==88)
                        loaded[d].disparr[x-1][y+1]=loaded[d].baarr[x-1][y+1];
                    if(loaded[d].disparr[x-1][y]==88)
                        loaded[d].disparr[x-1][y]=loaded[d].baarr[x-1][y];

                    if(loaded[d].disparr[x][y-1]==0)
                        open(loaded[d].disparr,loaded[d].baarr,(x),(y-1));
                    if(loaded[d].disparr[x][y+1]==0)
                        open(loaded[d].disparr,loaded[d].baarr,(x),(y+1));
                    if(loaded[d].disparr[x+1][y-1]==0)
                        open(loaded[d].disparr,loaded[d].baarr,(x+1),(y-1));
                    if(loaded[d].disparr[x+1][y]==0)
                        open(loaded[d].disparr,loaded[d].baarr,(x+1),(y));
                    if(loaded[d].disparr[x+1][y+1]==0)
                        open(loaded[d].disparr,loaded[d].baarr,(x+1),(y+1));
                    if(loaded[d].disparr[x-1][y-1]==0)
                        open(loaded[d].disparr,loaded[d].baarr,(x-1),(y-1));
                    if(loaded[d].disparr[x-1][y+1]==0)
                        open(loaded[d].disparr,loaded[d].baarr,(x-1),(y+1));
                    if(loaded[d].disparr[x-1][y]==0)
                        open(loaded[d].disparr,loaded[d].baarr,(x-1),(y));

                }
                if (loaded[d].baarr[x][y]==-1)
                {
                    T=1;
                    for(i=1; i<((loaded[d].r)-1); i++)
                    {
                        for(j=1; j<((loaded[d].c)-1); j++)
                        {


                            if(loaded[d].baarr[i][j]==-1)
                                loaded[d].disparr[i][j]=-1;
                        }

                    }
                    loaded[d].disparr[x][y]=loaded[d].baarr[x][y];
                }
                else if (loaded[d].baarr[x][y]==0)
                {
                    open(loaded[d].disparr,loaded[d].baarr,(x),(y));
                }
                else loaded[d].disparr[x][y]=loaded[d].baarr[x][y];
            }
            else if (move=='f')
            {
                loaded[d].disparr[x][y]=-2;
                if (loaded[d].baarr[x][y]==-1)
                {
                    w++;
                }

            }
            else if (move=='q')
                loaded[d].disparr[x][y]=-3;
            else if (move=='u')
            {
                if (loaded[d].disparr[x][y]==-2) loaded[d].disparr[x][y]=88;
                if (loaded[d].disparr[x][y]==-3)  loaded[d].disparr[x][y]=88;
            }
        }
        else if(move=='b')
        {
            system("cls");
            printf("(1) SAVE GAME \n (2) NEW GAME \n(3) EXIT WITHOUT SAVING \n(4) cancel");
            scanf("%d",&ds);
            if(ds==1)

            {
                savegame(loaded[d].baarr,loaded[d].disparr,loaded[d].r,loaded[d].c);
                return;
            }
            if (ds==2)
                newgame();
            if(ds==3)
                return;
            if (ds==4)
                continue;
        }
        /*  else if (move=='b')
              {
                  printf("(1) SAVE GAME \n (2) NEW GAME (3) EXIT WITHOUT SAVING");
                  if(ds==1)
                      savegame(loaded[d].baarr,loaded[d].disparr,)

              }

                  }
        */
        system("cls");
        for(i=0; i<loaded[d].r; i++)
        {
            for(j=0; j<loaded[d].c; j++)
            {
                if ((loaded[d].disparr[i][j]>0)&&(loaded[d].disparr[i][j]!=88)&&(loaded[d].disparr[i][j]<10))
                    printf("%d   ",loaded[d].disparr[i][j]);
                else if((loaded[d].disparr[i][j]>0)&&(loaded[d].disparr[i][j]!=88)&&(loaded[d].disparr[i][j]>9))
                    printf("%d  ",loaded[d].disparr[i][j]);
                else if(loaded[d].disparr[i][j]==0)
                    printf("    ");
                else if (loaded[d].disparr[i][j]==-1)
                {
                    printf("*   ");
                }
                else if (loaded[d].disparr[i][j]==-2)
                    printf("f   ");

                else if (loaded[d].disparr[x][y]==-3)
                {
                    printf("?   ");
                }
                else if(loaded[d].disparr[i][j]==-10)
                    printf("    ");

                else printf("X   ");
                // if((i==(0)&&(j==(c-1))))
                //printf("\t\t%d",w);
            }
            printf("\n");
        }
mo++;
diff =(ended-start)/1000;
int temp;
temp=diff;
int min=0;
while(temp>60)
    {
        temp=temp-60;
        min++;

    }
printf("\n TIME %d:%d",min,temp);

        if(T==1) break;
    }
    int score;
    score= (((loaded[d].r)*(loaded[d].c))/((ended-start)*mo));
    system("cls");
    if (T==1)
        printf("You lose");
    else {printf("you win \n your score is %d your time is %d",score,diff);
    players(score);

    }



}
void savegame(int ba[r][c],int disp[r][c],int r,int c)
{
    int i,j;
    system("cls");

    printf("\n");
    printf("\n");

    FILE* fu;
    fu= fopen("game.txt","a");
    fprintf(fu,"%d %d ",r,c);


    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            fprintf(fu,"%d ",ba[i][j]);

        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            fprintf(fu,"%d ",disp[i][j]);

        }
    }
    fclose(fu);
       system("COLOR 3F");
printf("GAME successfully  ");
}

void open (int disp[r][c], int ba[r][c], int x, int y);
void mines(int ba[r][c],int x, int y,int r,int c);
int main()
{   system("COLOR 3F");
    int l=-1;
    int d;


    while(l==-1)
    {
        //system("cls");
        printf("(1) NEW GAME \n (2) LOAD GAME \n(3)EXIT ");
        scanf("%d",&d);
        if (d==1)
            newgame();
        if (d==2)
            completegame();
        if(d==3)
        {
            l=0;
        }
    }
    return 0;
}
void mines(int ba[r][c],int x, int y,int r,int c)
{
    int tc,tr;
    int m;
    int i,j;
    //time_t t;
    srand(time(NULL));
    m=1+(((r-2)*(c-2))/10);
    while (m!=0) // puts mines randomly
    {
        tr=rand()%(r-1);
        tc=rand()%(c-1);
        //  if ((tr!=(x-1)&&tr!=(x)&&tr!=(x+1))||(tc!=(y-1)&&tr!=(y)&&tr!=(y+1)))
        if (!((tr==0)||(tc==0)||((tr==(x-1))&&(tc==(y-1)))||((tr==(x-1))&&(tc==(y)))||((tr==(x-1))&&(tc==(y+1)))||((tr==(x))&&(tc==(y-1)))||((tr==(x))&&(tc==(y)))||((tr==(x))&&(tc==(y+1)))||((tr==(x+1))&&(tc==(y-1)))||((tr==(x+1))&&(tc==(y)))||((tr==(x+1))&&(tc==(y+1)))))
        {


            if (ba[tr][tc]!=-1)
            {
                ba[tr][tc] = -1;
                m--;
            }




        }
    }
    for(i=1; i<(r-1); i++)
    {
        for(j=1; j<(c-1); j++)
        {


            if (ba[i][j]==10)
                ba[i][j]=0;
        }
        printf("\n");
    }
    for(i=1; i<r-1; i++)
    {
        for(j=1; j<c-1; j++)
        {
            if  (ba[i][j]!=-1)
            {
                if (ba[i-1][j-1]==-1)
                {
                    ba[i][j]++;
                }

                if (ba[i-1][j]==-1)
                {
                    ba[i][j]++;
                }

                if (ba[i-1][j+1]==-1)
                {
                    ba[i][j]++;
                }

                if (ba[i][j-1]==-1)
                {
                    ba[i][j]++;
                }
                if (ba[i][j+1]==-1)
                {
                    ba[i][j]++;
                }
                if (ba[i+1][j-1]==-1)
                {
                    ba[i][j]++;
                }
                if (ba[i+1][j]==-1)
                {
                    ba[i][j]++;
                }
                if (ba[i+1][j+1]==-1)
                {
                    ba[i][j]++;
                }
            }




        }


    }


}
void open(int disp[r][c], int ba[r][c], int x, int y)
{

    if (ba[x][y]==0)
    {
        if(disp[x][y-1]==88)
            disp[x][y-1]=ba[x][y-1];
        if(disp[x][y+1]==88)
            disp[x][y+1]=ba[x][y+1];
        if(disp[x+1][y-1]==88)
            disp[x+1][y-1]=ba[x+1][y-1];
        if(disp[x+1][y]==88)
            disp[x+1][y]=ba[x+1][y];
        if(disp[x+1][y+1]==88)
            disp[x+1][y+1]=ba[x+1][y+1];
        if(disp[x-1][y-1]==88)
            disp[x-1][y-1]=ba[x-1][y-1];
        if(disp[x-1][y+1]==88)
            disp[x-1][y+1]=ba[x-1][y+1];
        if(disp[x-1][y]==88)
            disp[x-1][y]=ba[x-1][y];
        ba[x][y]=-10;

    }
    if ((ba[x][y-1]==0))
        open(disp,ba,x,y-1);
    if ((ba[x][y+1]==0))
        open(disp,ba,x,y+1);
    if ((ba[x-1][y]==0))
        open(disp,ba,x-1,y);
    if ((ba[x+1][y]==0))
        open(disp,ba,x+1,y);
    if ((ba[x-1][y-1]==0))
        open(disp,ba,x-1,y-1);
    if ((ba[x+1][y+1]==0))
        open (disp,ba,x+1,y+1);
    if ((ba[x+1][y-1]==0))
        open (disp,ba,x+1,y-1);
    if ((ba[x-1][y+1]==0))
        open (disp,ba,x-1,y+1);




}
void newgame()
{
    system("cls");
    system("COLOR 3F");
    int i,j;
    do
    {
        printf("ENTER THE DIMENSION R then C");
        scanf("%d%d",&r,&c);
    }
    while((r<9)||(c<9));

    int x,y;


    r+=2;
    c+=2;
    int ba[r][c];
    int disp[r][c];
    disp[0][0]=0;
    disp [r-1][0]=0;
    disp[0][c-1]=0;
    disp[r-1][c-1]=0;
    ba[0][0]=0;
    ba[r-1][0]=0;
    ba[0][c-1]=0;
    ba[r-1][c-1]=0;
    for (i=1; i<(c-1); i++)
    {
        disp[0][i]=i;
        disp[r-1][i]=i;
        disp[i][0]=i;
        disp[i][c-1]=i;
        ba[0][i]=i;
        ba[r-1][i]=i;
        ba[i][0]=i;
        ba[i][c-1]=i;
    }


    for(i=1; i<(r-1); i++)
    {
        for(j=1; j<(c-1); j++)
        {
            ba[i][j]=10;
            disp[i][j]=88;
        }

    }

    system("cls");
    do
    {
        printf("play your move ");
        scanf("%d%d",&x,&y);
    }
    while(x>r||y>c||x==0||y==0);
    system("cls");


    // mines(ba,(x),(y),r,c);
    /*
        printf("\n\n\n\n\n\n");
            for(i=1; i<(r-1); i++)
     {
         for(j=1; j<(c-1); j++)
             printf("%d   ",ba[i][j]);
         printf("\n");
     }
     */

//open(disp,ba[r][c],x,y);
    int ds;

    mines(ba,(x),(y),(r),(c));
    /*for(i=1; i<(r-1); i++)
       {
           for(j=1; j<(c-1); j++)
               printf("%d   ",ba[i][j]);
           printf("\n");
       }
        printf("\n"); printf("\n"); printf("\n");
        */

    open(disp,ba,(x),(y));

    /*     for(i=1; i<(r-1); i++)
    {
    for(j=1; j<(c-1); j++)
    {


        if (disp[i][j]==88)
            disp[i][j]=0;
    }
    printf("\n");
    }
    */
    system("cls");
    /*
           for(i=0; i<(r); i++)
        {

            for(j=0; j<(c); j++)
            {if ((disp[i][j]>0)&&(disp[i][j]!=88)&&(disp[i][j]<10))
                printf("%d   ",disp[i][j]);
    else if ((disp[i][j]>0)&&(disp[i][j]!=88)&&(disp[i][j]>=10))
                printf("%d  ",disp[i][j]);
                else if((disp[i][j]==0)||(disp[i][j]==-9))
                    printf("    ");
                    else printf("X   ");
            }

            printf("\n");
        }
        */

    char move;
    int T=0;
    int w=0;
    int m ;
    m=1+(((r-2)*(c-2))/10);
int mo=0;


    int start;
    int ended;
    start=clock();
    int diff;
    while (w<m)
    {
        ended=clock();


        printf("\nChoose whether to (o)open - (f)flag - (q)question - (u)unmark - (b) go back  \n");
        scanf("%c",&move);
        if((move=='o')||(move=='f')||(move=='u')||(move=='q'))
        {

            printf("\nplay your move\n");

            scanf("%d%d",&x,&y);

            system("cls");
            if(move=='o')
            {
                if (disp[x][y]==ba[x][y])
                {
                    if(disp[x][y-1]==88)
                        disp[x][y-1]=ba[x][y-1];
                    if(disp[x][y+1]==88)
                        disp[x][y+1]=ba[x][y+1];
                    if(disp[x+1][y-1]==88)
                        disp[x+1][y-1]=ba[x+1][y-1];
                    if(disp[x+1][y]==88)
                        disp[x+1][y]=ba[x+1][y];
                    if(disp[x+1][y+1]==88)
                        disp[x+1][y+1]=ba[x+1][y+1];
                    if(disp[x-1][y-1]==88)
                        disp[x-1][y-1]=ba[x-1][y-1];
                    if(disp[x-1][y+1]==88)
                        disp[x-1][y+1]=ba[x-1][y+1];
                    if(disp[x-1][y]==88)
                        disp[x-1][y]=ba[x-1][y];

                    if(disp[x][y-1]==0)
                        open(disp,ba,(x),(y-1));
                    if(disp[x][y+1]==0)
                        open(disp,ba,(x),(y+1));
                    if(disp[x+1][y-1]==0)
                        open(disp,ba,(x+1),(y-1));
                    if(disp[x+1][y]==0)
                        open(disp,ba,(x+1),(y));
                    if(disp[x+1][y+1]==0)
                        open(disp,ba,(x+1),(y+1));
                    if(disp[x-1][y-1]==0)
                        open(disp,ba,(x-1),(y-1));
                    if(disp[x-1][y+1]==0)
                        open(disp,ba,(x-1),(y+1));
                    if(disp[x-1][y]==0)
                        open(disp,ba,(x-1),(y));

                }
                if (ba[x][y]==-1)
                {
                    T=1;
                    for(i=1; i<(r-1); i++)
                    {
                        for(j=1; j<(c-1); j++)for(i=1; i<(r-1); i++)
                            {
                                if(ba[i][j]==-1)
                                    disp[i][j]=-1;
                            }

                    }
                    disp[x][y]=ba[x][y];
                }
                else if (ba[x][y]==0)
                {
                    open(disp,ba,(x),(y));
                }
                else disp[x][y]=ba[x][y];
            }
            else if (move=='f')
            {
                disp[x][y]=-2;
                if (ba[x][y]==-1)
                {
                    w++;
                }

            }
            else if (move=='q')
                disp[x][y]=-3;
            else if (move=='u')
            {
                if (disp[x][y]==-2) disp[x][y]=88;
                if (disp[x][y]==-3)  disp[x][y]=88;
            }
        }
        else if(move=='b')
        {

            system("cls");
            printf("(1) SAVE GAME \n (2) NEW GAME \n(3) EXIT WITHOUT SAVING \n(4) cancel");
            scanf("%d",&ds);
            if(ds==1)

            {
                savegame(ba,disp,r,c);

                return;
            }
            if (ds==2)
                newgame();
            if(ds==3)
                return;
            if (ds==4)
                continue;
        }

        /*  else if (move=='b')
              {
                  printf("(1) SAVE GAME \n (2) NEW GAME (3) EXIT WITHOUT SAVING");
                  if(ds==1)
                      savegame(ba,disp,)

              }

                  }
        */
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if ((disp[i][j]>0)&&(disp[i][j]!=88)&&(disp[i][j]<10))
                    printf("%d   ",disp[i][j]);
                else if((disp[i][j]>0)&&(disp[i][j]!=88)&&(disp[i][j]>9))
                    printf("%d  ",disp[i][j]);
                else if(disp[i][j]==0)
                    printf("    ");
                else if (disp[i][j]==-1)
                {
                    printf("*   ");
                }
                else if (disp[i][j]==-2)
                    printf("f   ");

                else if (disp[x][y]==-3)
                {
                    printf("?   ");
                }
                else if(disp[i][j]==-10)
                    printf("    ");

                else printf("X   ");
                // if((i==(0)&&(j==(c-1))))
                //printf("\t\t%d",w);
            }
            printf("\n");
        }

mo++;
diff =(ended-start)/1000;
int temp;
temp=diff;
int min=0;
while(temp>60)
    {
        temp=temp-60;
        min++;

    }
printf("\n TIME %d:%d",min,temp);

        if(T==1) break;
    }
    int score;
    score= (((r)*(c))/((ended-start)*mo));

    system("cls");

    if (T==1)
        printf("You lose");
    else {printf("you win \n your score is %d your time is %d",score,diff);
    players(score);

    }






}
