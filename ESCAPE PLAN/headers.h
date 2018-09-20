#include<bits/stdc++.h>
using namespace std;
#ifndef __HEADERS_HEADER
#define __HEADERS_HEADER

struct place
{
    string name;
    string zilla;
    string div;
    string category;
    float  rate;
    string detail;
    string image;

};


struct id{
    char u_nm[100];
    char pss[100];
};

int getChoice(string str[],char temp[]);//

void add();//

int input(int call);//

int check(char str[], char pswrd[]);//

void delay(double sec);//

int print(string s,int fish);// to be

int  f_print(int k);

int srch(int boss);

void place_rating(int x);

void feed();

void helpp();

void abt_us();

#endif
