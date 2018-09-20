#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "headers.h"
struct place p1;
struct place p[20];

int getChoice(char str[][40])
{
    int choice=1;
    char ch=10;
    while(ch!=13)
    {
        int cnt=0, pos=0;

        system("cls");
        printf("\t\t\t     _  _  _  ___      _   _  _    \n");
        printf("\t\t\t    |_ |_ |_|  |  | | |_| |_ |_    \n");
        printf("\t\t\t    |  |_ | |  |  |_| | \\ |_  _|  \n\n\n");

        while(strcmp(str[pos],"NULL"))
        {
            if(choice==cnt+1)       printf("\n\t\t\t    --> %s\n\t",str[pos]);
            else                    printf("\n\t\t\t\t%s\n",str[pos+1]);
            cnt++;
            pos+=2;
        }

        ch = getch();
        if(ch == 72)                choice--;
        else if(ch == 80)           choice++;
        if(choice<1)                choice=cnt;
        else if(choice>cnt)         choice=1;
    }
    return choice;
};

void add()
{
    system("cls");

    printf("\n\tName of the place : ");
    gets(p1.name);

    printf("\n\tZilla : ");
    gets(p1.zilla);

    printf("\n\tDivision : ");
    gets(p1.div);

    printf("\n\tCategory(such as Natural, Historical or Architectural etc) : ");
    gets(p1.category);

    printf("\n\tRate the place(on the scale of 5.0) : ");
    scanf("%f",&p1.rate);
    getchar();

    printf("\n\tWrite details about the place :\n\t\t");
    gets(p1.detail);

    FILE *fp;
    fp=fopen("Users Contribution.txt","a");

    fprintf(fp,"%s\n%s\n%s\n%s\n%f\n%s\n\n",p1.name,p1.zilla,p1.div,p1.category,p1.rate,p1.detail);

    fclose(fp);
    printf("\n\n\t\t\tThanks\n\t\t\tfor\n\t\t\tyour\n\t\t\tValuable\n\t\t\tContribution!!!!\n");
    delay(5);
}

void delay(double sec)
{
    clock_t start,current;

    start = clock();
    current = clock();

    while((double)(current-start)/CLOCKS_PER_SEC < sec)     current = clock();
}
void include()
{
    system("cls");
    char x;
    int i=0;
    FILE *fp;
    fp=fopen("Visiting Places.txt","r");
    while(feof(fp)==NULL)
    {
        fscanf(fp,"%[^'\n']s",&p[i].name);
        x=getc(fp);
        //x=getc(fp);
        fscanf(fp,"%[^'\n']s",&p[i].zilla);
        x=getc(fp);
        //x=getc(fp);
        fscanf(fp,"%[^'\n']s",&p[i].div);
        x=getc(fp);
        //x=getc(fp);
        fscanf(fp,"%[^'\n']s",&p[i].category);
        x=getc(fp);
        //x=getc(fp);
        fscanf(fp,"%[^'\n']s",&p[i].detail);
        x=getc(fp);
        //x=getc(fp);
        fscanf(fp,"%[^'\n']s",&p[i].web);
        x=getc(fp);
        //x=getc(fp);
        fscanf(fp,"%f",&p[i].rate);
        x=getc(fp);
        x=getc(fp);

        printf("%s\n%s\n%s\n%s\n%s\n%s\n%f\n\n",p[i].name,p[i].zilla,p[i].div,p[i].category,p[i].detail,p[i].web,p[i].rate);
        i++;
    }
    delay(100);
    fclose(fp);

}
