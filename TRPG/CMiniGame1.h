#pragma once
#include "pch.h"
#include "Define.h"
#include "CGame.h"
class CMiniGame1 : public CGame
{
private:
	int m_iStrike;
	int m_iBall;
	int m_iRound;
	int m_iMaxRound;

	int m_iNum;
	int m_iSize;
	int* m_iAnswer;
	int* m_iGuess;

public:
	CMiniGame1();
	explicit CMiniGame1(int _iLevel, bool* _bIsLose);
	~CMiniGame1();


public:
	void	Initialize() override;
	void	Update()override; //酒流 后 窃荐
	void	Release()override; //酒流 后 窃荐

public:
	void MakeAnswer()override;
	void StrikeBall()override;
	void PlayGame()override;
};

