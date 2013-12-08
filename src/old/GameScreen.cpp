#include "DxLib.h"
#include "GameScreen.h"
#include "CommonScreenConfigure.h"
#include "FontSettings.h"
#include "CommonUtils.h"

GameScreen::GameScreen( GameDataInfo *gameDataInfo ) {
    m_sideMargin = screenSize_x / 10;
    m_bottomMargin = screenSize_y / 20;

    for( int i = 0; i < 8; i++ ) {
        m_pushCountLocation_x[i] = m_sideMargin + ( (screenSize_x - (m_sideMargin * 2)) / 7 ) * i;
        m_playerNameLocation_x[i] = m_sideMargin + ( (screenSize_x - (m_sideMargin * 2)) / 7 ) * i;
    }

    int restTimeFontSize = 0;
    GetFontStateToHandle( NULL, &restTimeFontSize, NULL, restTimeFont );
    m_restTimeLocation_x = screenSize_x / 2;
    m_restTimeLocation_y = screenSize_y - ( m_bottomMargin + restTimeFontSize );

    int playerNameFontSize = 0;
    GetFontStateToHandle( NULL, &playerNameFontSize, NULL, playerNameFont );
    for( int i = 0; i < 4; i++ ) {      
        m_playerNameLocation_y[2 * i + 1] = m_restTimeLocation_y - ( m_bottomMargin + playerNameFontSize );
        m_playerNameLocation_y[2 * i] = m_playerNameLocation_y[2 * i + 1] - ( playerNameFontSize + 10 );
    }

    m_chartBottomLocation_y = m_playerNameLocation_y[0] - ( m_bottomMargin >> 1 );

    int pushCountFontSize = 0;
    GetFontStateToHandle( NULL, &pushCountFontSize, NULL, counterFont );
    for( int i = 0; i < 8; i++ ) {
        m_pushCountLocation_y[i] = m_chartBottomLocation_y - pushCountFontSize;
    }

    m_startCountDownLocation_x = screenSize_x / 2;
    m_startCountDownLocation_y = screenSize_y / 2;

    m_gameDataInfo = gameDataInfo;

    m_sizeOfPushCount = sizeof(m_pushCount) - 1;
    m_sizeOfRestTime = sizeof(m_restTime) - 1;
}

GameScreen::~GameScreen() {

}

void GameScreen::ShowStartCountDown( void ) {
    char restTimeToStart[3];

    if( m_gameDataInfo->GetRestTimeToStart() > 5 ) {
        DrawStringInAlignmentPos( screenSize_x >> 1, (screenSize_y >> 1) - 36, "Are you ready?", BLACK, areYouReadyFont );
    }

    else if( m_gameDataInfo->GetRestTimeToStart() > 0 ) {
        _snprintf( restTimeToStart, sizeof(restTimeToStart), "%d", m_gameDataInfo->GetRestTimeToStart() );
        DrawStringInAlignmentPos( screenSize_x >> 1, (screenSize_y >> 1) - 36, restTimeToStart, BLACK, restTimeToStartFont );
    }
}

void GameScreen::ShowPushCount( void ) {
    double restTimeInFlotingPoint = ((double)m_gameDataInfo->GetRestTime() / 10);

    for( int i = 0; i < 8; i++ ) {
        _snprintf( m_pushCount, m_sizeOfPushCount, "%d", m_gameDataInfo->GetPushCount(i) );

        DrawStringInAlignmentPos( m_pushCountLocation_x[i], 
            m_pushCountLocation_y[i] - m_gameDataInfo->GetPushCount(i), 
            m_pushCount,
            BLACK,
            counterFont );
        
        DrawStringInAlignmentPos( m_playerNameLocation_x[i], m_playerNameLocation_y[i], m_gameDataInfo->GetPlayerName(i), BLACK, playerNameFont );

        DrawChart( m_pushCountLocation_x[i], m_chartBottomLocation_y, 60, m_gameDataInfo->GetPushCount(i), BLACK );
    }

    _snprintf( m_restTime, m_sizeOfRestTime, "%4.1f", restTimeInFlotingPoint );
    DrawStringInAlignmentPos( m_restTimeLocation_x, m_restTimeLocation_y, m_restTime, BLACK, restTimeFont );
}

void GameScreen::ShowTimeUp( void ) {
    DrawStringInAlignmentPos( screenSize_x >> 1, (screenSize_y >> 1) - 24, "Time UP!", RED, areYouReadyFont );
}

void GameScreen::DrawChart( int xLocationOfChartCenter, int yLocation, int chartWidth, int chartHeight, int color ) {
    int xLeftTopOfChart = xLocationOfChartCenter - ( chartWidth >> 1 );
    int yLeftTopOfChart = yLocation - chartHeight;
    int xRightBottomOfChart = xLocationOfChartCenter + ( chartWidth >> 1 );
    int yRightBottomOfChart = yLocation;

    DrawBox( xLeftTopOfChart, yLeftTopOfChart, xRightBottomOfChart, yRightBottomOfChart, color, TRUE );
}

void GameScreen::DrawGraphAtCenterOfScreen( const char *graphName ) {
    int graphHandle = LoadGraph( graphName );

    DrawGraph( screenSize_x / 2, screenSize_y / 2, graphHandle, TRUE );
}