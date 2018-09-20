#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include "headers.h"
using namespace std;

int main()
{
    int choice=0, choice1=0, choice11=0,x=0;
    char user_name[20],pswrd[20];
    string  s[] = {"V I S I T I N G   P L A C E S","Visiting Places","R A T E    P L A C E S","Rate Places","A D D    P L A C E S","Add Places","F E E D B A C K","Feedback","H E L P","Help","A B O U T    U S","About us","E X I T","Exit","NULL"};
    string  s1[] = {"G E N E R A L   C A T E G O R Y","General Category","R A T I N G   W I S E","Rating Wise","S E A R C H   Y O U R   D E S I R E","Search Your Desire","C U S T O M I Z E D","Customized","B A C K","Back","H O M E","Home","NULL"};
    string s11[] = {"H I S T O R I C A L","Historical","N A T U R A L","Natural","B E A C H","Beach","A R C H I T E C T U R A L","Architectural","R E L I G I O U S","Religious","R E G I O N A L","Regional","W A T E R F A L L","Waterfall","E C O   T O U R I S M","Eco Tourism","B A C K","Back","H O M E","Home","NULL"};
    string s116[] = { "D H A K A","Dhaka","C H I T T A G O N G","Chittagong","K H U L N A","Khulna","R A J S H A H I","Rajshahi","S Y L H E T","Sylhet","R A N G P U R","Rangpur","M Y M E N S I N G H","Mymensingh","B A R I S A L","Barisal","B A C K","Back","H O M E","Home","NULL" };
    while(x==0)
    {
        printf("\tUSER NAME\t:: ");
        gets(user_name);
        printf("\n\tPASSWORD\t:: ");
        gets(pswrd);
        x = check(user_name,pswrd);
        //system("cls");
        if(x==0) {  system("cls");printf("\tUser name and Password doesn't match\n\n"); }
    }
    input(100);
    while(choice!=7)
    {
        system("cls");
pre:// HOME
        choice = getChoice(s,NULL);
        if(choice==1)      // VISITING PLACES
        {
pre1:
            choice1  = getChoice(s1,NULL);
            if(choice1 ==1)// general category
            {
pre11:
                choice11 = getChoice(s11,NULL);
                if(choice11==1)         print(s11[1],0);//historical
                else if(choice11==2)    print(s11[3],0);
                else if(choice11==3)    print(s11[5],0);
                else if(choice11==4)    print(s11[7],0);
                else if(choice11==5)    print(s11[9],0);
                else if(choice11==6)                        // REGIONAL  c116
                {
                    int choice116 = getChoice(s116,NULL);
                    if(choice116==1)    print(s116[1],1);
                    if(choice116==2)    print(s116[3],1);
                    if(choice116==3)    print(s116[5],1);
                    if(choice116==4)    print(s116[7],1);
                    if(choice116==5)    print(s116[9],1);
                    if(choice116==6)    print(s116[11],1);
                    if(choice116==7)    print(s116[13],1);
                    if(choice116==8)    print(s116[15],1);
                    if(choice116==9)    goto pre11;
                    if(choice116==10)   goto pre;
                }
                else if(choice11==7)    print(s11[13],0);
                else if(choice11==8)    print(s11[15],0);
                else if(choice11==9)    goto pre1;  // back
                else if(choice11==10)   goto pre;   // home
            }


            //   PROBLEMM  PROBLEM  PROBLE  PROBL   PROB    PRO  PR       P
            else if(choice1==2) //rating wise     PROBLEMMMMMMMMMMMM
            {
                string bud[]= {"4 to 5","4 to 5","3 to 4","3 to 4","Below 3","Below 3","NULL"};
                int res=getChoice(bud," ");
                if(res==1)          print("",10);  // 4--5
                else if(res==2)     print("",9);   // 3--4
                else if(res==3)     print("",8);   // <3
                //printf("")
            }

            else if(choice1==3)     srch(100);   // search ur desire


            //   PROBLEMM  PROBLEM  PROBLE  PROBL   PROB    PRO  PR       P
            else if(choice1==4)      //customized     PROBLEMMMMMMMMMMMM
            {
                system("cls");
                string good[]= {"M O S T   V I S I T E D","Most visited","R E C E N T L Y   D I S C O V E R E D","Recently Discovered","R E C O M M E N D E D","Recommended","NULL"};
                int res1=getChoice(good," "); cout<<res1;delay(3);
                if(res1==1)             print("",10);  //
                else if(res1==2)        print("",600); //
                else if(res1==3)        print("",700); //
            }
            else if(choice1==5 || choice1==6)  goto pre;
        }
        else if(choice==2)
        {
            place_rating(x);
        }
        else if(choice==3)          add();  // ADD PLACES
        else if(choice==4)          feed();
        else if(choice==5)          helpp();
        else if(choice==6)          abt_us();

    }
    system("cls");
    printf("\nThanks a lot!!!!!!!!\n\nBe with Us!!!\n");
    return 0;
}
