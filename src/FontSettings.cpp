#include "DxLib.h"
#include "FontSettings.h"
#include "CommonScreenConfigure.h"

int defaultFont;
int titleFont;
int captionFont;
int counterFont;
int restTimeFont;
int playerNameFont;
int registPlayerNameFont;
int restTimeToStartFont;
int areYouReadyFont;
int winnerFont;
int secondWinnerFont;
int thirdWinnerFont;
int underFourthFont;
int answerFont;

void GenerateFontHandle( void ) {
    defaultFont = CreateFontToHandle( 
        "���C���I", 
        48,
        6,
        DX_FONTTYPE_ANTIALIASING );

    titleFont = CreateFontToHandle( 
        "�l�r ����", 
        48,
        5,
        DX_FONTTYPE_ANTIALIASING );

    captionFont = CreateFontToHandle( 
        "���C���I", 
        36,
        5,
        DX_FONTTYPE_ANTIALIASING );

    counterFont = CreateFontToHandle( 
        "�l�r ����", 
        36,
        5,
        DX_FONTTYPE_ANTIALIASING );

    restTimeFont = CreateFontToHandle( 
        "LED BOARD", 
        72,
        5,
        DX_FONTTYPE_ANTIALIASING,
        DX_CHARSET_DEFAULT );

    restTimeToStartFont = CreateFontToHandle( 
        "LED BOARD", 
        72,
        5,
        DX_FONTTYPE_ANTIALIASING,
        DX_CHARSET_DEFAULT );

    areYouReadyFont = CreateFontToHandle( 
        "�l�r ����", 
        84,
        5,
        DX_FONTTYPE_ANTIALIASING );

    playerNameFont = CreateFontToHandle( 
        "���C���I", 
        28,
        5,
        DX_FONTTYPE_ANTIALIASING );

    registPlayerNameFont = CreateFontToHandle( 
        "���C���I", 
        48,
        5,
        DX_FONTTYPE_ANTIALIASING );

    winnerFont = CreateFontToHandle( 
        "���C���I", 
        60,
        5,
        DX_FONTTYPE_ANTIALIASING );

    secondWinnerFont = CreateFontToHandle( 
        "���C���I", 
        48,
        5,
        DX_FONTTYPE_ANTIALIASING );

    thirdWinnerFont = CreateFontToHandle( 
        "���C���I", 
        36,
        5,
        DX_FONTTYPE_ANTIALIASING );

    underFourthFont = CreateFontToHandle( 
        "���C���I", 
        28,
        5,
        DX_FONTTYPE_ANTIALIASING );

    answerFont = CreateFontToHandle( 
        "�l�r ����", 
        60,
        5,
        DX_FONTTYPE_ANTIALIASING );

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
        BRIGHTGRAY,
        BRIGHTGRAY,
        BLACK,
        BLACK );

    SetTransColor( 255, 255, 255 );
}