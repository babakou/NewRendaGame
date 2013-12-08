#include "Player.h"
#include <string.h>

Player::Player( const char *name, int belongingTeam ) {
    strncpy( m_name, name, sizeof(m_name) );
    m_belongingTeam = belongingTeam;
    m_pushCount = 0;
}

Player::~Player() {

}

void Player::IncrementCount( void ) {
    m_pushCount = 300;
}

const char* Player::GetName( void ) {
    return m_name;
}

int Player::GetBelongingTeam( void ) {
    return m_belongingTeam;
}

int Player::GetPushCount( void ) {
    return m_pushCount;
}