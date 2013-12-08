#ifndef _RULESCREEN_
#define _RULESCREEN_

#include "Screen.h"

class RuleScreen : public Screen{
public:
    RuleScreen( int height, int width );
    ~RuleScreen();
    bool Draw( void );
    void FadeIn( void );
    void FadeOut( void );

private:
    int m_ruleImg;
};

#endif