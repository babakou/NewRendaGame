#ifndef _PLAYER_
#define _PLAYER_

#include "Button.h"
#include <string>

class Player {
public:
    Player(){};
    Player( const char *name, int buttonID );
    Player( const Player& org );
    ~Player();

    void IncrementCount( void );
    const char* GetName( void );
    int GetPushCount( void );
    bool DoesPush( void );
    int GetRank( void );
    void SetRank( int rank );
    int GetButtonID( void );

private:
    int m_pushCount;
    int m_buttonID;
    Button m_button;
    std::string m_name;
    int m_rank;
};

#endif