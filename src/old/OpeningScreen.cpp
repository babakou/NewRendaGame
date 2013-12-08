#include "DxLib.h"
#include "CommonScreenConfigure.h"
#include "OpeningScreen.h"
#include "CommonUtils.h"
#include "FontSettings.h"

OpeningScreen::OpeningScreen( GameDataInfo *gameDataInfo ) {
    m_openingTitleLetter = "˜A‘Å‘ÎŒˆ2013(TBD!!)";
    m_gameDataInfo = gameDataInfo;
}

OpeningScreen::~OpeningScreen( void ) {

}

void OpeningScreen::Show( void ) {
    ClearDrawScreen();
    DrawStringInAlignmentPos( screenSize_x / 2, screenSize_y / 2 - 24, m_openingTitleLetter, BLACK, titleFont );
    ScreenFlip();

    while( CheckHitKey( KEY_INPUT_Z ) == 0 ) {
        if( ProcessMessage() == -1 ) {
            break;
        }
    }

    m_gameDataInfo->StateChange( 1 );
}