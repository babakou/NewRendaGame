#ifndef _RESULTSCREEN_
#define _RESULTSCREEN_

#include "Screen.h"
#include "Game.h"

class ResultScreen : public Screen {
public:
    ResultScreen( int height, int width, Game *game );
    ~ResultScreen();
    bool Draw( void );
    void FadeIn( void );
    void FadeOut( void );

private:
    Game *m_game;
};

#endif