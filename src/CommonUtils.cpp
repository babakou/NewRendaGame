#include <string.h>

#include "DxLib.h"
#include "CommonUtils.h"
#include "CommonScreenConfigure.h"

int DrawStringAtCenterOfScreen( const char *string, int color, int fontHandle ) {
    int centerOfTheScreen_x = screenSize_x >> 1;
    int centerOfTheScreen_y = screenSize_y >> 1;
    int strWidth = GetDrawStringWidthToHandle( string, strlen( string ), fontHandle );

    int leftTopOfString_x = centerOfTheScreen_x - (strWidth >> 1);
    
    return DrawStringToHandle( leftTopOfString_x, centerOfTheScreen_y, string, color, fontHandle );
}

int DrawStringInAlignmentPos( int x, int y, const char *string, int color, int fontHandle ) {
    int xLeftTopOfString = x - ( GetDrawStringWidthToHandle( string, strlen( string ), fontHandle ) / 2 );

    return DrawStringToHandle( xLeftTopOfString, y, string, color, fontHandle );
}

void DrawStringCapableCR( int x, int y, const char *string, int color, int fontHandle ) {
    return;
}

void ListUpFontsToFile() {
    char *fontNameBuffer;
    int numFonts;
    FILE *fp;

    fp = fopen( "UsableFonts.txt", "w" );
    if( fp == NULL ) return;

    numFonts = EnumFontName( NULL, 0 );

    fontNameBuffer = (char *)malloc( numFonts * 64 );
    if( fontNameBuffer == NULL ) return;
    
    EnumFontName( fontNameBuffer, numFonts );

    for( int i = 0; i < numFonts; i++ ) {
        fprintf( fp, fontNameBuffer + i * 64 );
    }

    free( fontNameBuffer );

    fclose( fp );
}