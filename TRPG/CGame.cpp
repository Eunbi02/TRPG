#include "CGame.h"
#include "pch.h"


CGame::CGame() : m_iLevel(1),m_bIsLose(nullptr)
{
	cout << "���� Ŭ���� �⺻ �����ڸ� ��������ϴ�" << endl;
}

CGame::CGame(int _iLevel, bool* _bIsLose) :
	m_iLevel(_iLevel), m_bIsLose(_bIsLose)
{
	cout << "���� : " << m_iLevel << "���� �θ� ������" << endl;
}

CGame::~CGame()
{
	cout << "���� ������ ����" << endl;
}

void CGame::SetLevel(int _iLevel) {
	this->m_iLevel = _iLevel;
}

void CGame::SetIsLose(int _bIsLose)
{
	*(this->m_bIsLose) = _bIsLose;
}
