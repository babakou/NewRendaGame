#ifndef _GAMESCREEN_H_
#define _GAMESCREEN_H_

#include "GameDataInfo.h"

class GameScreen {
public:
    GameScreen( GameDataInfo *gameDataInfo );
    ~GameScreen();
    void ShowPushCount( void ); 
    void ShowStartCountDown( void );
    void ShowTimeUp( void );

private:
    int m_pushCountLocation_x[8];
    int m_pushCountLocation_y[8];

    int m_playerNameLocation_x[8];
    int m_playerNameLocation_y[8];

    int m_startCountDownLocation_x;
    int m_startCountDownLocation_y;
    
    int m_chartBottomLocation_y;

    int m_restTimeLocation_x;
    int m_restTimeLocation_y;

    GameDataInfo *m_gameDataInfo;

private:
    void DrawChart( int xLocationOfChartCenter, int yLocation, int chartWidth, int chartHeight, int color );
    void DrawGraphAtCenterOfScreen( const char *graphName );

    char m_pushCount[6];
    char m_restTime[10];
    int m_sizeOfPushCount;
    int m_sizeOfRestTime;

    int m_sideMargin;
    int m_bottomMargin;
};

#endif