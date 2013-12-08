#ifndef _ENTRYSCREEN_
#define _ENTRYSCREEN_

#include "Screen.h"
#include "PlayerList.h"
#include <string>
#include <vector>

class EntryScreen : public Screen {
public:
    EntryScreen( int width, int height, PlayerList* playerList );
    ~EntryScreen();
    bool Draw();
    void FadeIn();
    void FadeOut();

private:
    void DrawInitialScreen( void );

private:
    PlayerList *m_playerList;

    int m_entryWindowImg;
    int m_yellowEntryWindowImg;
};

#endif