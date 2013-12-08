#include "DxLib.h"
#include "OpeningScreen.h"
#include "CommonScreenConfigure.h"
#include <string>

OpeningScreen::OpeningScreen( int width, int height ) {
    m_width = width;
    m_height = height;

    m_titleImg = LoadGraph( "C:/Users/babakou/Works/Renda/bmp/TitlePlate.jpg" );

    int titleWidth = 0;
    int titleHeight = 0;
    GetGraphSize( m_titleImg, &titleWidth, &titleHeight );
    m_titleLetterLocation_x = (width / 2) - (titleWidth / 2);
    m_titleLetterLocation_y = (height / 2) - (titleHeight / 2);
}

OpeningScreen::~OpeningScreen() {
}

bool OpeningScreen::Draw( void ) {
    //DrawBox( 0, 0, m_width - 1, m_height - 1, WHITE, TRUE );
    DrawGraph( 0, 0, TakahashiImg, FALSE );
    DrawGraph( m_titleLetterLocation_x, m_titleLetterLocation_x, m_titleImg, TRUE );

    return true;
}

void OpeningScreen::FadeOut( void ) {
    for( int brightness = 255; brightness >= 0; brightness -= 15 ) {
        SetDrawBright( brightness, brightness, brightness );
        ClearDrawScreen();
        Draw();
        ScreenFlip();
        Sleep( 10 );
    }
}

void OpeningScreen::FadeIn( void ) {
    for( int brightness = 0; brightness < 256; brightness += 15 ) {
        SetDrawBright( brightness, brightness, brightness );
        ClearDrawScreen();
        Draw();
        ScreenFlip();
        Sleep( 10 );
    }
}