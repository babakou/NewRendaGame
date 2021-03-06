#include "ResultScreen.h"
#include "CommonUtils.h"
#include "CommonScreenConfigure.h"
#include "FontSettings.h"
#include "DxLib.h"

ResultScreen::ResultScreen( GameDataInfo *gameDataInfo ) {
    m_gameDataInfo = gameDataInfo;

    rankingFonts[0] = winnerFont;
    rankingFonts[1] = secondWinnerFont;
    rankingFonts[2] = thirdWinnerFont;

    for( int i = 3; i < 8; i++ ) {
        rankingFonts[i] = underFourthFont;
    }
}

ResultScreen::~ResultScreen() {

}

void ResultScreen::Show( void ) {
    ClearDrawScreen();

    int fontSize;
    int strLocation = 100;

    DrawStringInAlignmentPos( captionLocation_x, captionLocation_y, "結果", BLACK, captionFont );

    for( int i = 0; i < 8; i++ ) {
        GetFontStateToHandle( NULL, &fontSize, NULL, rankingFonts[i] );
        DrawFormatStringToHandle( screenSize_x >> 4, strLocation, BLACK, rankingFonts[i], "%d 位  :  %s  %d 連打", i + 1, m_gameDataInfo->GetPlayerName( i ), m_gameDataInfo->GetPushCount( i ) ); 
        strLocation += (fontSize + 10);
    }

    ScreenFlip();
}