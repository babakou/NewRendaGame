#include <string.h>
#include "DxLib.h"
#include "CommonUtils.h"
#include "FontSettings.h"
#include "CommonScreenConfigure.h"
#include "PlayerEntryScreen.h"

PlayerEntryScreen::PlayerEntryScreen( GameDataInfo *gameDataInfo ) {
    m_gameDataInfo = gameDataInfo;

    for( int i = 0; i < 8; i++ ) {
        memset( m_playerName[i], ' ', sizeof(m_playerName[i]) );
    }

    SetKeyInputStringColor( 
        BLACK, 
        BLACK, 
        WHITE,
        BLACK,
        WHITE,
        WHITE,
        BLACK,
        BLACK,
        BLACK,
        BLACK,
        WHITE,
        WHITE,
        WHITE,
        BLACK,
        BLACK );

    m_givenPlayerNameID = 0;

    for( int i = 0; i < 8; i++ ) {
        _snprintf( m_preHeader[i], sizeof( m_preHeader[i] ), "Player %d : ", (i + 1) );
    }
}

PlayerEntryScreen::~PlayerEntryScreen( void ) {

}

void PlayerEntryScreen::Show( void ) { 
    ClearDrawScreen();

    static int preHeaderWidth = GetDrawStringWidthToHandle( m_preHeader[0], strlen( m_preHeader[0] ), defaultFont );
    DrawStringInAlignmentPos( screenSize_x / 2, 0, "参加する方の名前を教えてください", BLACK, captionFont );

    for( int i = 0; i < 8; i++ ) {
        DrawStringToHandle( 10, (i + 1) * 60, m_preHeader[i], BLACK, defaultFont );
    }

    for( int i = 0; i < m_givenPlayerNameID; i++ ) {
        DrawStringToHandle( 10 + preHeaderWidth + 10, (i + 1) * 60, m_playerName[i], BLACK, registPlayerNameFont );
    }

    if( m_givenPlayerNameID >= 8 ) {
        DrawStringInAlignmentPos( screenSize_x / 2, screenSize_y - 100, "ゲームを開始します。", BLACK, captionFont );
        ScreenFlip();

        while( CheckHitKey( KEY_INPUT_Z ) == 0 ) {
            if( ProcessMessage() == -1 ) {
                break;
            }
        }

        m_gameDataInfo->StateChange( 3 );
        m_givenPlayerNameID = 0;

        return;
    }

    ScreenFlip();

    memset( m_playerName[m_givenPlayerNameID], ' ', sizeof( m_playerName[m_givenPlayerNameID] ) );
    if( 2 == KeyInputString( 10 + preHeaderWidth + 10, (m_givenPlayerNameID + 1) * 60, 48, m_playerName[m_givenPlayerNameID], TRUE ) ) {
        return;
    }

    m_gameDataInfo->SetPlayerName( m_givenPlayerNameID, m_playerName[m_givenPlayerNameID] );

    m_givenPlayerNameID++;
}

void PlayerEntryScreen::AskPlayerName( int playerID ) {

}