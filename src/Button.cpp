#include "DxLib.h"
#include "Button.h"

Button::Button( void ) {
    m_pushState = false;
    m_prevPushState = false;
}

Button::~Button() {
    
}

void Button::AssignPADandKeyID( int PAD, int keyID ) {
    m_PAD = PAD;
    m_keyID = keyID;
}

bool Button::IsPushed( void ) {
    bool IsPushed = ( GetJoypadInputState( m_PAD ) & m_keyID );

    if( IsPushed ) {
        return true;
    }
    else {
        return false;
    }
}

bool Button::IsPushedInPrevFrame( void ) {
    return m_prevPushState;
}

void Button::UpDatePushState( bool prevState ) {
    m_prevPushState = prevState;
}