#include "DxLib.h"
#include "OpeningScreen.h"
#include "RuleScreen.h"
#include "EntryScreen.h"
#include "GameScreen.h"
#include "ResultScreen.h"
#include "CommonScreenConfigure.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {

    ConfigureCommonScreen();
    if( DxLib_Init() == -1 ) {
        return -1;
    }

    GenerateFontHandle();
    TakahashiImg = LoadGraph( Takahashi_M_Path );

    PlayerList *playerList = NULL;

    Game *game = NULL;
    
    Screen *openingScreen = NULL;
    Screen *ruleScreen = NULL;
    Screen *entryScreen = NULL;
    Screen *gameScreen = NULL;
    Screen *resultScreen = NULL;

    SetDrawScreen( DX_SCREEN_BACK );

    int startTime, endTime;
    int cycleCount = 0;
    int state = 0;

    while( 1 ) {
        if( state == 0 ) {
            openingScreen = new OpeningScreen( screenSize_x, screenSize_y );
            openingScreen->FadeIn();
            while( ProcessMessage() == 0 && state == 0 ) {
                ClearDrawScreen();
                openingScreen->Draw();
                ScreenFlip();
                if( 0 != CheckHitKey( KEY_INPUT_Z ) ) {
                    state = 1;
                }
            }
            openingScreen->FadeOut();
        }

        if( state == 1 ) {
            ruleScreen = new RuleScreen( screenSize_x, screenSize_y );
            ruleScreen->FadeIn();
            while( ProcessMessage() == 0 && state == 1 ) {
                ClearDrawScreen();
                ruleScreen->Draw();
                ScreenFlip();
                if( 0 != CheckHitKey( KEY_INPUT_Z ) ) {
                    state = 2;
                }
            }
            ruleScreen->FadeOut();
        }

        bool IsEntryEnd = false;
        while( state == 2 ) {
            entryScreen = new EntryScreen( screenSize_x, screenSize_y, playerList );
            entryScreen->FadeIn();

            while ( ProcessMessage() == 0 && !IsEntryEnd ) {
                IsEntryEnd = entryScreen->Draw();
            }

            entryScreen->FadeOut();
            state = 3;
        }
  
        while( state == 3 ) {
            playerList = new PlayerList();
            game = new Game( playerList );
            gameScreen = new GameScreen( screenSize_x, screenSize_y, game );
            gameScreen->FadeIn();

            while( ProcessMessage () == 0 && game->GetRestTimeToStart() > 0 ) {
                game->CountDown();
                ClearDrawScreen();
                gameScreen->Draw();
                ScreenFlip();
            }

            state = 4;
        }

        while( ProcessMessage() == 0 && state == 4 ) {
            startTime = GetNowCount();
            game->Main();
            cycleCount++;
            if( (cycleCount % 4) == 0 ) {
                game->RestTimeDecrement();
            }
            if( (cycleCount % 2) == 0 ) {
                ClearDrawScreen();
                gameScreen->Draw();
                ScreenFlip();
            }
            endTime = GetNowCount();
            Sleep( 25 - (startTime - endTime) );

            if( game->IsGameFinished() ) {
                state = 5;
            }
        }

        cycleCount = 0;

        while( state == 5 ) {
            while( ProcessMessage() == 0 && !CheckHitKey( KEY_INPUT_Z ) ) {
                ClearDrawScreen();
                gameScreen->Draw();
                ScreenFlip();
            }
            state = 6;
            gameScreen->FadeOut();
            game->PrepareForResult();
        }      

        while( state == 6 ) {
            resultScreen = new ResultScreen( screenSize_x, screenSize_y, game );
            resultScreen->FadeIn();
            while ( ProcessMessage() == 0 && !CheckHitKey( KEY_INPUT_Z ) && !CheckHitKey( KEY_INPUT_P ) ){
                ClearDrawScreen();
                resultScreen->Draw();
                ScreenFlip();

                if( CheckHitKey( KEY_INPUT_Z ) && CheckHitKey( KEY_INPUT_P ) ) {
                    state = 2;
                }
            }

            if( state != 6 ) {
                resultScreen->FadeOut();
            }
        }

        if ( game != NULL ) delete game; game = NULL;
        if ( entryScreen != NULL ) delete entryScreen; entryScreen = NULL;
        if ( gameScreen != NULL ) delete gameScreen; gameScreen = NULL;
        if ( resultScreen != NULL) delete resultScreen; resultScreen = NULL;
    }

    DxLib_End();
    if( openingScreen != NULL ) delete openingScreen;
    if( ruleScreen != NULL ) delete ruleScreen;
    if( entryScreen != NULL ) delete entryScreen;
    if( gameScreen != NULL ) delete gameScreen;
    if( resultScreen != NULL ) delete resultScreen;
    if( game != NULL ) delete game;
    if( playerList != NULL ) delete playerList;

    return 0;
}