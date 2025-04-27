#pragma once
#include "CMonster.h"
#include "CGame.h"
#include "CMiniGame1.h"
#include "CMiniGame2.h"
//#include "GamePointer.h"


//생성자와 소멸자
CMonster::	CMonster() :
	CObject("Unknown", 100, 0, 10,1),
	m_pGameNum(0),m_pIsWin(0),MiniGame1(nullptr)
{
	cout << "몬스터 기본 생성자 생성" << endl;
}

CMonster::  CMonster(string _name, int _hp,int _mp , int _attack,int _level, int _gameNum, bool _isLose):
	CObject(_name, _hp, _mp, _attack,_level), 
	m_pGameNum(0), m_pIsWin(0), MiniGame1(nullptr)
{
	m_tagINFO.iLevel = _level;
	cout << this->m_tagINFO.strName << " 몬스터 생성자 생성" << endl;
}

CMonster::CMonster(const CMonster& rhs):
	CObject(rhs.GetName(), rhs.GetHp(),rhs.GetExp(), rhs.GetAttack(),rhs.GetLevel()),
	m_pGameNum(rhs.GetGameNum()), m_pIsWin(rhs.GetIsLose()), MiniGame1(nullptr)
{
	cout << rhs.GetName() << " 몬스터 복사 생성자 생성" << endl;
}

CMonster::	~CMonster() { Release(); }


void CMonster::SetMonsterLevel(int _level) {
	if (_level >= 0)
		(this->m_tagINFO.iLevel) = _level;
	switch (_level) {
	case 1:
		// 초급 몬스터 설정
		m_tagINFO.iHp = 10;
		m_tagINFO.iAttack = 5;
		break;
	case 2:
		// 중급 몬스터 설정
		m_tagINFO.iHp = 30;
		m_tagINFO.iAttack = 10;
		break;
	case 3:
		// 고급 몬스터 설정
		m_tagINFO.iHp = 50;
		m_tagINFO.iAttack = 50; //원래는 15
		break;
	default:
		// 기본값 설정
		break;
	}
}

// 랜덤으로 게임넘버 생성후, 레벨과 게임 넘버에 맞게 미니게임 인스턴스 생성
void CMonster::SetGameNum() {
	//m_pGameNum = rand() % 3 + 1;
	m_pGameNum = 1;

	switch (m_pGameNum) {
	case 1:
		m_tagINFO.strName = "슬라임";
		MiniGame1 = new CMiniGame1(m_tagINFO.iLevel, &m_pIsWin);
		break;
	case 2:
		m_tagINFO.strName = "드워프";
		MiniGame2 = new CMiniGame2(m_tagINFO.iLevel, &m_pIsWin);
		break;
	case 3:
		break;
	default:
		break;
	}
}


void CMonster::SetIsLose(bool* _isLose)
{
	this->m_pIsWin = _isLose;
}

void CMonster::Initialize()
{
	m_tagINFO.strName = "Unknown";
	m_tagINFO.iHp = 100;
	m_tagINFO.iExp = 0;
	m_tagINFO.iAttack = 10;
	m_tagINFO.iLevel = 1;
}

void CMonster::Update()
{
}

void CMonster::Release()
{
	SAFE_DELETE(MiniGame1);
	SAFE_DELETE(MiniGame2);
}

void CMonster::SetGame()
{
	switch (m_pGameNum) {
	case 1:
		MiniGame1->MakeAnswer();
		break;
	case 2:
		MiniGame2->Initialize();
		break;
	case 3:
		break;
	default:
		break;
	}
}

void CMonster::PlayGame()
{
	system("cls");

	switch (m_pGameNum) {
	case 1:
		MiniGame1->PlayGame();
		break;
	case 2:
		MiniGame2->PlayGame();
		break;
	case 3:
		break;
	default:
		break;
	}

	system("pause");
}

void CMonster::CountMonsterKill()
{
	m_iMonsterKilled++;
}

