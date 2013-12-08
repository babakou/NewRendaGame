#ifndef _PLAYERENTRYSCREEN_H_
#define _PLAYERENTRYSCREEN_H_

#include "GameDataInfo.h"

class PlayerEntryScreen {
public:
    PlayerEntryScreen( GameDataInfo *gameDataInfo );
    ~PlayerEntryScreen();
    void Show( void );

private:
    void AskPlayerName( int playerID );

private:
    char m_playerName[8][50];
    GameDataInfo *m_gameDataInfo;
    int m_givenPlayerNameID;

    char m_preHeader[8][15];
};

#endif