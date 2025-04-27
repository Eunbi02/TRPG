#pragma once
#include "CObject.h"
#include "Define.h"

class CGame;
class CMiniGame1;
class CMiniGame2;


//monster�� ������ ���ӳѹ��� �޾ƾ���.
class CMonster : public CObject {
private:
	//int m_iLevel;
	int m_pGameNum;
	bool m_pIsWin;

	//CGame* Game;
	CGame* MiniGame1;
	CGame* MiniGame2;

	//�����ڿ� �Ҹ���
	CMonster();
	explicit CMonster(string _name, int _hp, int _mp, int _attack, int _level, int _gameNum, bool _isLose);
	CMonster(const CMonster& rhs);
	virtual ~CMonster();
public:
	static int m_iMonsterKilled;

	static CObject* Create()
	{
		CObject* pCMonster = new CMonster;

		return pCMonster;
	}

	static CObject* Create(string _name, int _hp, int _mp,
		int _attack, int _level, int _gameNum, bool _isLose)
	{
		CObject* pCMonster = new CMonster(_name, _hp,
			_mp, _attack, _level, _gameNum, _isLose);

		return pCMonster;
	}

	static CObject* Create(const CMonster& rhs)
	{
		CObject* pCMonster = new CMonster(rhs);

		return pCMonster;
	}

	void Destroy()
	{
		if (this != nullptr)
			delete this;
	}

	

	// get, set func
public:
	int GetGameNum() const		{ return m_pGameNum; };
	bool GetIsLose()const	{ return m_pIsWin; };

	void SetMonsterLevel(int _level)  override;
	void SetGameNum() override;
	void SetIsLose(bool*_isLose)override;

public:
	void	Initialize() override;
	void	Update()override; //���� ��
	void	Release()override;

public:
	void SetGame()override;
	void PlayGame()override;
	static void CountMonsterKill();

};

