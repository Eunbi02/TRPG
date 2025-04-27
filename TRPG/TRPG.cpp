// TRPG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include "MainGame.h"

int main()
{
    srand(unsigned int(time(nullptr)));
    
    //MainGame Game;

    /*Game.Initialize();
    Game.Update();*/

    MainGame* pGame = MainGame::Create();
    pGame->Initialize();
    pGame->Update();
    pGame->Destroy();

    delete pGame;
    
    return 0;
}
