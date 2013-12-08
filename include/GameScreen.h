#ifndef _GAMESCREEN_
#define _GAMESCREEN_

#include "Game.h"
#include "Screen.h"

class GameScreen : public Screen {
public:
    GameScreen( int width, int height, Game *game );
    ~GameScreen();
    bool Draw();
    void FadeIn( void );
    void FadeOut( void );

private:
    Game *m_game;
    void DrawChart( int xLocationOfChartCenter, int yLocation, int chartWidth, int chartHeight, int color );
};

#endif