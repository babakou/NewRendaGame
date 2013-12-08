#include "DxLib.h"
#include "Player.h"

static int PADNumFromButtonID( int buttonID ) {
    if( 0 <= buttonID && buttonID <= 3 ) {
        return DX_INPUT_KEY_PAD1;
    }
    else if( 4 <= buttonID && buttonID <= 7 ) {
        return DX_INPUT_PAD2;
    }
    else {
        return -1;
    }
}

static int KeyNumFromButtonID( int buttonID ) {
    if( buttonID == 0 || buttonID == 4 ) {
        return PAD_INPUT_1;
    }
    else if( buttonID == 1 || buttonID == 5 ) {
        return PAD_INPUT_2;
    }
    else if( buttonID == 2 || buttonID == 6 ) {
        return PAD_INPUT_3;
    }
    else if( buttonID == 3 || buttonID == 7 ) {
        return PAD_INPUT_4;
    }
    else {
        return -1;
    }
}

Player::Player( const char *name, int buttonID ) {
    m_name = name;
    m_pushCount = 0;
    m_buttonID = buttonID;
    m_rank = 0;

    m_button.AssignPADandKeyID( PADNumFromButtonID( buttonID ), KeyNumFromButtonID( buttonID ) );
}

Player::Player( const Player& org ) {
    m_name = org.m_name;
    m_pushCount = org.m_pushCount;
    m_buttonID = org.m_buttonID;
    m_rank = org.m_rank;

    m_button.AssignPADandKeyID( PADNumFromButtonID( org.m_buttonID ), KeyNumFromButtonID( org.m_buttonID ) );
}

Player::~Player() {
}

void Player::IncrementCount( void ) {
    m_pushCount++;
}

const char* Player::GetName( void ) {
    return m_name.c_str();
}

int Player::GetPushCount( void ) {
    return m_pushCount;
}

int Player::GetRank( void ) {
    return m_rank;
}

void Player::SetRank( int rank ) {
    m_rank = rank;
}

int Player::GetButtonID( void ) {
    return m_buttonID;
}

bool Player::DoesPush( void ) {
    bool isCurrentlyPushed = m_button.IsPushed();
    bool doesPush;

    if( isCurrentlyPushed && !m_button.IsPushedInPrevFrame() ) {
        doesPush = true;
    }
    else {
        doesPush = false;
    }

    m_button.UpDatePushState( isCurrentlyPushed );

    return doesPush;
}