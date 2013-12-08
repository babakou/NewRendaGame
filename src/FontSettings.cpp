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
        "PixelMplus12 Regular", 
        48,
        6,
        DX_FONTTYPE_ANTIALIASING );

    titleFont = CreateFontToHandle( 
        "‚l‚r –¾’©", 
        48,
        5,
        DX_FONTTYPE_ANTIALIASING );

    captionFont = CreateFontToHandle( 
        "PixelMplus12 Regular", 
        36,
        5,
        DX_FONTTYPE_ANTIALIASING );

    counterFont = CreateFontToHandle( 
        "PixelMplus12 Regular", 
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
        "PixelMplus12 Regular", 
        84,
        5,
        DX_FONTTYPE_ANTIALIASING );

    playerNameFont = CreateFontToHandle( 
        "PixelMplus12 Regular", 
        28,
        5,
        DX_FONTTYPE_ANTIALIASING );

    registPlayerNameFont = CreateFontToHandle( 
        "PixelMplus12 Regular", 
        48,
        5,
        DX_FONTTYPE_ANTIALIASING );

    winnerFont = CreateFontToHandle( 
        "PixelMplus12 Regular", 
        60,
        5,
        DX_FONTTYPE_ANTIALIASING );

    secondWinnerFont = CreateFontToHandle( 
        "PixelMplus12 Regular", 
        48,
        5,
        DX_FONTTYPE_ANTIALIASING );

    thirdWinnerFont = CreateFontToHandle( 
        "PixelMplus12 Regular", 
        36,
        5,
        DX_FONTTYPE_ANTIALIASING );

    underFourthFont = CreateFontToHandle( 
        "PixelMplus12 Regular", 
        28,
        5,
        DX_FONTTYPE_ANTIALIASING );

    answerFont = CreateFontToHandle( 
        "PixelMplus12 Regular", 
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

    SetTransColor( 0, 0, 0 );
}