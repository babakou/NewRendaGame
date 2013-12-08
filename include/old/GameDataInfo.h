#ifndef _GAMEDATAINFO_H_
#define _GAMEDATAINFO_H_

#include "Button.h"
#include "Player.h"

class GameDataInfo {
public:
    GameDataInfo();
    ~GameDataInfo();
    int GetPushCount( int playerID );
    const char* GetPlayerName( int playerID );
    int GetRestTime( void );
    int GetRestTimeToStart( void );
    void DoMainGameProcedure( void );
    void DoStartCountDown( void );
    int GetGameState( void );
    void SetPlayerName( int playerID, const char *playerName );

    void CreatePlayers( void );
    void CreateButtons( void );

    void Clear( void );
    
    void StateChange( int nextState );

    void SortPlayerByPushCount( void );

private:
    int PlayerIDFromJoyPadAndInputID( int JoypadID, int inputID );
    void buttonPushStateUpdate( int playerID );
    void DeletePlayers( void );
    void DeleteButtons( void );
   
private:
    Button *m_button[8];
    Player *m_player[8];

    int m_restTime;

    int m_restTimeToStart;

    int m_gameState;

    char m_playerName[8][50];
};

#endif