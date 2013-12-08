#ifndef _OPENINGSCREEN_
#define _OPENINGSCREEN_

#include "Screen.h"
#include <string>
#include "FontSettings.h"

class OpeningScreen : public Screen {
public:
    OpeningScreen( int width, int height );
    ~OpeningScreen();
    bool Draw();
    void FadeIn( void );
    void FadeOut( void );

private:
    int m_titleLetterLocation_x;
    int m_titleLetterLocation_y;

    int m_titleImg;
};

#endif