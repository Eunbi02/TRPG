#pragma once
#include "CGame.h"

class CMiniGame2 : public CGame
{
private:
	int m_iSize;
	int m_iRound;

	int m_icomIdx1;
	int m_icomIdx2;
	int m_iuserIdx1;
	int m_iuserIdx2;

	int icomBingoNum;
	int iuserBingoNum;
	int icomElement;
	int iuserElement;

	int comNumChek[25];

	int** comBingo;
	int** userBingo;

public:
	CMiniGame2();
	explicit CMiniGame2(int _iLevel, bool* _bIsLose);
	virtual ~CMiniGame2();

public:
	void	Initialize()	override;
	void	Update()		override;
	void	Release()		override;

public:
	void BingoSuffle();
	void MakeComBingo();
	void MakeUserBingo();

	void ArrIdx(int** _Bingo, int _iElement, int* _pIdx1, int* _pIdx2) override;
	void BingoCheck(int** _Bingo, int _iIdx1, int _iIdx2, int* _iBNum) override;

	void PrintBingo(int** _Bingo) override;

public:
	void PlayGame() override;
};

