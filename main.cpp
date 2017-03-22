#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <ctime>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;


template <typename T>
string NumberToString(T pNumber)
{
 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

int a[3][3] = { 0 }; // Game Track
int y = 1; // My car's location
bool GameGoing = true;
bool CreateCarOnNext = false;
int best;
int current;

void DrawRoad(){
    setcolor(BLACK);
    setlinestyle(1,0,10);
    rectangle(5, 10, 635, 155);
    rectangle(5, 155 + 5, 635, 155 + 5 + 145);
    rectangle(5, 155 + 5 + 145 + 5, 635, 155 + 5 + 145 + 155);
    setcolor(RED);
    rectangle(10, 10, 630, 20);
    rectangle(10, 450, 630, 460);
}

void DrawCars(){
    if (GameGoing){
        bar(0,0,640,480);

        for(int i = 0 ; i < 3 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++)
            {
                if (a[i][j] != 0)
                {
                    int y = (i * 140) + 40;
                    int x = (j * 213) + 5;

                    setlinestyle(0,0,0);
                    setcolor(BLUE);

                    if (a[i][j] == 2)
                        setcolor(BROWN);

                    line(x + 10 , y  + 0 , x + 10 , y + 20);
                    line(x + 10, y + 0 , x + 30, y + 0);
                    line (x + 30, y + 0, x + 30, y + 20);
                    line (x + 10, y + 20, x +30 , y + 20);
                    line(x + 10 , y  + 80 , x + 10 , y + 100);
                    line(x + 10, y + 80 , x + 30, y + 80);
                    line (x + 30, y + 80, x + 30, y + 100);
                    line (x + 10, y + 100, x +30 , y + 100);
                    line (x + 15, y + 75, x + 15, y +80 );
                    line (x + 0, y + 75, x + 15, y + 75);
                    line (x + 15, y + 75, x + 20, y + 70);
                    line (x + 20 , y + 20 , x + 20 , y + 80);
                    line (x +15 , y + 20, x + 15, y + 25);
                    line (x + 20 , y + 20, x + 20, y + 30);
                    line (x + 0, y + 25, x + 15, y + 25);
                    line (x + 15, y + 25 , x + 20 , y + 30);
                    line (x + 0 , y + 25 , x + 0 , y + 75);
                    line (x + 20 , y + 35 , x + 80 , y + 0 );
                    line(x+20, y + 65 , x+ 80 , y+100);
                    line ( x + 80 , y + 0 , x + 100, y + 0);
                    line ( x + 80 , y + 100 , x + 100, y + 100);
                    line ( x + 100 , y + 10 , x + 110, y + 20);
                    line ( x + 100 , y + 0 , x + 100, y + 10);
                    line ( x + 100 , y + 90 , x + 100, y + 100);
                    line (x+110 , y + 80 , x+ 130, y + 75);
                    line (x + 110, y + 20 , x + 130, y + 25);
                    line (x + 100 , y + 90 , x+ 110 , y + 80);
                    line( x+ 130 , y+25 , x + 130, y + 35);
                    line( x+ 130 , y+65 , x + 130, y + 75);
                    line( x+ 200 , y+40 , x + 200, y + 60);
                    line( x+ 130 , y+35 , x + 200, y + 40);
                    line( x+ 130 , y+65 , x + 200, y + 60);
                    line(x + 145 , y  + 0 , x + 145 , y + 20);
                    line(x + 145, y + 0 , x + 165, y + 0);
                    line (x + 165, y + 0, x + 165, y + 20);
                    line (x + 145, y + 20, x +165 , y + 20);
                    line(x + 145 , y  + 80 , x + 145 , y + 100);
                    line(x + 145, y + 80 , x + 165, y + 80);
                    line (x + 165, y + 80, x + 165, y + 100);
                    line (x + 145, y + 100, x +165 , y + 100);
                    line ( x + 145 , y + 35 , x + 155 , y + 20);
                    line ( x + 145 , y + 35 , x + 165 , y + 20);
                    line (x + 155 , y + 20 , x + 155, y+80);
                    line (x + 145 , y + 65, x + 155 , y + 80);
                    line (x + 145 , y + 65, x + 165 , y + 80);
                    line ( x+ 170 , y + 0 , x + 170 , y + 5);
                    line ( x+ 170 , y + 95 , x + 170 , y + 100);
                    line ( x+ 200 , y + 0 , x + 200 , y + 5);
                    line ( x+ 200 , y + 95 , x + 200 , y + 100);
                    line ( x + 170 , y + 0, x + 200, y + 0);
                    line ( x + 170 , y + 95, x + 200, y + 95);
                    line ( x + 170 , y + 100, x + 200, y + 100);
                    line ( x + 170 , y + 5, x + 200, y + 5);
                    line (x + 195 , y + 5 , x + 195 , y + 95);
                    line (x + 190 , y + 5 , x + 190 , y + 95);
                    line (x + 175 , y+ 5 , x + 175 , y + 20);
                    line (x + 175 , y+ 80 , x + 175 , y + 95);
                    line (x + 175 , y + 20 , x + 190 , y + 35);
                    line (x + 175, y+80 , x + 190, y + 65);
                }
            }
        }
        DrawRoad();
    }
}
void GameOver(){

    bar(0,0,640,480);
    setcolor(BLACK);
    setbkcolor(WHITE);
    outtextxy(240, 240, "••• GAME OVER •••");

    string B = "Best: ";
    B.append(NumberToString(best));
    string C = "Current: ";
    C.append(NumberToString(current));


    char  b [1024];
    char c [1024];

    strcpy(b, B.c_str());
    strcpy(c, C.c_str());

    outtextxy(275, 270 , b);
    outtextxy(265, 300 , c);
    outtextxy(190, 330, "Press any key to RESTART the game!");

    a[0][0] = a[1][0] = a[2][0] = 0;

    GameGoing = false;
    current = 0;
}

void KeyPress(){
    char ch = getch();
    switch(ch)
    {
    case 'q':
        if (y > 0)
        {
            if (a[y - 1][0] == 1) {GameOver();}
        }
        break;
    case 'a':
        if (y < 2)
        {
            if (a[y + 1][0] == 1){ GameOver();}
        }
        break;
    }
    switch(ch)
    {
    case 'q':
        if (y > 0)
        {
            a[y][0] = 0;
            y--;
            a[y][0] = 2;
        }
        break;
    case 'a':
        if (y < 2)
        {
            a[y][0] = 0;
            y++;
            a[y][0] = 2;
        }
        break;
    }
    DrawCars();
}

void MoveCars(){
    for (int i = 0 ; i <=2 ; i++)
    {
        for (int j = 0 ; j <= 2 ; j++)
        {
            if (j < 2 )
            {
                int w = j + 1;
                if ( a[i][j] == 2 && a[i][w] == 1)
                {
                    GameOver();
                }
                else if (a[i][j] != 2)
                    a[i][j] = a[i][w];
            }
        }
    }

    if (CreateCarOnNext)
        CreateCarOnNext = false;
    else CreateCarOnNext = true;


    for (int n = 0 ; n < 2 ; n++)
    {
        int i_rand = rand()%(2-0 + 1) + 0;
        a[0][2] = 0;
        a[1][2] = 0;
        a[2][2] = 0;
        if (CreateCarOnNext)
            a[i_rand][2] =  1;

    }

    DrawCars();
}

int main()
{
    a[1][0]= 2;
    srand(time(NULL));

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int errorcode = graphresult();

    outtextxy(240, 240, "Press any key to start");
    best = current = 0;
    getch();


    DrawCars();
    clock_t start = clock();
    for (;;)
    {
        while (!kbhit())
        {
            float time = (clock () - start) / CLOCKS_PER_SEC;
            if ((time >= 0.25) && GameGoing)
            {
                start = clock();
                MoveCars();
                current += 50;
                if (current >= best)
                    best = current;
            }
        }
        if (!GameGoing){
            a[1][0]= 2;
            GameGoing = true;
        }
        else{
            KeyPress();
        }
    }
}
