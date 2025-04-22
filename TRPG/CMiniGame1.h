#pragma once
#include "pch.h"
#include "Define.h"
class CMiniGame1
{
private:
	int* m_pLevel;
	//int* m_iGameNum;
	bool* m_pIsWin;


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
	explicit CMiniGame1(int* _level,bool* _isWin);
	~CMiniGame1();

public:
	int* GetLevel()	const { return m_pLevel; };
	void SetLevel(int* _level);

public:
	void	Initialize();
	void	Update(); //酒流 后 窃荐
	void	Release(); //酒流 后 窃荐

public:
	void MakeAnswer();
	void StrikeBall();
	void PlayGame();
};

