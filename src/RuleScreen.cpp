#include "RuleScreen.h"
#include "DxLib.h"
#include "CommonScreenConfigure.h"

RuleScreen::RuleScreen( int width, int height ) {
    m_width = width;
    m_height = height;

    m_ruleImg = LoadGraph( "C:/Users/babakou/Works/Renda/bmp/_Rule.jpg" );
}

RuleScreen::~RuleScreen() {
    DeleteGraph( m_ruleImg );
}

bool RuleScreen::Draw( void ) {
    DrawGraph( 0, 0, TakahashiImg, FALSE );
    DrawGraph( 0, 0, m_ruleImg, TRUE );

    return true;
}

void RuleScreen::FadeOut( void ) {
    for( int brightness = 255; brightness >= 0; brightness -= 15 ) {
        SetDrawBright( brightness, brightness, brightness );
        ClearDrawScreen();
        Draw();
        ScreenFlip();
        Sleep( 10 );
    }
}

void RuleScreen::FadeIn( void ) {
    for( int brightness = 0; brightness < 256; brightness += 15 ) {
        SetDrawBright( brightness, brightness, brightness );
        ClearDrawScreen();
        Draw();
        ScreenFlip();
        Sleep( 10 );
    }
}