#pragma once
#include "CMonster.h"
#include "CGame.h"
//#include "GamePointer.h"


//생성자와 소멸자
CMonster::	CMonster() :
	CObject("Unknown", 10, 10, 5),
	m_iLevel(1),m_pGameNum(nullptr),m_pIsWin(nullptr), Game(nullptr)
{
	cout << "몬스터 기본 생성자 생성" << endl;
}

CMonster::  CMonster(string _name, int _hp,int _mp , int _attack,int _level, int _gameNum, bool _isLose):
	CObject(_name, _hp, _mp, _attack), 
	m_iLevel(_level), m_pGameNum(nullptr), m_pIsWin(nullptr),Game(nullptr)
{
	cout << this->m_strName << " 몬스터 생성자 생성" << endl;
}

CMonster::	~CMonster() { Release(); }


void CMonster::SetLevel(int _level) {
	if (_level >= 0)
		(this->m_iLevel) = _level;
	switch (_level) {
	case 1:
		// 초급 몬스터 설정
		m_iHp = 50;
		m_iAttack = 5;
		break;
	case 2:
		// 중급 몬스터 설정
		m_iHp = 100;
		m_iAttack = 10;
		break;
	case 3:
		// 고급 몬스터 설정
		m_iHp = 150;
		m_iAttack = 15;
		break;
	default:
		// 기본값 설정
		break;
	}
}
void CMonster::SetGameNum(int* _game) {
		(this->m_pGameNum) = _game;
}


void CMonster::SetIsLose(bool* _isLose)
{
	this->m_pIsWin = _isLose;
}

void CMonster::Initialize()
{
	m_strName	= "Unknown";
	m_iHp		= 10;
	m_iMp		= 10;
	m_iAttack	= 5;

	if (!Game) {
		Game = new CGame();
	}

	//m_iLevel = 1;
	//m_pGameNum = 1;
	//m_pIsWin = 0;
}


void CMonster::Update()
{
}

void CMonster::Release()
{
	SAFE_DELETE(Game);
}

void CMonster::SetGame()
{
	//game 셋팅
	
	Game->SetLevel(&m_iLevel);
	Game->SetGameNum(m_pGameNum);
	Game->SetIsWin(m_pIsWin);
	Game->Initialize();
}

void CMonster::PlayGame()
{
	system("cls");

	Game->PlayGame();

	system("pause");
}

