#include <iostream>

#include <Windows.h>

int width = 120;
int height = 40;


float fPlayerX = 14.7f;			// Player Start Position
float fPlayerY = 5.09f;
float fPlayerA = 0.0f;			// Player Start Rotation(угол)



const std::wstring map[10]=
{
    L"##########",
    L"#........#",
    L"#........#",
    L"#........#",
    L"#........#",
    L"#........#",
    L"#........#",
    L"#........#",
    L"#........#",
    L"##########",

};


int main()
{
    wchar_t *screen = new wchar_t[width*height];
    HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(console);
    DWORD bytesWritten = 0;

    // main loop
    while (true){

        for(int i = 0; i < width*height; ++i)
          {
           *screen = '  ';
 }
        //handlers
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000){

        }

        if (GetAsyncKeyState((unsigned short)'D') & 0x8000){

        }

        if (GetAsyncKeyState((unsigned short)'W') & 0x8000){

        }

        if (GetAsyncKeyState((unsigned short)'S') & 0x8000){

        }


        // rander


        // stats
        for(int i = 0; i < 10; ++i)
        {//начало первого фора
            for(int j = 0; j < 10; ++j)
            {//начало второго фора



                if(i==1)
                {
                    screen[172+j] = map[i][j] ;//коэффициент(-6) отвечает за то ,что строчка двигается либо влево,либо вправо.(+1) за то ,что строчка двигается либо вверх,либо вниз.
                }
                else if(i==2)//здесь не получается
                {
                    screen[255+(j)] = map[i][j] ;
                }
                else if(i==3)
                {
                    screen[356+j-17] = map[i][j] ;
                }
                else if(i==4)
                {
                    screen[445+j-23] = map[i][j] ;
                }
                else if(i==5)//здесь не получается
                {
                    screen[534+j-29] = map[i][j] ;
                }
                else if(i==6)
                {
                    screen[89*(i+1)+(j-34)] = map[i][j] ;
                }
                else if(i==7)
                {
                    screen[89*(i+1)+(j-40)] = map[i][j] ;
                }
                else if(i==8)//здесь не получается
                {
                    screen[89*(i+1)+(j-46)] = map[i][j] ;
                }
                else if(i==9)
                {
                    screen[890+j-51] = map[i][j] ;
                }
                else
                {
                    screen[89+j] = map[i][j] ;
                }

        }// конец второго фора
}//конец первого фора
        swprintf_s(screen, 40, L"X=%3.2f, Y=%3.2f, A=%3.2f", fPlayerX, fPlayerY, fPlayerA);
        screen[width * height - 1] = '\0';

        WriteConsoleOutputCharacter(console, screen, width * height, { 0,0 }, &bytesWritten);
    }

    return 0;
}
