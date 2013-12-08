#include "PlayerList.h"

static void SwapPlayer( Player & player1, Player & player2 ) {
    Player tmp = player1;
    player1 = player2;
    player2 = tmp;
}

PlayerList::PlayerList( void ) {

}

PlayerList::~PlayerList() {
    m_player.clear();
}

Player * PlayerList::operator[]( int idx ) {
    return &(m_player[ idx ]);
}

void PlayerList::AddPlayer( const char *name, int buttonID ) {
    Player player( name, buttonID );
    m_player.push_back( player );
}

void PlayerList::Clear( void ) {
    m_player.clear();
}

int PlayerList::GetNumOfPlayer( void ) {
    return m_player.size();
}

void PlayerList::SortByPushCount( void ) {
    Player tmpPlayer;
    int currentPushCount;
    int comparedPushCount;

    if( 2 <= GetNumOfPlayer() ) {
        for( int rank = 0; rank < GetNumOfPlayer(); rank++ ) {
            for( int j = rank + 1; j < GetNumOfPlayer(); j++ ) {
                currentPushCount = m_player[rank].GetPushCount();
                comparedPushCount = m_player[j].GetPushCount();
                if( currentPushCount < comparedPushCount ) {
                    SwapPlayer( m_player[rank], m_player[j] );
                }
            }
        }
    }
}

void PlayerList::Ranking( void ) {
    for( int i = 0; i < GetNumOfPlayer(); i++ ) {
        if( 1 <= i && (m_player[i].GetPushCount() == m_player[i - 1].GetPushCount()) ) {
            m_player[i].SetRank( m_player[i - 1].GetRank() );
        }
        else {
            m_player[i].SetRank(i + 1);
        }
    }
}