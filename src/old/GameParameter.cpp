#include "GameParameter.h"

GameParameter::GameParameter() {
    for( int i = 0; i < 8; i++ ) {
        m_buttonCount[i] = 20;
    }

    m_restTime = 150;
}

GameParameter::~GameParameter() {

}

int GameParameter::GetButtonCount( int playerID ) {
    return m_buttonCount[ playerID ];
}

int GameParameter::GetRestTime( void ) {
    return m_restTime;
}