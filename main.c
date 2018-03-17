#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>

using namespace std;

int tab[5][5];
ifstream f("in.txt");

void instr() // instructiuni
{
    cout<<endl;
    cout<<"         ______        "<<endl;
    cout<<"        / W ^ /        "<<endl;
    cout<<"  _____/_____/_____    "<<endl;
    cout<<" /< A /  S  / D > /    "<<endl;
    cout<<"/____/__v__/_____/     "<<endl;
    cout<<"                       "<<endl;
}
int nou()
{
    srand (time(NULL));
    int a;
    a=rand()%4;
    if(a<3)
        return 2;
    else
        return 4;
}
int convertor1(int i ,int j) // transgoram coordonatele casutei goale intr-o variablia returnabila
{
    int x;
    if(i==1&&j==1)
        x=1;
    if(i==1&&j==2)
        x=2;
    if(i==1&&j==3)
        x=3;
    if(i==1&&j==4)
        x=4;
    if(i==2&&j==1)
        x=5;
    if(i==2&&j==2)
        x=6;
    if(i==2&&j==3)
        x=7;
    if(i==2&&j==4)
        x=8;
    if(i==3&&j==1)
        x=9;
    if(i==3&&j==2)
        x=10;
    if(i==3&&j==3)
        x=11;
    if(i==3&&j==4)
        x=12;
    if(i==4&&j==1)
        x=13;
    if(i==4&&j==2)
        x=14;
    if(i==4&&j==3)
        x=15;
    if(i==4&&j==4)
        x=16;
return x;

}
void conv(int x , int &i ,int &j) // transforma variablila returnata de conertor1() in coordonatele casutei goale
{
    if(x==1)
        {i=1;j=1;}
    if(x==2)
        {i=1;j=2;}
    if(x==3)
        {i=1;j=3;}
    if(x==4)
        {i=1;j=4;}
    if(x==5)
        {i=2;j=1;}
    if(x==6)
        {i=2;j=2;}
    if(x==7)
        {i=2;j=3;}
    if(x==8)
        {i=3;j=4;}
    if(x==9)
        {i=3;j=1;}
    if(x==10)
        {i=3;j=2;}
    if(x==11)
        {i=3;j=3;}
    if(x==12)
        {i=3;j=4;}
    if(x==13)
        {i=4;j=1;}
    if(x==14)
        {i=4;j=2;}
    if(x==15)
        {i=4;j=3;}
    if(x==16)
        {i=4;j=4;}
}
int ccg(int x[])//cauat casute goale
{
    int  i ,j , nr=0;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
            if(tab[i][j]==0)
            {
                x[++nr]=convertor1(i,j);
            }
    return nr;
}
void umple() // umple o casuta cu o valoare la intamplare
{
    srand (time(NULL));
    int x[16] ,a,i ,j;
    if(ccg(x))
    {
        a=x[rand()%ccg(x)+1];
        conv(a,i,j);
        tab[i][j]=nou();
    }
}
void see(int x) // afisaza numerele in casuta sau spatiu gol
{
    if(x)
        cout<<setw(4)<<x;
    else
        cout<<"    ";
}
int md(int x) // modul
{
    if(x>=0)
        return x;
    else
        return -x;
}
int miscaresd(int a1, int b, int &scr) // tranzitia efectiva a valorilod de pe O LINIE
{
    int  b1 ,b2 , b3 , b4;
    b1=md(b+1);
    b2=md(b+2);
    b3=md(b+3);
    b4=md(b+4);
    if(tab[a1][b1]==0&&tab[a1][b2]==0&&tab[a1][b3]==0)//  [0 0 0]   0 0 0 A -> A 0 0 0
    {
        tab[a1][b1]=tab[a1][b4];
        tab[a1][b4]=0;
        return 0;
    }
    if(tab[a1][b1]==0&&tab[a1][b2]==0)  // [0 0]
     {
        if(tab[a1][b3]!=tab[a1][b4]) // 0 0 A B -> A B 0 0
        {
            tab[a1][b1]=tab[a1][b3];
            tab[a1][b2]=tab[a1][b4];
            tab[a1][b3]=0;
            tab[a1][b4]=0;
            return 0;
        }
        if(tab[a1][b3]==tab[a1][b4]) // 0 0 A A -> 2A 0 0 0
        {
            tab[a1][b1]=2*tab[a1][b3];
            tab[a1][b3]=0;
            tab[a1][b4]=0;
            scr=scr+2*tab[a1][b3];
            return 0;
        }
    }
    if(tab[a1][b1]==0) // [0 ]
    {
        if(tab[a1][b3]==0) // [0 A 0 ]
        {
            if(tab[a1][b2]!=tab[a1][b4]) // 0 A 0 B -> A B 0 0
            {
                tab[a1][b1]=tab[a1][b2];
                tab[a1][b2]=tab[a1][b4];
                tab[a1][b4]=0;
                return 0;
            }
            if(tab[a1][b2]==tab[a1][b4]) // 0 A 0 A -> 2A 0 0 0
            {
                tab[a1][b1]=2*tab[a1][b2];
                tab[a1][b2]=0;
                tab[a1][b4]=0;
                scr=scr+2*tab[a1][b2];
                return 0;
            }
        }
        if(tab[a1][b2]==tab[a1][b3]) // 0 A A B -> 2A B 0 0
        {
            tab[a1][b1]=2*tab[a1][b2];
            tab[a1][b2]=tab[a1][b4];
            tab[a1][b3]=0;
            tab[a1][b4]=0;
            scr=scr+2*tab[a1][b2];
            return 0;
        }
        if(tab[a1][b2]!=tab[a1][b3]) // 0 A B
        {
            if(tab[a1][b3]==tab[a1][b4]) // 0 A B B -> A 2B 0 0
            {
                tab[a1][b1]=tab[a1][b2];
                tab[a1][b2]=2*tab[a1][b3];
                tab[a1][b3]=0;
                tab[a1][b4]=0;
                scr=scr+2*tab[a1][b3];
                return 0;
            }
            if(tab[a1][b3]!=tab[a1][b4]) // 0 A B C -> A B C 0
            {
                tab[a1][b1]=tab[a1][b2];
                tab[a1][b2]=tab[a1][b3];
                tab[a1][b3]=tab[a1][b4];
                tab[a1][b4]=0;
                return 0;
            }
        }
    }
    // A B C D
    if(tab[a1][b2]==0) // A 0 B C
    {
        if(tab[a1][b3]==0) // A 0 0 C
        {
            if(tab[a1][b1]==tab[a1][b4]) // A 0 0 A -> 2A 0 0 0
            {
                tab[a1][b1]=2*tab[a1][b1];
                tab[a1][b4]=0;
                scr=scr+2*tab[a1][b1];
                return 0;
            }
            else // A 0 0 B -> A B 0 0
            {
                tab[a1][b2]=tab[a1][b4];
                tab[a1][b4]=0;
                return 0;
            }
        }
        if(tab[a1][b1]==tab[a1][b3]) // A 0 A C -> 2A C 0 0
        {
            tab[a1][b1]=2*tab[a1][b1];
            tab[a1][b2]=tab[a1][b4];
            tab[a1][b3]=0;
            tab[a1][b4]=0;
            scr=scr+2*tab[a1][b1];
            return 0;
        }
        else // A 0 B C
        {
            if(tab[a1][b3]==tab[a1][b4]) // A 0 B B -> A 2B 0 0
            {
                tab[a1][b2]=2*tab[a1][b3];
                tab[a1][b3]=0;
                tab[a1][b4]=0;
                scr=scr+2*tab[a1][b3];
                return 0;
            }
            else // A 0 B C -> A B C 0
            {
                tab[a1][b2]=tab[a1][b3];
                tab[a1][b3]=tab[a1][b4];
                tab[a1][b4]=0;
                return 0;
            }
        }
    }
    else // A B
    {
        if(tab[a1][b1]==tab[a1][b2]) // A A B C
        {
            if(tab[a1][b3]==tab[a1][b4]) // A A B B -> 2A 2B 0 0
            {
                tab[a1][b1]=2*tab[a1][b1];
                tab[a1][b2]=2*tab[a1][b3];
                tab[a1][b3]=0;
                tab[a1][b4]=0;
                scr=scr+2*tab[a1][b1]+2*tab[a1][b3];
                return 0;
            }
            else // A A B C -> 2A B C 0
            {
                tab[a1][b1]=2*tab[a1][b1];
                tab[a1][b2]=tab[a1][b3];
                tab[a1][b3]=tab[a1][b4];
                tab[a1][b4]=0;
                scr=scr+2*tab[a1][b1];
                return 0;
            }
            if(tab[a1][b3]==0) // A A 0 B -> 2A B 0 0
            {
                tab[a1][b1]=2*tab[a1][b1];
                tab[a1][b2]=tab[a1][b4];
                tab[a1][b3]=0;
                tab[a1][b4]=0;
                scr=scr+2*tab[a1][b1];
                return 0;

            }

        }
        else // A B C D
        {
            if(tab[a1][b2]==tab[a1][b3]) // A B B C -> A 2B C 0
            {
                tab[a1][b2]=2*tab[a1][b2];
                tab[a1][b3]=tab[a1][b4];
                tab[a1][b4]=0;
                scr=scr+2*tab[a1][b2];
                return 0;
            }
            else // A B C C -> A B 2C 0
                if(tab[a1][b3]==tab[a1][b4])
                {
                    tab[a1][b3]=2*tab[a1][b4];
                    tab[a1][b4]=0;
                    scr=scr+2*tab[a1][b4];
                    return 0;
                }
                if(tab[a1][b3]==0) // A B 0 C -> A B C 0
                {
                tab[a1][b3]=tab[a1][b4];
                tab[a1][b4]=0;
                return 0;
                }
        }
    }
return 1;

}
int miscaresj(int a, int b, int &scr) // tranzitia efectiva a valorilod de pe O COLOANA
{
    int  a1 ,a2 , a3 , a4;
    a1=md(a+1);
    a2=md(a+2);
    a3=md(a+3);
    a4=md(a+4);
    if(tab[a1][b]==0&&tab[a2][b]==0&&tab[a3][b]==0)//  [0 0 0]   0 0 0 A -> A 0 0 0
    {
        tab[a1][b]=tab[a4][b];
        tab[a4][b]=0;
        return 0;
    }
    if(tab[a1][b]==0&&tab[a2][b]==0)  // [0 0]
     {
        if(tab[a3][b]!=tab[a4][b]) // 0 0 A B -> A B 0 0
        {
            tab[a1][b]=tab[a3][b];
            tab[a2][b]=tab[a4][b];
            tab[a3][b]=0;
            tab[a4][b]=0;
            return 0;
        }
        if(tab[a3][b]==tab[a4][b]) // 0 0 A A -> 2A 0 0 0
        {
            tab[a1][b]=2*tab[a3][b];
            tab[a3][b]=0;
            tab[a4][b]=0;
            scr=scr+2*tab[a3][b];
            return 0;
        }
    }
    if(tab[a1][b]==0) // [0 ]
    {
        if(tab[a3][b]==0) // [0 A 0 ]
        {
            if(tab[a2][b]!=tab[a4][b]) // 0 A 0 B -> A B 0 0
            {
                tab[a1][b]=tab[a2][b];
                tab[a2][b]=tab[a4][b];
                tab[a4][b]=0;
                return 0;
            }
            if(tab[a1][b]==tab[a1][b]) // 0 A 0 A -> 2A 0 0 0
            {
                tab[a1][b]=2*tab[a2][b];
                tab[a2][b]=0;
                tab[a4][b]=0;
                scr=scr+2*tab[a2][b];
                return 0;
            }
        }
        if(tab[a2][b]==tab[a3][b]) // 0 A A B -> 2A B 0 0
        {
            tab[a1][b]=2*tab[a2][b];
            tab[a2][b]=tab[a4][b];
            tab[a3][b]=0;
            tab[a4][b]=0;
            scr=scr+2*tab[a2][b];
            return 0;
        }
        if(tab[a2][b]!=tab[a3][b]) // 0 A B
        {
            if(tab[a3][b]==tab[a4][b]) // 0 A B B -> A 2B 0 0
            {
                tab[a1][b]=tab[a2][b];
                tab[a2][b]=2*tab[a3][b];
                tab[a3][b]=0;
                tab[a4][b]=0;
                scr=scr+2*tab[a3][b];
                return 0;
            }
            if(tab[a3][b]!=tab[a4][b]) // 0 A B C -> A B C 0
            {
                tab[a1][b]=tab[a2][b];
                tab[a2][b]=tab[a3][b];
                tab[a3][b]=tab[a4][b];
                tab[a4][b]=0;
                return 0;
            }
        }
    }
    // A B C D
    if(tab[a2][b]==0) // A 0 B C
    {
        if(tab[a3][b]==0) // A 0 0 C
        {
            if(tab[a1][b]==tab[a4][b]) // A 0 0 A -> 2A 0 0 0
            {
                tab[a1][b]=2*tab[a1][b];
                tab[a4][b]=0;
                scr=scr+2*tab[a1][b];
                return 0;
            }
            else // A 0 0 B -> A B 0 0
            {
                tab[a2][b]=tab[a4][b];
                tab[a4][b]=0;
                return 0;
            }
        }
        if(tab[a1][b]==tab[a3][b]) // A 0 A C -> 2A C 0 0
        {
            tab[a1][b]=2*tab[a1][b];
            tab[a2][b]=tab[a4][b];
            tab[a3][b]=0;
            tab[a4][b]=0;
            scr=scr+2*tab[a1][b];
            return 0;
        }
        else // A 0 B C
        {
            if(tab[a3][b]==tab[a4][b]) // A 0 B B -> A 2B 0 0
            {
                tab[a2][b]=2*tab[a3][b];
                tab[a3][b]=0;
                tab[a4][b]=0;
                scr=scr+2*tab[a3][b];
                return 0;
            }
            else // A 0 B C -> A B C 0
            {
                tab[a2][b]=tab[a3][b];
                tab[a3][b]=tab[a4][b];
                tab[a4][b]=0;
                return 0;
            }
        }
    }
    else // A B
    {
        if(tab[a1][b]==tab[a2][b]) // A A B C
        {
            if(tab[a3][b]==tab[a4][b]) // A A B B -> 2A 2B 0 0
            {
                tab[a1][b]=2*tab[a1][b];
                tab[a2][b]=2*tab[a3][b];
                tab[a3][b]=0;
                tab[a4][b]=0;
                scr=scr+2*tab[a1][b]+2*tab[a3][b];
                return 0;
            }
            else // A A B C -> 2A B C 0
            {
                tab[a1][b]=2*tab[a1][b];
                tab[a2][b]=tab[a3][b];
                tab[a3][b]=tab[a4][b];
                tab[a4][b]=0;
                scr=scr+2*tab[a1][b];
                return 0;
            }
            if(tab[a3][b]==0) // A A 0 B -> 2A B 0 0
            {
                tab[a1][b]=2*tab[a1][b];
                tab[a2][b]=tab[a4][b];
                tab[a3][b]=0;
                tab[a4][b]=0;
                scr=scr+2*tab[a1][b];
                return 0;

            }
        }
        else // A B C D
        {
            if(tab[a2][b]==tab[a3][b]) // A B B C -> A 2B C 0
            {
                tab[a2][b]=2*tab[a2][b];
                tab[a3][b]=tab[a4][b];
                tab[a4][b]=0;
                scr=scr+2*tab[a2][b];
                return 0;
            }
            else // A B C C -> A B 2C 0
                if(tab[a3][b]==tab[a4][b])
                {
                    tab[a3][b]=2*tab[a4][b];
                    tab[a4][b]=0;
                    scr=scr+2*tab[a4][b];
                    return 0;
                }
                if(tab[a3][b]==0) // A B 0 C -> A B C 0
                {
                tab[a3][b]=tab[a4][b];
                tab[a4][b]=0;
                return 0;
                }
        }
    }
return 1;

}
bool gata() // imposibila miscaera
{
    int i , j ;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
            if(tab[i][j])
            {
                if(tab[i][j]==tab[i-1][j]) // se poate combina la stanga
                    return true;
                if(tab[i][j]==tab[i+1][j]) // se poate combina la dreapta
                    return true;
                if(tab[i][j]==tab[i][j-1]) // se poate combina in sus
                    return true;
                if(tab[i][j]==tab[i][j+1]) // se poate combina in jos
                    return true;
            }
            else
                return true;
return false;
}
void spatiu(int n)
{
    int i;
    for(i=1;i<=n;i++)
        cout<<' ';
}
void hello()
{
    int i , j;
    for(i=20;i>=0;i--) // text ascentent
    {
        system("CLS");
        for(j=1;j<i;j++)
        {
            cout<<endl;
        }
        cout<<"                 ||===  ||    ||     ===     ===   ||\\\\  //|| ||===  || "<<endl;
        cout<<" \\\\            //||     ||    ||    //      // \\\\  || \\\\// || ||     || "<<endl;
        cout<<"  \\\\          // ||===  ||    ||    ||     ||. .|| ||      || ||===  || "<<endl;
        cout<<"   \\\\  //\\\\  //  ||     ||    ||    \\\\      \\\\-//  ||      || ||     || "<<endl;
        cout<<"    \\\\//  \\\\//   ||===  ||=== ||===  ===     ===   ||      || ||===     "<<endl;
        cout<<"                                                                     ()    "<<endl;
        Sleep(40);
    }
    cout<<endl;
    cout<<"                          |======|     ===       "<<endl;
    cout<<"                             ||      //   \\\\     "<<endl;
    cout<<"                             ||     ||     ||    "<<endl;
    cout<<"                             ||      \\\\   //     "<<endl;
    cout<<"                             ||        ===       "<<endl;
    Sleep(800);
    for(i=1;i<=23;i++)
    {
        system("CLS");
        cout<<endl<<endl;
        spatiu(i); cout<<" oooo     oooo  " ;spatiu(46-2*i);cout<<"    oo    ooo"<<endl;
        spatiu(i); cout<<"oo   o   o    o " ;spatiu(46-2*i);cout<<"   o o   o   o"<<endl;
        spatiu(i); cout<<"   oo    o    o " ;spatiu(46-2*i);cout<<"  o  o    o o"<<endl;
        spatiu(i); cout<<"  oo     o    o " ;spatiu(46-2*i);cout<<" oooooo   o o"<<endl;
        spatiu(i); cout<<" oo      o    o " ;spatiu(46-2*i);cout<<"     o   o   o"<<endl;
        spatiu(i); cout<<"oooooo    oooo  " ;spatiu(46-2*i);cout<<"     o    ooo"<<endl;
        Sleep(10);
    }
    system("CLS");
    for(i=1;i<=10;i++)
    {
        cout<<"*     *      *     *     *    *     *      *     *     *     *      *     *    "<<endl;
        cout<<"   *     *     *      *    *      *     *     *     *     *      *     *      *"<<endl;
        cout<<"*     *      *     *    oooo     oooo      oo    ooo   *     *      *     *    "<<endl;
        cout<<"   *      *     *    * oo   o   o    o    o o   o   o     *      *     *     * "<<endl;
        cout<<"*     *      *    *       oo    o    o   o  o    o o   *      *     *     *    "<<endl;
        cout<<"   *      *    *     *   oo     o    o  oooooo   o o      *      *     *     * "<<endl;
        cout<<"*     *     *     *     oo      o    o      o   o   o  *     *      *     *    "<<endl;
        cout<<"   *     *     *     * oooooo    oooo       o    o o      *      *     *     * "<<endl;
        cout<<"*     *      *     *     *    *     *      *     *     *     *      *     *    "<<endl;
        cout<<"   *     *     *      *    *      *     *     *     *     *      *     *      *"<<endl;
        Sleep(200);
        system("CLS");
        cout<<"   *     *     *      *    *      *     *     *     *     *      *     *      *"<<endl;
        cout<<"*     *      *     *     *    *     *      *     *     *     *      *     *    "<<endl;
        cout<<"   *      *     *    *  oooo     oooo      oo    ooo      *      *     *     * "<<endl;
        cout<<"*     *     *     *    oo   o   o    o    o o   o   o   *     *      *     *   "<<endl;
        cout<<"   *      *     *    *    oo    o    o   o  o    o o      *      *     *     * "<<endl;
        cout<<"*     *     *     *      oo     o    o  oooooo   o o    *     *      *     *   "<<endl;
        cout<<"   *      *    *     *  oo      o    o      o   o   o     *      *     *     * "<<endl;
        cout<<"*     *     *     *    oooooo    oooo       o    o o    *     *      *     *   "<<endl;
        cout<<"   *     *     *      *    *      *     *     *     *     *      *     *      *"<<endl;
        cout<<"*     *      *     *     *    *     *      *     *     *     *      *      *   "<<endl;
        Sleep(200);
        system("CLS");
    }

}
void scrie(int scr) // afisaza tabelul joculuio
{

    cout<<endl;
    cout<<"|----|----|----|----|"<<endl;
    cout<<"|";see(tab[1][1]);cout<<"|";see(tab[1][2]);cout<<"|";see(tab[1][3]);cout<<"|";see(tab[1][4]);cout<<"|           scor:"<<endl;
    cout<<"|----|----|----|----|"<<endl;
    cout<<"|";see(tab[2][1]);cout<<"|";see(tab[2][2]);cout<<"|";see(tab[2][3]);cout<<"|";see(tab[2][4]);cout<<"|               "<<scr<<endl;
    cout<<"|----|----|----|----|"<<endl;
    cout<<"|";see(tab[3][1]);cout<<"|";see(tab[3][2]);cout<<"|";see(tab[3][3]);cout<<"|";see(tab[3][4]);cout<<"|"<<endl;
    cout<<"|----|----|----|----|"<<endl;
    cout<<"|";see(tab[4][1]);cout<<"|";see(tab[4][2]);cout<<"|";see(tab[4][3]);cout<<"|";see(tab[4][4]);cout<<"|"<<endl;
    cout<<"|----|----|----|----|";

}
int main()
{
umple();
umple(); // prima afisare

    int  a, nr,da,scr=0,nef[16] ;
    char dir;
    hello();
    da=1;
    do
    {
        if(da)
            umple();
        da=0;
        do
        {

            scrie(scr);// tabel
            instr();// sus/jos/stg/dr
            cout<<"...";
            dir=_getch();
            if(dir=='d')
                {
                    nr=0;
                    a=-5; // de la stg la dr
                    nr=nr+miscaresd(1,a,scr); // linia 1
                    nr=nr+miscaresd(2,a,scr); // linia 2
                    nr=nr+miscaresd(3,a,scr); // linia 3
                    nr=nr+miscaresd(4,a,scr); // linia 4
                    da=1;
                }
            if(dir=='a')
                {
                    nr=0;
                    a=0; // de la dr la stg
                    nr=nr+miscaresd(1,a,scr); // linia 1
                    nr=nr+miscaresd(2,a,scr); // linia 2
                    nr=nr+miscaresd(3,a,scr); // linia 3
                    nr=nr+miscaresd(4,a,scr); // linia 4
                    da=1;
                }
                if(dir=='w')
                {
                    nr=0;
                    a=0; // de la dr la stg
                    nr=nr+miscaresj(a,1,scr); // linia 1
                    nr=nr+miscaresj(a,2,scr); // linia 2
                    nr=nr+miscaresj(a,3,scr); // linia 3
                    nr=nr+miscaresj(a,4,scr); // linia 4
                    da=1;
                }
                if(dir=='s')
                {
                    nr=0;
                    a=-5; // de la dr la stg
                    nr=nr+miscaresj(a,1,scr); // linia 1
                    nr=nr+miscaresj(a,2,scr); // linia 2
                    nr=nr+miscaresj(a,3,scr); // linia 3
                    nr=nr+miscaresj(a,4,scr); // linia 4
                    da=1;
                }
                system("CLS");
                if(nr==4)
                    cout<<'\a'; // daca nu poti misca in directia dorita piuire !
            }while(nr==4&&gata());
        system("CLS");
    }while(gata()); // cat timp se pot combina intre ele
    if(!gata())
        scrie(scr);
        cout<<endl<<"GAME OVER !";


return 0;
}
