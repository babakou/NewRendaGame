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
    std::string m_titleLetter;

    int m_titleLetterLocation_x;
    int m_titleLetterLocation_y;
};

#endif