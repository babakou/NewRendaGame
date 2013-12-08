#ifndef _RESULTSCREEN_H_
#define _RESULTSCREEN_H_

#include "GameDataInfo.h"

class ResultScreen {
public:
    ResultScreen( GameDataInfo *gameDataInfo );
    ~ResultScreen();
    void Show();

private:
    GameDataInfo *m_gameDataInfo;
    int rankingFonts[8];
};

#endif