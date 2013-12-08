#include "StateManager.h"
#include "DxLib.h"

StateManager::StateManager( void ) {
    m_gameState = 0;
}

StateManager::~StateManager( void ) {

}

void StateManager::ChangeState( int nextState ) {
    m_gameState = nextState;

    if( m_gameState == 0 && CheckHitKeyAll() ) {
        m_gameState = 3;
    }

    else if( m_gameState == 3 )
}