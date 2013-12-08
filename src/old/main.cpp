#include "DxLib.h"
#include "OpeningScreen.h"
#include "GameScreen.h"
#include "PlayerEntryScreen.h"
#include "ResultScreen.h"
#include "FontSettings.h"
#include "CommonUtils.h"
#include "CommonScreenConfigure.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {

    ConfigureCommonScreen();
    if( DxLib_Init() == -1 ) {
        return -1;
    }

    GenerateFontHandle();

    GameDataInfo *gameDataInfo = new GameDataInfo();
    
    OpeningScreen *openingScreen = new OpeningScreen( gameDataInfo );
    PlayerEntryScreen *playerEntryScreen = new PlayerEntryScreen( gameDataInfo );
    GameScreen *gameScreen = new GameScreen( gameDataInfo );
    ResultScreen *resultScreen = new ResultScreen( gameDataInfo );

    SetDrawScreen( DX_SCREEN_BACK );

    int startTime, endTime;

    while( ProcessMessage() == 0 && CheckHitKey( KEY_INPUT_ESCAPE ) == 0 ) {
        while( ProcessMessage() == 0 && gameDataInfo->GetGameState() != 3 ) {
            switch( gameDataInfo->GetGameState() ) {
            case 0:
                openingScreen->Show();
                break;

            case 1:
                playerEntryScreen->Show();
                ScreenFlip();
                break;

            }
        }

        gameDataInfo->CreatePlayers();
        gameDataInfo->CreateButtons();

        while( ProcessMessage() == 0 && gameDataInfo->GetGameState() != 1 ) {
            switch( gameDataInfo->GetGameState() ) {
            case 3:
                ClearDrawScreen();
                gameScreen->ShowStartCountDown();
                gameScreen->ShowPushCount();
                ScreenFlip();
                gameDataInfo->DoStartCountDown();
                break;

            case 4:
                startTime = GetNowCount();
                gameDataInfo->DoMainGameProcedure();
                ClearDrawScreen();
                gameScreen->ShowPushCount();
                ScreenFlip();
                endTime = GetNowCount();
                WaitTimer( 20 - (endTime - startTime) );
                break;

            case 5:
                ClearDrawScreen();
                gameScreen->ShowPushCount();
                gameScreen->ShowTimeUp();
                ScreenFlip();
                WaitTimer( 5000 );
                gameDataInfo->StateChange( 6 );
                gameDataInfo->SortPlayerByPushCount();
                break;

            case 6:
                resultScreen->Show();

            default:
                break;
            }
        }

        gameDataInfo->Clear();
    }

    DxLib_End();
    delete openingScreen;
    delete gameScreen;
    delete gameDataInfo;

    return 0;
}