#ifndef _PLAYERLIST_
#define _PLAYERLIST_

#include "Player.h"
#include <vector>

class PlayerList {
public:
    PlayerList( void );
    ~PlayerList();
    void AddPlayer( const char* name, int buttonID );
    void Clear();
    Player * operator[]( int idx );
    int GetNumOfPlayer( void );
    void SortByPushCount( void );
    void Ranking( void );

private:
    std::vector<Player> m_player;
};

#endif