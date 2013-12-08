#include "Game.h"

static int samplingTimeOfInput;

Game::Game( PlayerList *playerList ) {
    m_playerList = playerList;

    m_restTimeToStart = 5;
    m_restTimeToFinish = 150;

    m_readerPushCount = -1;
}

Game::~Game() {
    m_playerList->Clear();
}

bool Game::DoesWaitingStart( void ) {
    return (m_restTimeToStart > 0);
}

bool Game::IsGameFinished( void ) {
    return (m_restTimeToFinish == 0);
}

int Game::GetRestTimeToStart( void ) {
    return m_restTimeToStart;
}

int Game::GetRestTimeToFinish( void ) {
    return m_restTimeToFinish;
}

void Game::CountDown( void ) {
    Sleep( 1000 );
    m_restTimeToStart --;
}

void Game::RestTimeDecrement( void ) {
    m_restTimeToFinish--;
}

int Game::GetNumOfPlayer( void ) {
    return m_playerList->GetNumOfPlayer();
}

Player * Game::GetPlayerInfo( int buttonID ) {
    return (*m_playerList)[buttonID];
}

void Game::Main( void ) {
    for( int i = 0; i < m_playerList->GetNumOfPlayer(); i++ ) {
        if( (*m_playerList)[i]->DoesPush() ) {
            (*m_playerList)[i]->IncrementCount();
        }
    }
}

void Game::PrepareForResult( void ) {
    m_playerList->SortByPushCount();
    m_playerList->Ranking();
}

void Game::Clear( void ) {
    m_restTimeToStart = 5;
    m_restTimeToFinish = 150;

    m_playerList->Clear();
}