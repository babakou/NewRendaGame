#ifndef _COMMONSCREENCONFIGURE_
#define _COMMONSCREENCONFIGURE_

extern int screenSize_x;
extern int screenSize_y;
extern int screenColorDepthBit;

extern int captionLocation_x;
extern int captionLocation_y;

extern const int WHITE;
extern const int BLACK;
extern const int RED;
extern const int BRIGHTGRAY;
extern const int BLUE;
extern const int GREEN;

extern const char *Takahashi_M_Path;
extern int TakahashiImg;

void ConfigureCommonScreen( void );

#endif