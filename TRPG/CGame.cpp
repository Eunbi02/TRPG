#include "CGame.h"
#include "pch.h"


CGame::CGame() : m_iLevel(1),m_bIsLose(nullptr)
{
	cout << "게임 클래스 기본 생성자를 만들었습니다" << endl;
}

CGame::CGame(int _iLevel, bool* _bIsLose) :
	m_iLevel(_iLevel), m_bIsLose(_bIsLose)
{
	cout << "레벨 : " << m_iLevel << "게임 부모 생성자" << endl;
}

CGame::~CGame()
{
	cout << "게임 생성자 삭제" << endl;
}

void CGame::SetLevel(int _iLevel) {
	this->m_iLevel = _iLevel;
}

void CGame::SetIsLose(int _bIsLose)
{
	*(this->m_bIsLose) = _bIsLose;
}
