#include "ResultScreen.h"
#include "DxLib.h"
#include "FontSettings.h"
#include "CommonScreenConfigure.h"

namespace RS {
    std::string captionStr = "Œ‹‰Ê";
    int captionLoc_x;
    int captionLoc_y;
    std::vector< std::string > playerResult;
    std::vector<int> playerResultLoc_x;
    std::vector<int> playerResultLoc_y;
    std::vector<int> playerResultFont;

    char answerStr[100];
    int answerLoc_x;
}

ResultScreen::ResultScreen( int width, int height, Game *game ) {
    m_width = width;
    m_height = height;
    m_game = game;

    RS::playerResult.clear();
    RS::playerResultLoc_x.clear();
    RS::playerResultLoc_y.clear();
    RS::playerResultFont.clear();

    int captionFontHeight = 0;
    GetFontStateToHandle( NULL, &captionFontHeight, NULL, captionFont );
    int strWidth = GetDrawStringWidthToHandle( RS::captionStr.c_str(), RS::captionStr.length(), captionFont );
    RS::captionLoc_x = (width / 2) - (strWidth / 2);
    RS::captionLoc_y = 15;

    char tmp[100];

    for( int i = 0; i < game->GetNumOfPlayer(); i++ ) {
        int rank = game->GetPlayerInfo(i)->GetRank();
        std::string name = game->GetPlayerInfo(i)->GetName();
        int pushCount = game->GetPlayerInfo(i)->GetPushCount();
        _snprintf( tmp, sizeof(tmp) - 1, "%dˆÊ : %s  %d˜A‘Å", rank, name.c_str(), pushCount );
        RS::playerResult.push_back( tmp );

        if( 1 == rank ) {
            RS::playerResultFont.push_back( winnerFont );
        }
        else if( 2 == rank ) {
            RS::playerResultFont.push_back( secondWinnerFont );
        }
        else if( 3 == rank ) {
            RS::playerResultFont.push_back( thirdWinnerFont );
        }
        else {
            RS::playerResultFont.push_back( underFourthFont );
        }

        strWidth = GetDrawStringWidthToHandle( RS::playerResult[i].c_str(), RS::playerResult[i].length(), RS::playerResultFont[i] );
        RS::playerResultLoc_x.push_back( (width / 2) - (strWidth / 2) );
        if( i == 0 ) {
            RS::playerResultLoc_y.push_back( RS::captionLoc_y + captionFontHeight + 10 );
        }
        else {
            int resultFontHeight = 0;
            GetFontStateToHandle( NULL, &resultFontHeight, NULL, RS::playerResultFont[i - 1] );
            RS::playerResultLoc_y.push_back( RS::playerResultLoc_y[i - 1] + resultFontHeight + 10 );
        }
    }

    _snprintf( RS::answerStr, sizeof( RS::answerStr ) - 1, "%d”Ô %s ‚³‚ñ", game->GetPlayerInfo(0)->GetButtonID() + 1, game->GetPlayerInfo(0)->GetName() );

    strWidth = GetDrawStringWidthToHandle( RS::answerStr, strlen( RS::answerStr ), answerFont );
    RS::answerLoc_x = (width / 2) - (strWidth / 2);
}

ResultScreen::~ResultScreen() {

}

bool ResultScreen::Draw( void ) {
    //DrawBox( 0, 0, m_width - 1, m_height - 1, WHITE, TRUE );
    DrawGraph( 0, 0, TakahashiImg, FALSE );
    DrawStringToHandle( RS::captionLoc_x, RS::captionLoc_y, RS::captionStr.c_str(), BLACK, captionFont );

    int numOfPlayer = m_game->GetNumOfPlayer();

    for( int i = 0; i < numOfPlayer; i++ ) {
        DrawStringToHandle( RS::playerResultLoc_x[i], RS::playerResultLoc_y[i], RS::playerResult[i].c_str(), BLACK, RS::playerResultFont[i] );
    }

    DrawStringToHandle( 100, RS::playerResultLoc_y[numOfPlayer - 1] + 100, "³‰ð‚Í", BLACK, answerFont );
    DrawStringToHandle( RS::answerLoc_x, RS::playerResultLoc_y[numOfPlayer - 1] + 180, RS::answerStr, RED, answerFont );
    DrawStringToHandle( 700, RS::playerResultLoc_y[numOfPlayer - 1] + 260, "‚Å‚µ‚½I", BLACK, answerFont );

    return true;
}

void ResultScreen::FadeOut( void ) {
    for( int brightness = 255; brightness >= 0; brightness -= 15 ) {
        SetDrawBright( brightness, brightness, brightness );
        ClearDrawScreen();
        Draw();
        ScreenFlip();
        Sleep( 10 );
    }
}

void ResultScreen::FadeIn( void ) {
    for( int brightness = 0; brightness < 256; brightness += 15 ) {
        SetDrawBright( brightness, brightness, brightness );
        ClearDrawScreen();
        Draw();
        ScreenFlip();
        Sleep( 10 );
    }
}