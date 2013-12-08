#ifndef _GAME_
#define _GAME_

#include "PlayerList.h"
#include <string>

class Game {
public: 
    Game( PlayerList *playerList );
    ~Game();
    void Main( void );
    bool DoesWaitingStart( void );
    bool IsGameFinished( void );
    int GetRestTimeToStart( void );
    int GetRestTimeToFinish( void );
    Player * GetPlayerInfo( int buttonID );
    int GetNumOfPlayer( void );
    void RestTimeDecrement( void );
    void CountDown( void );
    void Clear();
    void PrepareForResult( void );

private:
    PlayerList *m_playerList;
    
    int m_restTimeToStart;
    int m_restTimeToFinish;

    int m_readerPushCount;
    std::string m_readerName;
};

#endif