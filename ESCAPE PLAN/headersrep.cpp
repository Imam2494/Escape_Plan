#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include "headers.h"
using namespace std;



vector<place> vec;

vector<place> vec3[0];

char us1[]="aa",us2[]="bb",us3[]="cc",pss1[]="aa",pss2[]="bb",pss3[]="cc";




int check(char str[], char pswrd[])
{
    if(strcmp(str,us1)==0 && strcmp(pswrd,pss1)==0)             return 1;
    else if(strcmp(str,us2)==0 && strcmp(pswrd,pss2)==0)        return 2;
    else if(strcmp(str,us3)==0 && strcmp(pswrd,pss3)==0)        return 3;
    else                                                        return 0;

}

int getChoice(string str[],char temp[])
{
    int choice=1;
    char ch=10;
    while(ch!=13)
    {
        int cnt=0, pos=0;

        system("cls");
        if(temp==NULL)
        {
            printf("\t\t\t     _  _  _  ___      _   _  _    \n");
            printf("\t\t\t    |_ |_ |_|  |  | | |_| |_ |_    \n");
            printf("\t\t\t    |  |_ | |  |  |_| | \\ |_  _|  \n\n\n");
        }
        else { cout<<temp<<"\n\n";  }   //   recently modofied

        while(str[pos]!="NULL")
        {
            if(choice==cnt+1)       cout<<"\n\t\t\t    --> "<<str[pos]<<"\n\t";
            else                    cout<<"\n\t\t\t\t"<<str[pos+1]<<"\n";
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
}
int input(int call)
{
    ifstream file;      // opening in reading mode

    if(call==100)       file.open("Visiting Places.txt");
    else if(call==1)    file.open("User1.txt");
    else if(call==2)    file.open("User2.txt");
    else if(call==3)    file.open("User3.txt");


    while(1)
    {
        place A;                    // declaring a structure(temporary)_
        getline(file,A.name);

        if((A.name).size()==0)  break;

        getline(file,A.zilla);

        getline(file,A.div);

        getline(file,A.category);

        file >> A.rate;

        string str;
        getline(file,str);          // For the new line

        getline(file,A.detail);

        getline(file,A.image);

        if(call==100)       vec.push_back(A);
        else if(call==1)    vec3[0].push_back(A);
        else if(call==2)    vec3[1].push_back(A);
        else if(call==3)    vec3[2].push_back(A);
        getline(file,str);          // For the new line again!
    }
    file.close();
}

int print(string s,int fish)
{
    int uniq,i,a[1000];
    int cnt=0,f=0;
    string lol;
    string wok[200];
    for(i = 0; i<vec.size() ; i++)
    {
        if(fish==0)     lol=vec[i].category;
        else if(fish==10)
        {
            if(vec[i].rate>=4)  {
                //lol=vec[i].name;
                wok[cnt++]=vec[i].name;
                wok[cnt++]=vec[i].name;
                a[f++]=i; continue;
            }
        }
        else if(fish==9)
        {
            if(vec[i].rate<4 && vec[i].rate>=3) {
                    //lol=vec[i].rate;
                wok[cnt++]=vec[i].name;
                wok[cnt++]=vec[i].name;
                a[f++]=i; continue;
            }
        }
        else if(fish==8)
        {
            if(vec[i].rate<3)
            {
                //lol=vec[i].rate;
                wok[cnt++]=vec[i].name;
                wok[cnt++]=vec[i].name;
                a[f++]=i; continue;
            }
        }
        else if(fish==1) {
            lol = vec[i].div;
        }

        if(s==lol)
        {
            wok[cnt++]=vec[i].name;
            wok[cnt++]=vec[i].name;
            a[f++]=i;
        }


    }

    wok[cnt]="NULL";
    int choice=getChoice(wok,"");
    f_print(a[choice-1]);
    return (-100);
}
int f_print(int k)
{
    system("cls");
    int i=0;
    cout<<vec[k].name<<"\n";
    cout<<vec[k].zilla<<"\n";
    cout<<vec[k].div<<"\n";
    cout<<vec[k].category<<"\n";
    cout<<vec[k].detail<<"\n";
    cout<<vec[k].image<<"\n\n";
    cout<<"\n\n\n\tdo u wish to view image?(y/n)  \n";
    char ch;
    ch = getch();
    if(ch=='y')
    {
        if(vec[k].name=="JAFLONG") system("JAFLONG.jpg");
        if(vec[k].name=="COX'S BAZAR SEA BEACH") system("COX.jpg");
        if(vec[k].name=="INANI BEACH") system("INANI.jpg");
        if(vec[k].name=="KUAKATA") system("KUAKATA.jpg");
        if(vec[k].name=="PATENGA") system("PATENGA.jpg");
        if(vec[k].name=="SITAKUNDA") system("SITAKUNDA.jpg");
        if(vec[k].name=="Lalbagh Fort") system("Lalbagh.jpg");
        if(vec[k].name=="Ahsan Manzil") system("Ahsan.jpg");
        if(vec[k].name=="Mainamati") system("Mainamati.jpg");
        if(vec[k].name=="St. Martin's Island") system("St.jpg");
        if(vec[k].name=="Bichanakandi") system("Bichanakandi.jpg");
        if(vec[k].name=="Parliament building") system("Parliament.jpg");
        if(vec[k].name=="Shat Gombuj Masjid") system("Shat.jpg");
        if(vec[k].name=="Baitul Mukarram") system("Baitul.jpg");
        if(vec[k].name=="Shahjalal Mazar") system("Shahjalal.jpg");
        if(vec[k].name=="Sundarbans") system("Sundarbans.jpg");
        if(vec[k].name=="Lawachara Rain Forest") system("Lawachara.jpg");
        if(vec[k].name=="Madhabkunda Waterfall") system("Madhabkunda.jpg");
        if(vec[k].name=="Jadipai Waterfall") system("Jadipai.jpg");
        if(vec[k].name=="Mohasthangar") system("Mohasthangar.jpg");
        if(vec[k].name=="Ramshagor Dighi") system("Ramshagor.jpg");
        if(vec[k].name=="Garo Hills") system("Garo.jpg");
        if(vec[k].name=="Hum Hum Waterfall") system("Hum.jpg");
    }

}

int srch(int boss)
{
    system("cls");
    int i;
    string str[3];
    cout<<"\t\tPLEASE ENTER YOUR DESIRE\n\n";
    getline(cin,str[0]);
    int flg=0;
    for( i=0; i<vec.size(); i++)
    {
        if(vec[i].name == str[0])
        {
            str[1]=str[0];
            str[2]="NULL";
            flg=1;
            if(boss==1|| boss==2|| boss==3)   return i;
            break;
        }
    }
    if(flg==1)
    {
        int choice = getChoice(str,"");
        if(choice==1)   f_print(i);
    }
    else if(flg==0)      cout<<"\n\n\t\tInvalid Name\n\n";
    delay(3);
    return -99;
}

void place_rating(int x)
{
    system("cls");
    while(1)
    {
        int y = srch(x);
        if(y>=0)
        {
            input(x);
            input(100);
            int flg=0;
            for(int i=0; i<vec.size(); i++)
            {   flg=0;
                for(int j=0; j<vec3[x-1].size(); j++)
                {
                    //if(vec3[j].name==vec[i].name)
                    {
                        cout<<"\n\n\t\tYOU HAVE ALREADY RATED THIS PLACE \n";
                        flg=1; delay(3);
                        break;
                    }
                }
                if(flg) break;
            }
            if(flg) break;
            if(!flg)
            {
                string str[]= {"1","1","2","2","3","3","4","4","5","5","NULL"};
                int choice = getChoice(str,"");
                ofstream file;
                if(x==1)            file.open("User1.txt",ios_base::app);
                else if(x==2)       file.open("User2.txt",ios_base::app);
                else if(x==3)       file.open("User3.txt",ios_base::app);


                file <<     vec[y].name     << endl;
                file <<     vec[y].zilla    << endl;
                file <<     vec[y].div      << endl;
                file <<     vec[y].category << endl;
                file <<     choice     << endl;
                file <<     vec[y].detail   << endl;
                file <<     vec[y].image    << endl;
                file <<                        endl;
                cout<<"THANKS FOR YOUR RATING\n\n"; delay(3);
                break;
            }
        }
        else { break; }
    }
}


void add()    //    PROBLEMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
{
    system("cls");
    place A;                    // declaring a structure(temporary)_
    cout<<"\t\t ENTER NAME :: ";
    getline(cin,A.name);

    //if((A.name).size()==0)  break;
    cout<<"\t\t ENTER ZILLA :: ";
    getline(cin,A.zilla);
    cout<<"\t\t ENTER DIV :: ";
    getline(cin,A.div);
    cout<<"\t\t ENTER CATEGORY :: ";
    getline(cin,A.category);
    cout<<"\t\t RATE THE PLACE(in a scale of 5) :: ";
    string str[]= {"1","1","2","2","3","3","4","4","5","5","NULL"};
    int choice = getChoice(str,"RATE THE PLACE\n");    ///////      FROM  HERE
    A.rate=choice;
    system("cls");
    string str1;
    //getline(cin,str1);          // For the new line
    cout<<"\t\t ENTER DESCRIPTION  ::  ";
    getline(cin,A.detail);

    //getline(file,A.image);

    vec.push_back(A);

    //getline(cin,str1);

    ofstream file;   // writing &append mode
    file.open("User's Contribution.txt",ios_base::app);
    // For the new line agai
    file <<     A.name     << endl;
    file <<     A.zilla    << endl;
    file <<     A.div      << endl;
    file <<     A.category << endl;
    file <<     A.rate     << endl;
    file <<     A.detail   << endl;
    //file <<     vec[0].image    << endl;
    file <<                        endl;
    file.close();
    system("cls");
    cout<<"\n\n\n\n\n\t\t  THANKS FOR PROVIDING YOUR VALUABLE RESOURCE.\n";
    cout<<"\t\t  HOPE YOUR FULL SUPPORT..\n";
    cout<<"\t\t  THANK YOU...   \n";
    delay(3);
}



void delay(double sec)
{
    clock_t start,current;

    start = clock();
    current = clock();

    while((double)(current-start)/CLOCKS_PER_SEC < sec)     current = clock();
}
void feed()
{
    system("cls");
    cout<<"\t\tWe would be greatly benefitted if u would provide us some feedback.\n\n";
    ofstream file;
    file.open("feed.txt",ios_base::app);
    string str;
    getline(cin,str);
    file<<str<<endl;
    file.close();
}

void helpp()
{
    system("cls");
    cout<<"\t\tSome FAQ :: \n\n";
    cout<<"\t\tQ*  how to recover your password \n";
    cout<<"\t\tA*  .......(under construction)";
    delay(3);
}

void abt_us()
{
    system("cls");
    cout<<"\t\tTHIS PROJECT WAS MADE BY - \n\n";
    cout<<"\t\t\t*NAIMUR RAHMAN HEMAL(154408)\n";
    cout<<"\t\t\t**IMAM MOSHARAF(154402)\n\n\n";
    cout<<"\t\tSPECIAL THANKS TO - \n";
    cout<<"\t\t\t*FAHIM SHAHRIAR SHAKKHOR(154440)\n";
    cout<<"\t\t\t*SHAHED AHMED(1544..)\n\n\n";
    delay(3);
}
