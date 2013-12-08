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
        "メイリオ", 
        48,
        6,
        DX_FONTTYPE_ANTIALIASING );

    titleFont = CreateFontToHandle( 
        "ＭＳ 明朝", 
        48,
        5,
        DX_FONTTYPE_ANTIALIASING );

    captionFont = CreateFontToHandle( 
        "メイリオ", 
        36,
        5,
        DX_FONTTYPE_ANTIALIASING );

    counterFont = CreateFontToHandle( 
        "ＭＳ 明朝", 
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
        "ＭＳ 明朝", 
        84,
        5,
        DX_FONTTYPE_ANTIALIASING );

    playerNameFont = CreateFontToHandle( 
        "メイリオ", 
        28,
        5,
        DX_FONTTYPE_ANTIALIASING );

    registPlayerNameFont = CreateFontToHandle( 
        "メイリオ", 
        48,
        5,
        DX_FONTTYPE_ANTIALIASING );

    winnerFont = CreateFontToHandle( 
        "メイリオ", 
        60,
        5,
        DX_FONTTYPE_ANTIALIASING );

    secondWinnerFont = CreateFontToHandle( 
        "メイリオ", 
        48,
        5,
        DX_FONTTYPE_ANTIALIASING );

    thirdWinnerFont = CreateFontToHandle( 
        "メイリオ", 
        36,
        5,
        DX_FONTTYPE_ANTIALIASING );

    underFourthFont = CreateFontToHandle( 
        "メイリオ", 
        28,
        5,
        DX_FONTTYPE_ANTIALIASING );

    answerFont = CreateFontToHandle( 
        "ＭＳ 明朝", 
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