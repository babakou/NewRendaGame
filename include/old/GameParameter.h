#ifndef _GAMEPARAMETER_H_
#define _GAMEPARAMETER_H_

class GameParameter {
public:
    GameParameter();
    ~GameParameter();
    int GetButtonCount( int playerID );
    int GetRestTime( void );

private:
    int m_buttonCount[8];
    int m_restTime;
};

#endif