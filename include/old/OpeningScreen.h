#ifndef _OPENINGSCREEN_H_
#define _OPENINGSCREEN_H_

#include "GameDataInfo.h"

class OpeningScreen {
public:
    OpeningScreen( GameDataInfo *gameDataInfo );
    ~OpeningScreen();
    void Show();

private:
    GameDataInfo *m_gameDataInfo;
    const char *m_openingTitleLetter;
};

#endif