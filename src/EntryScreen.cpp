#include "EntryScreen.h"
#include "CommonScreenConfigure.h"
#include "FontSettings.h"
#include <string.h>

namespace ES {
    std::string captionLetter = "参加する方の名前を教えてください(敬称略)";
    int captionLetterHeight;
    int captionLocation_x;
    int captionLocation_y;
    int registPlayerNameHeight;

    char header[8][20];
    int headerWidth[8];
    int playerNameLocation_y[8];

    std::string playerName[8];

    int currentPlayerNum = 0;

    std::string gameStartStr = "ゲームを開始します";
    int gameStartLoc_x;
    int gameStartLoc_y;
}

EntryScreen::EntryScreen( int width, int height, PlayerList *playerList ) {
    m_width = width;
    m_height = height;

    m_playerList = playerList;

    GetFontStateToHandle( NULL, &ES::captionLetterHeight, NULL, captionFont );

    int strWidth = GetDrawStringWidthToHandle( ES::captionLetter.c_str(), ES::captionLetter.length(), captionFont );
    captionLocation_x = (m_width / 2) - (strWidth / 2);
    captionLocation_y = 15;

    GetFontStateToHandle( NULL, &ES::registPlayerNameHeight, NULL, registPlayerNameFont );

    for( int i = 0; i < 8; i++ ) {
         _snprintf( ES::header[i], sizeof( ES::header[i] ), "Player %d : ", (i + 1) );
        ES::headerWidth[i] = GetDrawStringWidthToHandle( ES::header[i], strlen( ES::header[i] ), registPlayerNameFont );
    }

    for( int i = 0; i < 8; i++ ) {
        ES::playerNameLocation_y[i] = captionLocation_y + ES::captionLetterHeight + 10 + ( (ES::registPlayerNameHeight + 10) * i );
    }

    for( int i = 0; i < 8; i++ ) {
        ES::playerName[i].clear();
    }

    int gameStartStrHeight = 0;
    GetFontStateToHandle( NULL, &gameStartStrHeight, NULL, captionFont );
    strWidth = GetDrawStringWidthToHandle( ES::gameStartStr.c_str(), ES::gameStartStr.length(), captionFont );
    ES::gameStartLoc_x = (width / 2) - (strWidth / 2);
    ES::gameStartLoc_y = m_height - 100;
}

EntryScreen::~EntryScreen() {
}

void EntryScreen::DrawInitialScreen( void ) {
    //DrawBox( 0, 0, m_width - 1, m_height - 1, WHITE, TRUE );
    DrawGraph( 0, 0, TakahashiImg, FALSE );

    DrawStringToHandle( captionLocation_x, captionLocation_y, ES::captionLetter.c_str(), BLACK, captionFont );

    for( int i = 0; i < 8; i++ ) {
        DrawStringToHandle( 10, ES::playerNameLocation_y[i], ES::header[i], BLACK, defaultFont );
    }
}

bool EntryScreen::Draw( void ) {
    ClearDrawScreen();

    DrawInitialScreen();

    for( int i = 0; i < ES::currentPlayerNum; i++ ) {
        DrawStringToHandle( 10 + ES::headerWidth[i], ES::playerNameLocation_y[i], ES::playerName[i].c_str(), BLACK, registPlayerNameFont );
    }

    if( ES::currentPlayerNum >= 8 ) {
        DrawStringToHandle( ES::gameStartLoc_x, ES::gameStartLoc_y, ES::gameStartStr.c_str(), BLACK, captionFont );
        ScreenFlip();

        while( 0 == CheckHitKey( KEY_INPUT_Z ) ) {
            if( ProcessMessage() == -1 ) {
                break;
            }
        }

        for( int i = 0; i < ES::currentPlayerNum; i++ ) {
            if( 0 != ES::playerName[i].length() ) {
                m_playerList->AddPlayer( ES::playerName[i].c_str(), i );
            }
        }

        ES::currentPlayerNum = 0;

        return true;
    }

    ScreenFlip();

    char tmpName[50];
    if( 2 == KeyInputString( 10 + ES::headerWidth[ES::currentPlayerNum] + 10, ES::playerNameLocation_y[ES::currentPlayerNum], 48, tmpName, TRUE ) ) {
        if( ES::currentPlayerNum >= 1 ) {
            ES::playerName[ES::currentPlayerNum - 1].clear();
            ES::currentPlayerNum --;
        }
        return false;
    }
    ES::playerName[ES::currentPlayerNum] = tmpName;

    ES::currentPlayerNum++;

    return false;
}

void EntryScreen::FadeIn( void ) {
    for( int brightness = 0; brightness < 256; brightness += 15 ) {
        ClearDrawScreen();
        SetDrawBright( brightness, brightness, brightness );
        DrawInitialScreen();
        ScreenFlip();
        Sleep( 10 );
    }
}

void EntryScreen::FadeOut( void ) {
    for( int brightness = 255; brightness >= 0; brightness -= 15 ) {
        ClearDrawScreen();
        SetDrawBright( brightness, brightness, brightness );
        DrawInitialScreen();
        for( int i = 0; i < ES::currentPlayerNum; i++ ) {
            DrawStringToHandle( 10 + ES::headerWidth[i], ES::playerNameLocation_y[i], ES::playerName[i].c_str(), BLACK, registPlayerNameFont );
        }
        ScreenFlip();
        Sleep( 10 );
    }
}