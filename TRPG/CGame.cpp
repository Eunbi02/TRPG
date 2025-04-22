#include "CGame.h"
#include "pch.h"
#include "CMiniGame1.h"
//#include "GamePointer.h"


CGame::CGame() : m_pLevel(NULL), m_pGameNum(NULL),
m_pIsWin(NULL),MiniGame1(nullptr)
{
	cout << "���� Ŭ���� �⺻ �����ڸ� ��������ϴ�" << endl;
}

CGame::CGame(int* _level, int* _gameNum, bool* _isLose) :
	m_pLevel(_level), m_pGameNum(_gameNum),m_pIsWin(_isLose),MiniGame1(nullptr)
{
	cout << "���� : " << m_pLevel << " ���ӹ�ȣ : " << m_pGameNum << "����" << endl;
}

CGame::~CGame()
{
	cout << "���� ������ ����" << endl;
}

void CGame::SetLevel(int* _level) {
		m_pLevel = _level;
}

void CGame::SetGameNum(int* _num)
{
		m_pGameNum = _num;
}

void CGame::SetIsWin(bool* _isWin)
{
	m_pIsWin = _isWin;
}

void CGame::SetLevel(int level) {
	if (m_pLevel) *m_pLevel = level;
}
void CGame::SetGameNum(int num) {
	if (m_pGameNum) *m_pGameNum = num;
}

void CGame::Initialize()
{
	/**m_pLevel	= 1;
	*m_pGameNum = 1;
	*m_pIsWin	= true;*/
	if (*m_pGameNum == 1) {
		if(!MiniGame1)
			MiniGame1 = new CMiniGame1(m_pLevel, m_pIsWin);

		//MiniGame1->SetLevel(m_pLevel);	//���� ����
		MiniGame1->Initialize();		//������ ���� ������ �ʱ�ȭ
		MiniGame1->MakeAnswer();		//���� ����
	}
}

void CGame::Update()
{
}

void CGame::Release()
{
	SAFE_DELETE(MiniGame1);
}

void CGame::PlayGame()
{
	if (*m_pGameNum == 1) {
		MiniGame1->PlayGame();
	}
}
