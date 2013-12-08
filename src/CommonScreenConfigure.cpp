#include "DxLib.h"
#include "CommonScreenConfigure.h"

int screenSize_x;
int screenSize_y;
int screenColorDepthBit;

int captionLocation_x;
int captionLocation_y;

const int WHITE = GetColor( 255, 255, 255 );
const int BLACK = GetColor( 0, 0, 0 );
const int RED = GetColor( 255, 0, 0 );
const int BRIGHTGRAY = GetColor( 200, 200, 200 );
const int BLUE = GetColor( 0, 0, 255 );
const int GREEN = GetColor( 0, 255, 0 );
const int YELLOW = GetColor( 0, 255, 255 );

const char *Takahashi_M_Path = "C:/Users/babakou/Works/Renda/bmp/CommonBackScreen.jpg";
int TakahashiImg;

void ConfigureCommonScreen( void ) {
    //GetDefaultState( &screenSize_x, &screenSize_y, &screenColorDepthBit );
    screenSize_x = 1024;
    screenSize_y = 768;
    screenColorDepthBit = 32;

    captionLocation_x = screenSize_x / 2;
    captionLocation_y = screenSize_y / 15;

    SetGraphMode( screenSize_x, screenSize_y, screenColorDepthBit );

    ChangeWindowMode( TRUE );
    SetBackgroundColor( 0, 0, 0 );
}