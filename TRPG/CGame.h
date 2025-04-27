#pragma once
#include "pch.h"
#include "Define.h"

class CGame{
protected:
	int m_iLevel;
	bool* const m_bIsLose;
public:
	CGame();
	explicit CGame(int _iLevel, bool* _bIsLose);
	virtual ~CGame();


public:
	int GetLevel()	const { return m_iLevel; };
	bool GetIsLose() const { return *m_bIsLose; };

	void SetLevel(int _iLevel);
	void SetIsLose(int _bIsLose);
	

public:
	virtual void	Initialize()	= 0;
	virtual void	Update()		= 0;
	virtual void	Release()		= 0;

	virtual void	PlayGame()		= 0;


	// minigame1 함수
public:
	virtual void MakeAnswer() { return; };
	virtual void StrikeBall() { return; };
	
	// minigame2 함수
public:
	virtual void BingoSuffle()		{ return; };
	virtual void MakeComBingo()		{ return; };
	virtual void MakeUserBingo()	{ return; };

	virtual void ArrIdx(int** _Bingo, int _iElement, int* _pIdx1, int* _pIdx2) { return; };
	virtual void BingoCheck(int** _iBingo, int _iIdx1, int _iIdx2, int* _iBNum) { return; };

	virtual void PrintBingo(int** _Arr) { return; };

};