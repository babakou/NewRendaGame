#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Button.h"

class Player {
public:
    Player( const char *name, int belongingTeam );
    ~Player();

    void IncrementCount( void );
    const char* GetName( void );
    int GetBelongingTeam( void );
    int GetPushCount( void );

private:
    int m_pushCount;
    char m_name[50];
    int m_belongingTeam;
};

#endif