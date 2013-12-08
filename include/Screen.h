#ifndef _SCREEN_
#define _SCREEN_

class Screen {
public:
    virtual ~Screen();
    virtual bool Draw() = 0;
    virtual void FadeOut( void ) = 0;
    virtual void FadeIn( void ) = 0;

protected:
    int m_width;
    int m_height;
};

#endif