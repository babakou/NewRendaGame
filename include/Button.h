#ifndef _BUTTON_
#define _BUTTON_

#include "DxLib.h"

class Button {
public:
    Button();
    ~Button();
    void AssignPADandKeyID( int PAD, int KeyID );
    bool IsPushed( void );
    bool IsPushedInPrevFrame( void );
    void UpDatePushState( bool prevState );

private:
    bool m_pushState;
    bool m_prevPushState;
    int m_PAD;
    int m_keyID;
};

#endif