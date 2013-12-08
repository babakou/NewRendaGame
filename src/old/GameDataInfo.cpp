#include "DxLib.h"
#include "GameDataInfo.h"

GameDataInfo::GameDataInfo() {
    m_restTime = 150;

    m_restTimeToStart = 3;

    m_gameState = 0;
}

GameDataInfo::~GameDataInfo() {
    DeletePlayers();
    DeleteButtons();
}

void GameDataInfo::CreatePlayers( void ) {
    for( int i = 0; i < 8; i++ ) {
        m_player[i] = new Player( m_playerName[i], i );
    }
}

void GameDataInfo::CreateButtons( void ) {
    m_button[0] = new Button( DX_INPUT_KEY_PAD1, PAD_INPUT_1 );
    m_button[1] = new Button( DX_INPUT_KEY_PAD1, PAD_INPUT_2 );
    m_button[2] = new Button( DX_INPUT_KEY_PAD1, PAD_INPUT_3 );
    m_button[3] = new Button( DX_INPUT_KEY_PAD1, PAD_INPUT_4 );

    m_button[4] = new Button( DX_INPUT_KEY_PAD1, PAD_INPUT_5 );
    m_button[5] = new Button( DX_INPUT_KEY_PAD1, PAD_INPUT_6 );
    m_button[6] = new Button( DX_INPUT_KEY_PAD1, PAD_INPUT_7 );
    m_button[7] = new Button( DX_INPUT_KEY_PAD1, PAD_INPUT_8 );

    /*m_button[4] = new Button( DX_INPUT_PAD2, PAD_INPUT_1 );
    m_button[5] = new Button( DX_INPUT_PAD2, PAD_INPUT_2 );
    m_button[6] = new Button( DX_INPUT_PAD2, PAD_INPUT_3 );
    m_button[7] = new Button( DX_INPUT_PAD2, PAD_INPUT_4 );*/
}

void GameDataInfo::Clear( void ) {
    m_restTime = 150;
    m_restTimeToStart = 8;

    DeletePlayers();
    DeleteButtons();
}

void GameDataInfo::DeletePlayers( void ) {
    for( int i = 0; i < 8; i++ ) {
        if( m_player[i] != NULL ) {
            delete m_player[i];
            m_player[i] = NULL;
        }
    }
}

void GameDataInfo::DeleteButtons( void ) {
    for( int i = 0; i < 8; i++ ) {
        if( m_button[i] != NULL ) {
            delete m_button[i];
            m_button[i] = NULL;
        }
    }
}

int GameDataInfo::PlayerIDFromJoyPadAndInputID( int JoypadID, int inputID ) {
    if( JoypadID == DX_INPUT_KEY_PAD1 ) {
        if( inputID == PAD_INPUT_1 ) {
            return 0;
        }
        else if( inputID == PAD_INPUT_2 ) {
            return 1;
        }
    }
}

void GameDataInfo::StateChange( int nextState ) {
    m_gameState = nextState;
}

int GameDataInfo::GetPushCount( int playerID ) {
    return m_player[ playerID ]->GetPushCount();
}

const char* GameDataInfo::GetPlayerName( int playerID ) {
    return m_player[ playerID ]->GetName();
}

int GameDataInfo::GetRestTime( void ) {
    return m_restTime;
}

int GameDataInfo::GetRestTimeToStart( void ) {
    return m_restTimeToStart;
}

int GameDataInfo::GetGameState( void ) {
    return m_gameState;
}

void GameDataInfo::SetPlayerName( int playerID, const char *playerName ) {
    strncpy( m_playerName[playerID], playerName, sizeof( m_playerName[playerID] ) );
}

void GameDataInfo::DoStartCountDown( void ) {
    if( m_restTimeToStart > 0 ) {
        WaitTimer(1000);
        m_restTimeToStart--;
    }
    else {
        m_gameState = 4;
    }
}

void GameDataInfo::DoMainGameProcedure( void ) {
    bool isCurrentlyPushed;
    bool isPreviouslyPushed;

    static int internalCounter = 5;

    for( int i = 0; i < 8; i++ ) {
        isCurrentlyPushed = m_button[i]->IsPushed();
        isPreviouslyPushed = m_button[i]->IsPushedInPrevFrame();

        if( isCurrentlyPushed && !isPreviouslyPushed ) {
            m_player[i]->IncrementCount();
        }

        m_button[i]->UpDatePushState( isCurrentlyPushed );
    }

    internalCounter--;
    if( internalCounter <= 0 && m_restTime > 0 ) {
        m_restTime--;
        internalCounter = 5;
    }

    if( m_restTime == 0 ) {
        m_gameState = 5;
    }
}

void GameDataInfo::SortPlayerByPushCount( void ) {
    Player *tmpPlayer;
    int currentPushCount;
    int comparedPushCount;

    for( int rank = 0; rank < 8; rank++ ) {
        for( int j = rank + 1; j < 8; j++ ) {
            currentPushCount = m_player[rank]->GetPushCount();
            comparedPushCount = m_player[j]->GetPushCount();
            if( currentPushCount < comparedPushCount ) {
                tmpPlayer = m_player[rank];
                m_player[rank] = m_player[j];
                m_player[j] = tmpPlayer;
            }
        }
    }
}