#ifndef _COMMONUTILS_H_
#define _COMMONUTILS_H_

int DrawStringAtCenterOfScreen( const char *string, int color, int fontHandle );
int DrawStringInAlignmentPos( int x, int y, const char *string, int color, int fontHandle );
void DrawStringCapableCR( int x, int y, const char *string, int color, int fontHandle );
void ListUpFontsToFile();

#endif