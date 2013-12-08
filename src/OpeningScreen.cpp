#include "DxLib.h"
#include "OpeningScreen.h"
#include "CommonScreenConfigure.h"
#include <string>

OpeningScreen::OpeningScreen( int width, int height ) {
    m_width = width;
    m_height = height;

    m_titleLetter = "–ÚŽw‚¹‚‹´M! (AT)˜A‘Å‘ÎŒˆ!";

    int titleLetterHeight = 0;
    GetFontStateToHandle( NULL, &titleLetterHeight, NULL, titleFont );
    int strWidth = GetDrawStringWidthToHandle( m_titleLetter.c_str(), m_titleLetter.length(), titleFont );
    m_titleLetterLocation_x = (width / 2) - (strWidth / 2);
    m_titleLetterLocation_y = (height / 2) - (titleLetterHeight / 2);
}

OpeningScreen::~OpeningScreen() {
}

bool OpeningScreen::Draw( void ) {
    //DrawBox( 0, 0, m_width - 1, m_height - 1, WHITE, TRUE );
    DrawGraph( 0, 0, TakahashiImg, FALSE );
    DrawStringToHandle( m_titleLetterLocation_x, m_titleLetterLocation_x, m_titleLetter.c_str(), BLACK, titleFont );

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