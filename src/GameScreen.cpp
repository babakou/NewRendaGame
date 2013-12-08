#include "GameScreen.h"
#include "FontSettings.h"
#include "CommonScreenConfigure.h"
#include "DxLib.h"
#include <string>
#include <vector>

namespace GS {
    std::string areYouReadyStr = "Are you ready?";
    int areYouReadyLoc_x;
    int areYouReadyLoc_y;
    int countDownLoc_x;
    int countDownLoc_y;
    int sideMargin;
    int restTimeLoc_x;
    int restTimeLoc_y;
    std::vector<int> chartCenter;
    std::vector<int> playerNameLoc_x;
    std::vector<int> playerNameLoc_y;
    int chartBottomLoc;
    std::vector<int> pushCountLoc_x;
    std::vector<int> pushCountLoc_y;
    std::string timeUpStr = "Time UP!";
    int timeUpLoc_x;
    int timeUpLoc_y;

    int chartImg;
    int timeUpImg;
};

GameScreen::GameScreen( int width, int height, Game *game ) {
    m_game = game;

    m_width = width;
    m_height = height;

    GS::chartCenter.clear();
    GS::playerNameLoc_x.clear();
    GS::playerNameLoc_y.clear();
    GS::pushCountLoc_x.clear();
    GS::pushCountLoc_y.clear();

    int areYouReadyHeight = 0;
    GetFontStateToHandle( NULL, &areYouReadyHeight, NULL, areYouReadyFont );
    int strWidth = GetDrawStringWidthToHandle( GS::areYouReadyStr.c_str(), GS::areYouReadyStr.length(), areYouReadyFont );
    GS::areYouReadyLoc_x = (width / 2) - (strWidth / 2);
    GS::areYouReadyLoc_y = (height / 2) - (areYouReadyHeight / 2);

    int countDownFontHeight = 0;
    std::string countDownExample = "5";
    GetFontStateToHandle( NULL, &countDownFontHeight, NULL, restTimeFont );
    strWidth = GetDrawStringWidthToHandle( countDownExample.c_str(), countDownExample.length(), restTimeFont );
    GS::countDownLoc_x = (width / 2) - (strWidth / 2);
    GS::countDownLoc_y = (height / 2) - (countDownFontHeight / 2);

    int restTimeFontHeight;
    std::string restTimeExample = "15.0";
    GetFontStateToHandle( NULL, &restTimeFontHeight, NULL, restTimeFont );
    strWidth = GetDrawStringWidthToHandle( restTimeExample.c_str(), restTimeExample.length(), restTimeFont );
    GS::restTimeLoc_x = (width / 2) - (strWidth / 2);
    //GS::restTimeLoc_y = height - restTimeFontHeight - 10;
    GS::restTimeLoc_y = 10;

    int playerFontHeight = 0;
    GetFontStateToHandle( NULL, &playerFontHeight, NULL, playerNameFont );
    int lowerLocation = height - ( playerFontHeight + 100 );
    int upperLocation = lowerLocation - ( playerFontHeight + 5 );
    int playerNameWidth, prevPlayerNameWidth;
    for( int i = 0; i < game->GetNumOfPlayer(); i++ ) {
        std::string playerName = game->GetPlayerInfo(i)->GetName();
        playerNameWidth = GetDrawStringWidthToHandle( playerName.c_str(), playerName.length(), playerNameFont );
        GS::chartCenter.push_back( ( width / (2 * game->GetNumOfPlayer() + 2) ) * (2 * (i + 1)) );
        GS::playerNameLoc_x.push_back( GS::chartCenter[i] - (playerNameWidth / 2) );
        if( i >= 1 && GS::playerNameLoc_y[i - 1] == upperLocation && ( GS::playerNameLoc_x[i] - (GS::playerNameLoc_x[i - 1] + prevPlayerNameWidth) < 10 ) ) {
            GS::playerNameLoc_y.push_back( lowerLocation );
        }
        else {
            GS::playerNameLoc_y.push_back( upperLocation );
        }
        prevPlayerNameWidth = playerNameWidth;
    }

    GS::chartBottomLoc = upperLocation - 10;

    int counterFontHeight = 0;
    GetFontStateToHandle( NULL, &counterFontHeight, NULL, counterFont );
    std::string pushCountExample = "100";
    strWidth = GetDrawStringWidthToHandle( pushCountExample.c_str(), pushCountExample.length(), counterFont );
    for( int i = 0; i < game->GetNumOfPlayer(); i++ ) {
        GS::pushCountLoc_x.push_back( GS::chartCenter[i] - (strWidth / 2) );
        GS::pushCountLoc_y.push_back( GS::chartBottomLoc - (counterFontHeight + 10) );
    }

    int timeUpFontHeight = 0;
    GetFontStateToHandle( NULL, &timeUpFontHeight, NULL, areYouReadyFont );
    strWidth = GetDrawStringWidthToHandle( GS::timeUpStr.c_str(), GS::timeUpStr.length(), areYouReadyFont );
    GS::timeUpLoc_x = ( width / 2 ) - ( strWidth / 2 );
    GS::timeUpLoc_y = ( height / 2 ) - ( timeUpFontHeight / 2 );

    GS::chartImg = LoadGraph( "C:/Users/babakou/Works/Renda_Game/bmp/chart.jpg" );
}

GameScreen::~GameScreen() {

}

bool GameScreen::Draw( void ) {
    //DrawBox( 0, 0, m_width - 1, m_height - 1, WHITE, TRUE );
    DrawGraph( 0, 0, TakahashiImg, FALSE );
    if( m_game->IsGameFinished() ) {
        DrawStringToHandle( GS::timeUpLoc_x, GS::timeUpLoc_y, GS::timeUpStr.c_str(), RED, areYouReadyFont );
        //DrawGraph( GS::timeUpLoc_x, GS::timeUpLoc_y, GS::timeUpImg, TRUE );
    }
    else {
        if( m_game->DoesWaitingStart() ) {
            if( m_game->GetRestTimeToStart() > 3 ) {
                DrawStringToHandle( GS::areYouReadyLoc_x, GS::areYouReadyLoc_y, GS::areYouReadyStr.c_str(), BLACK, areYouReadyFont );
            }
            else {
                DrawFormatStringToHandle( GS::countDownLoc_x, GS::countDownLoc_y, BLACK, restTimeFont, "%d", m_game->GetRestTimeToStart() );
            }
        }
        for( int i = 0; i < m_game->GetNumOfPlayer(); i++ ) {
            int pushCount = m_game->GetPlayerInfo(i)->GetPushCount();
            DrawFormatStringToHandle( GS::pushCountLoc_x[i], GS::pushCountLoc_y[i] - (pushCount * 3), BLACK, counterFont, "%d", pushCount );
            DrawStringToHandle( GS::playerNameLoc_x[i], GS::playerNameLoc_y[i], m_game->GetPlayerInfo(i)->GetName(), BLACK, playerNameFont );
            int chartColor = GetColor( pushCount, pushCount, pushCount );
            DrawChart( GS::chartCenter[i], GS::chartBottomLoc, 60, pushCount * 3, chartColor );
        }
    }


    DrawFormatStringToHandle( GS::restTimeLoc_x, GS::restTimeLoc_y, BLACK, restTimeFont, "%04.1f", ((double)m_game->GetRestTimeToFinish() / 10) );

    return true;
}

void GameScreen::DrawChart( int xLocationOfChartCenter, int yLocation, int chartWidth, int chartHeight, int color ) {
    int xLeftTopOfChart = xLocationOfChartCenter - ( chartWidth >> 1 );
    int yLeftTopOfChart = yLocation - chartHeight;
    int xRightBottomOfChart = xLocationOfChartCenter + ( chartWidth >> 1 );
    int yRightBottomOfChart = yLocation;

    //DrawBox( xLeftTopOfChart, yLeftTopOfChart, xRightBottomOfChart, yRightBottomOfChart, color, TRUE );
    DrawRectGraph( xLeftTopOfChart, yLeftTopOfChart, 0, 500 - chartHeight, 60, chartHeight, GS::chartImg, FALSE, FALSE );
}

void GameScreen::FadeIn( void ) {
    for( int brightness = 0; brightness < 256; brightness += 15 ) {
        SetDrawBright( brightness, brightness, brightness );
        ClearDrawScreen();
        Draw();
        ScreenFlip();
        Sleep( 10 );
    }
}

void GameScreen::FadeOut( void ) {
    for( int brightness = 255; brightness >= 0; brightness -= 15 ) {
        SetDrawBright( brightness, brightness, brightness );
        ClearDrawScreen();
        Draw();
        ScreenFlip();
        Sleep( 10 );
    }
}