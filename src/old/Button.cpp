#include "DxLib.h"
#include "Button.h"

Button::Button( int belongingPAD, int inputID ) {
    m_belongingPAD = belongingPAD;
    m_inputID = inputID;
    m_pushState = false;
    m_prevPushState = false;
}

Button::~Button() {
    
}

bool Button::IsPushed( void ) {
    bool IsPushed = ( GetJoypadInputState( m_belongingPAD ) & m_inputID );

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