#ifndef _BUTTON_H_
#define _BUTTON_H_

class Button {
public:
    Button( int belongingPAD, int inputID );
    ~Button();
    bool IsPushed( void );
    bool IsPushedInPrevFrame( void );
    void UpDatePushState( bool prevState );

private:
    bool m_pushState;
    bool m_prevPushState;
    int m_belongingPAD;
    int m_inputID;

};

#endif