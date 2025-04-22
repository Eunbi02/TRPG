#pragma once
#include "CObject.h"
#include "Define.h"

class CGame;

//monster의 레벨과 게임넘버를 받아야함.
class CMonster : public CObject {
private:
	int m_iLevel;
	int* m_pGameNum;
	bool* m_pIsWin;

	CGame* Game;

	//생성자와 소멸자
public:
	CMonster();
	explicit CMonster(string _name, int _hp, int _mp, int _attack, int _level, int _gameNum, bool _isLose);
	~CMonster();

	// get, set func
public:
	int GetLevel() const	{ return m_iLevel; };
	int GetGame() const		{ return *m_pGameNum; };
	bool GetIsLose()const	{ return *m_pIsWin; };

	void SetLevel(int _level);
	void SetGameNum(int* _game);
	void SetIsLose(bool*_isLose);

public:
	void	Initialize();
	void	Update(); //아직 빔
	void	Release(); 

public:
	void SetGame(); 
	void PlayGame();
};