#pragma once
//#include "GameSetting.cpp"
#include "CPlayer.h"
#include "CMonster.h"
#include "CSelectNum.h"

//game, isWin 포인터로 옮겨주기

//과정들 함수화???

class MainGame
{
private:
	enum NUMBER { LOADING=0,NAME, JOB, HUNT, MONSTER, FIGHT,END, ERRO }; // 만약 저장파일 입출력을 여기 저기서 하게 되면 그것도 추가
	string jobList[4] = { "전사", "마법사", "도적", "불러오기" };
	string huntList[3] = { "사냥터", "저장하기", "종료" };
	string monsterList[4] = { "초급", "중급", "고급", "전 단계" };
	string attackList[2] = { "공격", "도망" };
	int m_GameStage;
	bool isRunning; 

	CPlayer* m_pPlayer;
	CMonster* m_pMonster;

	CSelectNum SelectJob;
	CSelectNum SelectHunt;
	CSelectNum SelectMonster;
	CSelectNum SelectAttack;

	int* m_pGameNum;
	bool* m_pIsWin;
	
public:
	MainGame();
	~MainGame();

public:
public:
	void		Initialize();
	void		InitializeMonster();
	void		Update();			// 매 프레임마다 변화하는 값을 계산하는 함수
	void		Release();			// 동적 할당한 포인터의 메모리를 해제하는 코드를 모아두는 함수
};